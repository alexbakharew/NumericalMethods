#include <thread>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <future>         // std::async, std::future
#include <vector>
// unmovable class with some big data
class Param 
{
    friend class MyClass;
public:
    std::vector<int> array;
public:
    Param() = delete;
    Param(const Param &other) = delete;

    Param(const std::vector<int>& initial)
    {
        std::cout << "Array constructor\n";
        array.resize(initial.size());
        std::copy(initial.begin(), initial.end(), array.begin());
    }
    Param & operator=(const Param& other) = delete;

    friend std::ostream& operator<<(std::ostream &os,Param &param);
    virtual ~Param() 
    {
        std::cout << "Array Destructor" << std::endl;
    }

};

std::ostream& operator<<(std::ostream &os,Param &param)
{
    for(auto &i : param.array)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T>& vec)
{
    for(auto &i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

// thread class with unmovable objects
class MyClass 
{
protected:
    std::unique_ptr<Param> ptr;
public:

    MyClass( std::unique_ptr<Param> &&param) {
        ptr = std::move(param);
        std::cout << "My Class Constructor" << std::endl;
    }

    MyClass(MyClass &&other) {
        ptr = std::move(other.ptr);
        std::cout << "My Class Moved" << std::endl;
    }

    MyClass(const MyClass &) = delete;
    MyClass & operator=(const MyClass &)= delete;
    
    std::unique_ptr<Param> operator()() 
    {
        long int sum;
        for(auto &i : ptr->array)
        {
            sum += i;
        }
        sum /= ptr->array.size();
        
        for(auto &i : ptr->array)
        {
            i += sum;
        }
        return std::move(ptr);
    }

};

int main() 
{
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,0,8,6,3,4,5,6,4,3,5,6,7,8,6,5,4,3,2,7,8,8,0};
    std::future<std::unique_ptr<Param>> my_thread = std::async(std::move( // move thread
                          MyClass(std::move( // move param of the thread
                                  std::unique_ptr<Param>( // create big object
                                     new Param(arr))))));
    // std::unique_ptr<Param> param(new Param("HEllo World!"));

    auto res = my_thread.get();
    arr = res.get()->array;
    std::cout << arr << std::endl;
    return 0;
}


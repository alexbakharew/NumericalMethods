#include <thread>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <future>         // std::async, std::future
#include <vector>
// unmovable class with some big data
class Param {
public:
    std::string str;
public:
    Param() = delete;
    Param(const Param &other) = delete;

    Param(const char* value) : str(value) {
        std::cout << "Param Constructor:" << str << std::endl;
    }
    Param & operator=(const Param& other) = delete;

    friend std::ostream& operator<<(std::ostream &os,Param &param);
    virtual ~Param() {
        std::cout << "Param Destructor" << std::endl;
    }

};

std::ostream& operator<<(std::ostream &os,Param &param){
  return os << param.str;    
}

// thread class with unmovable objects
class MyClass {
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
        ptr->str += std::string("JOPA\n");
        return std::move(ptr);
    }

};

int main() 
{

    std::future<std::unique_ptr<Param>> my_thread = std::async(std::move( // move thread
                          MyClass(std::move( // move param of the thread
                                  std::unique_ptr<Param>( // create big object
                                     new Param("Hello world!"))))));
    // std::unique_ptr<Param> param(new Param("HEllo World!"));

    auto res = my_thread.get();
    std::cout << res->str << std::endl;
    
    return 0;
}


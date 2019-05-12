#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <random>
#include <ctime>
void add(int* ref, size_t count)
{
    for(size_t i = 0; i < count; ++i)
    {
        ++*ref;
    }
}
void MakeSequentaly()
{

}
void MakeConcurrently(const int task_size, const int count, std::vector<int>& vals)
{
    std::vector<std::thread> threads(task_size);
    for(int i = 0; i < task_size; ++i)
    {
        threads[i] = std::thread(add, &vals[i], count);
    }
    for(int i = 0; i < task_size; ++i)
    {
        threads[i].join();
        std::cout << vals[i] << std::endl;
    }
}
int main()
{
    const int task_size = 10;
    const int count = 1000000;
    std::vector<int> vals(task_size, 0);

    double v1 = 1.0;
    float v2 = 1.0;
    long long v3 = 1;
    std::cout << sizeof(&v1) << " " << sizeof(&v2) << " " << sizeof(&v3) << "\n";
//    for(int i = 0; i < task_size; ++i)
//    {
//        threads[i] = std::thread(add, &vals[i], count);
//    }
//    for(int i = 0; i < task_size; ++i)
//    {
//        threads[i].join();
//        std::cout << vals[i] << std::endl;
//    }

    return 0;
}

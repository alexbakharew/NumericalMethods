#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <random>
#include <ctime>
void add(long int& ref, size_t count)
{
    long int tmp = ref;
    for(size_t i = 0; i < count; ++i)
    {
        tmp += 1;
    }
    ref = tmp;
}
void MakeSequentaly(const long int task_size, const long int count, std::vector<long int>& vals)
{
    for(int i = 0; i < task_size; ++i)
    {
        add(std::ref(vals[i]), count);
    }
}
void MakeConcurrently(const long int task_size, const long int count, std::vector<long int>& vals, std::vector<std::thread>& threads)
{

    for(int i = 0; i < task_size; ++i)
    {
        threads[i] = std::thread(add, std::ref(vals[i]), count);
    }
    for(int i = 0; i < task_size; ++i)
    {
        threads[i].join();
    }
}
int main()
{
    const long int task_size = 8;
    const long int count = 100000000;
    
    std::vector<long int> vals1(task_size, 0);
    std::vector<long int> vals2(task_size, 0);
    std::vector<std::thread> threads(task_size);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    MakeConcurrently(task_size, count, vals1, threads);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Concurrently = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;

    begin = std::chrono::steady_clock::now();
    MakeSequentaly(task_size, count, vals2);
    end = std::chrono::steady_clock::now();
    std::cout << "Sequentaly = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;

    return 0;
}


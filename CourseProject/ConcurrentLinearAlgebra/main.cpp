#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <future>
#include <random>
#include <ctime>
#include <memory>
#include <iostream>
#include "boostedmatrix.h"
#include "boostedmatrix.cpp"
void TestAddition()
{
    BoostedMatrix<double> m1;
    BoostedMatrix<double> m2;
    std::fstream f1("../ConcurrentLinearAlgebra/input/0.t", std::ios::in);
    std::fstream f2("../ConcurrentLinearAlgebra/input/1.t");
    if(f1.is_open())
        f1 >> m1;
    if(f2.is_open())
        f2 >> m2;
//    std::cout << m1 << "\n-------------\n";
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    m1 += m2;
//    std::cout << m1 << std::endl;
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;

}
void TestFuture()
{
    // future from a packaged_task
    std::packaged_task<int()> task([]{ return 7; }); // wrap the function
    std::future<int> f1 = task.get_future();  // get a future
    std::thread t(std::move(task)); // launch on a thread

    // future from an async()
    std::future<int> f2 = std::async(std::launch::async, []{ return 8; });

    // future from a promise
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread( [&p]{ p.set_value_at_thread_exit(9); }).detach();

    std::cout << "Waiting..." << std::flush;
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done!\nResults are: "
              << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
    t.join();
}
std::vector<int> func(std::vector<int>& v1, std::vector<int>& v2)
{
    std::vector<int> res;
    for(int i = 0; i < v1.size(); ++i)
    {
        res.push_back(v1[i] + v2[i]);
    }
    return res;
}
int f(int a, int b)
{
    return a + b;
}
void test()
{
    std::vector<int> v1 = {1 ,2 ,4};
    std::vector<int> v2 = {1 ,2 ,4};

    std::future<std::vector<int>> f2 = std::async(std::launch::async, func, std::ref(v1), std::ref(v2));
    f2.wait();
    auto res =  f2.get();
    for(auto i : res)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
int main()
{
    TestAddition();
    return 0;
}

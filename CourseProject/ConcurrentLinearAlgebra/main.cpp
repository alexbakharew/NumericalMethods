#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <future>
#include <random>
#include <ctime>
#include <memory>
void func(std::vector<int>& v/*, int& res*/)
{
    auto v_curr = std::move(v);
    auto GetSum = [&v_curr]()
    {
        int sum = 0;
        for(int i = 0; i < v_curr.size(); ++i)
        {
            sum += v_curr[i];
        }
        return sum;
    };
    std::cout << GetSum();
    return;
}

int main()
{
    std::vector<int> v = {1, 5, 3, 6, 8, 2, 3, 4,5 ,6};
    int sum;
    std::thread t(func, v/*, sum*/);
    t.join();
//    func(v, sum);
    std::cout << sum << std::endl;
    return 0;
}

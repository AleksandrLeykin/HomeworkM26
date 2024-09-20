#include <iostream>
#include <chrono>
//#include <cstdlib> //rand()
//#include <ctime> //time()
//#include <thread>

#include "sumArray.h"

int main()
{
    //int n = 100000, m = 0;
    //
    //std::vector<int> vec(n);

    //srand(time(nullptr));
    //for (int i = 0; i < n; ++i)
    //{
    //    vec[i] = rand() % 101;
    //    //std::cout << vec[i] << " ";
    //}
    //std::cout << "\n";
    //auto begin = std::chrono::steady_clock::now();

    //for (int i = 0; i < vec.size(); i++)
    //{
    //    m += vec[i];
    //}
    //std::cout << m <<"\n";
    //auto end = std::chrono::steady_clock::now();

    //auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //std::cout << "\n";
    //std::cout << "The time: " << elapsed_ms.count() << " ms\n";
    
    const int array_size = 10000000;
    const int number_threads = 5;
    SumArray sum(array_size, number_threads);
    //sum.printArray();

    //calsulate sum using threads
    auto t_start = std::chrono::system_clock::now();
    int s = sum.calculate_using_threads();
    auto t_end = std::chrono::system_clock::now();
    long diff = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
    std::cout << "SUM (using threads: " << number_threads << ") is " << s << "  Time (ms): " << diff << std::endl;

    //calculate sum in main thread
    t_start = std::chrono::system_clock::now();
    s = sum.calculate_without_threads();
    t_end = std::chrono::system_clock::now();
    diff = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
    std::cout << "SUM (main thread) is " << s << "  Time (ms): " << diff << std::endl;

    return 0;   
}


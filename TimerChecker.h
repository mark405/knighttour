#pragma once

#include <chrono>
#include <iostream>
using namespace std::chrono;

class TimerChecker
{
    private:
        steady_clock::time_point begin;
        steady_clock::time_point finish;
    public:
        TimerChecker()
        {
            begin = steady_clock::now();
        }
        ~TimerChecker()
        {
            finish = steady_clock::now();

            auto countOfNanoseconds = duration_cast<nanoseconds>(finish - begin).count();
            std::cout << "Time is: " << countOfNanoseconds << " nanoseconds" << std::endl;

            auto countOfMicroseconds = duration_cast<microseconds>(finish - begin).count();
            std::cout << "Time is: " << countOfMicroseconds << " microseconds" << std::endl;
        }

};

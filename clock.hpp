#ifndef CLOCK_HPP // include guard
#define CLOCK_HPP
#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include <stdio.h>

class Clock {
    public:
        Clock();

        int get_step();

        std::string now(std::string format = "");

        void increment();

        void reset();
    private:
        int start;
        int step;
};

#endif // CLOCK_HPP
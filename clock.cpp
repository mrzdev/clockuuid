/*
github: @mrzdev

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// The Clock class keeps track of the env's timestep and returns current local time

#include "clock.hpp"

Clock::Clock() {
    start = 0;
    step = start;
}

int Clock::get_step() {
    return step;
}

std::string Clock::now(std::string format){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    if (format == "") {
        return asctime(now);
    } else {
        char buf[80];
        strftime(buf, sizeof(buf), format.c_str(), now);
        return buf;
    }
}

void Clock::increment(){
    step++;
}

void Clock::reset() {
    step = start;
}

int main(){
    std::shared_ptr<Clock> clock = std::make_shared<Clock>();
    std::string current_time = clock->now();
    printf("Current time: %s\n", current_time.c_str());
    printf("Step: %d\n", clock->get_step());

    clock->increment();
    current_time = clock->now();
    printf("Step: %d\n", clock->get_step());

    return 0;
}

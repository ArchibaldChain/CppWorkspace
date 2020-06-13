// waiting.cpp  -- using clock in a time-delay loop
#include <iostream>
#include <ctime>
int main()
{
    float secs = 5;
    clock_t delay = secs * CLOCKS_PER_SEC; //convert to clock ticks
    std::cout << "starting\a\n";
    clock_t start = clock();
    while (clock() - start < delay)
        ;
    std::cout << "done\a\n";
    return 0;
}
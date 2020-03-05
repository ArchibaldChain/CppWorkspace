//
// Created by Archibald Chain on 2020/2/27.
//
#include <iostream>

int main(){
    const int MINUTES = 60;
    const int SECONDS = 60;
    const int HOURS = 24;
    using namespace std;
    cout << "Enter the number of seconds"<<endl;
    long time, t;
    cin >> time;
    t = time;
    int seconds, minutes, hours, days;
    seconds = time % SECONDS;
    time = time / SECONDS;
    minutes = (time) % MINUTES;
    time = time / MINUTES;
    hours = (time) % HOURS;
    days = time / HOURS;
    printf("%ld seconds = %d days, %d hours, %d minutes, %d seconds", t, days, hours, minutes, seconds);

}


#include <iostream>
#include <time.h>
#include <math.h>

const int WORK_TIME = 1500;
const int BREAK_TIME = 240;
const int LONG_BREAK_TIME = 1200;

const int CHECKS = 4;

void PassTime(int timePass){
    time_t timer;
    time_t start;
    time(&start);    //Get start time

    if (timePass == WORK_TIME)
        std::cout << "Work Time" << std::endl;
    else if (timePass == BREAK_TIME)
        std::cout << "Short Break Time" << std::endl;
    else if (timePass == LONG_BREAK_TIME)
        std::cout << "Extended Break Time" << std::endl;

    while (true){
        time(&timer);
        if (difftime(timer, start) == timePass){
            break;
        }
    }
    std::cout << "End" << std::endl;
}

void Cycle(){
    PassTime(WORK_TIME);
    PassTime(BREAK_TIME);
}

void StartWork(){
    int count = 0;
    while (true){
        if (count != CHECKS){
            Cycle();
            count++;
        }
        else{
            PassTime(LONG_BREAK_TIME);
        }
    }
}

int main(){
    StartWork();
}
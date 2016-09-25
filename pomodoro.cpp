#include <iostream>
#include <time.h>
#include <math.h>
#include <string>
#include <unistd.h>

const double WORK_TIME = 1200;
const double BREAK_TIME = 240;
const double LONG_BREAK_TIME = 900;
const double SEC_IN_MIN = 60;
const int TOTAL_COUNT = 3;

void PassTime(int timePass){
    time_t timer;
    time_t start;
    time(&start);    //Get start time

    if (timePass == WORK_TIME)
        std::cout << "Work Time: " << WORK_TIME/SEC_IN_MIN << " minutes" << std::endl;
    else if (timePass == BREAK_TIME)
        std::cout << "Short Break Time: " << BREAK_TIME/SEC_IN_MIN << " minutes" << std::endl;
    else if (timePass == LONG_BREAK_TIME)
        std::cout << "Extended Break Time: " << LONG_BREAK_TIME/SEC_IN_MIN << " minutes" << std::endl;

    while (true){   
        time(&timer);
        if (difftime(timer, start) == timePass * 3/4){
            std::cout << "Time remaining: " << (timePass * 1/4)/ SEC_IN_MIN << " minutes " << std::endl;
        }
        if (difftime(timer, start) == timePass* 1/2){
            std::cout << "Time remaining: " << (timePass * 1/2)/ SEC_IN_MIN << " minutes " << std::endl;
        }
        if (difftime(timer, start) == timePass* 1/4){
            std::cout << "Time remaining: " << (timePass * 3/4)/ SEC_IN_MIN << " minutes " << std::endl;
        }
        if (difftime(timer, start) == timePass){
            break;
        }
        sleep(1);
    }
}

void Cycle(){
    PassTime(WORK_TIME);
    PassTime(BREAK_TIME);
}

void ClearScreen(){
    std::cout << std::string(50, '\n');
}

void StartWork(){
    int count = 0;
    while (true){
        if (count == TOTAL_COUNT){
            ClearScreen();
            PassTime(LONG_BREAK_TIME);
            count = 0;
        }
        else{
            Cycle();
            count++;
        }
    }
}

int main(){
    StartWork();
}

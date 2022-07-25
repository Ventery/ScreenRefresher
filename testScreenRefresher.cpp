#include <iostream>
#include <unistd.h>
#include "ScreenRefresher.h"
using namespace std;

#define MEASURE "bytes"
#define AMOUNT 102400
#define PERCENTAGE 77
int main()
{
    {
        ScreenRefresher outputer(MEASURE, AMOUNT);
        int block = AMOUNT/PERCENTAGE;
        for (int now =block ; now < AMOUNT; now+=block)
        {
            if (AMOUNT - now < block)
                now = AMOUNT;
            usleep(300000);
            outputer.rePrint(now);
        }     
    }
    return 0;
}
#include "../lockstatus.h"
using namespace sensorinfo;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const int kSleepingTime = 20000;

inline void Sleep(void);

int main(void)
{
    sensorinfo::SensorStatus current_cpu;

    srand((unsigned)time(NULL));
    double cpu = 0;
    while (1)
    {
        cpu = random() % 100;
        cpu = cpu * (random() % 100) / 100;
        current_cpu.set_cpu(cpu);
        Sleep();
        printf("%.06f %%\n", current_cpu.get_cpu());
    }

    return 0;
} // main

inline void Sleep(void)
{
    for (int i = 0; i < kSleepingTime; ++i)
    {
        for (int j = 0; j < kSleepingTime; ++j)
        {
        }
    }
} // Sleep

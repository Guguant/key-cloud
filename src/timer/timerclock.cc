/*
 * Copyright (c) 2017 An.AI Inc.
 * All rights reserved.
 *
 * License boilerplate.
 *
 * Sun Yiming. Email: hi@anai.co
 */

#include "timerclock.h"
#include <ctime>
#include <stdio.h>

using namespace std;

namespace samtimer
{
    // transform standard time to string format's time.
    string Timer::GetStringTime(string &st)
    {
        char tmp_time[50];
        sprintf(tmp_time,  "%d-%02d-%02d %02d:%02d:%02d", \
                            current_time_.year_,\
                            current_time_.mon_, \
                            current_time_.day_, \
                            current_time_.hour_,\
                            current_time_.min_, \
                            current_time_.sec_  \
                            );
        st = tmp_time;
        return tmp_time;
    }
    
    // call time API to catch standard time.
    void Timer::set_current_time()
    {
        time_t seed = time(NULL);
        tm* now = localtime(&seed);

        current_time_.year_ = now->tm_year + 1900;
        current_time_.mon_  = now->tm_mon + 1;
        current_time_.day_  = now->tm_mday;
        current_time_.hour_ = now->tm_hour;
        current_time_.min_  = now->tm_min;
        current_time_.sec_  = now->tm_sec;
    }

    StandardTime Timer::get_current_time() const
    {
        return current_time_;
    }

} // namespace samtimer

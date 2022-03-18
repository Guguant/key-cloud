/*
 * Copyright (c) 2017 - 2022.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 * Description: Class Timer used to test.
 */

#include "../timerclock.h"
#include <stdio.h>

int main(void)
{
    knotimer::Timer Now;
    std::string st;

    Now.set_current_time();
    Now.GetStringTime(st);

    printf("%s\n", st.c_str());
    return 0;
}

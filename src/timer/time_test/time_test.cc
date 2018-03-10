// TEST: Class Timer

#include "../timerclock.h"
#include <stdio.h>

int main(void)
{
    samtimer::Timer Now;
    std::string st;

    Now.set_current_time();
    Now.GetStringTime(st);
    
    printf("%s\n", st.c_str());
    return 0;
}
#include "Display.h"
#include <sys/time.h>


extern "C" 
void c_display(const char * string)
{
	timeval tp;
	gettimeofday(&tp, 0);
    int64_t time = tp.tv_sec;
    time *= 1000;
    time += tp.tv_usec / 1000;
    char c_str[100] = "";
    sprintf(c_str, "Current time value is %ld, and %s", time, string);

    Display display;
    display.display_string(c_str);

    return;
}
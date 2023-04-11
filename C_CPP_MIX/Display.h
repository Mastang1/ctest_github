#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <string>
#include <string.h>
#include <list>


class Display
{
private:
    /* data */
    typedef std::list <std::string> string_list_t;
    string_list_t m_str_list;

public:
    Display(/* args */);
    ~Display();
    void display_string(const char * string);
    void display_list();
    void on_callback();
};




#endif
#include "Display.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Display::Display(/* args */)
{
    m_str_list.push_back("Today");
    m_str_list.push_back("is");
    m_str_list.push_back("a");    
    m_str_list.push_back("nice");
    m_str_list.push_back("day!");

}

Display::~Display()
{
    m_str_list.clear();
}

void Display::display_string(const char * string)
{
    std::cout << string <<std::endl;
}

void Display::display_list()
{
    if(!m_str_list.empty()){
        for(string_list_t::iterator it = m_str_list.begin();it != m_str_list.end();it++){
            std::cout << *it << " ";
        }
        std::cout<< std::endl;
    }
    return;
}

void Display::on_callback()
{
    std::cout << "callback function from class Display!\n";
    return;
}
#include <iostream>
#include "funcs.h"

// add functions here
using std::endl;
using std::cout;
using std::string;

void test_ascii(string str)
{
    for(int i=0;i<str.length();i++)
    {
        cout<<str[i]<<" "<<(int)str[i]<<endl;
    }
} 

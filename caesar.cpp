#include <iostream>
#include <cctype>
#include "caesar.h"

using std::string;

char shiftChar(char c, int rshift)
{
    int shifted=0,shifter=rshift%26; //mod 26 for really large numbers

    if(isspace(c)||ispunct(c)||isdigit(c))
    {
        return c;
    }

    if (isupper(c))
    {
        if(c+shifter>90)
        {
            return (int)c+(shifter)-26;
        }
        if(c+shifter<65)
        {
            return (int)c+(shifter)+26;
        }
    }

    if(islower(c))
    {
        if(c+shifter>122)
        {
            return (int)c+(shifter)-26;
        }
        if(c+shifter<97)
        {
            return (int)c+(shifter)+26;// +/- 26 for wraparound
        }
    }

    return c+(shifter);
}

string encryptCaesar(string plaintext, int rshift)
{
    string result="";
    
    for(int i=0;i<plaintext.length();i++)
    {
        result+=shiftChar(plaintext[i],rshift);
    }
    return result;
}

#include <iostream>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"

using std::string;
using std::cout;
using std::endl;

string encryptVigenere(string plaintext, string keyword)
{
    int shifter=0, charcounter=0;
    char chartemp; //character of keyword
    string result="";
    int keywordat;
    for(int i=0;i<plaintext.length();i++)
    {
        if(isalpha(plaintext[i]))
        {
            charcounter++;
            keywordat=charcounter%keyword.length()-1;
            if ((int)keywordat<0)
            {
                keywordat+=keyword.length();
            }
           // cout<<keywordat<<endl;
            chartemp=keyword.at(keywordat);
            if(isupper(chartemp))
            {
                shifter=(int)chartemp-65;
            }
            else if(islower(chartemp))
            {
                shifter=(int)chartemp-97;
            }
        }
        result+=shiftChar(plaintext[i],shifter);
    }
    return result;
}

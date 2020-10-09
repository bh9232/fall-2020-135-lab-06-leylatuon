#include <iostream>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

using std::string;

string decryptCaesar(string ciphertext, int rshift)
{
    int shifter=(-1)*rshift;
    return encryptCaesar(ciphertext,shifter);
}
string decryptVigenere(string ciphertext, string keyword)
{
    int shifter=0, charcounter=0;
    char chartemp; //character of keyword
    string result="";
    int keywordat;
    if (keyword=="")
    {
        return ciphertext;
    }
    for(int i=0;i<ciphertext.length();i++)
    {
        if(isalpha(ciphertext[i]))
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
        shifter=(-1)*(shifter);
        result+=shiftChar(ciphertext[i],shifter);
    }
    return result;
}





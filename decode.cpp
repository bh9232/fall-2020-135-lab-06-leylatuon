#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "funcs.h"
#include "caesar.h"
#include "decrypt.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

string decodeCaesar(string encoded)
{
    string strings[26]; //keep track of 26 possible rotations
    double stringdists[26]; //distances of each rotation
    int tempocc[26]={0}; //during each rotation contains # of char occurances
                        //initializes each letter occurance to 0
    double tempfreq[26];
    double frequencies[] =
    {   0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015,
        0.0077, 0.04, 0.024, 0.067, 0.075,0.019, 0.00095, 0.06, 0.063, 0.091, 
        0.028, 0.0098, 0.024, 0.0015, 0.02, 0.00074
    }; //letter frequencies from wikipedia
    string tempstr="";
    double tempdist=0;
    double alphacount=0;//counts alpha chars make sure not to divide by total chars including spaces/symbols
    for(int i=0;i<26;i++)//indexes through 26 sentence rotations
    {
        alphacount=0;
        tempdist=0;
        for(int o=0;o<26;o++)
        {
            tempocc[o]=0; //need to reset tempocc array
        }
        strings[i]=decryptCaesar(encoded,i);
        tempstr=strings[i];
       //cout<<tempstr<<endl;
        for(int j=0;j<strings[i].length();j++) //parse through each char in current sentence
        {
            if(isalpha(tempstr.at(j)))
            {
                if(islower(tempstr.at(j)))
                {
                    tempocc[tempstr.at(j)-97]++;//takes dec of current char and -97 to match to alphabet index
                                            //0-25 being a-z and adds 1 to # of occurances of corresponding char
                }
                else if(isupper(tempstr.at(j)))
                {
                    tempocc[tempstr.at(j)-65]++;
                }
                alphacount++;
            }

        }
        for(int k=0;k<26;k++)
        {
            tempfreq[k]=tempocc[k]/alphacount;//divide occurances by total alpha chars
            //cout<<tempfreq[k]<<endl;
        }

        for(int l=0;l<26;l++)
        {
            tempdist+=pow(tempfreq[l]-frequencies[l],2);
        }
    stringdists[i]=tempdist;
    //cout<<stringdists[i];
    }
    int indexSmallest=0;
    for(int u=1;u<26;u++)
    {
        if(stringdists[u]<stringdists[indexSmallest])
        {
            indexSmallest=u;
        }
    }
    
    return strings[indexSmallest];
}

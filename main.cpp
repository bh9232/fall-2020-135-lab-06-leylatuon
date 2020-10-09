#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

using std::cout;
using std::endl;

int main()
{
    test_ascii("Cat :3 Dog");
    cout<<endl;
    cout<<encryptCaesar("Hello, World!", 10)<<endl;
    cout<<encryptCaesar("The quick brown fox jumps over 13 lazy dogs.", 555)<<endl;
    cout<<encryptCaesar("Goldilocks & the 3 Bears.", 555)<<endl;
    cout<<encryptCaesar("Goldilocks & the 3 Bears.", -999)<<endl;
    cout<<encryptCaesar("The quick brown fox jumps over 13 lazy dogs.", -999)<<endl;
    cout<<encryptCaesar("The quick brown fox jumps over 13 lazy dogs.", 0)<<endl;

    cout<<encryptVigenere("The quick brown fox jumps over 13 lazy dogs.", "CAKE")<<endl;
    cout<<encryptVigenere("The quick brown fox jumps over 13 lazy dogs.", "cake")<<endl;
    cout<<encryptVigenere("Goldilocks & the 3 Bears.", "apples")<<endl;
    cout<<encryptVigenere("Goldilocks & the 3 Bears.", "APPLES")<<endl;

    return 0;
}

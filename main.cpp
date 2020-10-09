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
    cout<<encryptCaesar("Hello, World!", 10)<<endl<<endl;
    cout<<encryptVigenere("Hello, World!", "cake")<<endl<<endl;
    cout<<decryptVigenere("Vho uwimo dryap fyb luwtu ofit 13 lkda dyku.", "CAKE")<<endl<<endl;
    cout<<decryptVigenere("Vho uwimo dryap fyb luwtu ofit 13 lkda dyku.", "")<<endl<<endl;
    return 0;
}

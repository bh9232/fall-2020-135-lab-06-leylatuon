#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h""

TEST_CASE("Caesar Cipher")
{
    CHECK(encryptCaesar("The quick brown fox jumps over 13 lazy dogs.", 555)=="Cqn zdrlt kaxfw oxg sdvyb xena 13 ujih mxpb.");
    CHECK(encryptCaesar("Goldilocks & the 3 Bears.", 555)=="Pxumruxltb & cqn 3 Knjab.");
    CHECK(encryptCaesar("Goldilocks & the 3 Bears.", -999)=="Vdasxadrzh & iwt 3 Qtpgh.");
    CHECK(encryptCaesar("The quick brown fox jumps over 13 lazy dogs.", -999)=="Iwt fjxrz qgdlc udm yjbeh dktg 13 apon sdvh.");
    CHECK(encryptCaesar("The quick brown fox jumps over 13 lazy dogs.", 0)=="The quick brown fox jumps over 13 lazy dogs.");
}

TEST_CASE("Vigenere Cipher")
{
    CHECK(encryptVigenere("The quick brown fox jumps over 13 lazy dogs.", "CAKE")=="Vho uwimo dryap fyb luwtu ofit 13 lkda dyku.");
}

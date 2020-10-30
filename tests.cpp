#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "decode.h"

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
    CHECK(encryptVigenere("The quick brown fox jumps over 13 lazy dogs.", "cake")=="Vho uwimo dryap fyb luwtu ofit 13 lkda dyku.");
    CHECK(encryptVigenere("The quick brown fox jumps over 13 lazy dogs.", "j")=="Cqn zdrlt kaxfw oxg sdvyb xena 13 ujih mxpb.");
    CHECK(encryptVigenere("The quick brown fox jumps over 13 lazy dogs.", "")=="The quick brown fox jumps over 13 lazy dogs.");
}

TEST_CASE("Decrypt Ciphers")
{
    CHECK(decryptVigenere("Vho uwimo dryap fyb luwtu ofit 13 lkda dyku.", "CAKE")=="The quick brown fox jumps over 13 lazy dogs.");
    CHECK(decryptVigenere("Vho uwimo dryap fyb luwtu ofit 13 lkda dyku.", "cake")=="The quick brown fox jumps over 13 lazy dogs.");
    CHECK(decryptCaesar("Cqn zdrlt kaxfw oxg sdvyb xena 13 ujih mxpb.", 555)=="The quick brown fox jumps over 13 lazy dogs.");
    CHECK(decryptCaesar("Iwt fjxrz qgdlc udm yjbeh dktg 13 apon sdvh.", -999)=="The quick brown fox jumps over 13 lazy dogs.");
}

TEST_CASE("Decode with Frequency")
{
    CHECK(decodeCaesar("K nyelvo bksxlyg sc k zroxywoxyx yp yzdsmc")=="A double rainbow is a phenomenon of optics");
    CHECK(decodeCaesar("Hpphmf dispnf jt tjnqmz uif tvqfsjps cspxtfs.")=="Google chrome is simply the superior browser.");
    CHECK(decodeCaesar("J ibwf b dbmdvmvt fybn upnnpspx vogpsuvobufmz cvu mvdljmz J tuvejfe.")=="I have a calculus exam tommorow unfortunately but luckily I studied.");
    CHECK(decodeCaesar("Hm dmfkhrg bkzrr H kdzqmdc sgzs Bzdrzq nmbd rzhc 'ds st aqtsd'.")=="In english class I learned that Caesar once said 'et tu brute'.");
}


#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntToString(int number);
    static string getLine();
    static int convertStringToInt(string number);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int wczytajLiczbeCalkowita();
    static char getCharacter();
    static char wybierzOpcjeZMenuEdycja();
    static string removeChar(string str, char c);
    static char chooseOptionBeetwenTwoChars();
};

#endif

#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string konwerjsaIntNaString(int liczba);
    static string getLine();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int wczytajLiczbeCalkowita();
    static char getCharacter();
    static char wybierzOpcjeZMenuEdycja();
    string removeChar(string str, char c);
};

#endif

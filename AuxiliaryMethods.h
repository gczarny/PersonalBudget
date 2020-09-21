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
    static float convertStringToFloat(string number);
    static char getCharacter();
    static string replaceCommaWithDot(string line);
    static string removeChar(string str, char c);
    static char chooseOptionBeetwenTwoChars();
};

#endif

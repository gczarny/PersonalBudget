#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::getLine()
{
    cin.clear();
    cin.sync();
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::replaceCommaWithDot(string line)
{
    replace( line.begin(), line.end(), ',', '.'); // replace all ',' to '.'
    return line;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int integerNumber;
    istringstream iss(number);
    iss >> integerNumber;

    return integerNumber;
}

float AuxiliaryMethods::convertStringToFloat(string number)
{
    float floatNumber;
    istringstream iss(number);
    iss >> floatNumber;

    return floatNumber;
}

char AuxiliaryMethods::getCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

char AuxiliaryMethods::chooseOptionBeetwenTwoChars()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);



        if (input.length() == 1 && (tolower(input[0]) == 't' || tolower(input[0]) == 'n'))
        {
            character = input[0];
            break;
        }
        cout << "Wprowadz t lub n" << endl;
    }
    return character;
}

string AuxiliaryMethods::removeChar(string str, char c)
{
    string result;
    for (size_t i = 0; i < str.size(); i++)
    {
        char currentChar = str[i];
        if (currentChar != c)
        result += currentChar;
    }
    return result;
}

/*
string AuxiliaryMethods::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}


string AuxiliaryMethods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int AuxiliaryMethods::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
*/

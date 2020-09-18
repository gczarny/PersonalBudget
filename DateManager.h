#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
public:
    static bool extractDateAndCHeckIfValid(const string& s, int& d, int& m, int& y);
    static string checkActualDate(const string& s, int& d, int& m, int& y);
    static bool extractDateAndCHeckIfValid();
    static bool checkIfDateFormatAndYearAreValid(string date);
    static int convertStringDateToIntegerDate(string date);
    static string getActualDateInStringFormat();
    static string convertIntDateToStringWithHyphens(int date);

};

#endif

#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
public:
    static bool extractDateAndCHeckIfValid(const string& s, int& d, int& m, int& y);
    static bool checkIfDateFormatAndYearAreValid(string date);
    static string getActualYearAndMonth();
    static string getPreviousMonthOfActualYear();
    static string getDateFromUser();
    static string convertIntegerDateToYearAndMonthInString(int date);
    static string getActualDateInStringFormat();
    static string convertIntDateToStringWithHyphens(int date);
    static int convertStringDateToIntegerDate(string date);
};

#endif

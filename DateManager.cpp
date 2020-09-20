#include <iostream>
#include "DateManager.h"

using namespace std;


bool DateManager::extractDateAndCHeckIfValid(const string& s, int& d, int& m, int& y)
{
    istringstream is(s);
    char delimiter;

    if (is >> y >> delimiter >> m >> delimiter >> d) {
        struct tm t = {0};
        t.tm_mday = d;
        t.tm_mon = m - 1;
        t.tm_year = y - 1900;
        t.tm_isdst = -1;

        // normalize:
        time_t when = mktime(&t);
        const struct tm *norm = localtime(&when);

        // validate (is the normalized date still the same?):
        return (norm->tm_year == y - 1900 &&
                norm->tm_mon  == m - 1 &&
                norm->tm_mday == d
                );
    }
    return false;
}

bool DateManager::checkIfDateFormatAndYearAreValid(string date)
{
    int year = stoi(date.substr(0,4));
    int actualYear = stoi(getActualDateInStringFormat().substr(0,4));

    if(date.length() <= 11 && (year >= 2000 && year <= actualYear))
        return true;
    else
        return false;
}

string DateManager::getDateFromUser()
{
    int d, m, y;
    cout << "Wprowadz date w formacie rrrr-mm-dd (minimalny rok 2000): ";
    string date = AuxiliaryMethods::getLine();

    while(checkIfDateFormatAndYearAreValid(date) == false || extractDateAndCHeckIfValid(date, d, m, y) == false)
    {
        cout << "Wprowadzono niepoprawna date (poprawny format: rrrr-mm-dd)";
        date = AuxiliaryMethods::getLine();
    }

    return date;
}

string DateManager::getActualDateInStringFormat()
{
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d");
    auto str = oss.str();

    return str;
}

string DateManager::getActualYearAndMonth()
{
    string actualYearAndMonth = getActualDateInStringFormat().substr(0, 7);
    //actualYearAndMonth = actualYearAndMonth.substr(0, 7);                         //0,7 to include '-'
    actualYearAndMonth = AuxiliaryMethods::removeChar(actualYearAndMonth, '-');

    return actualYearAndMonth;
}
string DateManager::getPreviousMonthOfActualYear()
{
    string actualYearAndMonth = getActualDateInStringFormat().substr(0, 7);
    //actualYearAndMonth = actualYearAndMonth.substr(0, 7);
    actualYearAndMonth = AuxiliaryMethods::removeChar(actualYearAndMonth, '-');
    int previousMonth = AuxiliaryMethods::convertStringToInt(actualYearAndMonth) - 1;
    string previousMonthOfActualYear = AuxiliaryMethods::convertIntToString(previousMonth);

    return previousMonthOfActualYear;
}

string DateManager::convertIntegerDateToYearAndMonthInString(int date)
{
    string yearAndMonth = AuxiliaryMethods::convertIntToString(date);
    yearAndMonth = yearAndMonth.substr(0, 6);

    return yearAndMonth;
}


int DateManager::convertStringDateToIntegerDate(string date)
{
    string dateWithoutHyphens = AuxiliaryMethods::removeChar(date, '-'); //remove '-' from date
    int dateAsInteger = stoi(dateWithoutHyphens);

    return dateAsInteger;
}

string DateManager::convertIntDateToStringWithHyphens(int date)
{
    string dateWithHyphens = AuxiliaryMethods::convertIntToString(date);
    dateWithHyphens.insert(4, "-");
    dateWithHyphens.insert(7, "-");

    return dateWithHyphens;
}

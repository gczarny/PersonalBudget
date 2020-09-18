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
    int  year = stoi(date.substr(0,4));

    if(date.length() <= 11 && year >= 2000)
        return true;
    else
        return false;
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

int DateManager::convertStringDateToIntegerDate(string date)
{
    string dateWithoutHyphens;
    int dateAsInteger;

    dateWithoutHyphens = AuxiliaryMethods::removeChar(date, '-');
    dateAsInteger = stoi(dateWithoutHyphens);

    return dateAsInteger;
}

string DateManager::convertIntDateToStringWithHyphens(int date)
{
    string DateWithHyphens = AuxiliaryMethods::convertIntToString(date);
    DateWithHyphens.insert(4, "-");
    DateWithHyphens.insert(7, "-");

    return DateWithHyphens;
}

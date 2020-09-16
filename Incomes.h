#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <iostream>

using namespace std;

class Incomes
{
    //int incomeId;
    //string userId;
    string date;
    string item;
    string amount;

public:
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    string getDate();
    string getItem();
    string getAmount();
};

#endif

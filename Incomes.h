#ifndef INCOMES_H
#define INCOMES_H
#include <iostream>

using namespace std;

class Incomes
{
    int incomeId;
    string userId;
    string date;
    string item;
    string amount;

public:
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
};

#endif

#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>

using namespace std;

class Budget
{
    int userId;
    int date;
    string item;
    string amount;


public:
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getUserId();
    int getDate();
    string getItem();
    string getAmount();
};

#endif

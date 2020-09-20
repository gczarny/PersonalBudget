#ifndef EXPENSES_H
#define EXPENSES_H
#include <iostream>

using namespace std;

class Expenses
{
    int expenseId;
    int userId;
    int date;
    string item;
    string amount;


public:
    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount();
};

#endif

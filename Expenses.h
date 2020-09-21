#ifndef EXPENSES_H
#define EXPENSES_H
#include <iostream>
#include "Budget.h"

using namespace std;

class Expenses : public Budget
{
    int expenseId;

public:
    void setExpenseId(int newExpenseId);
    int getExpenseId();
};

#endif

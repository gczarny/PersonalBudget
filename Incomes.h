#ifndef INCOMES_H
#define INCOMES_H
#include <iostream>
#include "Budget.h"

using namespace std;

class Incomes : public Budget
{
    int incomeId;

public:
    void setIncomeId(int newIncomeId);
    int getIncomeId();
};

#endif

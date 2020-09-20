#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

#include "IncomesManager.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BalanceManager
{
public:
    static void displayCurrentMonthBalance(vector<Incomes> incomes);
    static void displayPreviousMonthBalance(vector<Incomes> incomes);
    static void displaySelectedPeriodBalance(vector<Incomes> incomes);

};

#endif

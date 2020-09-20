#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>

#include "Incomes.h"
#include "IncomesFile.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "BalanceManager.h"

using namespace std;

class IncomesManager
{
    const int LOGGED_USER_ID;
    vector <Incomes> incomes;
    IncomesFile incomesFile;

    void displayAllIncomes();
    void sortIncomesVectorByDateDescending();
public:
    IncomesManager(string incomesFilename, int loggedUserId)
    : incomesFile(incomesFilename),
      LOGGED_USER_ID(loggedUserId)
    {
        incomes = incomesFile.readIncomesOfLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void balanceOfCurrentMonth();
    void balanceOfPreviousMonth();
    void balanceOfSelectedPeriod();
    static void displayIncomeData(Incomes income);
};

#endif

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

using namespace std;

class IncomesManager
{
    const int LOGGED_USER_ID;
    IncomesFile incomesFile;
    vector <Incomes> incomes;
    void displayAllIncomes();
    void sortIncomesVectorByDateDescending();
    int displayBalanceAndCalculateSum(string yearAndMonth);

public:
    IncomesManager(string incomesFilename, int loggedUserId)
    : incomesFile(incomesFilename),
      LOGGED_USER_ID(loggedUserId)
    {
        incomes = incomesFile.readIncomesOfLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    int incomesBalance(char menuChoice);
    void displayIncomeData(Incomes income);
};

#endif

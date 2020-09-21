#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <sstream>
#include <windows.h>

#include "Expenses.h"
#include "ExpensesFile.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class ExpensesManager
{
    const int LOGGED_USER_ID;
    vector <Expenses> expenses;
    ExpensesFile expensesFile;

    void displayAllExpenses();
    void sortExpensesVectorByDateDescending();
    float displayBalanceAndCalculateSum(string yearAndMonth);
public:
    ExpensesManager(string expensesFilename, int loggedUserId)
    : expensesFile(expensesFilename),
      LOGGED_USER_ID(loggedUserId)
    {
        expenses = expensesFile.readExpensesOfLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addExpense();
    float expensesBalance(char menuChoice);
    void displayExpenseData(Expenses expense);
};

#endif

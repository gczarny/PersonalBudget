#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Markup.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"


using namespace std;

class ExpensesFile
{
    const string FILENAME_WITH_EXPENSES;
    int lastExpenseId;

public:
    ExpensesFile(string expensesFilename)
    : FILENAME_WITH_EXPENSES(expensesFilename)
    {
        lastExpenseId = 0;
    };
    vector <Expenses> readExpensesOfLoggedUserFromFile(int loggedUserId);
    void writeExpenseToFile(Expenses expense);
    int getLastExpenseId();
};

#endif

#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Markup.h"
#include "Incomes.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"


using namespace std;

class IncomesFile
{
    const string FILENAME_WITH_INCOMES;
    int lastIncomeId;

public:
    IncomesFile(string incomesFilename)
    : FILENAME_WITH_INCOMES(incomesFilename)
    {
        lastIncomeId = 0;
    };
    vector <Incomes> readIncomesOfLoggedUserFromFile(int loggedUserId);
    void writeIncomeToFile(Incomes income);
    int getLastIncomeId();
};

#endif

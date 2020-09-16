#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Incomes.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class IncomesFile
{
    const string FILENAME_WITH_INCOMES;
    int lastIncomeId;

    //bool czyPlikJestPusty(fstream &plikTekstowy);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int getLastIncomeIdFromFile();

public:
    IncomesFile(string incomesFilename)
    : FILENAME_WITH_INCOMES(incomesFilename),
    {
        lastIncomeId = 0;
    };
    vector <Incomes> readIncomesOfLoggedUserFromFile(int loggedUserId);
    bool writeIncomeToFile(Incomes income);
    int getLastIncomeId();
};

#endif

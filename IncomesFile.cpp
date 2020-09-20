#include <iostream>
#include "IncomesFile.h"

using namespace std;

vector<Incomes> IncomesFile::readIncomesOfLoggedUserFromFile(int loggedUserId)
{
    vector<Incomes> incomes;
    Incomes income;
    CMarkup xml;
    int date, userId;
    string dateString;

    xml.Load(FILENAME_WITH_INCOMES);
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem( "incomeId" );
        lastIncomeId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem( "userId" );
        userId = atoi(MCD_2PCSZ(xml.GetData()));
        if(userId == loggedUserId)
        {
            income.setIncomeId(lastIncomeId);
            income.setUserId(userId);
            xml.FindElem("date");
            date = DateManager::convertStringDateToIntegerDate(xml.GetData());
            income.setDate(date);
            xml.FindElem("item");
            income.setItem(xml.GetData());
            xml.FindElem("amount");
            income.setAmount(xml.GetData());
            incomes.push_back(income);
            xml.OutOfElem();
        }
        else
            xml.OutOfElem();
    }
    return incomes;

}

void IncomesFile::writeIncomeToFile(Incomes income)
{
    CMarkup xml;
    bool fileExists = xml.Load(FILENAME_WITH_INCOMES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    lastIncomeId++;
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", DateManager::convertIntDateToStringWithHyphens(income.getDate()));
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());

    xml.Save(FILENAME_WITH_INCOMES);

}

int IncomesFile::getLastIncomeId()
{
    return lastIncomeId;
}

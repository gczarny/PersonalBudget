#include <iostream>
#include "ExpensesFile.h"

using namespace std;

vector<Expenses> ExpensesFile::readExpensesOfLoggedUserFromFile(int loggedUserId)
{
    vector<Expenses> expenses;
    Expenses expense;
    CMarkup xml;
    int date, userId;

    xml.Load(FILENAME_WITH_EXPENSES);
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem( "expenseId" );
        lastExpenseId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem( "userId" );
        userId = atoi(MCD_2PCSZ(xml.GetData()));
        if(userId == loggedUserId)
        {
            expense.setExpenseId(lastExpenseId);
            expense.setUserId(userId);
            xml.FindElem("date");
            date = DateManager::convertStringDateToIntegerDate(xml.GetData());
            expense.setDate(date);
            xml.FindElem("item");
            expense.setItem(xml.GetData());
            xml.FindElem("amount");
            expense.setAmount(xml.GetData());
            expenses.push_back(expense);
            xml.OutOfElem();
        }
        else
            xml.OutOfElem();
    }
    return expenses;

}

void ExpensesFile::writeExpenseToFile(Expenses expense)
{
    CMarkup xml;
    bool fileExists = xml.Load(FILENAME_WITH_EXPENSES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getExpenseId());
    lastExpenseId++;
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", DateManager::convertIntDateToStringWithHyphens(expense.getDate()));
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", expense.getAmount());

    xml.Save(FILENAME_WITH_EXPENSES);

}

int ExpensesFile::getLastExpenseId()
{
    return lastExpenseId;
}

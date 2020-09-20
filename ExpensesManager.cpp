#include <iostream>
#include "ExpensesManager.h"

using namespace std;

void ExpensesManager::addExpense()
{
    Expenses expense;
    char dateChoice;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    cout << "Czy chcesz dodac przychod z dnia dzisiejszego? <t/n> ";
    dateChoice = AuxiliaryMethods::chooseOptionBeetwenTwoChars();

    if(dateChoice == 't')
        expense.setDate(DateManager::convertStringDateToIntegerDate(DateManager::getActualDateInStringFormat()));

    else
        expense.setDate(DateManager::convertStringDateToIntegerDate(DateManager::getDateFromUser()));

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);
    cout << "Okresl, czego dotyczy wydatek: ";
    expense.setItem(AuxiliaryMethods::getLine());
    cout << "Okresl wysokosc wydatku: ";
    expense.setAmount(AuxiliaryMethods::getLine());

    expenses.push_back(expense);
    expensesFile.writeExpenseToFile(expense);
    cout << "Nowy wydatek zostal dodany" << endl;

    system("pause");
}



void ExpensesManager::displayExpenseData(Expenses expense)
{
    cout << endl << "Id wydatku: " << expense.getExpenseId() << endl;
    cout << "Id Uzytkownika:     " << expense.getUserId() << endl;
    cout << "Data:               " << expense.getDate() << endl;
    cout << "Opis:               " << expense.getItem() << endl;
    cout << "Kwota:              " << expense.getAmount() << endl;
}

void ExpensesManager::displayAllExpenses()
{
    system("cls");
    if (!expenses.empty())
    {
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expenses> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
            displayExpenseData(*itr);
        cout << endl;
    }
    else
    {
        cout << endl << "Brak zapisanych przychodow" << endl << endl;
    }
    system("pause");
}

void ExpensesManager::balanceOfCurrentMonth()
{
    sortExpensesVectorByDateDescending();
    BalanceManager::displayCurrentMonthBalance(expenses);
}

void ExpensesManager::balanceOfPreviousMonth()
{
    sortExpensesVectorByDateDescending();
    BalanceManager::displayPreviousMonthBalance(expenses);
}

void ExpensesManager::balanceOfSelectedPeriod()
{
    sortExpensesVectorByDateDescending();
    BalanceManager::displaySelectedPeriodBalance(expenses);
}

void ExpensesManager::sortExpensesVectorByDateDescending()
{
    sort(expenses.begin(), expenses.end(), [](Expenses a, Expenses b){ return a.getDate() < b.getDate(); });
}


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

int ExpensesManager::displayBalanceAndCalculateSum(string yearAndMonth)
{
    int expensesSum = 0;
    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        string yearWithMonthFromIncomes = DateManager::convertIntegerDateToYearAndMonthInString((*itr).getDate());
        if(yearWithMonthFromIncomes == yearAndMonth)
        {
            expensesSum += AuxiliaryMethods::convertStringToInt((*itr).getAmount());
            displayExpenseData(*itr);
        }
    }
    return expensesSum;
}

int ExpensesManager::expensesBalance(char menuChoice)
{
    //system("cls");
    int expensesSum = 0;
    if (!expenses.empty())
    {
        sortExpensesVectorByDateDescending();
        cout << ">>>>>>> WYDATKI <<<<<<<" << endl;
        if(menuChoice == '3') //actual month
        {
            string actualYearAndMonth = DateManager::getActualYearAndMonth();
            expensesSum = displayBalanceAndCalculateSum(actualYearAndMonth);
        }
        else if(menuChoice == '4') //previous month
        {
            string previousMonthOfActualYear = DateManager::getPreviousMonthOfActualYear();
            expensesSum = displayBalanceAndCalculateSum(previousMonthOfActualYear);
        }

        else if(menuChoice == '5') //selected period
        {
            cout << "Poczatek zakresu wyszukiwania -> ";
            int firstDate = DateManager::convertStringDateToIntegerDate(DateManager::getDateFromUser());
            cout << "Koniec zakresu wyszukiwania -> ";
            int lastDate = DateManager::convertStringDateToIntegerDate(DateManager::getDateFromUser());
            for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
            {
                int dateFromIncomes = (*itr).getDate();
                if(dateFromIncomes >= firstDate && dateFromIncomes <= lastDate)
                {
                    expensesSum += AuxiliaryMethods::convertStringToInt((*itr).getAmount());
                    displayExpenseData(*itr);
                }

            }
        }
        return expensesSum;
    }
    else
    {
        cout << endl << "Brak zapisanych wydatkow" << endl << endl;
        system("pause");
        return 0;
    }
    //system("pause");
}

void ExpensesManager::sortExpensesVectorByDateDescending()
{
    sort(expenses.begin(), expenses.end(), [](Expenses a, Expenses b){ return a.getDate() < b.getDate(); });
}


#include <iostream>
#include "IncomesManager.h"

using namespace std;

void IncomesManager::addIncome()
{
    Incomes income;
    char dateChoice;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    cout << "Id ostatniego przychodu: " << incomesFile.getLastIncomeId() << endl;
    cout << "Czy chcesz dodac przychod z dnia dzisiejszego? <t/n> ";
    dateChoice = AuxiliaryMethods::chooseOptionBeetwenTwoChars();

    if(dateChoice == 't')
        income.setDate(DateManager::convertStringDateToIntegerDate(DateManager::getActualDateInStringFormat()));

    else
    {
        //string date = DateManager::getDateFromUser();
        income.setDate(DateManager::convertStringDateToIntegerDate(DateManager::getDateFromUser()));
    }
    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);
    cout << "Okresl, czego dotyczy przychod (np. lokata, wynagrodzenie, etc.): ";
    income.setItem(AuxiliaryMethods::getLine());
    cout << "Okresl wysokosc przychodu: ";
    income.setAmount(AuxiliaryMethods::getLine());

    incomes.push_back(income);

    incomesFile.writeIncomeToFile(income);
    cout << "Nowy przychod zostal dodany" << endl;

    system("pause");
}



void IncomesManager::displayIncomeData(Incomes income)
{
    cout << endl << "Id:         " << income.getIncomeId() << endl;
    cout << "Id Uzytkownika:     " << income.getUserId() << endl;
    cout << "Data:               " << income.getDate() << endl;
    cout << "Opis:               " << income.getItem() << endl;
    cout << "Kwota:              " << income.getAmount() << endl;
}

void IncomesManager::displayAllIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> PRZYCHODY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Incomes> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
            displayIncomeData(*itr);
        cout << endl;
    }
    else
    {
        cout << endl << "Brak zapisanych przychodow" << endl << endl;
    }
    system("pause");
}

void IncomesManager::balanceOfCurrentMonth()
{
    sortIncomesVectorByDateDescending();
    BalanceManager::displayCurrentMonthBalance(incomes);
}

void IncomesManager::balanceOfPreviousMonth()
{
    sortIncomesVectorByDateDescending();
    BalanceManager::displayPreviousMonthBalance(incomes);
}

void IncomesManager::balanceOfSelectedPeriod()
{
    sortIncomesVectorByDateDescending();
    BalanceManager::displaySelectedPeriodBalance(incomes);
}

void IncomesManager::sortIncomesVectorByDateDescending()
{
    sort(incomes.begin(), incomes.end(), [](Incomes a, Incomes b){ return a.getDate() < b.getDate(); });
}


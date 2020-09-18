#include <iostream>
#include "IncomesManager.h"

using namespace std;

void IncomesManager::addIncome()
{
    Incomes income;
    char dateChoice;
    int d, m, y;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    cout << "Id ostatniego przychodu: " << incomesFile.getLastIncomeId() << endl;
    displayAllIncomes();
    cout << "Czy chcesz dodac przychod z dnia dzisiejszego? <t/n> ";
    dateChoice = AuxiliaryMethods::getCharacter();

    if(dateChoice == 't')
    {
        income.setDate(DateManager::convertStringDateToIntegerDate(DateManager::getActualDateInStringFormat()));
    }
    else
    {
        cout << "Wprowadz date w formacie rrrr-mm-dd: ";
        string date = AuxiliaryMethods::getLine();
        while(DateManager::checkIfDateFormatAndYearAreValid(date) == false || DateManager::extractDateAndCHeckIfValid(date, d, m, y) == false)
        {
            cout << "Wprowadzono niepoprawna date (poprawny format: rrrr-mm-dd)";
            date = AuxiliaryMethods::getLine();
        }
        income.setDate(DateManager::convertStringDateToIntegerDate(date));
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
    cout << "Imie:               " << income.getUserId() << endl;
    cout << "Nazwisko:           " << income.getDate() << endl;
    cout << "Numer telefonu:     " << income.getItem() << endl;
    cout << "Email:              " << income.getAmount() << endl;
}

void IncomesManager::displayAllIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Incomes> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
            displayIncomeData(*itr);
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}


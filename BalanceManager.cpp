#include <iostream>
#include "BalanceManager.h"

using namespace std;

void BalanceManager::displayCurrentMonthBalance(vector<Incomes> incomes)
{
    system("cls");
    if (!incomes.empty())
    {
        string actualYearAndMonth = DateManager::getActualYearAndMonth();

        cout << ">>>>>>> Wyswietlony zostanie bilans przychodow oraz wydatkow z biezacego miesiaca <<<<<<<";
        for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string actualYearWithMonthFromIncomes = DateManager::convertIntegerDateToYearAndMonthInString((*itr).getDate());
            if(actualYearWithMonthFromIncomes == actualYearAndMonth)
                IncomesManager::displayIncomeData(*itr);
        }
    }
    else
    {
        cout << endl << "Brak zapisanych przychodow" << endl << endl;
    }
    system("pause");
}

void BalanceManager::displayPreviousMonthBalance(vector<Incomes> incomes)
{
    system("cls");
    if (!incomes.empty())
    {
        string previousMonthOfActualYear = DateManager::getPreviousMonthOfActualYear();

        cout << ">>>>>>> Wyswietlony zostanie bilans przychodow oraz wydatkow z poprzedniego miesiaca <<<<<<<";
        for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string yearWithMonthFromIncomes = DateManager::convertIntegerDateToYearAndMonthInString((*itr).getDate());
            if(yearWithMonthFromIncomes == previousMonthOfActualYear)
                IncomesManager::displayIncomeData(*itr);
        }
    }
    else
    {
        cout << endl << "Brak zapisanych przychodow" << endl << endl;
    }
    system("pause");
}

void BalanceManager::displaySelectedPeriodBalance(vector<Incomes> incomes)
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "Poczatek zakresu wyszukiwania -> ";
        int firstDate = DateManager::convertStringDateToIntegerDate(DateManager::getDateFromUser());
        cout << "Koniec zakresu wyszukiwania -> ";
        int lastDate = DateManager::convertStringDateToIntegerDate(DateManager::getDateFromUser());

        cout << ">>>>>>> Wyswietlony zostanie bilans przychodow oraz wydatkow z okreslonego zakresu <<<<<<<";
        for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            int dateFromIncomes = (*itr).getDate();
            if(dateFromIncomes >= firstDate && dateFromIncomes <= lastDate)
                IncomesManager::displayIncomeData(*itr);
        }
    }
    else
    {
        cout << endl << "Brak zapisanych przychodow" << endl << endl;
    }
    system("pause");
}

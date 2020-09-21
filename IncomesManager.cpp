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
    income.setAmount(AuxiliaryMethods::replaceCommaWithDot(AuxiliaryMethods::getLine()));

    incomes.push_back(income);

    incomesFile.writeIncomeToFile(income);
    cout << "Nowy przychod zostal dodany" << endl;

    system("pause");
}

void IncomesManager::displayIncomeData(Incomes income)
{
    cout << endl;
    cout << "Id przychodu:        " << income.getIncomeId() << endl;
    cout << "Id Uzytkownika:      " << income.getUserId() << endl;
    cout << "Data:                " << DateManager::convertIntDateToStringWithHyphens(income.getDate()) << endl;
    cout << "Opis:                " << income.getItem() << endl;
    cout << "Kwota:               " << income.getAmount() << endl;
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

float IncomesManager::displayBalanceAndCalculateSum(string yearAndMonth)
{
    float incomesSum = 0;
    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        string yearWithMonthFromIncomes = DateManager::convertIntegerDateToYearAndMonthInString((*itr).getDate());
        if(yearWithMonthFromIncomes == yearAndMonth)
        {
            incomesSum += AuxiliaryMethods::convertStringToFloat((*itr).getAmount());
            displayIncomeData(*itr);
        }
    }
    return incomesSum;
}

float IncomesManager::incomesBalance(char menuChoice)
{
    system("cls");
    float incomesSum = 0;
    if (!incomes.empty())
    {
        sortIncomesVectorByDateDescending();
        cout << ">>>>>>> PRZYCHODY <<<<<<<" << endl;
        if(menuChoice == '3') //actual month
        {
            string actualYearAndMonth = DateManager::getActualYearAndMonth();
            incomesSum = displayBalanceAndCalculateSum(actualYearAndMonth);
        }
        else if(menuChoice == '4') //previous month
        {
            string previousMonthOfActualYear = DateManager::getPreviousMonthOfActualYear();
            incomesSum = displayBalanceAndCalculateSum(previousMonthOfActualYear);
        }
        else if(menuChoice == '5') //selected period
        {
            cout << "Poczatek zakresu wyszukiwania -> ";
            int firstDate = DateManager::convertStringDateToIntegerDate(DateManager::getDateFromUser());
            cout << "Koniec zakresu wyszukiwania -> ";
            int lastDate = DateManager::convertStringDateToIntegerDate(DateManager::getDateFromUser());
            for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
            {
                int dateFromIncomes = (*itr).getDate();
                if(dateFromIncomes >= firstDate && dateFromIncomes <= lastDate)
                {
                    incomesSum += AuxiliaryMethods::convertStringToInt((*itr).getAmount());
                    displayIncomeData(*itr);
                }
            }
        }
        return incomesSum;
    }
    else
    {
        cout << endl << "Brak zapisanych przychodow" << endl << endl;
        return 0;
    }
}

void IncomesManager::sortIncomesVectorByDateDescending()
{
    sort(incomes.begin(), incomes.end(), [](Incomes a, Incomes b){ return a.getDate() < b.getDate(); });
}


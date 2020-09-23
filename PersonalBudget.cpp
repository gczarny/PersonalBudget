#include <iostream>

#include "PersonalBudget.h"

using namespace std;

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

void PersonalBudget::displayAllUsers()
{
    userManager.displayAllUsers();
}

int PersonalBudget::userLogging()
{
    userManager.userLogging();
    if(userManager.isUserLogged())
    {
        incomesManager = new IncomesManager(INCOMES_FILENAME, userManager.getLoggedUserId());
        expensesManager = new ExpensesManager(EXPENSES_FILENAME, userManager.getLoggedUserId());

    }
}

void PersonalBudget::editPassword()
{
    userManager.editPassword();
}

void PersonalBudget::userLogout()
{
    userManager.userLogout();
    delete incomesManager;
    delete expensesManager;
    incomesManager = NULL;
    expensesManager = NULL;
}

void PersonalBudget::addIncome()
{
    incomesManager->addIncome(); // -> poniewaz pracujemy na wskazniku
}

void PersonalBudget::addExpense()
{
    expensesManager->addExpense();
}

void PersonalBudget::displayBalanceOfCurrentMonth(char menuChoice)
{
    displayBalance(menuChoice);
}

void PersonalBudget::displayBalanceOfPreviousMonth(char menuChoice)
{
    displayBalance(menuChoice);
}

void PersonalBudget::displayBalanceOfSelectedPeriod(char menuChoice)
{
    displayBalance(menuChoice);
}

bool PersonalBudget::isUserLogged()
{
    if(userManager.isUserLogged())
        return true;
    else
        return false;
}

void PersonalBudget::displayBalance(char menuChoice)
{
    float incomesSum = incomesManager->incomesBalance(menuChoice);
    cout << "************************************" << endl;
    cout << "************************************" << endl;
    float expensesSum = expensesManager->expensesBalance(menuChoice);
    displaySumsAndDifferences(incomesSum, expensesSum);
    system("pause");
}

void PersonalBudget::displaySumsAndDifferences(float incomesSum, float expensesSum)
{
    cout << "************************************" << endl;
    cout << "************************************" << endl;
    cout << endl << "Suma przychodow w wyznaczonym okresie: " << incomesSum << endl;
    cout << "Suma wydatkow w wyznaczonym okresie: " << expensesSum << endl;
    cout << "Zysk/strata: " << incomesSum - expensesSum << endl;
}




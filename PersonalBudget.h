#include <iostream>
#include <conio.h>

#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"
#include "BalanceManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;
    IncomesManager* incomesManager;
    ExpensesManager* expensesManager;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

    void displayBalance(char menuChoice);
    void displaySumsAndDifferences(float incomesSum, float expensesSum);

public:
    int loggedUserId;
    //int lastIncomeId;
    //int lastExpenseId;

    PersonalBudget(string usersFilename, string incomesFilename, string expensesFilename)
    : userManager(usersFilename),
      INCOMES_FILENAME(incomesFilename),
      EXPENSES_FILENAME(expensesFilename)
    {
        incomesManager = NULL;
        expensesManager = NULL;
    };
    ~PersonalBudget()
    {
        delete incomesManager;
        delete expensesManager;
        incomesManager = NULL;
        expensesManager = NULL;
    };
    int userLogging();
    void userRegistration();
    void displayAllUsers();
    void editPassword();
    void displayBalanceOfCurrentMonth(char menuChoice);
    void displayBalanceOfPreviousMonth(char menuChoice);
    void displayBalanceOfSelectedPeriod(char menuChoice);
    void addIncome();
    void addExpense();
    void userLogout();
    bool isUserLogged();
};

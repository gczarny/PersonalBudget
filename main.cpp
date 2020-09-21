#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    char menuChoice;

    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    //personalBudget.displayAllUsers();
    while(true){
        if(personalBudget.isUserLogged() == false)
        {
            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            menuChoice = getch();

            switch (menuChoice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            system("cls");
            cout << "    >>> MENU  UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj przychod" << endl;
            cout << "2. Dodaj wydatek" << endl;
            cout << "3. Bilans z biezacego miesiaca" << endl;
            cout << "4. Bilans z poprzedniego miesiaca" << endl;
            cout << "5. Bilans z wybranego okresu" << endl;
            cout << "6. Zmien haslo" << endl;
            cout << "9. Wyloguj" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            menuChoice = getch();
            switch (menuChoice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayBalanceOfCurrentMonth(menuChoice);
                break;
            case '4':
                personalBudget.displayBalanceOfPreviousMonth(menuChoice);
                break;
            case '5':
                personalBudget.displayBalanceOfSelectedPeriod(menuChoice);
                break;
            case '6':
                personalBudget.editPassword();
                break;
            case '9':
                personalBudget.userLogout();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}


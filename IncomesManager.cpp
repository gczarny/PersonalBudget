#include <iostream>
#include "IncomesManager.h"

using namespace std;

void IncomesManager::addIncome()
{
    Incomes income;
    char dateChoice;
    int d,m,y;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    cout << "Czy chcesz dodac przychod z dnia dzisiejszego? <t/n> ";
    dateChoice = AuxiliaryMethods::getCharacter()

    if(dateChoice == 't')
    {
        income.setDate(convertStringDateToIntegerDate(getActualDateInStringFormat()));
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
        income.setDate(convertStringDateToIntegerDate(date));
    }
    income.setIncomeId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    income.setUserId(LOGGED_USER_ID);
    cout << "Okresl, czego dotyczy przychod (np. lokata, wynagrodzenie, etc.): ";
    income.setItem(AuxiliaryMethods::getLine());
    cout << "Okresl wysokosc przychodu: ";
    income.setAmount(AuxiliaryMethods::getLine());

    incomes.push_back(income);

    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac przychodu do pliku" << endl;
    system("pause");
}


/*
void AdresatManager::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:         " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatManager::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
            wyswietlDaneAdresata(*itr);
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
*/

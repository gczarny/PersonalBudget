#include <iostream>
#include "IncomesFile.h"

using namespace std;

/*
int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

bool PlikZAdresatami::czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
*/
vector<Incomes> IncomesFile::readIncomesOfLoggedUserFromFile(int loggedUserId)
{
    vector<Incomes> incomes;
    Incomes income;
    CMarkup xml;
    int date, userId;

    xml.Load(FILENAME_WITH_INCOMES);
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem( "incomeId" );
        income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "userId" );
        userId = xml.GetData();
        if(userId == loggedUserId)
        {
            income.setUserId(userId);
            xml.FindElem("date");
            date = DateManager::convertStringDateToIntegerDate(DateManager::getActualDateInStringFormat(xml.GetData()));
            income.setDate(date);
            xml.FindElem("item");
            income.setItem(xml.GetData());
            xml.FindElem("amount");
            income.setAmount(xml.GetData());
            incomes.push_back(income);
            xml.OutOfElem();
        }
    }
    return adresaci;

}

bool PlikZAdresatami::writeIncomeToFile(Incomes income)
{
    CMarkup xml;
    bool fileExists = xml.Load(FILENAME_WITH_INCOMES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", user.getUserId());
    xml.AddElem("userId", user.getLogin());
    xml.AddElem("Date", user.getPassword());
    xml.AddElem("Item", user.getName());
    xml.AddElem("Amount", user.getSurname());

    xml.Save(FILENAME_WITH_INCOMES);

    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true)
            plikTekstowy << liniaZDanymiAdresata;

        else
            plikTekstowy << endl << liniaZDanymiAdresata;
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}


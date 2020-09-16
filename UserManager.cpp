#include <iostream>
#include "UserManager.h"


using namespace std;

void UserManager::userRegistration()
{
    User user = setNewUserData();
    users.push_back(user);

    usersFile.writeUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::setNewUserData()
{
    User user;
    string login, password, name, surname;
    user.setUserId(getNewUserId());

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginInUse(user.getLogin()) == true);

    cout << "Podaj haslo (haslo powinno skladac sie przynajmniej z 5 dowolnych znakow lub liczb): ";
    cin >> password;
    user.setPassword(password);

    cout << "Podaj imie oraz nazwisko: ";
    cin >> name >> surname;
    user.setName(name);
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isLoginInUse(string login)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::displayAllUsers()
{
    system("cls");
    if (!users.empty())
    {
        cout << "             >>> UZYTKOWNICY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << "Id:    " << users[i].getUserId() << endl;
            cout << "Login: " << users[i].getLogin() << endl;
            cout << "Haslo: " << users[i].getPassword() << endl;
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma uzytkownikow." << endl << endl;
    }
    system("pause");
}

int UserManager::userLogging()
{
    string login = "", password = "";
    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::readLine();

    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            for(int permittedTries = 3; permittedTries > 0; permittedTries--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << permittedTries << ": ";
                password = AuxiliaryMethods::readLine();

                if(users[i].getPassword() == password)
                {
                    loggedUserId = users[i].getUserId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return loggedUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::editPassword()
{
    system("cls");
    string newPassowrd = "";
    cout << "Podaj nowe haslo (haslo powinno skladac sie przynajmniej z 5 dowolnych znakow lub liczb): ";
    newPassowrd = AuxiliaryMethods::readLine();

    if(isUserLogged())
    {
        for(int i = 0; i < users.size(); i++)
        {
            if(users[i].getUserId() == loggedUserId)
            {
                users[i].setPassword(newPassowrd);
                cout << "Haslo zostalo zmienione." << endl << endl;
                usersFile.editUserInFile(users[i], loggedUserId);
                system("pause");
            }
        }
        //usersFile.writeAllUsersToFile(users);

    }
    else
    {
        cout << "Aby zmienic haslo, nalezy sie zalogowac" << endl;
        system("pause");
    }
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

bool UserManager::isUserLogged()
{
    if(loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::userLogout()
{
    loggedUserId = 0;
}

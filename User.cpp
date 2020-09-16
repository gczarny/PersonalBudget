#include <iostream>
#include "User.h"

using namespace std;

void User::setUserId(int newUserId)
{
    userId = newUserId;
}

void User::setLogin(string newLogin)
{
    login = newLogin;
}

void User::setPassword(string newPassword)
{
    while(newPassword.length() <= 4)
    {
        cout << "Haslo powinno skladac sie przynajmniej z 5 dowolnych znakow lub liczb: ";
        cin >> newPassword;
    }
    if(newPassword.length() > 4)
        password = newPassword;
}

void User::setName(string newName)
{
    name = newName;
}

void User::setSurname(string newSurname)
{
    surname = newSurname;
}

int User::getUserId()
{
    return userId;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}

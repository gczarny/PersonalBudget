#include <iostream>
#include "UsersFile.h"


using namespace std;

bool UsersFile::isFileEmpty(fstream &xmlFile)
{
    xmlFile.seekg(0, ios::end);
    if (xmlFile.tellg() == 0)
        return true;
    else
        return false;
}

void UsersFile::writeUserToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("users.xml");
}

vector<User>  UsersFile::readUsersFromFile()
{
    CMarkup xml;
    User user;
    vector<User> users;

    xml.Load( "users.xml" );
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Login" );
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        users.push_back(user);
        xml.OutOfElem();
    }

    return users;
}

void UsersFile::editUserInFile(User user, int loggedUserId)
{
    CMarkup xml;

    xml.Load( "users.xml" );
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        //xml.IntoElem();
        xml.FindChildElem("UserId");
        if(atoi(MCD_2PCSZ(xml.GetChildData())) == user.getUserId())
        {
            xml.FindChildElem("Password");
            xml.RemoveChildElem();
            xml.AddChildElem("Password", user.getPassword());
        }
    }
    xml.Save("users.xml");
}

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <sstream>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    vector <User> users;
    int loggedUserId;
    UsersFile usersFile;

    User setNewUserData();
    int getNewUserId();
    bool isLoginInUse(string login);

public:
    UserManager(string filenameWithUsers)
    : usersFile(filenameWithUsers)
    {
        loggedUserId = 0;
        users = usersFile.readUsersFromFile();
    };

    void userRegistration();
    int userLogging();
    void displayAllUsers();
    void editPassword();
    int getLoggedUserId();
    bool isUserLogged();
    void userLogout();
};

#endif

#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdlib.h>     /* atoi */

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class UsersFile
{
    const string FILENAME_WITH_USERS;
    bool isFileEmpty(fstream &xmlFile);

public:
    UsersFile(string filenameWithUsers)
    : FILENAME_WITH_USERS(filenameWithUsers){};

    void writeUserToFile(User user);
    vector<User> readUsersFromFile();
    void editUserInFile(User user, int loggedUserId);
};

#endif

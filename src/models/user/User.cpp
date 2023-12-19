#include <iostream>
#include "User.h"
using std::cout;
using std::cin;

// Constructor
User::User(string usn = "", string pwd = "", string role = "NA")
{
    this->username = usn;
    this->password = pwd;
    this->role = role;
    this->isAuthenticated = isAuthenticated;
};


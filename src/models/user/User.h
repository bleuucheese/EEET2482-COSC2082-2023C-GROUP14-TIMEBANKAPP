#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_USER_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_USER_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class User
{
private:
    string username;
    string password;
    string role; // Admin, RegularMember
    bool isAuthenticated = false;

public:
    // Constructor
    User(string username, string password, string role){};

    string getUsername() { return username; };
    string getPassword() { return password; };
    string getRole() { return role; };
    bool getIsAuthenticated() { return isAuthenticated; };
    void setUsername(string username) { this->username = username; };
    void setPassword(string password) { this->password = password; };
    void setRole(string role) { this->role = role; };
    void setIsAuthenticated(bool isAuthenticated) { this->isAuthenticated = isAuthenticated; };
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_USER_H
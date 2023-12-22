#include <iostream>
#include <string>

#include "TimeBankSystem.h"
#include "./models/user/Admin.h"
using std::cin;
using std::cout;

// Constructor
TimeBankSystem::TimeBankSystem()
{
}

// Used ANSI escape codes to print colored text
void TimeBankSystem::welcomeScreen()
{
    std::cout << "\033[\e[38;5;16m----------------------------------------------------------------------------------------\033[0m\n"; // Orange color

    std::cout << "                          \033[1m EEET2482/COSC2082 ASSIGNMENT\033[0m                  \n\n";
    std::cout << "\033[\e[38;5;196m $$$$$$$$\\ $$$$$$\\ $$\\      $$\\ $$$$$$$$\\       $$$$$$$\\   $$$$$$\\  $$\\   $$\\ $$\\   $$\\\033[0m\n";
    std::cout << "\033[\e[38;5;202m \\__$$  __|\\_$$  _|$$$\\    $$$ |$$  _____|      $$  __$$\\ $$  __$$\\ $$$\\  $$ |$$ | $$  |\033[0m\n";
    std::cout << "\033[\e[38;5;214m    $$ |     $$ |  $$$$\\  $$$$ |$$ |            $$ |  $$ |$$ /  $$ |$$$$\\ $$ |$$ |$$  /\033[0m\n";
    std::cout << "\033[\e[38;5;227m    $$ |     $$ |  $$\\$$\\$$ $$ |$$$$$\\          $$$$$$$\\ |$$$$$$$$ |$$ $$\\$$ |$$$$$  /\033[0m\n";
    std::cout << "\033[\e[38;5;42m    $$ |     $$ |  $$ \\$$$  $$ |$$  __|         $$  __$$\\ $$  __$$ |$$ \\$$$$ |$$  $$<\033[0m\n";
    std::cout << "\033[\e[38;5;37m    $$ |     $$ |  $$ |\\$  /$$ |$$ |            $$ |  $$ |$$ |  $$ |$$ |\\$$$ |$$ |\\$$\\\033[0m\n";
    std::cout << "\033[\e[38;5;20m    $$ |   $$$$$$\\ $$ | \\_/ $$ |$$$$$$$$\\       $$$$$$$  |$$ |  $$ |$$ | \\$$ |$$ | \\$$\\\033[0m\n";
    std::cout << "\033[\e[38;5;54m    \\__|   \\______|\\__|     \\__|\\________|      \\_______/ \\__|  \\__|\\__|  \\__|\\__|  \\__|\033[0m\n";
    std::cout << "\nInstructor: \033[1;32mMr. Tran Duc Linh\033[0m                  \n";
    std::cout << "Group: \033[1;38;5;131mGroup 14 - HD Destroyers\033[0m             \n"; // Bold text, Orange color
    std::cout << " Trinh Nguyen Ha (s3981134)                      \n";
    std::cout << " Chau Chan Thien (s3975010)                      \n";
    std::cout << " Chau Chan Bang (s3975015)                       \n";
    std::cout << " Tran Manon Ophelie (s3968993)                   \n";
    std::cout << "\033[1;34m========================================================================================\033[0m \n";
    std::cout << "Note: Currently supporting hosts and supporters residing in \033[1;31mHanoi\033[0m and \033[1;31mSaigon\033[0m only.                    \n";
    std::cout << "\033[\e[38;5;16m----------------------------------------------------------------------------------------\033[0m\n";
}

void TimeBankSystem::systemMenu()
{
    cout << "======APPLICATION MENU======\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Continue as Guest\n";
    cout << "4. Exit\n";

    switch (promptAndGetChoice(1, 4))
    {
    case 1:
        loginMenu();
        break;
    case 2:
        registerMenu();
        break;
    case 3:
        guestMenu();
        break;
    case 4:
        return;
        break;
    }
}

void TimeBankSystem::loginMenu()
{
    cout << "======LOGIN MENU======\n";
    cout << "1. Login as Admin\n";
    cout << "2. Login as Regular Member\n";
    cout << "3. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        promptLogin();
        break;
    case 2:
        promptLogin();
        break;
    case 3:
        return;
        break;
    }
}

void TimeBankSystem::registerMenu()
{
    cout << "======REGISTER MENU======\n";
    cout << "1. Register as Regular Member\n";
    cout << "2. Back\n";
}

void TimeBankSystem::guestMenu()
{
    cout << "======GUEST MENU======\n";
    cout << "1. View all skill listings, but be aware that you won't be able to view any reviews!\n";
    cout << "2. Register as Regular Member\n";
    cout << "3. Back\n";
}

void TimeBankSystem::adminMenu()
{
    cout << "========ADMIN MENU=========\n";
    cout << "1. View All Members\n";
    cout << "2. View Sales Figures\n";
    cout << "3. Reset Password for a particular Member\n";
    cout << "4. Exit\n";
}


void TimeBankSystem::regularMemberMenu() {
    cout << "===========MEMBER MENU=============\n";
    cout << "1. Manage Personal Account\n";
    cout << "2. Skills\n";
    cout << "3. Requests\n";
    cout << "4. Reviews\n";
    cout << "5. Search Job Market\n";
    cout << "6. Exit\n";
}

int TimeBankSystem::promptAndGetChoice(unsigned min, unsigned max)
{
    // Inclusive
    int choice = -1;
    std::string buffer;

    do
    {
        std::cout << "Choose an operation: ";
        std::getline(std::cin, buffer);

        try
        {
            size_t pos;
            choice = std::stoi(buffer, &pos);

            if (pos != buffer.size())
            {
                throw std::invalid_argument("Invalid input");
            }

            if (choice < min || choice > max)
            {
                std::cout << "Invalid choice. Please enter a number between " << min << " and " << max << ".\n";
                choice = -1; // Reset choice if out of range
            }
        }
        catch (std::exception &e)
        {
            std::cout << "Invalid input. Please enter a valid number.\n";
            choice = -1; // Reset choice on exception
        }

    } while (choice == -1);

    return choice;
}

bool TimeBankSystem::isUniqueUsername(string username)
{
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getUsername() == username)
        {
            return false;
        }
    }
    return true;
}

bool TimeBankSystem::login(const std::string &username, const std::string &password)
{
    for (auto &user : this->memberList)
    {
        if (user.username == username && user.password == password)
        {
            user.isAuthenticated = true;
            return true;
        }
    }
    return false;
}

void TimeBankSystem::addMember(User &user){
    memberList.push_back(user);
}

void TimeBankSystem::promptLogin()
{
    std::string username, password;
    do
    {
        cout << "Enter your username: ";
        cin >> username;

        if (isUniqueUsername(username))
        {
            cout << "User not found! Please try again.\n";
        }
    } while (isUniqueUsername(username));

    do {
        cout << "Enter your password: ";
        cin >> password;

        if (!login(username, password))
        {
            cout << "Wrong password! Please try again.\n";
        }
    } while (!login(username, password));
    

    if (username == "@dmin2023")
    {
        adminMenu();
    }
    else
    {
        regularMemberMenu();
    }
    
}

int main()
{   
    TimeBankSystem sys;
    Admin admin(8);
    sys.addMember(admin);
    sys.welcomeScreen();
    sys.systemMenu();

    return 0;
}
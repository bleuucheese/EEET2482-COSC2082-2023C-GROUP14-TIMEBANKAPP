#include <iostream>
#include <string>

#include "TimeBankSystem.h"
#include "./models/user/Admin.h"
#include "./models/user/RegularMember.h"
#include "./models/user/User.h"
#include "./utils/myUtils.h"
#include "./utils/file/FileHandler.h"

using std::cin;
using std::cout;
using std::string;

// Create a FileHandler object to handle all file operations

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

void TimeBankSystem::bye()
{
    std::cout << "\033[\e[38;5;16m----------------------------------------------------------------------------------------\033[0m\n";
    std::cout << "Thank you for using our application! See you next time <3\n";
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
        bye();
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
        systemMenu();
        break;
    }
}

void TimeBankSystem::registerMenu()
{
    cout << "======REGISTER MENU======\n";
    cout << "1. Register as Regular Member\n";
    cout << "2. Back\n";

    switch (promptAndGetChoice(1, 2))
    {
    case 1:
        promptRegister();
        break;
    case 2:
        systemMenu();
        break;
    }
}

void TimeBankSystem::guestMenu()
{
    cout << "======GUEST MENU======\n";
    cout << "1. View all skill listings available\n";
    cout << "2. View all but be aware that you won't be able to view their reviews!\n";
    cout << "2. Register as Regular Member\n";
    cout << "3. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        // method to list all skill listings
        break;
    case 2:
        promptRegister();
        break;
    case 3:
        systemMenu();
        break;
    }
}

void TimeBankSystem::adminMenu()
{
    cout << "========ADMIN MENU=========\n";
    cout << "1. View All Members\n";
    cout << "2. View Sales Figures and Statistics\n"; // Revenue, number of members, number of skills, number of skill listings, number of requests, number of reviews
    cout << "3. Reset Password for a particular Member\n";
    cout << "4. Sign Out\n";

    switch (promptAndGetChoice(1, 4))
    {
    case 1:
        // method to view all members
        break;
    case 2:
        // method to view sales figures and statistics
        break;
    case 3:
        // method to reset password
        break;
    case 4:
        logout();
        systemMenu();
        break;
    }
}

void TimeBankSystem::regularMemberMenu()
{
    cout << "===========MEMBER MENU=============\n";
    cout << "1. Manage Personal Account\n";
    cout << "2. Skills\n";
    cout << "3. Listings\n";
    cout << "4. Requests\n";
    cout << "5. Reviews\n";
    cout << "6. Search Job Market\n";
    cout << "7. Sign Out\n";

    switch (promptAndGetChoice(1, 7))
    {
    case 1:
        profileMenu();
        break;
    case 2:
        skillMenu();
        break;
    case 3:
        listingMenu();
        break;
    case 4:
        requestMenu();
        break;
    case 5:
        reviewMenu();
        break;
    case 6:
        searchMenu();
        break;
    case 7:
        logout();
        systemMenu();
        break;
    }
}

int TimeBankSystem::promptAndGetChoice(unsigned min, unsigned max)
{
    // Inclusive
    int choice = -1;
    std::string buffer;

    // Clear the input buffer, esp when previously user has entered their info, \n is still in the buffer
    fflush(stdin);

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
    // For admin login
    if (username == "@dmin2023")
    {
        return false;
    }
    // For member login
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
    if (username == "@dmin2023" && password == "aptfinalproject")
    {
        admin.isAuthenticated = true;
        return true;
    }
    else if (username == "@dmin2023" && password != "aptfinalproject")
    {
        return false;
    }
    else if (username != "@dmin2023" && password == "aptfinalproject")
    {
        return false;
    }

    for (auto &user : this->memberList)
    {
        if (user.username == username && user.password == password)
        {
            user.isAuthenticated = true;
            this->currentMember = user; // Set current member to the user who just logged in
            return true;
        }
    }
    return false;
}

void TimeBankSystem::logout()
{
    if (admin.isAuthenticated)
    {
        admin.isAuthenticated = false;
    }
    for (auto &user : this->memberList)
    {
        if (user.isAuthenticated)
        {
            user.isAuthenticated = false;
        }
    }
    this->currentMember.isAuthenticated = false;
}

RegularMember TimeBankSystem::findMemberByUsername(string usn)
{
    for (RegularMember &member : this->memberList)
    {
        if (member.getUsername() == usn)
        {
            return member;
        }
    }
    throw std::runtime_error("Member not found!");
}

void TimeBankSystem::addMember(RegularMember &member)
{
    memberList.push_back(member);
}

void TimeBankSystem::addSkill(Skill &skill)
{
    skillList.push_back(skill);
}

void TimeBankSystem::addListing(SkillListing &listing)
{
    skillListingList.push_back(listing);
}

void TimeBankSystem::addRequest(Request &request)
{
    requestList.push_back(request);
}

void TimeBankSystem::addReview(Review &review)
{
    reviewList.push_back(review);
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

    do
    {
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

// For RegularMember registration only
void TimeBankSystem::promptRegister()
{
    std::string username, password, fullName, phoneNumber, email, homeAddress, creditCardNumber, city;
    double latitude, longitude;
    float balance = 400; // Assume member has 200$ in their bank account when they type their credit card number
    float skillRatingScore = 0;
    float supporterRatingScore = 0;
    float hostRatingScore = 0;
    int creditPoints = 20; // Default value, pay to system 20$ to get 20 credit points
    do
    {
        username = getValidUsername();

        if (!isUniqueUsername(username))
        {
            cout << "Username already exists! Please try again.\n";
        }
    } while (!isUniqueUsername(username));

    password = getValidPassword();
    fullName = getValidFullName();
    phoneNumber = getValidPhoneNumber();
    email = getValidEmail();
    homeAddress = getValidAddress();
    city = getValidCity();
    std::cout << "Before entering the coordinates, go to the link below and find out your geographic location :)\n";
    cout << "https://support.google.com/maps/answer/18539?hl=en&co=GENIE.Platform\%3DDesktop\n";
    latitude = getValidLatitude();
    longitude = getValidLongitude();
    cin.ignore();
    fflush(stdin); // Clear input buffer
    creditCardNumber = getValidCardNumber();

    if (city == "Hanoi")
    {
        RegularMember newMember(username, password, fullName, phoneNumber, email, homeAddress, Hanoi, latitude, longitude, creditCardNumber, balance, creditPoints, skillRatingScore, supporterRatingScore, hostRatingScore);
        if (newMember.payRegistrationFee())
        {
            addMember(newMember); // Add new member to the member list
            admin.revenue += 20;  // Add 20$ to the system revenue
        }
    }
    else if (city == "Saigon")
    {
        RegularMember newMember(username, password, fullName, phoneNumber, email, homeAddress, Saigon, latitude, longitude, creditCardNumber, balance, creditPoints, skillRatingScore, supporterRatingScore, hostRatingScore);
        if (newMember.payRegistrationFee())
        {
            addMember(newMember); // Add new member to the member list
            admin.revenue += 20;  // Add 20$ to the system revenue
        }
    }

    cout << "Registration successful!\n";
    systemMenu();
}

void TimeBankSystem::profileMenu()
{
    cout << "======PROFILE MENU======\n";
    cout << "1. View Profile\n";
    cout << "2. Sell Credits\n";
    cout << "3. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        viewProfile();
        break;
    case 2:
        // method to sell credits
        break;
    case 3:
        regularMemberMenu(); // Return to the previous menu
        break;
    }
}

void TimeBankSystem::skillMenu()
{
    cout << "======SKILLS MENU======\n";
    cout << "1. View Skills\n";
    cout << "2. Add Skill\n";
    cout << "3. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        // method to view skills of the current members

        break;
    case 2:
        promptAddSkill();
        break;
    case 3:
        regularMemberMenu();
        break;
    }
}

void TimeBankSystem::requestMenu()
{
    cout << "======REQUESTS MENU======\n";
    cout << "1. View Requests\n";
    cout << "2. Add Request\n";
    cout << "3. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        // method to view requests
        break;
    case 2:
        // method to add request
        break;
    case 3:
        return;
        break;
    }
}

void TimeBankSystem::reviewMenu()
{
    cout << "======REVIEWS MENU======\n";
    cout << "1. View Review History\n";
    cout << "2. Add Review\n";
    cout << "3. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        // method to view reviews
        break;
    case 2:
        // method to add review
        break;
    case 3:
        return;
        break;
    }
}

void TimeBankSystem::searchMenu()
{
    cout << "======SEARCH MENU======\n";
    cout << "1. Search by Skill\n";
    cout << "2. Search by Location\n";
    cout << "3. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        // method to search by skill
        break;
    case 2:
        // method to search by location
        break;
    case 3:
        return;
        break;
    }
}

void TimeBankSystem::listingMenu()
{
    cout << "======LISTING MENU======\n";
    cout << "1. View Listings\n";
    cout << "2. Add Listing\n";
    cout << "3. Hide Listing\n";
    cout << "4. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        // method to view listings
        break;
    case 2:
        // method to add listing, but first display a list of user's skills, and then prompt them to get the ID of the skill they want to list
        promptAddListing();
        break;
    case 3:
        // method to hide listing
        break;

    case 4:
        regularMemberMenu();
        break;
    }
}

void TimeBankSystem::viewProfile()
{
    /* Less efficient way because we have to loop through the member list to find the current member
    for (RegularMember &member : this->memberList)
    {
        if (member.isAuthenticated)
        {
            cout << "=============YOUR INFORMATION=============\n";
            member.showInfo();
            break;
        }
    }*/

    cout << "=============YOUR INFORMATION=============\n";
    this->currentMember.showInfo();
    profileMenu();
}

// Functions to ask user input for adding new objects to the system's vectors

void TimeBankSystem::promptAddSkill()
{
    std::string skillID, skillName, skillDescription, skillEfficiency, ownerName = "";
    skillName = getValidStringInput("Enter skill name: ");
    skillDescription = getValidStringInput("Enter skill description: ");
    skillEfficiency = getValidStringInput("Enter skill efficiency (Skillful/Adequate/Medium/...): ");
    ownerName = this->currentMember.getUsername();
    Skill newSkill(skillID, skillName, skillDescription, skillEfficiency, ownerName);
    addSkill(newSkill);
    currentMember.skills.push_back(&newSkill);
    cout << "Skill added successfully!\n";
    regularMemberMenu();
}

void TimeBankSystem::promptAddListing()
{
    std::string listingID, startDate, endDate, buffer = "";
    std::string skillID;
    int consumedCredsPerHour = 0;
    float minHostRatingScore = -1;
    int listingState = 0; // 0 = available, 1 = hidden, 2 = booked, 3 = completed; default = available when listing is created
    std::string supporterName = this->currentMember.getUsername();
    std::string hostName = ""; // Host name is empty when listing is created, will be updated when the listing is booked by that host
    Period workingTimeSlot;
    skillID = getValidStringInput("Enter skillID to begin making a Job Listing on the market: ");

    consumedCredsPerHour = getValidInt("Enter consumed credits per hour: ");
    do
    {
        cout << "Do you want to set a minimum host rating score? (Y/N): ";
        cin >> buffer;
        if (buffer == "Y" || buffer == "y")
        {
            minHostRatingScore = getValidFloat("Enter minimum host rating score: ");
            break;
        }
        else if (buffer == "N" || buffer == "n")
        {
            minHostRatingScore = -1;
            break;
        }
        else
        {
            cout << "Invalid input! Please try again.\n";
        }
    } while (buffer != "Y" || buffer != "y" || buffer != "N" || buffer != "n");
    fflush(stdin); // Clear input buffer

    startDate = getValidTimestamp("Enter start date in DD/MM/YYYY HH:MM:SS format: ");
    endDate = getValidTimestamp("Enter end date in DD/MM/YYYY HH:MM:SS format: ");
    workingTimeSlot = Period(DateTime(startDate), DateTime(endDate));
    SkillListing newListing(listingID, skillID, consumedCredsPerHour, minHostRatingScore, listingState, supporterName, hostName, workingTimeSlot);
    addListing(newListing);
    currentMember.skillListings.push_back(&newListing);

    cout << "Listing added successfully!\n";
    regularMemberMenu();
}

void TimeBankSystem::loadData()
{
    FileHandler fileHandler;
    this->memberList = fileHandler.loadUsers("./databases/users.csv");
    this->admin = fileHandler.loadAdmin("./databases/admin.csv");
    this->skillList = fileHandler.loadSkills("./databases/skills.csv");
    this->skillListingList = fileHandler.loadListings("./databases/listings.csv");
}

void TimeBankSystem::saveData()
{
    FileHandler fileHandler;
    fileHandler.saveUsers("./databases/users.csv", this->memberList);
    fileHandler.saveAdmin("./databases/admin.csv", this->admin);
    fileHandler.saveSkills("./databases/skills.csv", this->skillList);
    fileHandler.saveListings("./databases/listings.csv", this->skillListingList);
}

int main()
{
    TimeBankSystem sys;
    sys.loadData();
    sys.welcomeScreen();
    sys.systemMenu();
    sys.logout();
    sys.saveData();

    return 0;
}
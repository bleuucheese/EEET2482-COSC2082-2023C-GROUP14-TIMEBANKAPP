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
    cout << "0. Quit\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Continue as Guest\n";

    switch (promptAndGetChoice(0, 3))
    {
    case 0:
        bye();
        return;
        break;
    case 1:
        loginMenu();
        break;
    case 2:
        registerMenu();
        break;
    case 3:
        guestMenu();
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
        printMemberTable();
        break;
    case 2:
        // method to view sales figures and statistics
        break;
    case 3:
        promptAdminChangePassword();
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
    cout << "2. Manage Skills\n";
    cout << "3. Manage Listings\n";
    cout << "4. Manage Requests\n";
    cout << "5. Manage Reviews\n";
    cout << "6. Search\n";
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
            this->currentMember = &user; // Set current member to the user who just logged in
            extractMemberData();         // Extract data from the system's vectors to the current member's vectors
            return true;
        }
    }
    return false;
}

void TimeBankSystem::logout()
{
    if (this->admin.isAuthenticated)
    {
        admin.isAuthenticated = false;
    }
    // for (auto &user : this->memberList)
    // {
    //     if (user.isAuthenticated)
    //     {
    //         user.isAuthenticated = false;
    //     }
    // }
    if (this->currentMember != nullptr)
    {
        this->currentMember->isAuthenticated = false; // Hot fix for logout bug: segmentation fault
    }
}

RegularMember &TimeBankSystem::findMemberByUsername(string usn)
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

Skill &TimeBankSystem::findSkillByID(string skillID)
{
    for (Skill &skill : this->skillList)
    {
        if (skill.skillID == skillID)
        {
            return skill;
        }
    }
    // throw std::runtime_error("Skill not found!");
}

SkillListing &TimeBankSystem::findListingByID(string listingID)
{
    for (SkillListing &listing : this->skillListingList)
    {
        if (listing.listingID == listingID)
        {
            return listing;
        }
    }
    throw std::runtime_error("Listing not found!");
}

Request &TimeBankSystem::findRequestByID(string requestID)
{
    for (Request &request : this->requestList)
    {
        if (request.requestID == requestID)
        {
            return request;
        }
    }
    throw std::runtime_error("Request not found!");
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
    cout << "2. Top Up Credits\n";
    cout << "3. Sell Credits\n";
    cout << "4. Block a Member\n";
    cout << "5. Back\n";

    switch (promptAndGetChoice(1, 5))
    {
    case 1:
        viewProfile(); // can view blocked members' usernames
        break;
    case 2:
        promptTopUp();
        break;
    case 3:
        promptSellCredits();
        break;
    case 4:
        promptBlockMember();
        break;

    case 5:
        regularMemberMenu();
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

void TimeBankSystem::listingMenu()
{
    cout << "======LISTING MENU======\n";
    cout << "1. View Listings\n";
    cout << "2. Add Listing\n";
    cout << "3. Hide Listing\n";
    cout << "4. Unhide Listing\n";
    cout << "5. Back\n";

    switch (promptAndGetChoice(1, 5))
    {
    case 1:
        // method to view listings
        printListingTableMember();
        break;
    case 2:
        // method to add listing, but first display a list of user's skills, and then prompt them to get the ID of the skill they want to list
        promptAddListing();
        break;
    case 3:
        // method to hide listing
        promptHideListing();
        break;

    case 4:
        // method to unhide listing
        promptUnhideListing();
        break;

    case 5:
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
        // method to view requests, and prompt them to get the ID of the request they want to respond.
        printRequestTableMember();
        cout << std::endl;
        char choice;
        do
        {
            cout << "Do you want to respond to a request? (Y/N): ";
            cin >> choice;

        } while (choice != 'Y' & choice != 'y' & choice != 'N' & choice != 'n');
        if (choice == 'Y' || choice == 'y')
        {
            cout << "1. Accept Request\n";
            cout << "2. Reject Request\n";
            switch (promptAndGetChoice(1, 2))
            {
            case 1:
                if (promptRespondRequest())
                {
                    respondRequestFromPrompt('A');
                }
                else
                {
                    cout << "Cannot accept this request. Please try again.\n";
                    regularMemberMenu();
                }
                break;
            case 2:
                // method to reject request
                respondRequestFromPrompt('R');
                break;
            }
        }
        else if (choice == 'N' || choice == 'n')
        {
            regularMemberMenu();
            break;
        }
        break;

    case 2:
        // method to add request: display a list of listings, and then prompt them to get the ID of the listing they want to request
        if (promptAddRequest())
        {
            addRequestFromPrompt();
        }
        else
        {
            // cout << "Request failed! Please try again.\n";
            regularMemberMenu();
        }
        break;
    case 3:
        regularMemberMenu();
        break;
    }
}

void TimeBankSystem::reviewMenu()
{
    cout << "======REVIEWS MENU======\n";
    cout << "1. View Review History\n";
    cout << "2. Add Review For a Host\n";
    cout << "3. Add Review For a Supporter\n";
    cout << "4. Back\n";

    switch (promptAndGetChoice(1, 4))
    {
    case 1:
        // method to view reviews
        viewReviews();
        break;
    case 2:
        // method for a supporter to add review: #RH type
        promptHostReview();
        break;
    case 3:
        // method for a host to add review: #RS type
        promptSupporterReview();
        break;

    case 4:
        regularMemberMenu();
        break;
    }
}

void TimeBankSystem::searchMenu()
{
    cout << "======SEARCH MENU======\n";
    cout << "1. Search for a Member\n";
    cout << "2. Search for a listing\n";
    cout << "3. Back\n";

    switch (promptAndGetChoice(1, 3))
    {
    case 1:
        // method to search by username
        promptSearchMember();
        break;
    case 2:
        // method to search by location, and min host rate, and by current credits: isEligibleForViewingListing()
        promptSearchListing();
        break;
    case 3:
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
    (this->currentMember)->showInfo();
    profileMenu();
}

void TimeBankSystem::viewReviews()
{
    cout << "=============YOUR REVIEWS=============\n";
    this->currentMember->printReviews();
    reviewMenu();
}

void TimeBankSystem::promptAdminChangePassword()
{
    string username, newPassword;
    do
    {
        cout << "Enter the username of the member you want to reset password: ";
        cin >> username;
        if (isUniqueUsername(username))
        {
            cout << "User not found! Please try again.\n";
        }
        else if (username == "@dmin2023")
        {
            cout << "You cannot reset your own password! Please try again.\n";
        }

    } while (isUniqueUsername(username) || username == "@dmin2023");
    fflush(stdin); // Clear input buffer
    newPassword = getValidPassword();
    if (!admin.resetPasswordForMember(findMemberByUsername(username), newPassword))
    {
        cout << "Please try again\n";
    }
    adminMenu();
}

bool TimeBankSystem::isSkillIDExistAndOwned(string skillID)
{
    for (Skill &skill : this->skillList)
    {
        if (skill.skillID == skillID && skill.getOwnerName() == (this->currentMember)->getUsername())
        {
            return true;
        }
    }
    return false;
}

bool TimeBankSystem::isListingIDExistAndOwned(string listingID)
{
    for (SkillListing &listing : this->skillListingList)
    {
        if (listing.listingID == listingID && listing.getSupporterName() == (this->currentMember)->getUsername())
        {
            return true;
        }
    }
    return false;
}

bool TimeBankSystem::isListingIDExistAndNotOwned(string listingID)
{
    for (SkillListing &listing : this->skillListingList)
    {
        if (listing.listingID == listingID && listing.getSupporterName() != (this->currentMember)->getUsername())
        {
            return true;
        }
    }
    return false;
}

bool TimeBankSystem::isRequestIDExistAndOwned(string requestID)
{
    for (Request &request : this->requestList)
    {
        if (request.requestID == requestID && request.getReceiverName() == (this->currentMember)->getUsername())
        {
            return true;
        }
    }
    return false;
}

bool TimeBankSystem::isHostReviewGiven(string listingID)
{
    for (Review &review : this->reviewList)
    {
        if (review.reviewID[1] == 'H' && review.listingID == listingID && review.getReviewer() == (this->currentMember)->getUsername())
        {
            return true;
        }
    }
    return false;
}

bool TimeBankSystem::isSupporterReviewGiven(string listingID)
{
    for (Review &review : this->reviewList)
    {
        if (review.reviewID[1] == 'S' && review.listingID == listingID && review.getReviewer() == (this->currentMember)->getUsername())
        {
            return true;
        }
    }
    return false;
}

// Functions to ask user input for adding new objects to the system's vectors

void TimeBankSystem::promptAddSkill()
{
    std::string skillID, skillName, skillDescription, skillEfficiency, ownerName = "";
    skillName = getValidStringInput("Enter skill name: ");
    skillDescription = getValidStringInput("Enter skill description: ");
    skillEfficiency = getValidStringInput("Enter skill efficiency (Skillful/Adequate/Medium/...): ");
    ownerName = (this->currentMember)->getUsername();
    Skill newSkill(skillID, skillName, skillDescription, skillEfficiency, ownerName);
    addSkill(newSkill);
    (currentMember)->skills.push_back(&newSkill);
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
    Period workingTimeSlot;

    do
    {
        skillID = getValidStringInput("Enter skillID to begin making a Job Listing on the market: ");
        if (!isSkillIDExistAndOwned(skillID))
        {
            cout << "SkillID not found or not one of your added skills! Please try again.\n";
        }
    } while (!isSkillIDExistAndOwned(skillID));

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
    std::string supporterName = (this->currentMember)->getUsername();
    std::string hostName = ""; // Host name is empty when listing is created, will be updated when the listing is booked by that host
    startDate = getValidTimestamp("Enter start date in DD/MM/YYYY HH:MM:SS format: ");
    endDate = getValidTimestamp("Enter end date in DD/MM/YYYY HH:MM:SS format: ");
    workingTimeSlot = Period(DateTime(startDate), DateTime(endDate));
    SkillListing newListing(listingID, skillID, consumedCredsPerHour, minHostRatingScore, listingState, supporterName, hostName, workingTimeSlot);
    addListing(newListing);
    (currentMember->skillListings).push_back(&newListing);

    cout << "Listing added successfully!\n";
    regularMemberMenu();
}

void TimeBankSystem::promptHideListing()
{
    std::string listingID;
    // Prompt user to enter listingID until they enter a valid listingID that is owned by them
    do
    {
        listingID = getValidStringInput("Enter listingID to hide: ");
        if (!isListingIDExistAndOwned(listingID))
        {
            cout << "ListingID not found or not one of your added listings! Please try again.\n";
        }

    } while ((!isListingIDExistAndOwned(listingID)) || findListingByID(listingID).getListingState() != 0);

    if (findListingByID(listingID).hideListing())
    {
        cout << "Listing hidden successfully!\n";
    }
    else
    {
        cout << "Listing hide failed! Please try again.\n";
    }
    regularMemberMenu();
}

void TimeBankSystem::promptUnhideListing()
{
    std::string listingID;
    // Prompt user to enter listingID until they enter a valid listingID that is owned by them
    do
    {
        listingID = getValidStringInput("Enter listingID to unhide: ");
        if (!isListingIDExistAndOwned(listingID))
        {
            cout << "ListingID not found or not one of your added listings! Please try again.\n";
        }

    } while ((!isListingIDExistAndOwned(listingID)) || findListingByID(listingID).getListingState() != 1);

    if (findListingByID(listingID).unhideListing())
    {
        cout << "Listing unhidden successfully!\n";
    }
    else
    {
        cout << "Listing unhide failed! Please try again.\n";
    }
    regularMemberMenu();
}

bool TimeBankSystem::promptAddRequest()
{

    std::string requestID, listingID, requesterName, receiverName, requestStatus = "";

    std::string buffer = "";
    do
    {
        listingID = getValidStringInput("Enter listingID to begin making a request: ");
        if (!isListingIDExistAndNotOwned(listingID))
        {
            cout << "ListingID not found or is one of your added listings! Please try again.\n";
        }
    } while (!isListingIDExistAndNotOwned(listingID));

    // cout << "Checking today's date and listing's start date...\n"; // For debugging purpose
    if (!DateTime().isBeforeStartDate(findListingByID(listingID).getWorkingTimeSlot().getStartDate()))
    {
        cout << "You cannot make a request for this listing because today's date is after the listing's start date!\n";
        return false;
    }

    requesterName = (this->currentMember)->getUsername();         // host
    receiverName = findListingByID(listingID).getSupporterName(); // supporter
    /*Deep check*/
    // If the supporter is blocked by the host, the host cannot make a request for that supporter
    if (currentMember->isBlockerOf(receiverName))
    {
        cout << "You cannot make a request for this supporter because you have blocked them!\n";
        return false;
    }
    // If the host is blocked by the supporter, the host cannot make a request for that supporter
    if (currentMember->isBlockedBy(receiverName))
    {
        cout << "You cannot make a request for this supporter because they have blocked you :(\n";
        return false;
    }
    // isEligibleToBook method
    SkillListing listing = findListingByID(listingID);
    if (!listing.isEligibleToBook(*currentMember))
    {
        cout << "You cannot make a request for this listing because you don't meet the requirements!\n";
        return false;
    }
    // Proceed to create a new request when all the above conditions are met
    return true;
}

void TimeBankSystem::addRequestFromPrompt()
{
    std::string requestID, listingID, requesterName, receiverName, requestStatus = "";
    listingID = getValidStringInput("Reenter the listingID to confirm: ");
    requesterName = (this->currentMember)->getUsername();         // host
    receiverName = findListingByID(listingID).getSupporterName(); // supporter

    Request newRequest(requestID, listingID, requesterName, receiverName, DateTime(), requestStatus);
    addRequest(newRequest);                                       // Add new request to the system's request list
    (currentMember->sentreceivedRequests).push_back(&newRequest); // Add new request to the current member's request list

    // Update the listing state to booked and update the host name: not yet, because it is not accepted --> bug
    // findListingByID(listingID).setListingState(2);
    // findListingByID(listingID).setHostName(requesterName);
    cout << "Request added successfully!\n";
    regularMemberMenu();
}

void TimeBankSystem::respondRequestFromPrompt(char choice)
{
    std::string requestID = getValidStringInput("Enter requestID to confirm: ");

    if (choice == 'A')
    {
        findRequestByID(requestID).setRequestStatus("Accepted");
        findListingByID(findRequestByID(requestID).getListingID()).setListingState(2); // Set to book
        findListingByID(findRequestByID(requestID).getListingID()).setHostName(findRequestByID(requestID).getRequesterName());
        cout << "Request accepted successfully!\n";
    }
    else if (choice == 'R')
    {
        findRequestByID(requestID).setRequestStatus("Rejected");
        cout << "Request rejected successfully!\n";
    }
    regularMemberMenu();
}

bool TimeBankSystem::promptRespondRequest()
{
    std::string requestID;
    do
    {
        requestID = getValidStringInput("Enter requestID to respond: ");
        if (!isRequestIDExistAndOwned(requestID))
        {
            cout << "RequestID not found or not one of your incomming requests! Please try again.\n";
        }
    } while (!isRequestIDExistAndOwned(requestID));

    // cout << "Checking today's date and listing's start date...\n"; // For debugging purpose
    if (!DateTime().isBeforeStartDate(findListingByID(findRequestByID(requestID).getListingID()).getWorkingTimeSlot().getStartDate()))
    {
        cout << "You cannot respond to this request because today's date is after the listing's start date!\n";
        return false;
    }

    // cout << "Checking if the request is already accepted...\n"; // For debugging purpose
    else if (findRequestByID(requestID).getRequestStatus() == "Accepted")
    {
        cout << "You cannot respond to this request because it is already accepted!\n";
        return false;
    }

    // cout << "Checking if the request is already rejected...\n"; // For debugging purpose
    else if (findRequestByID(requestID).getRequestStatus() == "Rejected")
    {
        cout << "You cannot respond to this request because it is already rejected!\n";
        return false;
    }

    // Check with ongoing bookings of the supporter if they are available to accept the request (e,g: not overlapped with other bookings timeslot)
    for (Request *request : currentMember->sentreceivedRequests)
    {
        if (request->getRequestStatus() == "Accepted")
        {
            if (findListingByID(request->getListingID()).getSupporterName() == findListingByID(findRequestByID(requestID).getListingID()).getSupporterName())
            {
                if (findListingByID(request->getListingID()).getWorkingTimeSlot().isOverlappedWith(findListingByID(findRequestByID(requestID).getListingID()).getWorkingTimeSlot()))
                {
                    cout << "You cannot respond to this request because you are not available at that time!\n";
                    return false;
                }
            }
        }
    }
    return true;
}

void TimeBankSystem::promptHostReview()
{

    std::string listingID, reviewID, reviewContent, reviewerName, revieweeName = "";
    do
    {
        listingID = getValidStringInput("Enter listingID to begin making a review: ");
        if (!isListingIDExistAndOwned(listingID))
        {
            cout << "ListingID not found or not one of your added listings! Please try again.\n";
        }
        else if (isHostReviewGiven(listingID))
        {
            cout << "You have already given a host review for this listing! Please try again.\n";
        }

    } while (!isListingIDExistAndOwned(listingID) || isHostReviewGiven(listingID));

    // Check if the listing is completed
    if (findListingByID(listingID).listingState == 4)
    {
        reviewerName = (this->currentMember)->getUsername();
        revieweeName = findListingByID(listingID).getHostName();
        if (revieweeName == (this->currentMember)->getUsername())
        {
            cout << "You cannot review yourself! Please try again.\n";
            regularMemberMenu();
        }
        else if (revieweeName == "@dmin2023")
        {
            cout << "You cannot review the admin! Please try again.\n";
            regularMemberMenu();
        }
        else if (currentMember->isBlockedBy(revieweeName))
        {
            cout << "You cannot review this host because they have blocked you :(\n";
            regularMemberMenu();
        }
        else if (currentMember->isBlockerOf(revieweeName))
        {
            cout << "You cannot review this host because you have blocked them!\n";
            regularMemberMenu();
        }
        else
        {
            reviewContent = getValidStringInput("Enter review content: ");
            int hostRatingScore = getValidInt("Enter host rating score (1-5): ");
            reviewerName = (this->currentMember)->getUsername();
            Review newReview(reviewID, listingID, reviewContent, reviewerName, revieweeName, DateTime(), hostRatingScore);
            addReview(newReview);
            (currentMember->sentreceivedReviews).push_back(&newReview);
            // Also add to the reviewee's review list
            findMemberByUsername(revieweeName).sentreceivedReviews.push_back(&newReview);
            cout << "Review added successfully!\n";
            regularMemberMenu();
        }
    }
    else
    {
        cout << "You cannot review this listing because it is not completed yet!\n";
        regularMemberMenu();
    }
}

void TimeBankSystem::promptSupporterReview()
{
    // Cannot give supporter review if you are the supporter of the listing
    std::string listingID, reviewID, reviewContent, reviewerName, revieweeName = "";
    do
    {
        listingID = getValidStringInput("Enter listingID to begin making a review: ");
        if (!isListingIDExistAndNotOwned(listingID))
        {
            cout << "ListingID not found or is one of your added listings! Please try again.\n";
        }
        else if (isSupporterReviewGiven(listingID))
        {
            cout << "You have already given a review for this listing! Please try again.\n";
        }

    } while (!isListingIDExistAndNotOwned(listingID) || isSupporterReviewGiven(listingID));

    // Check if the listing is completed
    if (findListingByID(listingID).listingState == 4)
    {
        reviewerName = (this->currentMember)->getUsername();
        revieweeName = findListingByID(listingID).getSupporterName();
        if (revieweeName == (this->currentMember)->getUsername())
        {
            cout << "You cannot review yourself! Please try again.\n";
            regularMemberMenu();
        }
        else if (revieweeName == "@dmin2023")
        {
            cout << "You cannot review the admin! Please try again.\n";
            regularMemberMenu();
        }
        else if (currentMember->isBlockedBy(revieweeName))
        {
            cout << "You cannot review this supporter because they have blocked you :(\n";
            regularMemberMenu();
        }
        else if (currentMember->isBlockerOf(revieweeName))
        {
            cout << "You cannot review this supporter because you have blocked them!\n";
            regularMemberMenu();
        }
        else
        {
            reviewContent = getValidStringInput("Enter review content: ");
            int skillRatingScore = getValidInt("Enter skill rating score (1-5): ");
            int supporterRatingScore = getValidInt("Enter supporter rating score (1-5): ");
            reviewerName = (this->currentMember)->getUsername();
            Review newReview(reviewID, listingID, skillRatingScore, supporterRatingScore, reviewContent, reviewerName, revieweeName, DateTime());
            addReview(newReview);
            (currentMember->sentreceivedReviews).push_back(&newReview);
            // Also add to the reviewee's review list
            findMemberByUsername(revieweeName).sentreceivedReviews.push_back(&newReview);
            cout << "Review added successfully!\n";
            regularMemberMenu();
        }
    }
    else
    {
        cout << "You cannot review this listing because it is not completed yet!\n";
        regularMemberMenu();
    }
}

void TimeBankSystem::promptSearchMember()
{
    std::string username;
    do
    {
        username = getValidStringInput("Enter username to search: ");
        if (isUniqueUsername(username))
        {
            cout << "User not found! Please try again.\n";
        }
        else if (username == this->currentMember->getUsername())
        {
            cout << "You cannot search yourself! Please try again.\n";
        }
        else if (username == "@dmin2023")
        {
            cout << "You cannot search the admin! Please try again.\n";
        }
    } while (isUniqueUsername(username) || username == currentMember->getUsername() || username == "@dmin2023");
    RegularMember searchedMember = findMemberByUsername(username);
    if (currentMember->isBlockedBy(searchedMember.getUsername()))
    {
        cout << "Seems like they have blocked you :(\n";
        regularMemberMenu();
    }
    else if (currentMember->isBlockerOf(searchedMember.getUsername()))
    {
        cout << "You cannot search this member because you have blocked them!\n";
        regularMemberMenu();
    }
    else
    {
        cout << "=============SEARCHED MEMBER INFORMATION=============\n";
        searchedMember.showRestrictedMemberInfo();
        regularMemberMenu();
    }
}

void TimeBankSystem::promptSearchListing()
{
    std::string startDay, endDay, city;
    // This method will filter the listings based on the city, start date, end date
    // The displayed listings will be based on if the current member is eligible to view them

    // Prompt user to enter the city
    city = getValidCity();
    fflush(stdin); // Clear input buffer
    vector<SkillListing> saigonListings;
    vector<SkillListing> hanoiListings;

    for (SkillListing &listing : this->skillListingList)
    {
        if (listing.getSupporterName() != this->currentMember->getUsername() && listing.listingState == 0)
        {
            if (listing.isEligibleToBook(*currentMember))
            {
                if (findMemberByUsername(listing.getSupporterName()).city == 24)
                {
                    hanoiListings.push_back(listing);
                }
                else if (findMemberByUsername(listing.getSupporterName()).city == 28)
                {
                    saigonListings.push_back(listing);
                }
            }
        }
    }

    // Ask for start date and end date
    startDay = getValidTimestamp("Enter start date in DD/MM/YYYY HH:MM:SS format: ");
    cout << "Choose intervals: 1. Within 6 hours  2. Within 1 day  3. Within 1 week  4. Not specified\n";

    Period timeSlot1, timeSlot2, timeSlot3;
    switch (promptAndGetChoice(1, 4))
    {
    case 1:
        endDay = DateTime(startDay).addTimePeriod(0, 6, 0, 0).getFormattedTimestamp();
        cout << startDay << std::endl;
        cout << endDay << std::endl;
        timeSlot1 = Period(DateTime(startDay), DateTime(endDay));
        if (city == "Hanoi")
        {
            for (SkillListing &listing : hanoiListings)
            {
                if (listing.getWorkingTimeSlot().isOverlappedWith(timeSlot1))
                {
                    printSkillListingTable(listing);
                }
            }
        }
        else if (city == "Saigon")
        {
            for (SkillListing &listing : saigonListings)
            {
                if (listing.getWorkingTimeSlot().isOverlappedWith(timeSlot1))
                {
                    printSkillListingTable(listing);
                }
            }
        }
        break;
    case 2:
        endDay = DateTime(startDay).addTimePeriod(1, 0, 0, 0).getFormattedTimestamp();
        cout << endDay << std::endl;
        timeSlot2 = Period(DateTime(startDay), DateTime(endDay));
        if (city == "Hanoi")
        {
            for (SkillListing &listing : hanoiListings)
            {
                if (listing.getWorkingTimeSlot().isOverlappedWith(timeSlot2))
                {
                    printSkillListingTable(listing);
                }
            }
        }
        else if (city == "Saigon")
        {
            for (SkillListing &listing : saigonListings)
            {
                if (listing.getWorkingTimeSlot().isOverlappedWith(timeSlot2))
                {
                    printSkillListingTable(listing);
                }
            }
        }
        break;
    case 3:
        endDay = DateTime(startDay).addTimePeriod(7, 0, 0, 0).getFormattedTimestamp();
        cout << endDay << std::endl;
        timeSlot3 = Period(DateTime(startDay), DateTime(endDay));

        if (city == "Hanoi")
        {
            for (SkillListing &listing : hanoiListings)
            {
                if (listing.getWorkingTimeSlot().isOverlappedWith(timeSlot3))
                {
                    printSkillListingTable(listing);
                }
            }
        }
        else if (city == "Saigon")
        {
            for (SkillListing &listing : saigonListings)
            {
                if (listing.getWorkingTimeSlot().isOverlappedWith(timeSlot3))
                {
                    printSkillListingTable(listing);
                }
            }
        }
        break;
    case 4:
        if (city == "Hanoi")
        {
            for (SkillListing &listing : hanoiListings)
            {
                if (!listing.getWorkingTimeSlot().getStartDate().isBeforeStartDate(DateTime(startDay)))
                {
                    printSkillListingTable(listing);
                }
            }
        }
        else if (city == "Saigon")
        {

            for (SkillListing &listing : saigonListings)
            {
                if (!listing.getWorkingTimeSlot().getStartDate().isBeforeStartDate(DateTime(startDay)))
                {
                    printSkillListingTable(listing);
                }
            }
        }
        break;
    }

    regularMemberMenu();
}

void TimeBankSystem::promptTopUp()
{
    int amount = getValidInt("Enter amount of credit to top up: ");
    // Authorize the payment by get the user to enter their password to confirm
    string password;
    do
    {
        cout << "Enter your password to confirm transaction: ";
        cin >> password;
        if (password != (this->currentMember)->getPassword())
        {
            cout << "Wrong password! Please try again.\n";
        }
    } while (password != (this->currentMember)->getPassword());
    cout << "Processing payment...\n";

    if (currentMember->topUp(amount))
    {
        cout << "Top up successful! Added " << amount << " credits to your account.\n";
        this->admin.revenue += amount; // Add the amount of credits to the system's revenue
    }
    else
    {
        cout << "Top up failed! Please try again.\n";
    }
    regularMemberMenu();
}

void TimeBankSystem::promptSellCredits()
{
    // This will transfer 90% value of the amount of credits to the member's bank account from the system's revenue
    int amount = getValidInt("Enter amount of credit to sell: ");
    if (currentMember->sellCredits(amount))
    {
        cout << "Sell credits successful! Added $" << amount * 0.9 << " to your account.\n";
        this->admin.revenue -= amount * 0.9;
    }
    else
    {
        cout << "Sell credits failed! Please try again.\n";
    }
    regularMemberMenu();
}

void TimeBankSystem::promptBlockMember()
{
    string username;
    std::fstream blockFile("./databases/blocklist.csv", std::ios::app);

    do
    {
        cout << "Enter the username of the member you want to block: ";
        cin >> username;
        if (isUniqueUsername(username))
        {
            cout << "User not found! Please try again.\n";
        }
        else if (username == this->currentMember->getUsername())
        {
            cout << "You cannot block yourself! Please try again.\n";
        }
        else if (username == "@dmin2023")
        {
            cout << "You cannot block the admin! Please try again.\n";
        }

    } while (isUniqueUsername(username) || username == currentMember->getUsername() || username == "@dmin2023");
    RegularMember blockedMember = findMemberByUsername(username);
    if (currentMember->blockMember(blockedMember))
    {
        cout << "Block successful!\n";
        // Write the blocked member directly to the file
        blockFile << currentMember->getUsername() << "," << username << "\n";
        // Update the blocked member list of the currently logged in user
        // currentMember->blockedMembers.push_back(&blockedMember);
    }
    else
    {
        cout << "Block failed! Please try again.\n";
    }
    regularMemberMenu();
}

void TimeBankSystem::printRequestTableMember()
{

    std::cout << std::setw(10) << "RequestID" << std::setw(15) << "ListingID"
              << std::setw(15) << "Requester" << std::setw(15) << "Receiver"
              << std::setw(20) << "Timestamp" << std::setw(15) << "Status" << std::endl;
    std::cout << std::setfill('-') << std::setw(90) << "" << std::setfill(' ') << std::endl;

    for (const auto &request : this->currentMember->sentreceivedRequests)
    {
        if (request->getReceiverName() == (this->currentMember)->getUsername())
        {
            std::cout << std::setw(10) << request->requestID
                      << std::setw(15) << request->listingID
                      << std::setw(15) << request->requesterName
                      << std::setw(15) << request->receiverName
                      << std::setw(25) << request->requestTimeStamp.getFormattedTimestamp()
                      << std::setw(10) << request->requestStatus << std::endl;
        }
    }
}

void TimeBankSystem::printListingTableMember()
{
    cout << "Here are available listings on the market:\n";
    int leftColumnWidth = 40;
    int rightColumnWidth = 85;
    if (this->skillListingList.size() == 0)
    {
        cout << "N/A" << std::endl;
    }
    else
    {
        for (SkillListing &listing : this->skillListingList)
        {
            if (listing.supporterName != this->currentMember->getUsername() && listing.listingState == 0)
            {
                RegularMember supporter = findMemberByUsername(listing.supporterName);
                Skill skill = findSkillByID(listing.skillID);
                string city = (supporter.city == 24) ? "Hanoi" : "Saigon";
                int secs = listing.workingTimeSlot.durationInSeconds();
                double distance = supporter.calculateDistance(*currentMember);
                string minHostRatingScore = (listing.minHostRatingScore == -1) ? "N/A" : std::to_string(listing.minHostRatingScore);
                // Draw the top line of the table
                drawTableLine(leftColumnWidth + rightColumnWidth + 3);

                // Draw the header row
                drawRow(" Supporter Info", " Listing ID: " + listing.listingID + " - Total Credits Cost: " + std::to_string(listing.calculateTotalCreds()), leftColumnWidth, rightColumnWidth);

                // Draw line after header
                drawTableLine(leftColumnWidth + rightColumnWidth + 3);

                // Draw rows of the table
                drawRow("username: " + listing.getSupporterName(), "Skill perform:", leftColumnWidth, rightColumnWidth);
                drawRow("full name: " + supporter.fullName, "+ Name: " + skill.skillName, leftColumnWidth, rightColumnWidth);
                drawRow("phone number: " + supporter.phoneNumber, "+ Description: " + skill.description, leftColumnWidth, rightColumnWidth);
                drawRow("email: " + supporter.email, "+ Efficiency: " + skill.skillEfficiency, leftColumnWidth, rightColumnWidth);
                drawRow("home address: " + supporter.homeAddress, "Start Date: " + listing.workingTimeSlot.getStartDate().getFormattedTimestamp(), leftColumnWidth, rightColumnWidth);
                drawRow("city: " + city, "End Date: " + listing.workingTimeSlot.getEndDate().getFormattedTimestamp(), leftColumnWidth, rightColumnWidth);
                drawRow("hostRatingScore: " + std::to_string(supporter.getHostRatingScore()), listing.workingTimeSlot.convertSecToDuration(secs), leftColumnWidth, rightColumnWidth);
                drawRow("skillRatingScore: " + std::to_string(supporter.getSkillRatingScore()), "", leftColumnWidth, rightColumnWidth);
                drawRow("supporterRatingScore: " + std::to_string(supporter.getSupporterRatingScore()), "Minimum hostRatingScore required: " + minHostRatingScore, leftColumnWidth, rightColumnWidth);
                drawRow("", "Distance from you: " + std::to_string(distance) + " kilometers", leftColumnWidth, rightColumnWidth);
                // ... add more rows as needed ...

                // Draw the bottom line of the table
                drawTableLine(leftColumnWidth + rightColumnWidth + 3);

                for (Review &review : this->reviewList)
                {
                    if (review.getReviewee() == supporter.getUsername())
                    {
                        drawRow2(review.getReviewID() + ": " + review.getReviewer() + " posted on " + review.timestamp.getFormattedTimestamp(), "", rightColumnWidth, leftColumnWidth);
                        drawRow2("Skill: " + findSkillByID(findListingByID(review.listingID).skillID).skillName, "", rightColumnWidth, leftColumnWidth);
                        if (review.reviewID[1] == 'H')
                        {
                            // cout << review.reviewID[1] << std::endl;
                            drawRow2("hostRatingScore: " + std::to_string(review.hostRating), "", rightColumnWidth, leftColumnWidth);
                        }
                        else if (review.reviewID[1] == 'S')
                        {
                            // cout << review.reviewID[1] << std::endl;
                            drawRow2("skillRatingScore: " + std::to_string(review.skillRating), "", rightColumnWidth, leftColumnWidth);
                            drawRow2("supporterRatingScore: " + std::to_string(review.supporterRating), "", rightColumnWidth, leftColumnWidth);
                        }
                        drawRow2("Comments: " + review.comments, "", leftColumnWidth, rightColumnWidth);
                        drawRow2("", "", rightColumnWidth, leftColumnWidth);
                        drawTableLine(leftColumnWidth + rightColumnWidth + 3);
                    }
                }
            }
            cout << std::endl;
        }
    }

    listingMenu();
}

void TimeBankSystem::printSkillListingTable(SkillListing &listing)
{
    int leftColumnWidth = 40;
    int rightColumnWidth = 85;
    RegularMember supporter = findMemberByUsername(listing.supporterName);
    Skill skill = findSkillByID(listing.skillID);
    string city = (supporter.city == 24) ? "Hanoi" : "Saigon";
    int secs = listing.workingTimeSlot.durationInSeconds();
    double distance = supporter.calculateDistance(*currentMember);
    string minHostRatingScore = (listing.minHostRatingScore == -1) ? "N/A" : std::to_string(listing.minHostRatingScore);
    // Draw the top line of the table
    drawTableLine(leftColumnWidth + rightColumnWidth + 3);

    // Draw the header row
    drawRow(" Supporter Info", " Listing ID: " + listing.listingID + " - Total Credits Cost: " + std::to_string(listing.calculateTotalCreds()), leftColumnWidth, rightColumnWidth);

    // Draw line after header
    drawTableLine(leftColumnWidth + rightColumnWidth + 3);

    // Draw rows of the table
    drawRow("username: " + listing.getSupporterName(), "Skill perform:", leftColumnWidth, rightColumnWidth);
    drawRow("full name: " + supporter.fullName, "+ Name: " + skill.skillName, leftColumnWidth, rightColumnWidth);
    drawRow("phone number: " + supporter.phoneNumber, "+ Description: " + skill.description, leftColumnWidth, rightColumnWidth);
    drawRow("email: " + supporter.email, "+ Efficiency: " + skill.skillEfficiency, leftColumnWidth, rightColumnWidth);
    drawRow("home address: " + supporter.homeAddress, "Start Date: " + listing.workingTimeSlot.getStartDate().getFormattedTimestamp(), leftColumnWidth, rightColumnWidth);
    drawRow("city: " + city, "End Date: " + listing.workingTimeSlot.getEndDate().getFormattedTimestamp(), leftColumnWidth, rightColumnWidth);
    drawRow("hostRatingScore: " + std::to_string(supporter.getHostRatingScore()), listing.workingTimeSlot.convertSecToDuration(secs), leftColumnWidth, rightColumnWidth);
    drawRow("skillRatingScore: " + std::to_string(supporter.getSkillRatingScore()), "", leftColumnWidth, rightColumnWidth);
    drawRow("supporterRatingScore: " + std::to_string(supporter.getSupporterRatingScore()), "Minimum hostRatingScore required: " + minHostRatingScore, leftColumnWidth, rightColumnWidth);
    drawRow("", "Distance from you: " + std::to_string(distance) + " kilometers", leftColumnWidth, rightColumnWidth);
    // ... add more rows as needed ...

    // Draw the bottom line of the table
    drawTableLine(leftColumnWidth + rightColumnWidth + 3);

    for (Review &review : this->reviewList)
    {
        if (review.getReviewee() == supporter.getUsername())
        {
            drawRow2(review.getReviewID() + ": " + review.getReviewer() + " posted on " + review.timestamp.getFormattedTimestamp(), "", rightColumnWidth, leftColumnWidth);
            drawRow2("Skill: " + findSkillByID(findListingByID(review.listingID).skillID).skillName, "", rightColumnWidth, leftColumnWidth);
            if (review.reviewID[1] == 'H')
            {
                // cout << review.reviewID[1] << std::endl;
                drawRow2("hostRatingScore: " + std::to_string(review.hostRating), "", rightColumnWidth, leftColumnWidth);
            }
            else if (review.reviewID[1] == 'S')
            {
                // cout << review.reviewID[1] << std::endl;
                drawRow2("skillRatingScore: " + std::to_string(review.skillRating), "", rightColumnWidth, leftColumnWidth);
                drawRow2("supporterRatingScore: " + std::to_string(review.supporterRating), "", rightColumnWidth, leftColumnWidth);
            }
            drawRow2("Comments: " + review.comments, "", leftColumnWidth, rightColumnWidth);
            drawRow2("", "", rightColumnWidth, leftColumnWidth);
            drawTableLine(leftColumnWidth + rightColumnWidth + 3);
        }
    }
}

void TimeBankSystem::printMemberTable()
{
    for (RegularMember &mem : this->memberList)
    {
        mem.showInfo();
    }
    adminMenu();
}

void TimeBankSystem::loadData()
{
    FileHandler fileHandler;
    this->memberList = fileHandler.loadUsers("./databases/users.csv");
    this->admin = fileHandler.loadAdmin("./databases/admin.csv");
    this->skillList = fileHandler.loadSkills("./databases/skills.csv");
    this->skillListingList = fileHandler.loadListings("./databases/listings.csv");
    this->requestList = fileHandler.loadRequests("./databases/requests.csv");
    this->reviewList = fileHandler.loadReviews("./databases/reviews.csv");
}

void TimeBankSystem::saveData()
{
    FileHandler fileHandler;
    fileHandler.saveUsers("./databases/users.csv", this->memberList);
    fileHandler.saveAdmin("./databases/admin.csv", this->admin);
    fileHandler.saveSkills("./databases/skills.csv", this->skillList);
    fileHandler.saveListings("./databases/listings.csv", this->skillListingList);
    fileHandler.saveRequests("./databases/requests.csv", this->requestList);
    fileHandler.saveReviews("./databases/reviews.csv", this->reviewList);
}

void TimeBankSystem::extractMemberData()
{

    // Clear the current member's vectors first
    (this->currentMember)->skills.clear();
    (this->currentMember)->skillListings.clear();
    (this->currentMember)->sentreceivedRequests.clear();
    (this->currentMember)->sentreceivedReviews.clear();
    (this->currentMember)->blockedMembers.clear();

    // Extract data from skillList, skillListingList, requestList, reviewList to current user's skillListings, requests, reviews vectors of pointers
    /*skill*/
    for (Skill &skill : this->skillList)
    {
        if (skill.getOwnerName() == (this->currentMember)->getUsername())
        {
            (this->currentMember)->skills.push_back(&skill);
        }
    }

    /*skillListing*/
    for (SkillListing &listing : this->skillListingList)
    {
        if (listing.getSupporterName() == (this->currentMember)->getUsername())
        {
            (this->currentMember)->skillListings.push_back(&listing);
        }
    }

    /*request*/
    for (Request &request : this->requestList)
    {
        if (request.getRequesterName() == (this->currentMember)->getUsername()) // If the current member is the host
        {
            (this->currentMember)->sentreceivedRequests.push_back(&request); // sentRequest
        }
        else if (request.getReceiverName() == (this->currentMember)->getUsername()) // If the current member is the supporter
        {
            (this->currentMember)->sentreceivedRequests.push_back(&request); // receivedRequest
        }
    }

    /*review*/
    for (Review &review : this->reviewList)
    {
        if (review.getReviewer() == (this->currentMember)->getUsername())
        {
            (this->currentMember)->sentreceivedReviews.push_back(&review); // sentReview
        }
        else if (review.getReviewee() == (this->currentMember)->getUsername())
        {
            (this->currentMember)->sentreceivedReviews.push_back(&review); // receivedReview
        }
    }

    /*blockList*/
    std::fstream blockFile("./databases/blocklist.csv", std::ios::in);
    std::string line;
    std::string blocker, blockedMemberUsername;

    // Skip the first line
    std::getline(blockFile, line);

    while (std::getline(blockFile, line))
    {
        std::stringstream ss(line);
        std::getline(ss, blocker, ',');               // Read the blocker username
        std::getline(ss, blockedMemberUsername, ','); // Read the blocked member username

        if (blocker == (this->currentMember)->getUsername())
        {
            // You don't need to read blockedMemberUsername again here.
            // Instead, you can directly add it to the vector.
            RegularMember *blockedMember = &findMemberByUsername(blockedMemberUsername);

            if (blockedMember != nullptr)
            {
                (this->currentMember)->blockedMembers.push_back(blockedMember);
            }
            else
            {
                cout << "Error populating blocked members list!\n";
            }
        }
    }
}

void TimeBankSystem::automaticallyUpdate()
{
    // Automatically update the available listing state to hidden when the start date is passed
    for (SkillListing &listing : this->skillListingList)
    {
        if (listing.getListingState() == 0 && listing.getWorkingTimeSlot().getStartDate().isBeforeStartDate(DateTime()))
        {
            listing.setListingState(1);
        }
    }
    // Automatically update the booked listing state to ongoing when the start date is passed
    for (SkillListing &listing : this->skillListingList)
    {
        if (listing.getListingState() == 2 && listing.getWorkingTimeSlot().getStartDate().isBeforeStartDate(DateTime()))
        {
            listing.setListingState(3);
        }
    }
    // Automatically update the ongoing listing state to completed when the end date is passed
    for (SkillListing &listing : this->skillListingList)
    {
        if (listing.getListingState() == 3 && listing.getWorkingTimeSlot().getEndDate().isBeforeStartDate(DateTime()))
        {
            listing.setListingState(4);
            // Automatically increment the supporter's credit points when the listing is completed
            int creds = listing.calculateTotalCreds();
            // cout << "Supporter earned " << creds << " credits for completing this listing!\n"; // Debugging purpose
            findMemberByUsername(listing.getSupporterName()).creditPoints += listing.calculateTotalCreds();
            // Automatically decrement the host's credit points when the listing is completed
            findMemberByUsername(listing.getHostName()).creditPoints -= listing.calculateTotalCreds();
        }
    }

    // Automatically update the pending request state to rejected when the start date is passed1
    for (Request &request : this->requestList)
    {
        if (request.getRequestStatus() == "Pending" && findListingByID(request.getListingID()).getWorkingTimeSlot().getStartDate().isBeforeStartDate(DateTime()))
        {
            request.setRequestStatus("Rejected");
        }
    }
    // Automatically update the pending request state to rejected when the listingID is hidden
    for (Request &request : this->requestList)
    {
        if (request.getRequestStatus() == "Pending" && findListingByID(request.getListingID()).getListingState() == 1)
        {
            request.setRequestStatus("Rejected");
        }
    }
    // Automatically update the pending request state to rejected when the listingID is booked by another host
    for (Request &request : this->requestList)
    {
        if (request.getRequestStatus() == "Pending" && (findListingByID(request.getListingID()).getListingState() == 2 || findListingByID(request.getListingID()).getListingState() == 3))
        {
            request.setRequestStatus("Rejected");
        }
    }
}

void TimeBankSystem::clearData()
{
    this->memberList.clear();
    this->skillList.clear();
    this->skillListingList.clear();
    this->requestList.clear();
    this->reviewList.clear();
}

// int main()
// {
//     TimeBankSystem sys;
//     sys.loadData();
//     sys.welcomeScreen();
//     sys.systemMenu();
//     sys.logout();

//     sys.saveData();

//     return 0;
// }
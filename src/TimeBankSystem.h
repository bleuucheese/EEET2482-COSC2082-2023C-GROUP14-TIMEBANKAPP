#ifndef TIMEBANKSYSTEM_H
#define TIMEBANKSYSTEM_H

#include <iostream>
#include <vector>
#include "./models/user/RegularMember.h"
#include "./models/user/Admin.h"
#include "./models/skill/Request.h"
#include "./models/skill/SkillListing.h"
#include "./models/skill/Skill.h"
#include "./utils/myUtils.h"
using std::cin;
using std::cout;

class TimeBankSystem
{
private:
    Admin admin;
    RegularMember *currentMember; // The member who is currently logged in
    std::vector<RegularMember> memberList{};
    std::vector<Request> requestList{};
    std::vector<SkillListing> skillListingList{};
    std::vector<Skill> skillList{};
    std::vector<Review> reviewList{};

public:
    TimeBankSystem();

    void welcomeScreen();
    void systemMenu();
    void guestMenu();
    void regularMemberMenu();
    void adminMenu();
    void searchMenu();

    void skillMenu();
    void requestMenu();
    void reviewMenu();
    void listingMenu();
    void profileMenu();

    void loginMenu();
    void registerMenu();
    void promptLogin();
    void logout();
    void promptRegister();

    RegularMember &findMemberByUsername(string username);
    Skill &findSkillByID(string skillID);
    SkillListing &findListingByID(string listingID);
    Request &findRequestByID(string requestID);
    bool isSkillIDExistAndOwned(string skillID);
    bool isListingIDExistAndOwned(string listingID);
    bool isListingIDExistAndNotOwned(string listingID);
    bool isRequestIDExistAndOwned(string requestID);

    void viewProfile();

    bool login(const std::string &username, const std::string &password);
    bool isUniqueUsername(string username);

    // Functions for admin
    void promptAdminChangePassword();
    // Functions for regular member
    void promptAddSkill();
    void promptAddListing();
    void promptHideListing();
    void promptUnhideListing();
    bool promptAddRequest();
    void addRequestFromPrompt();
    void promptHostReview();
    void promptSupporterReview();

    bool promptRespondRequest();
    void respondRequestFromPrompt();

    void promptTopUp();
    void promptSellCredits();
    void promptBlockMember();
    void promptUnblockMember();

    // Functions for adding new objects to the system's vectors
    void addMember(RegularMember &member);
    void addSkill(Skill &skill);
    void addListing(SkillListing &listing);
    void addRequest(Request &request);
    void addReview(Review &review);

    // Functions for dipslay objects in the system's vectors in pretty tabular format, used by admin
    void printMemberTable();
    void printSkillTable();
    void printListingTable();
    void printRequestTable();
    void printReviewTable();
    void printSkillListingTable();

    // Function for display information tailored to a specific user
    void printRequestTableMember();

    // Functions for dipslay objects in the system's vectors in pretty tabular format, used by guests

    // Functions for searching objects in the system's vectors

    // This two functions use method from FileHandler.cpp to load data from CSV files to vectors and vice versa
    void loadData(); // Load data from CSV files to vectors
    void saveData(); // Save data from vectors to CSV files

    void automaticallyUpdate(); // Automatically update listing state based on current time, and automatically update member's credit based on listing state, and reject expired requests

    // Function to clear all vectors
    void clearData();

    // When a member is logged in, this function will be called to extract the member's data from the system's vectors
    void extractMemberData();

    void bye();
    int promptAndGetChoice(unsigned min, unsigned max);
};

#endif // TIMEBANKSYSTEM_H
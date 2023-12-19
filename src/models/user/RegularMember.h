#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "../Address.h"
#include "Request.h"
#include "Review.h"

using std::vector;
using std::string;
class RegularMember : public User
{
private:
    int creditPoints;
    string phoneNumber;
    string email;
    Address homeAddress;
    string creditCardNumber;
    int cvcNumber;
    float balance;
    vector<string> skills;
    float skillRatingScore;
    float supporterRatingScore;
    float hostRatingScore;
    vector<Review> receivedReviews;
    // vector<Request> receivedRequests;
    vector<RegularMember *> blockedMembers;

public:
    // Constructor
    RegularMember(string username, string password, string phoneNumber, string email, Address homeAddress, string creditCardNumber, int cvcNumber, float balance, vector<string> skills) : User(username, password, "RegularMember"){};

    // Getters and Setters
    int getCreditPoints() { return creditPoints; };
    string getPhoneNumber() { return phoneNumber; };
    string getEmail() { return email; };
    Address getHomeAddress() { return homeAddress; };
    string getCreditCardNumber() { return creditCardNumber; };
    int getCvcNumber() { return cvcNumber; };
    float getBalance() { return balance; };
    vector<string> getSkills() { return skills; };
    float getSkillRatingScore() { return skillRatingScore; };
    float getSupporterRatingScore() { return supporterRatingScore; };
    float getHostRatingScore() { return hostRatingScore; };
    // vector<Review> getReceivedReviews() { return receivedReviews; };
    // vector<Request> getReceivedRequests() { return receivedRequests; };
    vector<RegularMember *> getBlockedMembers() { return blockedMembers; };

    void setCreditPoints(int creditPoints) { this->creditPoints = creditPoints; };
    void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; };
    void setEmail(string email) { this->email = email; };
    void setHomeAddress(Address homeAddress) { this->homeAddress = homeAddress; };
    void setCreditCardNumber(string creditCardNumber) { this->creditCardNumber = creditCardNumber; };
    void setCvcNumber(int cvcNumber) { this->cvcNumber = cvcNumber; };
    void setBalance(float balance) { this->balance = balance; };
    void setSkills(vector<string> skills) { this->skills = skills; };
    void setSkillRating(float skillRatingScore) { this->skillRatingScore = skillRatingScore; };
    void setSupporterRating(float supporterRatingScore) { this->supporterRatingScore = supporterRatingScore; };
    void setHostRating(float hostRatingScore) { this->hostRatingScore = hostRatingScore; };
    // void setReceivedReviews(vector<Review> receivedReviews) { this->receivedReviews = receivedReviews; };
    // void setReceivedRequests(vector<Request> receivedRequests) { this->receivedRequests = receivedRequests; };
    void setBlockedMembers(vector<RegularMember *> blockedMembers) { this->blockedMembers = blockedMembers; };

    // Member functions
    void printReceivedReviews();
    float getSkillRatingScore();
    float getSupporterRatingScore();
    float getHostRatingScore();
    bool payRegistrationFee();
    double calculateDistance(RegularMember &otherMember);
    void printMemberInfo();
    void printRestrictedMemberInfo();
    bool topUp(int credPoints);
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
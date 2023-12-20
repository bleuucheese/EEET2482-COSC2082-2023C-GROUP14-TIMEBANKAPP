#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Request.h"
#include "Review.h"
#include "Skill.h"

using std::string;
using std::vector;
class RegularMember : public User
{
private:
    int creditPoints = 20;
    string phoneNumber;
    string email;
    string homeAddress;
    enum allowedCities
    {
        Hanoi = 24,
        Saigon = 28
    } city; // Hanoi or Saigon only
    string creditCardNumber;
    float balance;
    float skillRatingScore;
    float supporterRatingScore;
    float hostRatingScore;
    vector<Skill *> skills;
    vector<SkillListing *> skillListings;
    vector<Review *> sentreceivedReviews;
    vector<Request *> sentreceivedRequests;
    vector<RegularMember *> blockedMembers;

public:
    // Constructor
    

    // Getters and Setters
    int getCreditPoints() { return creditPoints; };
    string getPhoneNumber() { return phoneNumber; };
    string getEmail() { return email; };
    string getCreditCardNumber() { return creditCardNumber; };

    float getBalance() { return balance; };
    float getSkillRatingScore() { return skillRatingScore; };
    float getSupporterRatingScore() { return supporterRatingScore; };
    float getHostRatingScore() { return hostRatingScore; };
    // vector<Review> getReceivedReviews() { return receivedReviews; };
    // vector<Request> getReceivedRequests() { return receivedRequests; };
    vector<RegularMember *> getBlockedMembers() { return blockedMembers; };

    void setCreditPoints(int creditPoints) { this->creditPoints = creditPoints; };
    void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; };
    void setEmail(string email) { this->email = email; };

    void setCreditCardNumber(string creditCardNumber) { this->creditCardNumber = creditCardNumber; };

    void setBalance(float balance) { this->balance = balance; };

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

    friend class Skill;
    friend class SkillListing;
    friend class Request;
    friend class Review;
    friend class Address;
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
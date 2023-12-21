#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include "../skill/Request.h"
#include "../skill/Review.h"
#include "../skill/Skill.h"
#include "User.h"

using std::string;
using std::vector;

class Skill;        // Forward declaration to avoid circular dependency
class SkillListing; // Forward declaration to avoid circular dependency
class Request;      // Forward declaration to avoid circular dependency
class Review;       // Forward declaration to avoid circular dependency
class RegularMember : public User
{
private:
    string fullName;
    int creditPoints = 20;
    string phoneNumber;
    string email;
    string homeAddress;
    enum allowedCities
    {
        Hanoi = 24,
        Saigon = 28
    } city; // Hanoi or Saigon only
    double latitude;
    double longitude;
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
    RegularMember(string username = "", string password = "", string fullName = "", string phoneNumber = "", string email = "", string homeAddress = "", allowedCities city = Hanoi, double latitude = 0, double longitude = 0, string creditCardNumber = "", float balance = 0);

    // Getters and Setters
    int getCreditPoints() { return creditPoints; };
    string getPhoneNumber() { return phoneNumber; };
    string getEmail() { return email; };
    string getCreditCardNumber() { return creditCardNumber; };

    float getBalance() { return balance; };

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
    void showInfo();
    void printRestrictedMemberInfo();
    bool topUp(int credPoints);

    friend class Skill;
    friend class SkillListing;
    friend class Request;
    friend class Review;
    friend class Address;
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_USER_REGULARMEMBER_H
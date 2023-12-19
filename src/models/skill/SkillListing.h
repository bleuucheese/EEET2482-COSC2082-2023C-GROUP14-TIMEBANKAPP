#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILLLISTING_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILLLISTING_H
#include <iostream>
#include <string>
#include "RegularMember.h"
using std::cin;
using std::cout;

class SkillListing
{
private:
    string skillPerformed;
    int consumedCredsPerHour = 0;
    int minHostRatingScore = -1;
    int listingState = 0; // 0 = available, 1 = booked, 2 = completed
    RegularMember *pOwner;

public:
    SkillListing(string skillPerformed = "", int consumedCreds = 0, int minHostRatingScore = -1, int listingState = 0, RegularMember *pOwner = nullptr){};

    // Getters
    string getSkillPerformed() { return this->skillPerformed; };
    int getConsumedCredsPerHour() { return this->consumedCredsPerHour; };
    int getMinHostRatingScore() { return this->minHostRatingScore; };
    int getListingState() { return this->listingState; };
    RegularMember *getPOwner() { return this->pOwner; };

    // Setters
    void setSkillPerformed(string skillPerformed) { this->skillPerformed = skillPerformed; };
    void setConsumedCredsPerHour(int consumedCreds) { this->consumedCredsPerHour = consumedCreds; };
    void setMinHostRatingScore(int minHostRatingScore) { this->minHostRatingScore = minHostRatingScore; };
    void setListingState(int listingState) { this->listingState = listingState; };
    void setPOwner(RegularMember *pOwner) { this->pOwner = pOwner; };

    // Methods
    void displaySkillListing(){};
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILLLISTING_H
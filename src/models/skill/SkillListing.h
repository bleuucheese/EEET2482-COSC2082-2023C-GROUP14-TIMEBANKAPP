#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILLLISTING_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILLLISTING_H
#include <iostream>
#include <string>
#include "RegularMember.h"
#include "Skill.h"
#include "myUtils.h"
using std::cin;
using std::cout;

class SkillListing
{
private:
    Skill *skillPerformed;
    string listingID; // Lxxxxxxxx
    int consumedCredsPerHour = 0;
    float minHostRatingScore = -1; // -1 = no minimum rating score, optional
    int listingState = 0; // 0 = available, 1 = hidden, 2 = booked, 3 = completed
    string supporterName; // username of the member who created the listing
    string hostName; // username of the member who booked the listing
    // TimePeriod workingTimeSlot; 

public:
    SkillListing(Skill *skillPerformed = nullptr, int consumedCreds = 0, float minHostRatingScore = -1, string supporterName = "", string hostName = "");

    // Getters
  
    int getConsumedCredsPerHour() { return this->consumedCredsPerHour; };
    int getMinHostRatingScore() { return this->minHostRatingScore; };
    int getListingState() { return this->listingState; };

    

    // Setters
    
    void setConsumedCredsPerHour(int consumedCreds) { this->consumedCredsPerHour = consumedCreds; };
    void setMinHostRatingScore(int minHostRatingScore) { this->minHostRatingScore = minHostRatingScore; };
    void setListingState(int listingState) { this->listingState = listingState; };
   

    // Methods
    void displaySkillListing(){};
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_SKILLLISTING_H
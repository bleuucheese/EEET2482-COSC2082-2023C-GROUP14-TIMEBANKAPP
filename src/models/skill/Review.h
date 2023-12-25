#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REVIEW_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REVIEW_H
#include <iostream>
#include <string>

#include "../../utils/time/DateTime.h"
#include "../user/RegularMember.h"
#include "../../utils/myUtils.h"

using std::cin;
using std::cout;
using std::string;

class Review
{
private:
    string reviewID = "";    // 8 digits long, generated by system, unique, starts with "RS" for review about supporters, "RH" for review about hosts
    string listingID;        // id of the listing that is being reviewed
    int skillRating = 0;     // 1-5, filled by hosts only
    int supporterRating = 0; // 1-5, filled by hosts only
    int hostRating = 0;      // 1-5, filled by supporters only

    std::string comments;
    string reviewer;    // username of the member who created the review
    string reviewee;    // username of the member who is being reviewed
    DateTime timestamp; // DD/MM/YYYY HH:MM:SS format, automatically generated by system

public:
    // Constructor for review by host
    Review(std::string reviewID, string listingID, int skillRating, int supporterRating, std::string comments, string reviewer, string reviewee, DateTime timestamp);

    // Constructor for review by supporter
    Review(std::string reviewID, string listingID, int hostRating, std::string comments, string reviewer, string reviewee, DateTime timestamp);

    void printReview();

    // Getters
    string getReviewID() const { return this->reviewID; }

    string getListingID() const { return this->listingID; }

    int getSkillRating() const { return this->skillRating; }

    int getSupporterRating() const { return this->supporterRating; }

    int getHostRating() const { return this->hostRating; }

    std::string getComments() const { return this->comments; }

    string getReviewer() const { return this->reviewer; }

    string getReviewee() const { return this->reviewee; }

    DateTime getTimestamp() const { return this->timestamp; }



    friend class TimeBankSystem;
    friend class FileHandler;
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REVIEW_H
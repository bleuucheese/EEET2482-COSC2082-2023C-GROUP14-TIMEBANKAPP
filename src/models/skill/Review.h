#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REVIEW_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REVIEW_H
#include <iostream>
#include <string>

#include "RegularMember.h"

using std::cin;
using std::cout;
class Review
{
private:
    int skillRating = 0;     // 1-5, filled by hosts only
    int supporterRating = 0; // 1-5, filled by hosts only
    int hostRating = 0;      // 1-5, filled by supporters only

    std::string comments;
    RegularMember *pReviewer = nullptr;
    RegularMember *pReviewee = nullptr;
    std::string timestamp; // DD/MM/YYYY HH:MM:SS format, change to type Calendar later
    int reviewType;        // 0: review by supporter, 1: review by host

public:
    string parseDate() {}
    // Constructor for review by host
    Review(int skillRating, int supporterRating, std::string comments, RegularMember *pReviewer, RegularMember *pReviewee){};

    // Constructor for review by supporter
    Review(int hostRating, std::string comments, RegularMember *pReviewer, RegularMember *pReviewee){};

    void printReview() {}

    int getSkillRating() { return this->skillRating; }

    int getSupporterRating() { return this->supporterRating; }

    int getHostRating() { return this->hostRating; }

    std::string getComments() { return this->comments; }
    
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REVIEW_H
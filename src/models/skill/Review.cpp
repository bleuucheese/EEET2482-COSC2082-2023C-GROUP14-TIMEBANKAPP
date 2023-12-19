#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include "Review.h"

using std::cin;
using std::cout;

// Constructor for review by host
Review::Review(int skillRatingScore, int supporterRatingScore, std::string comments, RegularMember *pReviewer, RegularMember *pReviewee)
{
    this->skillRating = skillRatingScore;
    this->supporterRating = supporterRatingScore;
    this->comments = comments;
    this->pReviewer = pReviewer;
    this->pReviewee = pReviewee;
    this->timestamp = parseDate();
    this->reviewType = 0;
}

// Constructor for review by supporter
Review::Review(int hostRatingScore, std::string comments, RegularMember *pReviewer, RegularMember *pReviewee)
{
    this->hostRating = hostRatingScore;
    this->comments = comments;
    this->pReviewer = pReviewer;
    this->pReviewee = pReviewee;
    this->timestamp = parseDate();
    this->reviewType = 1;
}

void Review::printReview()
{
    cout << pReviewer->getUsername() << " ~ posted on " << this->timestamp << "\n";
    if (this->skillRating != 0)
    {
        cout << "Skill Rating: " << this->skillRating << "\n";
        cout << "Supporter Rating: " << this->supporterRating << "\n";
    }
    else
    {
        cout << "Host Rating: " << this->hostRating << "\n";
    }
    cout << "Description: " << this->comments << "\n";
    cout << std::endl;
}

string Review::parseDate()
{
    // Get current system time
    std::time_t now = std::time(0);
    std::tm *localTime = std::localtime(&now);

    // Format the timestamp (assuming YYYY-MM-DD HH:MM:SS format)
    std::ostringstream timestampStream;
    timestampStream << (localTime->tm_year + 1900) << '-'
                    << (localTime->tm_mon + 1) << '-'
                    << localTime->tm_mday << ' '
                    << localTime->tm_hour << ':'
                    << localTime->tm_min << ':'
                    << localTime->tm_sec;
    return timestampStream.str();
}


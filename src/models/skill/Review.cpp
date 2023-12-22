#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include "Review.h"
#include "../../utils/myUtils.h"

using std::cin;
using std::cout;
using std::string;

// Constructor for review by host
Review::Review(string reviewID, string listingID, int skillRatingScore, int supporterRatingScore, std::string comments, string reviewer, string reviewee, DateTime timestamp)
{
    this->timestamp = timestamp;
    if (reviewID == "")
    {
        this->reviewID = "S" + generateRandomID();
    }
    else
    {
        this->reviewID = reviewID;
    }
    this->listingID = listingID;
    this->skillRating = skillRatingScore;
    this->supporterRating = supporterRatingScore;
    this->comments = comments;
    this->reviewer = reviewer;
    this->reviewee = reviewee;
}

// Constructor for review by supporter1
Review::Review(string reviewID, string listingID, int hostRatingScore, std::string comments, string reviewer, string reviewee, DateTime timestamp)
{
    this->timestamp = timestamp;
    if (reviewID == "")
    {
        this->reviewID = "H" + generateRandomID();
    }
    else
    {
        this->reviewID = reviewID;
    }
    this->hostRating = hostRatingScore;
    this->comments = comments;
    this->reviewer = reviewer;
    this->reviewee = reviewee;
}

void Review::printReview()
{
    cout << "Review ID: " << this->reviewID << "\n";
    cout << "Listing ID: " << this->listingID << "\n";
    cout << reviewer << " ~ posted on " << this->timestamp.getFormattedTimestamp() << "\n";

    cout << "\n";
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

// int main()
// {
//     Review review("L0000001", 5, 4, "Smart supporter", "user1", "user2");
//     Review review2("L0000001", 5, "Generous host", "user2", "user1");
//     review.printReview();
//     return 0;
// }
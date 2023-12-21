#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REQUEST_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REQUEST_H

#include <iostream>
#include <string>
#include "SkillListing.h"
#include "../user/RegularMember.h"

using std::string;

class SkillListing; // forward declaration
class Request
{

private:
    string requestID; // Rxxxxxxxx
    SkillListing *pSkillListing;
    std::string requestStatus = "Pending"; // Pending, Accepted, Rejected
    std::string requestTimeStamp;          // DD/MM/YYYY HH:MM:SS format, change to type Calendar later
    std::string requesterName;
    std::string receiverName;

public:
    Request();

    SkillListing *getPSkillListing();
    void setPSkillListing(SkillListing *pSkillListing);
    // getters and setters
    string getRequestID();
    void setRequestID(string requestID);
    string getRequestStatus();
    void setRequestStatus(string requestStatus);
    string getRequestTimeStamp();
    void setRequestTimeStamp(string requestTimeStamp);
    string getRequesterName();
    void setRequesterName(string requesterName);
    string getReceiverName();
    void setReceiverName(string receiverName);

    void showInfo();
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REQUEST_H
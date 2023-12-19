#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REQUEST_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REQUEST_H

#include <iostream>
#include <string>
#include "SkillListing.h"
#include "RegularMember.h"

enum requestState
{
    AVAILABLE,
    BOOKED,
    COMPLETED
};
class Request
{

private:
    SkillListing *pSkillListing;
    enum requestState requestState = AVAILABLE; // 0 = available, 1 = booked, 2 = completed
    RegularMember *pRequester;

public:
    Request();
    Request(SkillListing *pSkillListing, RegularMember *pRequester);
    SkillListing *getPSkillListing();
    void setPSkillListing(SkillListing *pSkillListing);
    enum requestState getRequestState();
    void setRequestState(enum requestState requestState);
    RegularMember *getPRequester();
    void setPRequester(RegularMember *pRequester);
    void printRequestInfo();
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_SKILL_REQUEST_H
#include <iostream>
#include "Request.h"
#include "../../utils/myUtils.h"
#include <string>
using std::cin;
using std::cout;
using std::string;

Request::Request()
{
    this->requestID = "R" + generateRandomID();
    this->requestStatus = "Pending";
    this->requesterName = "";
    this->receiverName = "";
    this->pSkillListing = nullptr;
}

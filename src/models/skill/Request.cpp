#include <iostream>
#include "Request.h"
#include "../../utils/myUtils.h"
#include <string>
using std::cin;
using std::cout;
using std::string;

Request::Request(string requestID, string listingID, std::string requesterName, std::string receiverName,DateTime requestTimeStamp, std::string requestStatus)
{
    if (requestID.empty())
    {
        this->requestID = "R" + generateRandomID();
    }
    else
    {
        this->requestID = requestID;
    }
    this->requestStatus = requestStatus;
    this->requesterName = "";
    this->receiverName = "";
    

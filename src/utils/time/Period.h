#ifndef EEEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_PERIOD_H
#define EEEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_PERIOD_H

#include <iostream>
#include <string>
#include "DateTime.h"
using std::cin;
using std::cout;

class Period
{

private:
    DateTime startDate;
    DateTime endDate;

public:
    Period(DateTime startDate = DateTime(), DateTime endDate = DateTime());
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_PERIOD_H
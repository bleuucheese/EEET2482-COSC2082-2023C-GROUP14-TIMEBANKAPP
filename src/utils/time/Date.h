#ifndef EEEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_DATE_H
#define EEEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_DATE_H

#include <string>

struct Date
{
    int day;
    int month;
    int year;
    Date();
    Date(int Day, int Month, int Year);
    bool isLeapYear(int year);

    int daysInMonth(int month, int year);

    Date addDays(Date date, int days);

    Date addTimePeriod(Date startDate, int days, int hours, int minutes, int seconds);

    Date parseDate(std::string str);

    std::string formatDate(Date date);

    std::string calculateEndDate(int days, int hours, int minutes, int seconds);
};

#endif // EEET2482_COSC2082_UTILS_TIME_DATE_HEEEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_DATE_H

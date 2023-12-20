#ifndef EEEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_DATETIME_H
#define EEEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_DATETIME_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
#include <chrono>

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

class DateTime
{
private:
    std::tm tm;

    bool isValidFormat(const std::string &timestamp)
    {
        // Format should be "dd/mm/yyyy hh:mm:ss"
        std::istringstream ss(timestamp);
        ss >> std::get_time(&tm, "%d/%m/%Y %H:%M:%S");
        return !ss.fail() && ss.eof();
    }

    bool isValidDate()
    {
        // Check if the parsed date is valid
        std::tm copy = tm;
        copy.tm_isdst = -1; // Not considering daylight saving time

        std::time_t tt = std::mktime(&copy);
        if (tt == -1)
        {
            return false; // mktime returns -1 for invalid date
        }

        // Ensure that the normalized date matches the original date
        std::tm *ptm = std::localtime(&tt);
        return ptm && ptm->tm_mday == tm.tm_mday &&
               ptm->tm_mon == tm.tm_mon && ptm->tm_year == tm.tm_year;
    }

public:
    // Default constructor sets to current system time
    DateTime()
    {
        std::time_t current_time = std::time(nullptr);
        tm = *std::localtime(&current_time);
    }

    // Constructor that takes a timestamp string
    DateTime(const std::string &timestamp)
    {
        if (!isValidFormat(timestamp))
        {
            throw std::invalid_argument("Invalid date format");
        }

        // Set initial values
        std::istringstream ss(timestamp);
        ss >> std::get_time(&tm, "%d/%m/%Y %H:%M:%S");

        if (!isValidDate())
        {
            throw std::invalid_argument("Invalid date value");
        }
    }

    // Getters for individual components
    int getDay() const { return tm.tm_mday; }
    int getMonth() const { return tm.tm_mon + 1; }    // tm_mon is 0-11
    int getYear() const { return tm.tm_year + 1900; } // tm_year is years since 1900
    int getHour() const { return tm.tm_hour; }
    int getMinute() const { return tm.tm_min; }
    int getSecond() const { return tm.tm_sec; }

    std::time_t toTimeT() const
    {
        return std::mktime(const_cast<std::tm *>(&tm));
    }

    std::string getFormattedTimestamp() const
    {
        std::ostringstream oss;
        oss << std::put_time(&tm, "%d/%m/%Y %H:%M:%S");
        return oss.str();
    }
};
#endif // EEET2482_COSC2082_UTILS_TIME_DATE_HEEEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_UTILS_TIME_DATETIME_H

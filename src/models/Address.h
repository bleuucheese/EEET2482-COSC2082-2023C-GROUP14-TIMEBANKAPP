#ifndef EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_ADDRESS_H
#define EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_ADDRESS_H

#include <iostream>
#include <string>

using std::string;

struct Address
{
private:
    string street;
    string city;
    double latitude;
    double longitude;

public:
    // Constructor
    Address(string street = "", string city = "", double latitude = 0, double longitude = 0)
    {
        this->street = street;
        this->city = city;
        this->latitude = latitude;
        this->longitude = longitude;
    }

    // Getters and Setters
    string getStreet()
    {
        return this->street;
    }

    string getCity()
    {
        return this->city;
    }

    double getLatitude()
    {
        return this->latitude;
    }

    double getLongitude()
    {
        return this->longitude;
    }

    void setStreet(string street)
    {
        this->street = street;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    void setLatitude(double latitude)
    {
        this->latitude = latitude;
    }
    void setLongitude(double longitude)
    {
        this->longitude = longitude;
    }
};

#endif // EEET2482_COSC2082_2023C_GROUP14_TIMEBANKAPP_SRC_MODELS_ADDRESS_H
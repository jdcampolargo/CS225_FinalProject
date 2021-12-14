#pragma once
#include <iostream>
#include <string>

class Airport {
    public:
        Airport();
        Airport(std::string Name,std::string City, std::string Country, std::string AirportCode, std::string Latitude, std::string Longitude, std::string Altitude);
        std::string name_;
        std::string city_;
        std::string country_;
        std::string airportCode_;
        std::string latitude_;
        std::string longitude_;
        std::string altitude_;

};
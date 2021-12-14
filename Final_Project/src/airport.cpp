#include "include/airport.h"

Airport::Airport(){}

Airport::Airport(std::string Name,std::string City, std::string Country, std::string AirportCode, std::string Latitude, std::string Longitude, std::string Altitude) {
  name_ = Name;
  city_ = City;
  country_ = Country;
  airportCode_ = AirportCode;
  latitude_ = Latitude;
  longitude_ = Longitude;
  altitude_ = Altitude;
}

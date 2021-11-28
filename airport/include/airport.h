#include <iostream>
#include <string>

class Airport {
    public:
        Airport();
        //Airport(std::string Name,std::string City, std::string Country, float Latitude, float Longitude, float Altitude);
        //~Airport();
        int getNum();
    private:
        int num = 0;
};
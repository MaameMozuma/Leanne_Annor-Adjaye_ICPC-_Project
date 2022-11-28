/**
 * @author Leanne Annor-Adjaye
 * */

#include <string>
using namespace std;

#ifndef LEANNE_ANNOR_ADJAYE_ICP_PROJECT_AIRPORT_H
#define LEANNE_ANNOR_ADJAYE_ICP_PROJECT_AIRPORT_H


class Airport{
    private:
        int Airport_ID;
        string Name;
        string City;
        string Country;
        string IATA_Code;
        string ICAO_Code;
        float Latitude;
        float Longitude;
        int Altitude;
        float Timezone;
        string DST;
        string Tz_database_time_zone;
        string Type;
        string Source;

    public:
        Airport(int Airport_ID,
                string Name,
                string City,
                string Country,
                string IATA_Code,
                string ICAO_Code,
                float Latitude,
                float Longitude,
                int Altitude,
                float Timezone,
                string DST,
                string Tz_database_time_zone,
                string Type,
                string Source);

        const string &getCity() const; //getting city the airport is in
        const string &getCountry() const; //getting the country the airport is in
        const string &getIataCode() const; //getting the IATA code of the airport

        bool operator==(const Airport &rhs) const;
        bool operator<(const Airport &rhs) const;

        string toString();

};


#endif //LEANNE_ANNOR_ADJAYE_ICP_PROJECT_AIRPORT_H

/**
 * @author Leanne Annor-Adjaye
 * */

#include "Airport.h"

#include <utility>

using namespace std;

/**This is the constructor for the Airport class. It initialises the private variables of the class.
 * @param airport_ID
 * @param name
 * @param city
 * @param country
 * @param IATA_Code
 * @param ICAO_Code
 * @param latitude
 * @param longitude
 * @param altitude
 * @param timezone
 * @param DST
 * @param tz_database_time_zone
 * @param type
 * @param source
 * */
Airport::Airport(int Airport_ID,
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
                 string Source){
    this->Airport_ID = Airport_ID;
    this->Name = std::move(Name);
    this->City = std::move(City);
    this->Country = std::move(Country);
    this->IATA_Code = std::move(IATA_Code);
    this->ICAO_Code = std::move(ICAO_Code);
    this->Latitude = Latitude;
    this->Longitude = Longitude;
    this->Altitude = Altitude;
    this->Timezone = Timezone;
    this->DST = std::move(DST);
    this->Tz_database_time_zone = std::move(Tz_database_time_zone);
    this->Type = std::move(Type);
    this->Source = std::move(Source);
}

/**This is an overloading of the == operator.
 * It is comparing the Airport_ID of the current object to the Airport_ID of the object passed in as a parameter.
 *@param rhs
 * @return bool
 * */
bool Airport::operator==(const Airport &rhs) const{
    return Airport_ID == rhs.Airport_ID;
}

/**The toString() method returns a string representation of the airport object
 * @return The toString method is being returned.
 */
string Airport::toString() {
    return  "Airport_ID: " + to_string(Airport_ID) + " Name: " + Name + " City: " + City
            + " Country: " + Country + " IATA_Code: " + IATA_Code + " ICAO_Code: "
            + ICAO_Code + " Latitude: " + to_string(Latitude) + " Longitude: " + to_string(Longitude)
            + " Altitude: " + to_string(Altitude) + " Timezone: " + to_string(Timezone) + " DST: " + DST
            + " Tz_database_time_zone: " + Tz_database_time_zone + " Type: " + Type + " Source: "
            + Source + "\n";
}

/**This is an overloading of the < operator.
 * It is comparing the Airport_ID of the current object to the Airport_ID of the object passed in as a parameter.
 * @param rhs
 * @return bool
 */
bool Airport:: operator<(const Airport &rhs) const {
    return Airport_ID < rhs.Airport_ID;
}

const string &Airport :: getCity() const {return City;}
const string &Airport :: getCountry() const {return Country;}
const string &Airport :: getIataCode() const {return IATA_Code;}

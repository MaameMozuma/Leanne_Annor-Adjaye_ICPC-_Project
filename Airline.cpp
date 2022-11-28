/**
 * @author Leanne Annor-Adjaye
 * */

#include "Airline.h"

#include <utility>

/**This is the constructor for the airline class. It is called when an object of the class is created.
 * @param Airline_ID
 * @param Name
 * @param Alias
 * @param IATA_Code
 * @param ICAO_Code
 * @param Callsign
 * @param Country
 * @param Active
 */
Airline::Airline(int Airline_ID,
                 string Name,
                 string Alias,
                 string IATA_Code,
                 string ICAO_Code,
                 string Callsign,
                 string Country,
                 string Active){
    this->Airline_ID = Airline_ID;
    this->Name = std::move(Name);
    this->Alias = std::move(Alias);
    this->IATA_Code = std::move(IATA_Code);
    this->ICAO_Code = std::move(ICAO_Code);
    this->Callsign = std::move(Callsign);
    this->Country = std::move(Country);
    this->Active = std::move(Active);
}

/**This is a method that returns a string representation of the airline object.
 * @return The toString method is being returned.
 */
string Airline::toString() {
    return "Airline_ID: " + to_string(Airline_ID) + ", Name: " + Name + ", Alias: " + Alias
           + ", IATA_Code: " + IATA_Code + ", ICAO_Code: " + ICAO_Code + ", Callsign: "
           + Callsign + ", Country: " + Country + ", Active: " + Active + "\n";
}

/**
 * @author Leanne Annor-Adjaye
 * */

#ifndef LEANNE_ANNOR_ADJAYE_ICP_PROJECT_AIRLINE_H
#define LEANNE_ANNOR_ADJAYE_ICP_PROJECT_AIRLINE_H

#include <string>

using namespace std;

class Airline{
    private:
        int Airline_ID;
        string Name;
        string Alias;
        string IATA_Code;
        string ICAO_Code;
        string Callsign;
        string Country;
        string Active;
    public:
        Airline(int Airline_ID,
                string Name,
                string Alias,
                string IATA_Code,
                string ICAO_Code,
                string Callsign,
                string Country,
                string Active);

        string toString();

};

#endif //LEANNE_ANNOR_ADJAYE_ICP_PROJECT_AIRLINE_H

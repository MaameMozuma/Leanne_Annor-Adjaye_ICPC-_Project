/**
 * @author Leanne Annor-Adjaye
 * */

#ifndef LEANNE_ANNOR_ADJAYE_ICP_PROJECT_ROUTE_H
#define LEANNE_ANNOR_ADJAYE_ICP_PROJECT_ROUTE_H

#include <string>

using namespace std;

class Route{
    private:
        string Airline_Code;
        string Airline_ID;
        string Source_Airport_Code;
        string Source_Airport_ID;
        string Destination_Airport_Code;
        string Destination_Airport_ID;
        string Codeshare;
        string Stops;
        string Equipment;


    public:
        Route();
        Route(string Airline_Code,
              string Airline_ID,
              string Source_Airport_Code,
              string Source_Airport_ID,
              string Destination_Airport_Code,
              string Destination_Airport_ID,
              string Codeshare,
              string Stops,
              string Equipment);

        const string &getAirlineCode() const;
        const string &getSourceAirportCode() const;
        const string &getDestinationAirportCode() const;
        const string &getStops() const;
        bool operator==(const Route &rhs) const;
        bool operator<(const Route &rhs) const;
        string toString();

};


#endif //LEANNE_ANNOR_ADJAYE_ICP_PROJECT_ROUTE_H

/**
 * @author Leanne Annor-Adjaye
 * */

#ifndef LEANNE_ANNOR_ADJAYE_ICP_PROJECT_DATA_READER_H
#define LEANNE_ANNOR_ADJAYE_ICP_PROJECT_DATA_READER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <list>
#include <exception>
#include <sstream>
#include "Airport.h"
#include "Airline.h"
#include "Route.h"
#include "helper.h"

using namespace std;

class DataReader{

    private:
        //declaring member variables
        string Input_file;
        string Airport_file;
        string Airline_file;
        string Route_file;
        fstream inputStream;
        string line;

        vector<string> details_from_line;
        unordered_map<int, Airline> Airline_dictionary;
        list<string> Source_Destination_List;
        unordered_map<string, list<Airport>> Airport_dictionary;
        unordered_map<string, list<Route>> Route_dictionary;
        unordered_map<string, Airport> IATA_dictionary;


    public:
        //declaring and defining methods
        DataReader(const string& Input_file,
                   const string& Airport_file,
                   const string& Airline_file,
                   const string& Route_file);

        DataReader(const string& Input_file);

        DataReader();

        void ReadAirportFile(const string& file_name);
        void ReadAirlineFile(const string& file_name);
        void ReadRouteFile(const string& file_name);
        void ReadInputFile(const string& file_name);

        unordered_map<string, list<Airport>> getAirportDictionary()  {return Airport_dictionary;}
        unordered_map<string, list<Route>> getRouteDictionary()  {return Route_dictionary;}
        unordered_map<string, Airport> getiataDictionary() const {return IATA_dictionary;}
        list<string> getSourceDestinationList() const {return Source_Destination_List;}
};


#endif //LEANNE_ANNOR_ADJAYE_ICP_PROJECT_DATA_READER_H

/**
 * @author Leanne Annor-Adjaye
 * */

#include "data_reader.h"


/**A constructor for the DataReader class. It initializes the member variables of the class.
 * It also reads the files inputted
 * @param Input_file
 * @param Airport_file
 * @param Airline_file
 * @param Route_file
 */
DataReader::DataReader(const string& Input_file,
                       const string& Airport_file,
                       const string& Airline_file,
                       const string& Route_file){
    this->Input_file = Input_file;
    this->Airport_file = Airport_file;
    this->Airline_file = Airline_file;
    this->Route_file = Route_file;

    ReadAirportFile(Airport_file);
    ReadAirlineFile(Airline_file);
    ReadRouteFile(Route_file);
    ReadInputFile(Input_file);

}

/**A constructor for the DataReader class. It initializes the member variables of the class.
 * It also reads the files inputted
 * @param Input_file
 */
DataReader::DataReader(const string& Input_file){
    this->Input_file = Input_file;
    this->Airport_file = R"(C:\Users\DELL\OneDrive - Ashesi University\Desktop\Ashesi University Files\Ashesi university Year 2, Sem 2\ICP\Leanne_Annor-Adjaye_ICP_Project\airports.csv)";
    this->Airline_file = R"(C:\Users\DELL\OneDrive - Ashesi University\Desktop\Ashesi University Files\Ashesi university Year 2, Sem 2\ICP\Leanne_Annor-Adjaye_ICP_Project\airlines.csv)";
    this->Route_file = R"(C:\Users\DELL\OneDrive - Ashesi University\Desktop\Ashesi University Files\Ashesi university Year 2, Sem 2\ICP\Leanne_Annor-Adjaye_ICP_Project\routes.csv)";

    ReadAirportFile(Airport_file);
    ReadAirlineFile(Airline_file);
    ReadRouteFile(Route_file);
    ReadInputFile(Input_file);

}

/** This is a default constructor for the DataReader class
 * */
DataReader::DataReader() {};


/**Reading the airport file and storing the data in the airport dictionary.
 * @param file_name
 * @return
 */
void DataReader:: ReadAirportFile(const string& file_name){
    inputStream.open(file_name, ios::in); //creating a file object

    if (!inputStream){ //checking if the file is a valid file
        cout <<  "INVALID FILE PATH \n";
        exit(-1);
    }

    //this is reading the airport file and storing the data in the airport dictionary.
    while (getline(inputStream, line)) {
        details_from_line = split_function(line,','); //splitting each line so long as we have not reached the end of the file
        if (details_from_line.size() == 14 and details_from_line[9] !="\\N") { //taking only lines that have exactly fourteen columns
            Airport airport(stoi(details_from_line[0]), details_from_line[1], details_from_line[2],
                            details_from_line[3], details_from_line[4], details_from_line[5],
                            stod(details_from_line[6]),
                            stod(details_from_line[7]), stoi(details_from_line[8]), stod(details_from_line[9]),
                            details_from_line[10],
                            details_from_line[11], details_from_line[12], details_from_line[13]);

            //combining the city and country to use that as the key for the Airport_dictionary
            string city_and_country = details_from_line[2] + " " + details_from_line[3];

            string iata_code = details_from_line[4];

            //checking if the current airport object has an iata code and inserting
            //it into the IATA_dictionary if it has one
            if (iata_code != "\\N") {
                IATA_dictionary.insert({iata_code, airport});
            }


            /*This is checking if the airport dictionary already has a key that is the same as the current airport's city and country.
            If it does, then it adds the current airport to the list of airports that is associated with that key.
            If it does not, then it creates a new list of airports and adds the current airport to that list.
            It then inserts the new list into the airport dictionary with the city and country as the key.
            */
            if (Airport_dictionary.count(city_and_country) > 0) {
                Airport_dictionary.at(city_and_country).push_back(airport);
            } else {
                list <Airport> Airport_Collection;
                Airport_Collection.push_back(airport);
                Airport_dictionary.insert({city_and_country, Airport_Collection});
            }

        }
    }
    IATA_dictionary.reserve(IATA_dictionary.size()); //resizing the IATA_dictionary
    Airport_dictionary.reserve(Airport_dictionary.size());   //resizing the Airport_dictionary
    inputStream.close();
}

/**This function is reading the airline file and storing the data in the airline dictionary.
 * @param file_name
 */
void DataReader::ReadAirlineFile(const string& file_name){
    inputStream.open(file_name, ios::in); //creating a file object

    if (!inputStream){ //checking if the file is a valid file
        cout <<  "INVALID FILE PATH \n";
        exit(-1);
    }

    //this is reading the airline file and storing the data in the airline dictionary.
    while(getline(inputStream, line))  {
        details_from_line = split_function(line,','); //splitting each line so long as we have not reached the end of the file
        if (details_from_line.size() == 8){   //taking only lines that have exactly eight columns
            Airline airline(stoi(details_from_line[0]), details_from_line[1], details_from_line[2], details_from_line[3],
                            details_from_line[4], details_from_line[5], details_from_line[6], details_from_line[7]);

            Airline_dictionary.insert({stoi(details_from_line[0]), airline});
        }
    }
    Airline_dictionary.reserve(5); // resizing the Airline_dictionary
    inputStream.close();
}


/**This function is reading the route file and storing the data in the route dictionary.
 * @param file_name
 */
void DataReader::ReadRouteFile(const string& file_name) {
    inputStream.open(file_name, ios::in); //creating a file object

    if (!inputStream){ //checking if the file is a valid file
        cout <<  "INVALID FILE PATH \n";
        exit(-1);
    }

    //this is reading the route file and storing the data in the route dictionary.
    while(getline(inputStream, line))  {
        details_from_line = split_function(line,','); //splitting each line so long as we have not reached the end of the file
        if (details_from_line.size() == 9){  //taking only lines that have exactly nine columns
            Route route(details_from_line[0], details_from_line[1], details_from_line[2],
                        details_from_line[3], details_from_line[4],
                        details_from_line[5], details_from_line[6], details_from_line[7], details_from_line[8]);


            /*This is checking if the route dictionary already has a key that is the same as the current route's source airport code.
            If it does, then it adds the current route to the list of routes that is associated with that key.
            If it does not, then it creates a new list of routes and adds the current route to that list.
            It then inserts the new list into the route dictionary with the source airport code as the key.
             */
            if (Route_dictionary.count(details_from_line[2]) > 0) {
                Route_dictionary.at(details_from_line[2]).push_back(route);
            } else {
                list <Route> Route_Collection;
                Route_Collection.push_back(route);
                Route_dictionary.insert({details_from_line[2], Route_Collection});
            }
        }
    }
    Route_dictionary.reserve(Route_dictionary.size()); //resizing the route dictionary
    inputStream.close();
}

/**This function is reading the input file and storing the data in the Source_Destination_List.
 * @param file_name
 */
void DataReader::ReadInputFile(const string& file_name){
    inputStream.open(file_name, ios::in); //creating a file object
    int position;

    if (!inputStream){ //checking if the file is a valid file
        cout <<  "INVALID FILE PATH \n";
        exit(-1);
    }

    /* Reading the input file and storing the data in the Source_Destination_List. */
    while(getline(inputStream, line))  {
        details_from_line = split_function(line,',');

        Source_Destination_List.push_back(details_from_line[0]);

        /* Removing the white spaces from the destination airport. */

        position = details_from_line[1].find_first_not_of(" ");
        Source_Destination_List.push_back(details_from_line[1].substr(position, details_from_line[1].length()));
    }
    inputStream.close();
}

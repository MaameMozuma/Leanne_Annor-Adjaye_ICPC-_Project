/**
 * @author Leanne Annor-Adjaye
 * */

#include "breadth_first_search.h"
#include <string>
#include <list>
#include <queue>
#include <iostream>



/**
 * This constructor takes in a file name and reads the source and destination cities and countries from the file
 * @param file_name The name of the file that contains the data.
 */
breadth_first_search::breadth_first_search(std::string file_name) {
    this->input_file_name = file_name;

    this->datareader = DataReader(file_name);

    list <string> data = datareader.getSourceDestinationList();

    this->source_city_name = data.front();
    data.pop_front();
    this->source_country_name = data.front();
    data.pop_front();
    this->destination_city_name = data.front();
    data.pop_front();
    this->destination_country_name = data.front();

}

/**Returning a list of routes that are available from the iata code that is passed in.
 * @param iata_code
 * @return list actions_list
 */
list<Route> breadth_first_search::actions(const string& iata_code) {
    list<Route> actions_list;

    /*This is checking if the iata code is in the route dictionary.
    If it is, it returns the list of routes that are available from that iata code.
    If it is not, it prints out "No route was found".
     */
    if (datareader.getRouteDictionary().count(iata_code) > 0){
        actions_list = datareader.getRouteDictionary().at(iata_code);
    }
    else{
        cout<< "No route was found" << endl;
    }
    return actions_list;
}

bool breadth_first_search:: breadth_first(){
    //declaring variables
    //list <Node> explored_nodes;
    queue<Node> Frontier;
    list<Route> actions_available;
    list<Node>keys;


    cout << "About to do a BFS on the problem..." << endl;

    list<Node> starting_airports_available = getStartingAirports(); //getting the airports at the start city and country


    /*This is checking if the starting airport is the destination airport.
    If it is, it prints out "You're there!" and returns true.
    If it is not, it pushes the starting airport into the frontier.
    */
    for (const Node& airport : starting_airports_available){
        if (goal_test(airport.getChild()) != 0){
            cout << "You're there!" << endl;
            return true;
        }
        else {
            Frontier.push(airport);
        }
    }

    while (!Frontier.empty()){

        Node popped_iata_code = Frontier.front(); //popping a node from the frontier
        Frontier.pop();
        explored_nodes.push_back(popped_iata_code);  //adding the popped node to the explored set

        actions_available = actions(popped_iata_code.getChild()); //getting the actions of the popped node

        /* This is checking if the destination airport code is in the iata dictionary.
        * If it is, it gets the airport object and creates a node object.
        * It then checks if the airport is in the explored nodes and the frontier.
        * If it is not, it checks if the airport is the destination airport.
        * If it is, it prints out "Found a solution!", prints the path and returns true.
        * If it is not, it pushes the airport into the frontier.
        */
        for (const Route& route: actions_available){
            if (datareader.getiataDictionary().count(route.getDestinationAirportCode()) > 0){
                Airport airport = datareader.getiataDictionary().at(route.getDestinationAirportCode());
                Node child (airport.getIataCode(), popped_iata_code.getChild(), route.getAirlineCode(), route.getStops());
                if (!(contains_in_list(explored_nodes, airport.getIataCode())) and !find_object(Frontier, airport.getIataCode())){
                    if (goal_test(airport.getIataCode()) == 1 ){
                        cout << "Found a solution!" << endl;
                        print_path(child);
                        return true;
                    }
                    Frontier.push(child);
                }
            }
        }
    }
    cout << "We could not find a valid path. Try again!" << endl;
    return false;
}


/**Getting the starting airports from the airport dictionary.
 * @return list valid_airports_with_iatacode
 */
list<Node> breadth_first_search::getStartingAirports() {
    string iata_code;
    list <Node> valid_airports_with_iatacode;
    list<Airport> starting_airports;
    source_city_country = source_city_name + " " + source_country_name;

    //checking if the start city and country exists in our dictionary and returning
    //the corresponding list value if it exists
    if (datareader.getAirportDictionary().find(source_city_country) != datareader.getAirportDictionary().end()){
        starting_airports = datareader.getAirportDictionary().at(source_city_country);
    }
    else {
        cout << "Sorry, no city and country exists with the starting point given." << endl;
        exit(-1);
    }

    /*This is checking if the iata code is not equal to "\\N".
     * If it is not, it gets the iata code, creates a node out of it
     * and pushes it into the list of valid_airports_with_iatacode.
     */

    for (const Airport& airport : starting_airports){
        if (airport.getIataCode() != "\\N")
            iata_code = airport.getIataCode();
        valid_airports_with_iatacode.emplace_back(iata_code, " ", " ", "0");
    }
    return valid_airports_with_iatacode;
}

/**This is checking if the current airport's city and country is the same as the destination city and country.
 * @param airport_code
 * @return int 0 or 1
 */
int breadth_first_search::goal_test(const string& airport_code) {
    Airport test_airport = datareader.getiataDictionary().at(airport_code);
    const string& matched_city = test_airport.getCity();
    const string& matched_country = test_airport.getCountry();
    if (matched_city == destination_city_name and matched_country == destination_country_name){
        return 1;
    }
    return 0;
}

/**Getting the valid route from the path dictionary.
 * @param dest
 * @return node children
 */
Node breadth_first_search:: get_valid_route(const Node& dest) {
    Node empty_node(" ", "0", " ", " ");
    for (Node n: explored_nodes){
        if (n.getChild() == dest.getParent())
            return n;
    }
    return empty_node;
}

/**This is printing the path to a file.
 * @param destination
 */
void breadth_first_search::print_path(Node destination) {
    //declaring and defining variables
    string file_name;
    fstream outputStream;
    list <Node> actions;
    int count = 1;
    int total_num_stops = 0;

    file_name = split_function(input_file_name, '.').front();

    //creating a file name
    file_name = file_name + string("_output.txt");

    actions.push_front(destination);

    /*This is getting the valid route from the path dictionary.
     */
    while (destination.getParent() != " ") { //checking if the current node is not the source node
        Node node = get_valid_route(destination);
        if (node.getChild() != " ") {
            actions.push_front(node);
            destination = node;
        }
    }


    outputStream.open(file_name, ios::out);

    if (outputStream.is_open()) { //printing the path to the file whilst the file is a valid file
        //This is printing the path to a file.
        for (const Node& fin_nodes: actions) {
            if (fin_nodes.getParent() != " ") {
                outputStream << count << ". " << fin_nodes.getAirlineCode() << " from " << fin_nodes.getParent() << " to "
                             << fin_nodes.getChild()  << " " << fin_nodes.getNumOfStops() << " stops" << endl;
                total_num_stops += stoi(fin_nodes.getNumOfStops());
                count++;
            }
        }
        outputStream << "Total flights: " << actions.size() - 1 << endl;
        outputStream << "Total additional stops: " << total_num_stops << endl;
        outputStream << "Optimality Criteria: flights" << endl;
    }
}

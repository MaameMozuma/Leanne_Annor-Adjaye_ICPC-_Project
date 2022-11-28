/**
 * @author Leanne Annor-Adjaye
*/

#ifndef LEANNE_ANNOR_ADJAYE_ICP_PROJECT_BREADTH_FIRST_SEARCH_H
#define LEANNE_ANNOR_ADJAYE_ICP_PROJECT_BREADTH_FIRST_SEARCH_H

#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include "data_reader.h"
#include <vector>
#include "Node.h"
#include <algorithm>

using namespace std;

class breadth_first_search{
    private:
        string source_city_name;
        string source_country_name;
        string destination_city_name;
        string destination_country_name;
        string source_city_country;
        string input_file_name;
        DataReader datareader;
        list <Node> explored_nodes;

    public:
        breadth_first_search(string input_file_name);

        list<Node> getStartingAirports();
        bool breadth_first();
        int goal_test(const string& airport_code);
        Node get_valid_route(const Node& dest);
        void print_path(Node destination);
        list<Route> actions(const string& iata_code);
};


#endif //LEANNE_ANNOR_ADJAYE_ICP_PROJECT_BREADTH_FIRST_SEARCH_H


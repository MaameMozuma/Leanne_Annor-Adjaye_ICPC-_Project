/**
 * @author Leanne Annor-Adjaye
 * */

#ifndef LEANNE_ANNOR_ADJAYE_ICP_PROJECT_NODE_H
#define LEANNE_ANNOR_ADJAYE_ICP_PROJECT_NODE_H

#include <string>

using namespace std;

class Node {

    private:
        string child;
        string parent;
        string airline_code;
        string num_of_stops;


    public:
        Node(string child, string parent, string airline_code, string num_of_stops);

        Node(const Node &t){
            child = t.child;
            parent = t.parent;
            airline_code = t.airline_code;
            num_of_stops = t.num_of_stops;
        }

        const string &getChild() const;
        const string &getParent() const;
        const string &getAirlineCode() const;
        const string &getNumOfStops() const;

        bool operator==(const Node &rhs) const;
        bool operator<(const Node &rhs) const;

};

#endif //LEANNE_ANNOR_ADJAYE_ICP_PROJECT_NODE_H

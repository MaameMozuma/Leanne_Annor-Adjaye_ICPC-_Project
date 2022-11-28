/**
 * @author Leanne Annor-Adjaye
 * */

#include "Node.h"

#include <utility>

/**This is a constructor for the node class. It is initializing the values of the class.
 * @param child
 * @param parent
 * @param airline_code
 * @param num_of_stops
 */
Node::Node(string child, string parent, string airline_code, string num_of_stops) {
    this->child = std::move(child);
    this->parent = std::move(parent);
    this->airline_code = std::move(airline_code);
    this->num_of_stops = std::move(num_of_stops);
}

/**This is an operator overload for the == operator.
 *It is comparing the child of the current object to the child of the object passed in.
 */
bool Node::operator==(const Node &rhs) const {
    return child == rhs.child;
}

/**This is an operator overload for the < operator.
 *It is comparing the child of the current object to the child of the object passed in.
 */
bool Node::operator<(const Node &rhs) const {
    return child < rhs.child;
}

const string &Node::getChild() const {return child;}
const string &Node::getParent() const {return parent;}
const string &Node::getAirlineCode() const {return airline_code;}
const string &Node::getNumOfStops() const {return num_of_stops;}



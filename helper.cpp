/**
 * @author Leanne Annor-Adjaye
 * */

#include "helper.h"

/**
 * It takes a string and a delimeter as input and returns a vector of strings
 * @param str The string to be split
 * @param delimeter The character that separates the values in the string.
 * @return A vector of strings
 */
vector<string> split_function(std::string str, char delimeter) {
    vector<string> details_in_line;
    int len = str.length();
    for(int i=0;i< len ;i++)
    {
        int j=i;
        while(str[i] != delimeter && i<len)
            i++;
        string temp=str.substr(j,i-j);
        details_in_line.push_back(temp);
    }
    return details_in_line;
}

/**
 * This function takes in a queue of type Node and a string and returns a boolean value
 * @param queue_structure the queue that you want to search through
 * @param queue_type the type of queue you want to search through
 * @return A boolean value.
 */
bool find_object(queue<Node> queue_structure, std::string queue_type) {
    while (!queue_structure.empty()){
        if (queue_structure.front().getChild() == queue_type){
            return true;
        }
        else{
            queue_structure.pop();
        }
    }
    return false;
}

/**
 * This function takes in a list of nodes and a string and returns true
 * if the string is in the list of nodes and false if otherwise
 * @param list_structure the list of nodes that we are searching through
 * @param code the code of the node we want to check if it's in the list
 * @return A boolean value.
 */
bool contains_in_list(list<Node> list_structure, std::string code) {
    while (!list_structure.empty()){
        if (list_structure.front().getChild() == code){
            return true;
        }
        else{
            list_structure.pop_front();
        }
    }
    return false;
}


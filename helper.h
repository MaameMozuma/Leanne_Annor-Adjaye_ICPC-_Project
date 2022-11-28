/**
 * @author Leanne Annor-Adjaye
 * */

#ifndef LEANNE_ANNOR_ADJAYE_ICP_PROJECT_HELPER_H
#define LEANNE_ANNOR_ADJAYE_ICP_PROJECT_HELPER_H

#include <vector>
#include <string>
#include <queue>
#include "Node.h"
#include <list>


vector<string> split_function(string str,char delimeter);
bool find_object(queue<Node> queue_structure, string queue_type);
bool contains_in_list(list<Node> list_structure, string code);


#endif //LEANNE_ANNOR_ADJAYE_ICP_PROJECT_HELPER_H

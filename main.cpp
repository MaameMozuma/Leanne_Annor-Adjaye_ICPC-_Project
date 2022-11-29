#include "breadth_first_search.h"

using namespace std;

int main(){
    //creating an instance of the breadth-first search class
    breadth_first_search bfs("accra-rio de janeiro.txt");

    bfs.breadth_first(); //calling bfs
    return 0;
}


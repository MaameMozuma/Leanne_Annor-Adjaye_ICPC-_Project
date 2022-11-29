# Leanne_Annor-Adjaye_ICPC-_Project

## ICP C++ Individual Project

NB: Kindly look at Leanne_Annor-Adjaye_ICPC-_Project to see all files that were created. It includes the reflection document, csv files, c++ files and .txt files.
To run test cases:
- create your .txt file and make sure it is in the Testing directory under CMakeFiles
- make sure your text file has content inside. To enter a destination, follow this format: 
  - for your source location, you can do: Accra, Ghana on the first line
  - for your destination location, you can do: Istanbul, Turkey on the second line
  - make sure you have only two lines in your text file with the source location on the first line and destination on the second
  - make sure your city and country begin with a capital letter and are separated by a comma and a space
- go the main.cpp file
- find bfs("accra-rio de janeiro.txt") 
- replace "accra-rio de janeiro.txt" with the absolute file path of the input file with quotation marks. E.g. "C:\user\downloads\accra-istanbul.txt"
- go to the data_reader.cpp file and change the file paths of the airlines, airports and routes .csv files to the absolute file paths in order to run the code
- Run the main.cpp to test the code

To change the airport, airline and route files:
- go to data_reader.cpp
- replace airports.csv, airlines.csv and routes.csv with similar files you want to use
- replace the input file (with the source and destination) using the steps mentioned above
- then run the main file

**Tech Stack**

Clion C++ 14

**Entry Point of Program**

**Leanne_Annor-Adjaye_ICPC-_Project-main**
 - Project directory
    - Airline.cpp
    - Airline.h
    
    - Airport.cpp
    - Airport.h
    
    - Node.cpp
    - Node.h
    
    - Route.cpp
    - Route.h
    
    - main.cpp
    
    - data_reader.cpp
    - data_reader.h
    
    - breadth_first_search.cpp
    - breadth_first_search.h
    
    - helper.cpp
    - helper.h
   

RUN 


`https://github.com/MaameMozuma/Leanne_Annor-Adjaye_ICPC-_Project.git`

`cd Leanne_Annor-Adjaye_ICPC-_Project-main`

run `CLang main.cpp`

run `Leanne_Annor-Adjaye_ICPC-_Project-main.exe`

**NB: Please create your .txt file in `cmake-build-debug` for the code to run properly

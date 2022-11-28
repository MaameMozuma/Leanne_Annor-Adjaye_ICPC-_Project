/**
 * @author Leanne Annor-Adjaye
 * */


#include "Route.h"

#include <utility>

/**This is a constructor for the Route class. It is initialising the private variables of the class.
 * @param Airline_Code
 * @param Airline_ID
 * @param Source_Airport_Code
 * @param Source_Airport_ID
 * @param Destination_Airport_Code
 * @param Destination_Airport_ID
 * @param Codeshare
 * @param Stops
 * @param Equipment
 */
Route::Route(string Airline_Code,
             string Airline_ID,
             string Source_Airport_Code,
             string Source_Airport_ID,
             string Destination_Airport_Code,
             string Destination_Airport_ID,
             string Codeshare,
             string Stops,
             string Equipment){
    this->Airline_Code = std::move(Airline_Code);
    this->Airline_ID = std::move(Airline_ID);
    this->Source_Airport_Code = std::move(Source_Airport_Code);
    this->Source_Airport_ID = std::move(Source_Airport_ID);
    this->Destination_Airport_Code = std::move(Destination_Airport_Code);
    this->Destination_Airport_ID = std::move(Destination_Airport_ID);
    this->Codeshare = std::move(Codeshare);
    this->Stops = std::move(Stops);
    this->Equipment = std::move(Equipment);
}

/**This is an operator overloading function for ==.
 * It is comparing the private variables of the class to the private variables of the class that is passed in as a parameter.
 * @param rhs
 * @return bool
 */
bool Route:: operator==(const Route &rhs) const {
    return Airline_Code == rhs.Airline_Code &&
           Airline_ID == rhs.Airline_ID &&
           Source_Airport_Code == rhs.Source_Airport_Code &&
           Source_Airport_ID == rhs.Source_Airport_ID &&
           Destination_Airport_Code == rhs.Destination_Airport_Code &&
           Destination_Airport_ID == rhs.Destination_Airport_ID &&
           Codeshare == rhs.Codeshare &&
           Stops == rhs.Stops &&
           Equipment == rhs.Equipment;
}

/**This is an operator overloading function for <.
 * It is comparing the private variables of the class to the private variables
 * of the route object that is passed in as a parameter.
 * @param rhs
 * @return bool
*/
bool Route:: operator<(const Route &rhs) const {
    return Airline_Code < rhs.Airline_Code &&
           Airline_ID < rhs.Airline_ID &&
           Source_Airport_Code < rhs.Source_Airport_Code &&
           Source_Airport_ID < rhs.Source_Airport_ID &&
           Destination_Airport_Code < rhs.Destination_Airport_Code &&
           Destination_Airport_ID < rhs.Destination_Airport_ID &&
           Codeshare < rhs.Codeshare &&
           Stops < rhs.Stops &&
           Equipment < rhs.Equipment;
}

/**This is a function that is returning a string.
 * @return a string representation of the route object.
 */
string Route:: toString(){
    return + "Airline_Code: " + Airline_Code + " Airline_ID: " + Airline_ID + " Source_Airport_Code: "
           + Source_Airport_Code + " Source_Airport_ID: " + Source_Airport_ID
           + " Destination_Airport_Code: " + Destination_Airport_Code + " Destination_Airport_ID: "
           + Destination_Airport_ID + " Codeshare: " + Codeshare + " Stops: " + Stops
           + " Equipment: " + Equipment;
}

const string &Route :: getAirlineCode() const {return Airline_Code;}
const string &Route :: getSourceAirportCode() const {return Source_Airport_Code;}
const string &Route :: getDestinationAirportCode() const {return Destination_Airport_Code;}
const string &Route :: getStops() const {return Stops;}

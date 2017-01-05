#ifndef FLIGHT_H
#define FLIGHT_H
#include "flightSchedule.hpp"
#include "PassengerIndividual.hpp"
#include "Passenger.hpp"
#include "PassengerBusiness.hpp"
#include "City.hpp"
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;


class Flight
{
public:

    Flight();
    void printMenu(); //print menu
    void createCustomer(); //create customer database
    void bookReservation(); //book flight
    void printPassengerInfo(); //print specific passenger info
    void printPassengerBookingList(); //print passenger booking list with popularities
    void printDepartureCity(); //print departure city with popularities
    void printArrivalCity(); // print arrival city with popularities
    void printflightRoute(); //print flight routes with popularities
    void printflightSchedule(); //print flight schedule
    void setFlightSchedule(); // initialize flight schedule
    void setIndidualCustomer(); //initialize individual passenger
    void setBusinessCustomer(); //initialize business passenger
    void setCity(); //initialize city
    static bool SortByAQty(const City& c1, const City& c2 ); //sort arrival city quantity (descending)
    static bool SortByDQty(const City& c1, const City& c2 ); //sort departure city quantity (descending)
    static bool SortByRoutes(const FlightSchedule &f1,  const FlightSchedule &f2); //sort flight routes by booking quantity (descending)
    static bool SortByflightNo(const FlightSchedule &f1, const FlightSchedule&f2); //sort flight number(ascending)
    static bool sortByPB(const Passenger& p1,const Passenger& p2 );//sort business passenger booking (descending)
    //sort individual passenger by Id number (ascending)
    static bool SortByIdNoI(const PassengerIndividual& p1,const PassengerIndividual& p2);
    //sort business passenger by Id number (ascending)
    static bool SortByIdNoB(const PassengerBusiness& p1,const PassengerBusiness& p2);
    static bool sortByPI(const Passenger& p1,const Passenger& p2 ); //sort individual passenger booking (descending)
    static bool sortByAll(const Passenger& p1, const Passenger &p2); //sort all passenger booking (descending)



protected:
    vector<PassengerIndividual> PI; //composition: PassengerIndividual member object
    vector<PassengerBusiness> PB; //composition: PassengerBusiness member object
    vector <FlightSchedule> fs; //composition: FlightSchedule member object
    vector <City> city; //composition: City member object

};
#endif // FLIGHT_H


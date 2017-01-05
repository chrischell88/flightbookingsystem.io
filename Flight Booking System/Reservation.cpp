#include "Reservation.hpp"
#include <iostream>
using namespace std;

//constructor
Reservation::Reservation(string departure,string arrival, string dDate,string aDate, int flight_no) :
                        aDate(aDate), dDate(dDate), departure(departure), arrival(arrival), flight_no(flight_no){}

void Reservation::setDDate(string dDate) {this->dDate = dDate;} //set departure date

string Reservation::getDDate() const {return dDate;} //return departure date

void Reservation::setADate(string aDate) {this->aDate = aDate;} //set arrival date

string Reservation::getADate() const {return aDate;} //return arrival date

void Reservation::setDeparture(string departure) {this->departure = departure;} //set departure city

string Reservation::getDeparture() const {return departure;} //return departure city

void Reservation::setArrival(string arrival){this->arrival = arrival;} //set arrival city

string Reservation::getArrival() const {return arrival;} //return arrival city

void Reservation::setFlight_no(int flight_no){this->flight_no = flight_no;} //set flight number

int Reservation::getFlight_no()const {return flight_no;} //return flight number

void Reservation::printReservation() const //print booking details
{
    cout << "Departure city: " << departure << '\t' << "Arrival city: "
        << arrival << '\t' << "Departure date: " << dDate << '\t' << "Arrival Date: "
        << aDate << '\t' << "Flight no: " << flight_no << endl;
}

//set booking details
void Reservation::setReservation(string departure, string arrival,string dDate,
                                 string aDate, int flight_no)
{
    this->dDate = dDate;
    this->aDate = aDate;
    this->departure = departure;
    this->arrival = arrival;
    this->flight_no = flight_no;
}

#ifndef RESERVATION_HPP
#define RESERVATION_HPP
#include <string>
using namespace std;

class Reservation
{
public:
    Reservation(string departure = "unknown",string arrival = "unknown",
                string dDate = "unknown",string aDate = "unknown",  int flight_no =0);
    void setDDate(string dDate); //set departure date
    string getDDate() const; //return departure date
    void setADate(string aDate); //set arrival date
    string getADate() const; //return arrival date
    void setDeparture(string departure); //set departure city
    string getDeparture() const; //return departure city
    void setArrival(string arrival); //set arrival city
    string getArrival() const; //return arrival city
    void setFlight_no(int flight_no); //set flight number
    int getFlight_no() const; //return flight number
    void printReservation() const; //print booking details
    //set booking details
    void setReservation(string departure, string arrival,string dDate,
                                 string aDate, int flight_no);
private:
    string dDate; //departure date
    string departure; //departure city
    string aDate; // arrival date
    string arrival; //arrival city
    int flight_no; // flight number
};
#endif // RESERVATION_HPP


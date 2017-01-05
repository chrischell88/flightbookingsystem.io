#ifndef PASSENGER_INDIVIDUAL_HPP
#define PASSENGER_INDIVIDUAL_HPP
#include "Passenger.hpp"
#include "Reservation.hpp"
#include <vector>
using namespace std;

//PassengerIndividual class derived from Passenger
class PassengerIndividual:public Passenger
{
public:

    PassengerIndividual(int Id_no, const string &name, const string &phoneNo,
                         string IC_no);
    virtual ~PassengerIndividual(){};
    void setIdNo(int Id_no); //set ID number
    int  getIdNo() const; // return ID number
    void setIC_no(string IC_no); // set IC number
    string getIC_no() const; // return IC number
    virtual void print() const; //print individual passenger details
    //set booking details
    void setReservation(string departure, string arrival, string dDate, string aDate, int flight_no);
    PassengerIndividual operator++(); //increment booking quantity counter

private:
 int Id_no; //ID number
 string IC_no; //IC number
 vector <Reservation> R; // composition :Reservation member object
};



#endif // PASSENGER_INDIVIDUAL_HPP



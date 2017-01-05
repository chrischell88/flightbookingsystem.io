#include "PassengerIndividual.hpp"
#include "Reservation.hpp"
#include <iostream>
using namespace std;

//constructor
PassengerIndividual::PassengerIndividual(int Id_no,const string &name, const string &phoneNo, string IC_no):
                        Passenger(name, bookingQty, phoneNo), Id_no(Id_no), IC_no(IC_no)
{
    bookingQty = 0;

}

void PassengerIndividual::setIdNo(int Id_no){this->Id_no = Id_no;} //set ID number

int PassengerIndividual::getIdNo()const {return Id_no;} //return ID number

void PassengerIndividual::setIC_no(string IC_no) {this->IC_no = IC_no;} //set IC number

string PassengerIndividual::getIC_no()const {return IC_no;} //return IC number

void PassengerIndividual::print() const //print individual passenger details
{
    cout << "Individual Passenger" << endl;
    cout << "ID Number: " << Id_no << endl;
    Passenger::print();
    cout << "Identification No: " << IC_no << endl;
    for (unsigned int i=0; i<R.size(); i++)
        R[i].printReservation();
}

//set flight booking details
void PassengerIndividual::setReservation(string departure, string arrival, string dDate, string aDate, int flight_no)
{
    R.push_back(Reservation(departure,arrival, dDate, aDate, flight_no));
}

//increment booking quantity counter
PassengerIndividual PassengerIndividual::operator++()
{
    ++bookingQty;

    return *this;
}

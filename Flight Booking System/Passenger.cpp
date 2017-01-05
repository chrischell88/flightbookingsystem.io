#include "Passenger.hpp"
#include <iostream>

//constructor
Passenger::Passenger(const string &name, const int &bookingQty, const string &phoneNo):
           name(name),bookingQty(bookingQty), phoneNo(phoneNo){}

//set name
void Passenger::setName(const string &name){this->name = name;}

//get name
string Passenger::getName()const {return name;}

//set booking quantity
void Passenger::setbookingQty(const int &bookingQty){this->bookingQty = bookingQty;}

//return booking quantity
int Passenger::getbookingQty()const {return bookingQty;}

//set phone number
void Passenger::setPhoneNo(const string &phoneNo){this->phoneNo = phoneNo;}

//return phone number
string Passenger::getPhoneNo() const {return phoneNo;}

//print passenger details
void Passenger::print() const
{
    cout << "Name: " << name << endl;
    cout << "Number of flight booking: " << bookingQty << endl;
    cout << "Phone Number: " << phoneNo << endl;
}

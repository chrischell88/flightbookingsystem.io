#ifndef PASSENGER_HPP
#define PASSENGER_HPP
#include <string>
using namespace std;

//passenger base class
class Passenger
{
public:
    Passenger(const string &name = "unknown", const int &bookingQty = 0,
              const string &phoneNo = "unknown");
    virtual ~Passenger(){};
    void setName(const string &name); //set name
    string getName() const; //get name
    void setbookingQty(const int &bookingQty); //set booking quantity
    int getbookingQty() const; // return booking quantity
    void setPhoneNo(const string &phoneNo); // set phone number
    string getPhoneNo() const; // return phone number
    virtual void print() const; // print passenger information


protected:
   string name; //passenger name
   int bookingQty; // flight booking quantity
   string phoneNo; //phone number

};



#endif // PASSENGER_HPP


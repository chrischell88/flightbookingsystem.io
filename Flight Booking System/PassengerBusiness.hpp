#ifndef PASSENGER_BUSINESS_HPP
#define PASSENGER_BUSINESS_HPP
#include "Passenger.hpp"
#include "Reservation.hpp"
#include <vector>
using namespace std;

//PassengerBusiness class derived from Passenger
class PassengerBusiness:public Passenger
{
public:
    PassengerBusiness(int businessID_no,const string &name, const string &phoneNo,string companyName = "unknown",
                       string companyReg_no = "unknown");
    virtual ~PassengerBusiness(){};
    void setIdNo(int businessID_no); //set ID number
    int getIdNo() const; // return ID number
    void setCompanyName(string companyName); //set company name
    string getCompanyName()const; // return company name
    void setCompanyReg_no (string companyReg_no); //set company reg. number
    string getCompanyReg_no()const; //return company reg. number
    virtual void print() const; // print business passenger details
    //set booking details
    void setReservation(string departure, string arrival,string dDate, string aDate, int flight_no);
    //set business passenger details
    void setBusinessPassenger(int businessID_no, string name, string phoneNo,
                          string companyName, string  companyReg_No);
    PassengerBusiness operator++(); //increment counter booking quantity

private:
   int businessID_no; // business ID number
   string companyName; // company name
   string companyReg_no; // company registration number
   vector <Reservation> R; //composition Reservation member object
};



#endif // PASSENGER_BUSINESS_HPP




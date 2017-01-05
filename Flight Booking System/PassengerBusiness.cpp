#include "PassengerBusiness.hpp"
#include <iostream>
using namespace std;

//constructor
PassengerBusiness::PassengerBusiness(int businessID_no,const string &name, const string &phoneNo,
                        string companyName,string companyReg_no) :
                        Passenger(name, bookingQty, phoneNo),businessID_no(businessID_no),
                        companyName(companyName), companyReg_no(companyReg_no)
{
    bookingQty = 0;

}

//set ID number
void PassengerBusiness::setIdNo(int businessID_no){this->businessID_no = businessID_no;}

//return ID number
int PassengerBusiness::getIdNo()const {return businessID_no;}

//set company name
void PassengerBusiness::setCompanyName(string companyName){this->companyName = companyName;}

//return company name
string PassengerBusiness::getCompanyName()const {return companyName;}

//set company reg. number
void PassengerBusiness::setCompanyReg_no (string companyReg_no){this->companyReg_no = companyReg_no;}

//return company reg. number
string PassengerBusiness::getCompanyReg_no()const {return companyReg_no;}

//print business passenger details
void PassengerBusiness::print()const
{
    cout << "Business Passenger" << endl;
    cout << "Business ID no: " << businessID_no << endl;
    Passenger::print();
    cout << "Company Name: " << companyName << endl;
    cout << "Company Reg. number: " << companyReg_no << endl;
    for (unsigned int i=0; i<R.size(); i++)
        R[i].printReservation();
}

//set booking details
void PassengerBusiness::setReservation(string departure, string arrival, string dDate,
                                       string aDate, int flight_no)
{
    R.push_back(Reservation(departure,arrival, dDate, aDate, flight_no));
}

//increment booking quantity counter
PassengerBusiness PassengerBusiness::operator++()
{
    ++bookingQty;

    return *this;
}

//set business passenger details
void PassengerBusiness::setBusinessPassenger(int businessID_no, string name, string phoneNo,
                          string companyName, string  companyReg_No)
{
    this-> businessID_no = businessID_no;
    this-> name = name;
    this-> phoneNo = phoneNo;
    this-> companyName = companyName;
    this-> companyReg_no = companyReg_No;

}

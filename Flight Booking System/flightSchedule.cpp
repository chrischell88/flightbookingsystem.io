#include "flightSchedule.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

FlightSchedule::FlightSchedule(string d_city, string a_city,string d_date,string a_date,
                   int f_no, int m_book, int t_book, int bal_book):d_city(d_city),a_city(a_city),
                   d_date(d_date),a_date(a_date),f_no(f_no),m_book(m_book),t_book(t_book),bal_book(bal_book){}

void FlightSchedule::setDepartureCity (string d_city){this->d_city = d_city;}//set departure city

void FlightSchedule::setArrivalCity(string a_city){this->a_city = a_city;} //set arrival city

void FlightSchedule::setDepartureDate(string d_date){this->d_date = d_date;} //set departure date

void FlightSchedule::setArrivalDate(string a_date){this->a_date = a_date;} //set arrival date

void FlightSchedule::setFlightNo(int f_no){this->f_no = f_no;} //set flight number

void FlightSchedule::setMaxBooking(int m_book){this->m_book = m_book;} //set maximum seat

void FlightSchedule::setTotalBooking(int t_book){this->t_book = t_book;} //set booking seat

void FlightSchedule::setBalanceBooking(int bal_book){this->bal_book = bal_book;} //calculate balance set

string FlightSchedule::getDepartureCity()const {return d_city;} //return departure city

string FlightSchedule::getArrivalCity() const {return a_city;} //return arrival city

string FlightSchedule::getDepartureDate() const {return d_date;} //return departure date

string FlightSchedule::getArrivalDate() const {return a_date;} //return arrival date

int FlightSchedule::getFlightNo() const {return f_no;} //return flight number

int FlightSchedule::getMaxBooking() const {return m_book;} //return maximum seat

int FlightSchedule::getTotalBooking() const {return t_book;} //return booking seat

int FlightSchedule::getBalanceBooking() {return bal_book = m_book - t_book;} //return balance seat

void FlightSchedule::printSchedule() const //display flight schedule
{
   cout << d_city <<  '\t' << a_city << '\t' << d_date
            << '\t' << a_date << '\t' << f_no << '\t' << m_book
            << '\t' << t_book << '\t' << bal_book << endl;
}

//increment counter for booking seat
FlightSchedule FlightSchedule::operator++()
{
    ++t_book;

    return *this;
}

//decrement counter for balance booking seat
FlightSchedule FlightSchedule::operator--()
{
    --bal_book;

    return *this;
}

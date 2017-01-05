#ifndef FLIGHT_SCHEDULE
#define FLIGHT_SCHEDULE
#include <string>
using namespace std;

class FlightSchedule
{

public:
    FlightSchedule(string d_city ="unknown", string a_city ="unknown",string d_date = "unknown",string a_date = "unknown",
                   int f_no = 0, int m_book = 0, int t_book = 0, int bal_book = 0);
    void setDepartureCity (string d_city);//set departure city
    void setArrivalCity(string a_city); //set arrival city
    void setDepartureDate(string d_date); //set departure date
    void setArrivalDate(string a_date); //set arrival date
    void setFlightNo(int f_no); //set flight number
    void setMaxBooking(int m_book); //set maximum seat
    void setTotalBooking(int t_book); //set booking seat
    void setBalanceBooking(int bal_book); //set balance seat
    string getDepartureCity()const; //return departure city
    string getArrivalCity()const; //return arrival city
    string getDepartureDate()const; //return departure date
    string getArrivalDate()const; //return arrival date
    int getFlightNo()const; //return flight number
    int getMaxBooking()const; //return maximum booking
    int getTotalBooking()const; //return booking seat
    int getBalanceBooking(); //return balance seat
    void printSchedule()const; //print flight schedule
    FlightSchedule operator++(); //increment counter for booking seat
    FlightSchedule operator--(); //decrement counter for balance booking seat


private:
    string  d_city; //departure city
    string a_city; //arrival city
    string a_date; //arrival date
    string  d_date; //departure date
    int f_no; //flight number
    int m_book;  //maximum seat
    int t_book; //booking seat
    int bal_book; //balance seat


};
#endif // FLIGHT_SCHEDULE


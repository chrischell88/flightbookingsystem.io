#ifndef CITY_HPP
#define CITY_HPP
#include <string>
using namespace std;


class City
{
public:
    City(string name = "unknown", int dQty = 0, int aQty =0);
    void setCityName(string name); //set city name
    string getCityName()const; // return city name
    void setDqty(int dQty); // set departure city booking quantity
    int getDqty() const; // get departure city booking quantity
    void setAqty(int aQty); // set arrival city booking quantity
    int getAqty() const; // get arrival city booking quantity
    void sumDqty(); // increment departure city booking quantity
    void sumAqty(); // increment arrival city booking quantity


protected:
    string name; //city name
    int dQty; // departure city booking quantity
    int aQty; // arrival city booking quantity

};

#endif // CITY_HPP

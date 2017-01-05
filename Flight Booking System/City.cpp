#include "City.hpp"


//constructor
City::City(string name, int dQty, int aQty):name(name),dQty(dQty),aQty(aQty){}

//set city name
void City::setCityName(string name){this->name = name;}

//get city name
string City::getCityName()const{return name;}

//set departure city quantity
void City::setDqty(int dQty) {this->dQty = dQty;}

//get departure city quantity
int City::getDqty() const {return dQty;}

//set arrival city quantity
void City::setAqty(int aQty) {this->aQty = aQty;}

//get arrival city quantity
int City::getAqty() const {return aQty;}

//increment departure city booking quantity
void City::sumDqty()
{
     dQty++;

}

//increment arrival city booking quantity
void City::sumAqty()
{
     aQty++;

}






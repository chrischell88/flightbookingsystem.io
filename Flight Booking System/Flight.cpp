#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <typeinfo>
#include "Flight.hpp"
#include "PassengerIndividual.hpp"
#include "Passenger.hpp"
#include "PassengerBusiness.hpp"
#include "flightSchedule.hpp"
#include <vector>
#include <memory>
using namespace std;

Flight::Flight()
{
    setFlightSchedule(); //initialize flight schedule
    setCity(); // initialize city
    setBusinessCustomer(); // initialize business passenger
    setIndidualCustomer(); // initialize individual passenger


}


//initialize flight schedule
void Flight::setFlightSchedule()
{
    fs.push_back(FlightSchedule("KUL","SIN","010715","050715",1,1000,0,1000));
    fs.push_back(FlightSchedule("KUL","HKG","010715","060715",2,1000,0,1000));
    fs.push_back(FlightSchedule("KUL","JED","010715","070715",3,1000,0,1000));
    fs.push_back(FlightSchedule("SIN","KUL","020715","060715",4,1000,0,1000));
    fs.push_back(FlightSchedule("SIN","HKG","020715","060715",5,1000,0,1000));
    fs.push_back(FlightSchedule("SIN","JED","020715","060715",6,1000,0,1000));
    fs.push_back(FlightSchedule("HKG","KUL","030715","080715",7,1000,0,1000));
    fs.push_back(FlightSchedule("HKG","SIN","030715","080715",8,1000,0,1000));
    fs.push_back(FlightSchedule("HKG","JED","030715","080715",9,1000,0,1000));
    fs.push_back(FlightSchedule("JED","KUL","040715","110715",10,1000,0,1000));
    fs.push_back(FlightSchedule("JED","SIN","040715","110715",11,1000,0,1000));
    fs.push_back(FlightSchedule("JED","HKG","040715","110715",12,1000,0,1000));
}

//initialize city
void Flight::setCity()
{
    city.push_back(City("KUL", 0, 0));
    city.push_back(City("SIN", 0, 0));
    city.push_back(City("HKG", 0, 0));
    city.push_back(City("JED", 0, 0));
}

//initialize individual passenger
void Flight::setIndidualCustomer()
{
    PI.push_back(PassengerIndividual(1, "James" , "012-2228888" , "920102-10-1111"));
    PI.push_back(PassengerIndividual(2, "Kelvin", "012-3332222" , "920203-10-1100"));
    PI.push_back(PassengerIndividual(3, "Albert" , "012-3334444" , "920305-10-1101"));
}

//initialize business passenger
void Flight::setBusinessCustomer()
{
    PB.push_back(PassengerBusiness(1,"Kelly", "011-2221234", "Kelly Sdn Bhd","S01111"));
    PB.push_back(PassengerBusiness(2,"May", "011-2226666", "May Sdn Bhd","S01112"));
    PB.push_back(PassengerBusiness(3,"Alvin", "011-2227777", "Alvin Sdn Bhd","S01113"));
}


//print menu
void Flight::printMenu()
{
    int choice;

    cout << "               Flight Booking System               " << endl
         << "---------------------------------------------------" << endl
         << "1. Create New Customer                             " << endl
         << "2. Flight Reservation                              " << endl
         << "3. Display Flight Schedule                         " << endl
         << "4. Display Info of a Specified Passenger           " << endl
         << "5. Display Passenger Booking List                  " << endl
         << "6. Display Departure City Based On Popularities    " << endl
         << "7. Display Arrival City Based On Popularities      " << endl
         << "8. Display The Flight(routes) Based On Popularities" << endl
         << "9. Exit                                            " << endl << endl;

    cout << "Enter the number of your choice: ";
    cin >> choice;

    do
    {
      switch(choice)
      {
        case 1: createCustomer();
            break;
        case 2: bookReservation();
            break;
        case 3: printflightSchedule();
            break;
        case 4: printPassengerInfo();
            break;
        case 5: printPassengerBookingList();
            break;
        case 6: printDepartureCity();
            break;
        case 7: printArrivalCity();
            break;
        case 8: printflightRoute();
            break;
        case 9: exit(0);
            break;
        default:
             cout << "Incorrect choice entered !  Please enter again : ";
             cin >> choice;
      }
    }while((choice <1) && (choice >9));

}

//create passenger database
void Flight::createCustomer()
{
    int choice, Id_no;
    string name, phoneNo, IC_no, companyName, companyReg_No;

    system("cls");
    cout << "Create New Customer" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Enter type of customer (1. Individual 2.Business) : ";
    cin >> choice;

    //add individual passenger database
    if (choice == 1)
    {
        system("cls");

        cout << "ID No" << '\t' << "Customer Name" << endl;
        cout << "------------------------------------------" << endl;
        //sort individual passenger by Id number (ascending)
        sort(PI.begin(), PI.end(), SortByIdNoI);

        //display individual passenger by ID number and name
        for(unsigned int i=0; i<PI.size(); i++)
        {
            cout << PI[i].getIdNo() << '\t' << PI[i].getName() << endl;
        }

        cout << endl << endl;
        cout << "Enter New Customer:" << endl;
        cout << "-------------------" << endl;
        cout << "Enter ID no: ";
        cin >> Id_no;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter phone no: ";
        cin >> phoneNo;
        cout << "Enter Identification no: ";
        cin >> IC_no;

        PI.push_back(PassengerIndividual(Id_no, name, phoneNo, IC_no));
        cout << name << " created successfully.." << endl;
    }
    //add business passenger database
    else if (choice == 2)
    {

        cout << "ID No" << '\t' << "Customer Name" << endl;
        cout << "------------------------------------------" << endl;
         //sort business passenger by Id number (ascending)
        sort(PB.begin(), PB.end(), SortByIdNoB);

        //print business passenger by Id number and name
        for(unsigned int i=0; i<PB.size(); i++)
        {
            cout << PB[i].getIdNo() << '\t' << PB[i].getName() << endl;

        }

        cout << endl << endl;
        cout << "Enter New Customer:" << endl;
        cout << "-------------------" << endl;
        cout << "Enter Business ID no: ";
        cin >> Id_no;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter phone no: ";
        cin >> phoneNo;
        cin.ignore();
        cout << "Enter company name: ";
        getline(cin, companyName);
        cout << "Enter company Registration No: ";
        cin >> companyReg_No;
        cout << endl;

        PB.push_back(PassengerBusiness(Id_no, name, phoneNo, companyName, companyReg_No));
        cout << name << " created successfully.." << endl << endl;
    }
    else
    {
        cout << "Wrong input.";
        system ("pause");
        system("cls");
        printMenu();
    }
     system("pause");
     system("cls");
     printMenu();
}

//sort individual passenger by Id number (ascending)
bool Flight::SortByIdNoI(const PassengerIndividual& p1,const PassengerIndividual& p2 )
{
    return p1.getIdNo() < p2.getIdNo();
}

//sort business passenger by Id number (ascending)
bool Flight::SortByIdNoB(const PassengerBusiness& p1,const PassengerBusiness& p2 )
{
    return p1.getIdNo() < p2.getIdNo();
}

//book flight
void Flight::bookReservation()
{
    system("cls");
    int idChoice, type_answer, fchoice;


    cout << "Enter type of customer you want to make booking (1.Individual 2.Business): ";
    cin >> type_answer;

    system("cls");

    switch(type_answer)
    {
        case 1: //set booking details for individual customer
            cout << "ID No" << '\t' << "Customer Name" << endl;
            cout << "------------------------------------------" << endl;

            //sort individual passenger by Id number (ascending)
            sort(PI.begin(), PI.end(), SortByIdNoI);

            //display individual passenger by ID number and name
            for(unsigned int i=0; i<PI.size(); i++)
            {
                 cout << PI[i].getIdNo() << '\t' << PI[i].getName() << endl;

            }

            cout << endl << "Enter customer ID no that you want to make booking: ";
            cin >> idChoice;

            system("cls");

            //sort flight number(ascending)
            sort (fs.begin(), fs.end(), SortByflightNo);

            cout << "D.City" << '\t' << "A.City" << '\t' << "D.Date" << '\t'<< "A.Date"
                << '\t' << "F. No" << '\t' << "MaxSeat" << '\t' << "Booked" << " " << "BalSeat" <<endl;
            cout << "............................................................................." << endl;

            //print flight schedule
            for( unsigned int i=0; i<fs.size(); i++)
                fs[i].printSchedule();

            cout << "Enter flight no: ";
            cin >> fchoice;

            //set booking if flight number choice is 1
            if ((fchoice == 1) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                //set booking from individual passenger ID number
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1]; //increment individual passenger booking counter
                city[0].sumDqty(); //increment departure city quantity
                city[1].sumAqty(); //increment arrival city quantity
                ++fs[0]; //increment booking seat quantity
                --fs[0]; //decrement balance seat quantiy
            }
            //set booking if flight number choice is 2
            else if ((fchoice == 2) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[0].sumDqty();
                city[2].sumAqty();
                ++fs[1];
                --fs[1];
            }
            //set booking if flight number choice is 3
            else if ((fchoice == 3) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[0].sumDqty();
                city[3].sumAqty();
                ++fs[2];
                --fs[2];
            }
            //set booking if flight number choice is 4
            else if ((fchoice == 4) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[1].sumDqty();
                city[0].sumAqty();
                ++fs[3];
                --fs[3];
            }
            ////set booking if flight number choice is 5
            else if ((fchoice == 5) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[1].sumDqty();
                city[2].sumAqty();
                ++fs[4];
                --fs[4];
            }
            //set booking if flight number choice is 6
            else if ((fchoice == 6) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[1].sumDqty();
                city[3].sumAqty();
                ++fs[5];
                --fs[5];
            }
            //set booking if flight number choice is 7
            else if ((fchoice == 7) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[2].sumDqty();
                city[0].sumAqty();
                ++fs[6];
                --fs[6];
            }
            //set booking if flight number choice is 8
            else if ((fchoice == 8) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[2].sumDqty();
                city[1].sumAqty();
                ++fs[7];
                --fs[7];
            }
            //set booking if flight number choice is 9
            else if ((fchoice == 9) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[2].sumDqty();
                city[3].sumAqty();
                ++fs[8];
                --fs[8];
            }
            //set booking if flight number choice is 10
            else if ((fchoice == 10) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[3].sumDqty();
                city[0].sumAqty();
                ++fs[9];
                --fs[9];
            }
            //set booking if flight number choice is 11
            else if ((fchoice == 11) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[3].sumDqty();
                city[1].sumAqty();
                ++fs[10];
                --fs[10];
            }
            //set booking if flight number choice is 12
            else if ((fchoice == 12) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PI[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PI[idChoice-1];
                city[3].sumDqty();
                city[2].sumAqty();
                ++fs[11];
                --fs[11];
            }
            else
            {
                cout << "Cannot book same city for departure city and arrival city.."
                     << endl;

                system ("pause");
                system("cls");
                printMenu();
            }
            break;

        case 2://set booking details for business passenger

            cout << "ID No" << '\t' << "Customer Name" << endl;
            cout << "------------------------------------------" << endl;

             //sort business passenger by Id number (ascending)
            sort(PB.begin(), PB.end(), SortByIdNoB);

            //print business passenger by Id number and name
            for(unsigned int i=0; i<PB.size(); i++)
            {
                 cout << PB[i].getIdNo() << '\t' << PB[i].getName() << endl;

            }

            cout << endl << "Enter customer ID no that you want to make booking: ";
            cin >> idChoice;

            system("cls");

            //sort flight routes by booking quantity (descending)
            sort (fs.begin(), fs.end(), SortByflightNo);

            cout << "D.City" << '\t' << "A.City" << '\t' << "D.Date" << '\t'<< "A.Date"
                << '\t' << "F. No" << '\t' << "MaxSeat" << '\t' << "Booked" << " " << "BalSeat" <<endl;
            cout << "............................................................................." << endl;

            //print flight schedule
            for( unsigned int i=0; i<fs.size(); i++)
            fs[i].printSchedule();

            cout << "Enter flight no: ";
            cin >> fchoice;

            //set booking if flight number choice is 1
            if ((fchoice == 1) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                //set booking details for business passenger from ID number
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];//increment counter for booking quantity
                city[0].sumDqty(); //increment counter for departure city quantity
                city[1].sumAqty();//increment counter for arrival city quantity
                ++fs[0]; //increment counter for booking seat by routes
                --fs[0]; //decrement counter for balance seat by routes
            }
            //set booking if flight number choice is 2
            else if ((fchoice == 2) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[0].sumDqty();
                city[2].sumAqty();
                ++fs[1];
                --fs[1];
            }
            //set booking if flight number choice is 3
            else if ((fchoice == 3) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[0].sumDqty();
                city[3].sumAqty();
                ++fs[2];
                --fs[2];
            }
            //set booking if flight number choice is 4
            else if ((fchoice == 4) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[1].sumDqty();
                city[0].sumAqty();
                ++fs[3];
                --fs[3];
            }
            //set booking if flight number choice is 5
            else if ((fchoice == 5) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[1].sumDqty();
                city[2].sumAqty();
                ++fs[4];
                --fs[4];
            }
            //set booking if flight number choice is 6
            else if ((fchoice == 6) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[1].sumDqty();
                city[3].sumAqty();
                ++fs[5];
                --fs[5];
            }
            //set booking if flight number choice is 7
            else if ((fchoice == 7) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[2].sumDqty();
                city[0].sumAqty();
                ++fs[6];
                --fs[6];
            }
            //set booking if flight number choice is 8
            else if ((fchoice == 8) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[2].sumDqty();
                city[1].sumAqty();
                ++fs[7];
                --fs[7];
            }
            //set booking if flight number choice is 9
            else if ((fchoice == 9) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[2].sumDqty();
                city[3].sumAqty();
                ++fs[8];
                --fs[8];
            }
            //set booking if flight number choice is 10
            else if ((fchoice == 10) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[3].sumDqty();
                city[0].sumAqty();
                ++fs[9];
                --fs[9];
            }
            //set booking if flight number choice is 11
            else if ((fchoice == 11) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[3].sumDqty();
                city[1].sumAqty();
                ++fs[10];
                --fs[10];
            }
            //set booking if flight number choice is 12
            else if ((fchoice == 12) && (fs[fchoice-1].getBalanceBooking() > 0))
            {
                PB[idChoice-1].setReservation(fs[fchoice-1].getDepartureCity(), fs[fchoice-1].getArrivalCity(), fs[fchoice-1].getDepartureDate(),
                                              fs[fchoice-1].getArrivalDate(), fs[fchoice-1].getFlightNo());
                ++PB[idChoice-1];
                city[3].sumDqty();
                city[2].sumAqty();
                ++fs[11];
                --fs[11];
            }
            else
            {
                cout << "Cannot book same city for departure city and arrival city.."
                     << endl;

                system ("pause");
                system("cls");
                printMenu();
            }
            break;

        default:
            cout <<"Incorrect input entered.";
            break;

            system ("pause");
            system("cls");
            printMenu();

    }


    cout << "Booking created successfully.." << endl << endl;
    system ("pause");
    system("cls");
    printMenu();

}


//print specific passenger info
void Flight::printPassengerInfo()
{
    system("cls");
    int answer, viewID;
    cout << "Enter customer type that you want to display (1.Individual 2.Business): ";
    cin >> answer;

    system("cls");
    //print specific info for individual passenger
    if(answer == 1)
    {
        cout << "ID No" << '\t' << "Customer Name" << endl;
        cout << "------------------------------------------" << endl;

        //display individual passenger by ID number
        for(unsigned int i=0; i<PI.size(); i++)
        {
             cout << PI[i].getIdNo() << '\t' << PI[i].getName() << endl;

        }

        cout << endl << "Enter customer ID no that you want to display: ";
        cin >> viewID;

        system("cls");

        PI[viewID-1].print(); //call virtual print function

        system("pause");
        system("cls");
        printMenu();

    }
    else if (answer == 2) //print specific info business passenger
    {
        cout << "Business ID No" << '\t' << '\t' << "Name       " << endl;
        cout << "------------------------------------------------" << endl;

        //print business passenger by ID number and company name
        for(unsigned int i=0; i<PB.size(); i++)
        {
             cout << PB[i].getIdNo() << '\t' << '\t' << '\t' << PB[i].getName() << endl;

        }

        cout << endl << "Enter customer Business ID no that you want to display: ";
        cin >> viewID;

        system("cls");
        PB[viewID-1].print();//call virtual print function

        system("pause");
        system("cls");
        printMenu();
    }
    else
    {
        cout << "Wrong input..";
        system("pause");
        system("cls");
        printMenu();
    }

    system("pause");
    system("cls");
    printMenu();

}

//sort flight number(ascending)
bool Flight::SortByflightNo(const FlightSchedule &f1, const FlightSchedule&f2 )
{
     return f1.getFlightNo() < f2.getFlightNo();
}

//print flight schedule
void Flight::printflightSchedule()
{

    system("cls");

    sort (fs.begin(), fs.end(), SortByflightNo);

    cout << "D.City" << '\t' << "A.City" << '\t' << "D.Date" << '\t'<< "A.Date"
        << '\t' << "F. No" << '\t' << "MaxSeat" << '\t' << "Booked" << " " << "BalSeat" <<endl;
    cout << "............................................................................." << endl;

    //print flight schedule
    for( unsigned int i=0; i<fs.size(); i++)
        fs[i].printSchedule();

    system("pause");
    system("cls");
    printMenu();

}

//sort individual passenger booking (descending)
bool Flight::sortByPI(const Passenger& p1,const Passenger& p2 )
{
   return  p1.getbookingQty() > p2.getbookingQty();
}

//sort business passenger booking (descending)
bool Flight::sortByPB(const Passenger& p1,const Passenger& p2 )
{
   return  p1.getbookingQty() > p2.getbookingQty();
}

//sort all passenger booking (descending)
bool Flight::sortByAll(const Passenger &p1, const Passenger &p2 )
{
   return  p1.getbookingQty() > p2.getbookingQty();
}

//print passenger booking list with popularities
void Flight::printPassengerBookingList()
{
    system("cls");

    int choice;

    cout << "Display Passenger List   " << endl
         << "-------------------------" << endl
         << "1. All Passengers        " << endl
         << "2. Individual Passengers " << endl
         << "3. Business Passengers   " << endl << endl
         << "Enter your choice (1-3): " << endl;
    cin >> choice;

    //print all passenger
    if(choice == 1)
    {
        system("cls");
        vector<Passenger> P;
        copy ( PI.begin(), PI.end(), back_inserter(P));
        copy ( PB.begin(), PB.end(), back_inserter(P));

        sort(P.begin(), P.end(), sortByAll);

        for (unsigned int i=0; i<P.size(); i++)
        {
            cout << P[i].getName() << '\t' << '\t' << '\t' << P[i].getbookingQty() << endl;
        }

    }
    //print individual passenger
    else if (choice == 2)
    {
        system("cls");

        //sort individual passenger booking (descending)
        sort(PI.begin(), PI.end(), sortByPI);

        //print individual passengers with booking in descending order
        for (unsigned int i=0; i<PI.size(); i++)
        {
            cout << PI[i].getName() << '\t' << '\t' << '\t' << PI[i].getbookingQty() << endl;
        }
    }
    //print business passenger
    else if (choice == 3)
    {
        system("cls");

        //sort business passenger booking (descending)
        sort(PB.begin(), PB.end(), sortByPB);

        //print business passengers with booking in descending order
        for (unsigned int i=0; i<PB.size(); i++)
        {
            cout << PB[i].getName() << '\t' << '\t' << '\t' << PB[i].getbookingQty() << endl;
        }
    }
    else
    {
        cout << "Wrong inout entered..." << endl;
    }

    system("pause");
    system("cls");
    printMenu();

}


//sort departure city quantity (descending)
bool Flight::SortByDQty(const City &c1, const City &c2 )
{
     return c1.getDqty() > c2.getDqty();
}

//print departure city with popularities
void Flight::printDepartureCity()
{
    system("cls");

     //sort departure city quantity (descending)
    sort (city.begin(), city.end(), SortByDQty);

    cout << "Departure City" << '\t' << "Booking Quantity" << endl;
    cout << "----------------------------------------------------" << endl;

    //print departure city with quantity (descending)
    for (unsigned int i=0; i<city.size(); i++)
    {
       cout << city[i].getCityName() << '\t' << '\t' << '\t' << city[i].getDqty() << endl;

    }

    system("pause");
    system("cls");
    printMenu();
}

//sort arrival city quantity (descending)
bool Flight::SortByAQty(const City &c1, const City &c2 )
{
     return c1.getAqty() > c2.getAqty();
}

// print arrival city with popularities
void Flight::printArrivalCity()
{
    system("cls");

    //sort arrival city quantity (descending)
    sort (city.begin(), city.end(), SortByAQty);

    cout << "Arrival City" << '\t' << "Booking Quantity" << endl;
    cout << "--------------------------------------------------" << endl;

    //print arrival city with quantity (descending)
    for (unsigned int i=0; i<city.size(); i++)
    {
       cout << city[i].getCityName() << '\t' << '\t' << '\t' << city[i].getAqty() << endl;

    }

    system("pause");
    system("cls");
    printMenu();
}

//sort flight routes by booking quantity(descending)
bool Flight::SortByRoutes(const FlightSchedule  &f1,  const FlightSchedule  &f2 )
{
     return f1.getTotalBooking() > f2.getTotalBooking();
}

//print flight routes with popularities
void Flight::printflightRoute()
{
    system("cls");

    //sort flight routes by booking quantity (descending)
    sort (fs.begin(), fs.end(), SortByRoutes);

    cout << "Departure City" << '\t' << "Arrival City" << '\t' << "Booking Quantity" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    //print flight routes by booking quantity (descending)
    for (unsigned int i=0; i<fs.size(); i++)
    {
       cout << fs[i].getDepartureCity() << '\t' << '\t' << '\t' << fs[i].getArrivalCity()
            << '\t' << '\t' << fs[i].getTotalBooking() << endl;
    }

    system("pause");
    system("cls");
    printMenu();
}



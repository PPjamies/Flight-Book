/*
 * Test.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: Pazuz
 */
#include <iostream>
#include <ctype.h>
#include "Exception.h"
#include "FlightManager.h"
#include "Passenger.h"
using namespace std;

//Exceptions for invalid flight Numbers
void checkFlightNumber(int flightNumber){
	Exception NOFLIGHT("INVALID FLIGHT NUMBER EXCEPTION", 0);
	if(flightNumber != 100 && flightNumber != 200 && flightNumber != 300 && flightNumber != 400){
		throw NOFLIGHT;
	}
}
//Exceptions for invalid first Names
void checkFirstName(string firstName){
	Exception INVALID_FIRSTNAME("INVALID FIRST NAME EXCEPTION", 1);
	for(char c: firstName){
		if(isdigit(c)){
			throw INVALID_FIRSTNAME;
		}
	}
}
//Exceptions for invalid last Names
void checkLastName(string lastName){
	Exception INVALID_LASTNAME("INVALID LAST NAME EXCEPTION", 2);
	for(char c: lastName){
		if(isdigit(c)){
			throw INVALID_LASTNAME;
		}
	}
}

int main(){

	bool go = 1;
	char operation;

	int flightNumber;
	string firstName;
	string lastName;
	string address;
	string phone;

	FlightManager flightBook;		//Middle man between User and SortedLinkedList of Passengers

//*************************************************************************************************************//
	cout<< "***DELTA AIRLINES***" << endl;
	cout<< "Please choose an operation:" << endl;

	while(go){
		cout<< "A(Add) | S (Search) | D(Delete) | L(List) | Q(Quit):";
		cin>>operation;

		if(operation == 'A'){

			cin.ignore();
			cout<<"Enter flight number:"<<endl;
			cin>>flightNumber;
			checkFlightNumber(flightNumber);

			cin.ignore();
			cout<<"Enter first name:"<<endl;
			getline(cin,firstName);
			checkFirstName(firstName);

			cout<<"Enter last name:"<<endl;
			getline(cin,lastName);
			checkLastName(lastName);

			cout<<"Enter address:"<<endl;
			getline(cin,address);
			cout<<"Enter phone:"<<endl;
			getline(cin,phone);

			Passenger passenger(firstName, lastName, address, phone);	//create passenger
			flightBook.insertPassenger(flightNumber,passenger);			//store passenger into flightBook

		}else if(operation == 'S'){

			cin.ignore();
			cout<<"Enter first name:"<<endl;
			getline(cin,firstName);
			checkFirstName(firstName);

			cout<<"Enter last name:"<<endl;
			getline(cin,lastName);
			checkLastName(lastName);

			Passenger passenger(firstName, lastName);	//create temp passenger for comparison and retrieval of stored passenger
			flightBook.searchPassenger(passenger);

		}else if(operation == 'D'){

			cin.ignore();
			cout<<"Enter flight number:"<<endl;
			cin>>flightNumber;
			checkFlightNumber(flightNumber);


			cin.ignore();
			cout<<"Enter first name:"<<endl;
			getline(cin,firstName);
			checkFirstName(firstName);

			cout<<"Enter last name:"<<endl;
			getline(cin,lastName);
			checkLastName(lastName);

			Passenger passenger(firstName, lastName);
			flightBook.removePassenger(flightNumber,passenger);

		}else if(operation == 'L'){

			cin.ignore();
			cout<<"Enter flight number:"<<endl;
			cin>>flightNumber;
			checkFlightNumber(flightNumber);
			cin.ignore();

			flightBook.listPassenger(flightNumber);

		}else if(operation == 'Q'){
			go = 0;
			cout<<"End of program"<<endl;
		}
	}
	return 0;
}
//*************************************************************************************************************//

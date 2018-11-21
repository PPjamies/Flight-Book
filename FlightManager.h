/*
 * FlightManager.h
 * This program saves Passenger Objects to an array of SortedLinkedLists
 *
 *  Created on: Oct 24, 2018
 *      Author: Pazuz
 */

#ifndef FLIGHTMANAGER_H_
#define FLIGHTMANAGER_H_
#include <iostream>
#include "Passenger.h"
#include "SortedLinkedList.h"
using namespace std;

const int SIZE = 4;

class FlightManager{
	private:
		SortedLinkedList<Passenger> flights[SIZE];		//each index of the array holds a SortedLinkedList of Passengers
	public:
		FlightManager();
		void insertPassenger(int, Passenger&);
		void removePassenger(int, Passenger&);
		void searchPassenger(Passenger&);
		void listPassenger(int);
};

FlightManager::FlightManager(){} //empty constructor

void FlightManager:: insertPassenger(int flightNumber, Passenger& p){
	if(flightNumber == 100){
		flights[0].add(p);
	}else if(flightNumber == 200){
		flights[1].add(p);
	}else if(flightNumber == 300){
		flights[2].add(p);
	}else if(flightNumber == 400){
		flights[3].add(p);
	}
}
void FlightManager::removePassenger(int flightNumber, Passenger& p){
	if(flightNumber == 100){
		flights[0].remove(p);
	}else if(flightNumber == 200){
		flights[1].remove(p);
	}else if(flightNumber == 300){
		flights[2].remove(p);
	}else if(flightNumber == 400){
		flights[3].remove(p);
	}
}
void FlightManager::searchPassenger(Passenger& p){
	int flightNum = 4;

	//tests to see if passenger p is present in one of the lists and returns flightNumber
	if(flights[0].find(p) == 1){
		flightNum = 0;						//Flight Number 100
	}else if(flights[1].find(p) == 1){
		flightNum = 1;						//Flight Number 200
	}else if(flights[2].find(p) == 1){
		flightNum = 2;						//Flight Number 300
	}else if(flights[3].find(p) == 1){
		flightNum = 3;						//Flight Number 400
	}

	//retrieves the passenger
	if(flightNum == 0){
		cout<<"Flight Number: 100"<<endl;
		cout <<flights[flightNum].search(p)<<endl;
	}else if(flightNum == 1){
		cout<<"Flight Number: 200"<<endl;
		cout<<flights[flightNum].search(p)<<endl;
	}else if(flightNum == 2){
		cout<<"Flight Number: 300"<<endl;
		cout<<flights[flightNum].search(p)<<endl;
	}else if(flightNum == 3){
		cout<<"Flight Number: 400"<<endl;
		cout<<flights[flightNum].search(p)<<endl;
	}else if(flightNum == 4){
		cout<< "Not Found In Database"<< endl;
	}
}
void FlightManager::listPassenger(int flightNumber){

	if(flightNumber == 100){
		flights[0].list();
	}else if(flightNumber == 200){
		flights[1].list();
	}else if(flightNumber == 300){
		flights[2].list();
	}else if(flightNumber == 400){
		flights[3].list();
	}
}

#endif /* FLIGHTMANAGER_H_ */

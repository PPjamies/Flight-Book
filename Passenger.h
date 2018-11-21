/*
 * Passenger.h
 *
 *  Created on: Oct 21, 2018
 *      Author: Pazuz
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <iostream>
using namespace std;

class Passenger{
	string fName;
	string lName;
	string address;
	string phone;
public:
	Passenger(string pFirstName ="", string pLastName ="", string pAddress ="", string pPhone ="");
	string getFirstName();
	string getLastName();
	string getAddress();
	string getPhone();
	friend ostream& operator<<(ostream&, const Passenger&);
	friend bool operator<(const Passenger&, const Passenger&);
	friend bool operator>(const Passenger&, const Passenger&);
	friend bool operator==(const Passenger&, const Passenger&);
	friend bool operator!=(const Passenger&, const Passenger&);
};

Passenger::Passenger(string pFirstName, string pLastName, string pAddress, string pPhone){
	fName = pFirstName;
	lName = pLastName;
	address = pAddress;
	phone = pPhone;
}
string Passenger::getFirstName(){
	return fName;
}
string Passenger::getLastName(){
	return lName;
}
string Passenger::getAddress(){
	return address;
}
string Passenger::getPhone(){
	return phone;
}
ostream& operator<<(ostream& os, const Passenger& person){
	os<<"First Name: " << person.fName << "\nLastName: " << person.lName << "\nAddress: " << person.address << "\nPhone: +" << person.phone<<endl;
	return os;
}
bool operator<(const Passenger& p1, const Passenger& p2){
	return p1.lName < p2.lName;
}
bool operator>(const Passenger& p1, const Passenger& p2){
	return p1.lName > p2.lName;
}
bool operator==(const Passenger& p1, const Passenger& p2){
	return (p1.fName == p2.fName) && (p1.lName == p2.lName);
}
bool operator!=(const Passenger& p1, const Passenger& p2){
	return p1.lName != p2.lName && p1.fName != p2.fName;
}

#endif /* PASSENGER_H_ */

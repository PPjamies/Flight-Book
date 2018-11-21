/*
 * Exception.h
 * This class creates new exceptions
 *  Created on: Oct 23, 2018
 *      Author: Pazuz
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <iostream>
#include <exception>
using namespace std;

class Exception: public exception{
	int code;
	const char* message;
	public:
		Exception(const char*  _message, int _code):message(_message),code(_code){}
		int getCode(){
			return code;
		}
		const char* what() const throw(){
			return message;
		}
};

#endif /* EXCEPTION_H_ */

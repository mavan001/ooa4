#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class MyException {
private:
	std::string _message;
public:
	MyException();
	MyException(std::string errorMessage);
	std::string getMessage();

};

#endif 
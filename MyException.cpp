#include "MyException.h"

MyException::MyException() {
	_message = "Error: No error message specified";
}

MyException::MyException(std::string errorMessage) {
	_message = errorMessage;
}

std::string MyException::getMessage() {
	return _message;
}
#include "exceptions.h"

Exception::Exception(const std::string& message)
{
	this->message = message;
}

const char* Exception::what()
{
	return this->message.c_str();
}



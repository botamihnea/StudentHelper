#pragma once
#include <exception>
#include <string>

class Exception : public std::exception
{
private:
	std::string message;
public:
	Exception(const std::string& message);
	virtual const char* what();

};
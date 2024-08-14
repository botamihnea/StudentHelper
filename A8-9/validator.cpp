#include "validator.h"


void Validator::validate_title(std::string title)
{
	if (title.size() < 2 || title.size() > 50)
		throw Exception("Title must have between 1 and 50 characters!");
}

void Validator::validate_link(std::string link)
{
	if (link.substr(0, 5) != "https" || link.size() < 5)
		throw Exception("Link must start with https!");
}

void Validator::validate_seconds(int seconds)
{
	if (seconds < 0 || seconds > 59)
		throw Exception("Seconds must be between 0 and 59!");
}

void Validator::validate_minutes(int minutes)
{
	if (minutes < 0 || int(minutes) != minutes)
		throw Exception("Minutes must be a positive number!");
}

void Validator::validate_option(int option)
{
	if (option < 0 || option > 6)
		throw Exception("Option entered is not valid!");
}

void Validator::validate_option2(int option)
{
	if (option < 0 || option > 3)
		throw Exception("Option entered is not valid!");
}

void Validator::validate_option3(int option)
{
	if (option < 0 || option > 4)
		throw Exception("Option entered is not valid!");
}

void Validator::validate_first_option(int option)
{
	if (option < 0 || option > 2)
		throw Exception("Option entered is not valid!");
}

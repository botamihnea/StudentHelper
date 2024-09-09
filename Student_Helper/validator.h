#pragma once
#include "exceptions.h"

class Validator
{
public:
	static void validate_title(std::string title);
	static void validate_link(std::string link);
	static void validate_seconds(int seconds);
	static void validate_minutes(int minutes);
	static void validate_option(int option);
	static void validate_option2(int option);
	static void validate_option3(int option);
	static void validate_first_option(int option);
};
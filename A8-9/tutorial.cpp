#include "tutorial.h"
#include <iostream>
#include <string>

Tutorial::Tutorial(std::string title, std::string presenter, int minutes, int seconds, int likes, std::string link)
{
	this->title = title;
	this->presenter = presenter;
	this->minutes = minutes;
	this->seconds = seconds;
	this->likes = likes;
	this->link = link;
}

Tutorial::Tutorial() : title{ "" }, presenter{ "" }, minutes{ 0 }, seconds{ 0 }, likes{ 0 }, link{ "" }
{}

std::string Tutorial::getTitle()
{
	return this->title;
}

std::string Tutorial::getPresenter()
{
	return this->presenter;
}

std::string Tutorial::getLink()
{
	return this->link;
}

int Tutorial::getLikes()
{
	return this->likes;
}


int Tutorial::getMinutes()
{
	return this->minutes;
}

int Tutorial::getSeconds()
{
	return this->seconds;
}

bool Tutorial::operator==(const Tutorial& tutorial)
{
	return this->title == tutorial.title && this->link == tutorial.link;
}


#pragma once
#include <string>

class Tutorial
{
private:
	std::string title;
	std::string presenter;
	int minutes;
	int seconds;
	int likes;
	std::string link;
public:
	Tutorial();
	Tutorial(std::string title, std::string presenter, int minutes, int seconds, int likes, std::string link);
	std::string getTitle();
	std::string getPresenter();
	std::string getLink();
	int getLikes();
	int getMinutes();
	int getSeconds();

	bool operator==(const Tutorial& tutorial);
	friend std::ostream& operator<<(std::ostream& out, const Tutorial& tutorial);
	friend std::istream& operator>>(std::istream& in, Tutorial& tutorial);
};


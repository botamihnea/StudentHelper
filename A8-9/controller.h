#pragma once
#include "repository.h"

class Controller
{
private:
	Repository repo;
public:
	Controller();
	~Controller();
	void add_controller(std::string title, std::string presenter, int minutes, int seconds, int likes, std::string link);
	void remove_controller(std::string title, std::string link);
	void remove_controller_watch_list(std::string title, std::string link);
	std::vector<Tutorial> get_elements_controller();
	std::vector<Tutorial> get_elements_watch_list();
	void update_controller(std::string title, std::string link, std::string new_title, std::string new_presenter, int new_minutes, int new_seconds,
		int new_likes, std::string new_link);
	void add_watch_controller(std::string title, std::string presenter, int minutes, int seconds, int likes, std::string link);
	void go_to_next_tutorial(int& i, int size);
	void readFile(std::string filepath);
	void writeFile(std::string filepath);
	void writeFileCSV(std::string filepath);
	void writeFileHTML(std::string filepath);
	void openFile(std::string filepath);
};
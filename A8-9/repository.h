#pragma once
#include <vector>
#include "tutorial.h"


class Repository
{
private:
	std::vector<Tutorial> tutorials;
	std::vector<Tutorial> watch_list;
public:
	Repository();
	~Repository();
	void generate_tutorials();
	bool is_already_repo(std::string title, std::string link);
	bool is_already_watch_list(std::string title, std::string link);
	void add_tutorial(Tutorial tutorial);
	std::vector<Tutorial> get_elements_repo();
	std::vector<Tutorial> get_elements_watch_list_repo();
	void remove_tutorial(std::string title, std::string link);
	void remove_tutorial_from_watch_list(std::string title, std::string link);
	void update_tutorial(std::string title, std::string link, std::string new_title, std::string new_presenter, int new_minutes, int new_seconds,
		int new_likes, std::string new_link);
	void add_to_watch_list(Tutorial tutorial);
	void read_from_file(std::string filepath);
	void write_to_file(std::string filepath);
	void write_to_csv_file(std::string filepath);
	void write_to_html_file(std::string filepath);
	void open_file(std::string filepath);
};
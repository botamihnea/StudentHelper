#include "controller.h"
#include <stdexcept>
#include "exceptions.h"

Controller::Controller()
{
	this->repo = Repository();
}

Controller::~Controller()
{
}

/*
Verifies if the element is in the repo already, and if not it adds it with the given parameters taken from the ui function
If the element is already in our repository then we throw an exception.
*/
void Controller::add_controller(std::string title, std::string presenter, int minutes, int seconds, int likes, std::string link)
{
	Tutorial new_tutorial = Tutorial(title, presenter, minutes, seconds, likes, link);
	this->repo.add_tutorial(new_tutorial);

}

/*
Acceses the remove_tutorial function from the repo with the parameter read by the user in the user interface.
*/
void Controller::remove_controller(std::string title, std::string link)
{
	this->repo.remove_tutorial(title, link);
}

//Removes tutorial from the watch list
void Controller::remove_controller_watch_list(std::string title, std::string link)
{
	this->repo.remove_tutorial_from_watch_list(title, link);
}

/*
Acceses the update_tutorial function from the repo with the parameter read by the user in the user interface.
*/
void Controller::update_controller(std::string title, std::string link, std::string new_title, std::string new_presenter, int new_minutes, int new_seconds,
	int new_likes, std::string new_link)
{
	this->repo.update_tutorial(title, link, new_title, new_presenter, new_minutes, new_seconds, new_likes, new_link);
}

//Adds the tutorial to the watch list
void Controller::add_watch_controller(std::string title, std::string presenter, int minutes, int seconds, int likes, std::string link)
{
	Tutorial new_tutorial = Tutorial(title, presenter, minutes, seconds, likes, link);
	this->repo.add_to_watch_list(new_tutorial);
}

//Goes to the next tutorial in the list
void Controller::go_to_next_tutorial(int& i, int size)
{
	i++;
	if (i == size)
		i = 0;
}

void Controller::readFile(std::string filepath)
{
	this->repo.read_from_file(filepath);
}

void Controller::writeFile(std::string filepath)
{
	this->repo.write_to_file(filepath);
}

void Controller::writeFileCSV(std::string filepath)
{
	this->repo.write_to_csv_file(filepath);
}

void Controller::writeFileHTML(std::string filepath)
{
	this->repo.write_to_html_file(filepath);
}

void Controller::openFile(std::string filepath)
{
	this->repo.open_file(filepath);
}

/*
Gets all the elements from our repository.
*/
std::vector<Tutorial> Controller::get_elements_controller()
{
	return this->repo.get_elements_repo();
}

//Gets elements from the watch list
std::vector<Tutorial> Controller::get_elements_watch_list()
{
	return this->repo.get_elements_watch_list_repo();
}

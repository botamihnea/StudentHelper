#include "repository.h"
#include <random>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "exceptions.h"

using namespace std;
/*
It adds 10 random tutorials to our dynamic array.
*/



void Repository::generate_tutorials()
{
	std::string titles[10] = { "Classes", "Algorithms", "Introduction", "Types", "Declarations", "Backtracking",
	"Recursivity", "Loops", "Complexities", "Architecture" };
	std::string presenters[10] = { "Andrei", "Ioan", "Mihai", "Paul", "Mihnea", "Paul", "Bob", "Greg", "Vlad", "Paul" };
	int likes[10] = { 10, 100, 1000, 1500, 1700, 1800, 1950, 700, 900, 800 };
	int minutes[10] = { 10, 15, 20, 25, 30, 40, 45, 43, 35, 50 };
	int seconds[10] = { 12, 15, 18, 22, 25, 35, 36, 48, 49, 52 };
	std::string links[10] = { "https://Classes", "https://Basicalgorithms", "https://Introduction", "https://Datatypes",
	"https://Declarations", "https://Backtracking", "https://Recursivity", "https://Loops", "https://Complexities",
	"https://Layeredarchitecture" };
	for (int i = 0; i < 10; i++)
	{
		Tutorial tutorial = Tutorial(titles[i], presenters[i], minutes[i], seconds[i], likes[i], links[i]);
		add_tutorial(tutorial);
	}
}


void Repository::read_from_file(std::string filepath)
{
	ifstream fin(filepath);
	Tutorial tutorial;
	while (fin >> tutorial)
	{
		this->tutorials.push_back(tutorial);
	}

	fin.close();
}


/*
Constructor of the repository, initialization of the tutorials dyn. array and generates the random tutorials.
*/
Repository::Repository()
{
	this->tutorials = std::vector<Tutorial>();
	//generate_tutorials();
	read_from_file("tutorials.txt");
	this->watch_list = std::vector<Tutorial>();
}

Repository::~Repository()
{

}

/*
* Acceses the isAlready function to see if the tutorial having the parameters title and link is already in our dyn.array
*/
bool Repository::is_already_repo(std::string title, std::string link)
{
	Tutorial tutorial;
	tutorial = { title, "", 0, 0, 0, link };
	auto iterator = std::find(this->tutorials.begin(), this->tutorials.end(), tutorial);
	if (iterator != this->tutorials.end())
		return true;
	return false;
}

/*
* Acceses the isAlready function to see if the tutorial having the parameters title and link is already in our dyn.array
*/
bool Repository::is_already_watch_list(std::string title, std::string link)
{
	Tutorial tutorial;
	tutorial = { title, "", 0, 0, 0, link };
	auto iterator = std::find(this->watch_list.begin(), this->watch_list.end(), tutorial);
	if (iterator != this->watch_list.end())
		return true;
	return false;
}

/*
Acceses the add function of the dyn.array, the parameter tutorial represents the tutorial that will be added.
*/
void Repository::add_to_watch_list(Tutorial tutorial)
{
	if (this->is_already_watch_list(tutorial.getTitle(), tutorial.getLink()))
		throw Exception("This element already exists!");
	this->watch_list.push_back(tutorial);
}

void Repository::write_to_file(std::string filepath)
{
	ofstream fout(filepath);
	for (auto tutorial : this->tutorials)
		fout << tutorial;

	fout.close();
}

void Repository::write_to_csv_file(std::string filepath)
{
	ofstream fout(filepath);
	for (auto tutorial : this->watch_list)
		fout << tutorial;

	fout.close();
}

void Repository::write_to_html_file(std::string filepath)
{
	ofstream fout(filepath);
	fout << "<!DOCTYPE html>\n";
	fout << "<html>\n";
	fout << "<head>\n";
	fout << "<title>Watch List</title>\n";
	fout << "</head>\n";
	fout << "<body>\n";
	fout << "<table border=\"1\">\n";
	fout << "<tr>\n";
	fout << "<td>Title</td>\n";
	fout << "<td>Presenter</td>\n";
	fout << "<td>Minutes</td>\n";
	fout << "<td>Seconds</td>\n";
	fout << "<td>Likes</td>\n";
	fout << "<td>Link</td>\n";
	fout << "</tr>\n";
	for (auto tutorial : this->watch_list)
	{
		fout << "<tr>\n";
		fout << "<td>" << tutorial.getTitle() << "</td>\n";
		fout << "<td>" << tutorial.getPresenter() << "</td>\n";
		fout << "<td>" << tutorial.getMinutes() << "</td>\n";
		fout << "<td>" << tutorial.getSeconds() << "</td>\n";
		fout << "<td>" << tutorial.getLikes() << "</td>\n";
		fout << "<td><a href=\"" << tutorial.getLink() << "\">Link</a></td>\n";
		fout << "</tr>\n";
	}
	fout << "</table>\n";
	fout << "</body>\n";
	fout << "</html>\n";
	fout.close();
}

void Repository::open_file(std::string filepath)
{
	std::string command = "start " + filepath;
	system(command.c_str());
}

/*
Acceses the add function of the dyn.array, the parameter tutorial represents the tutorial that will be added.
*/
void Repository::add_tutorial(Tutorial tutorial)
{
	if (this->is_already_repo(tutorial.getTitle(), tutorial.getLink()))
		throw Exception("This element already exists!");
	this->tutorials.push_back(tutorial);
}

/*
Gets the elements from our dyn.array.
*/
std::vector<Tutorial> Repository::get_elements_repo()
{
	return this->tutorials;
}

/*
Gets the elements from our dyn.array.
*/
std::vector<Tutorial> Repository::get_elements_watch_list_repo()
{
	return this->watch_list;
}

/*
If the element doesnt exist, the function throws an exception, if it does then it finds the index of the element and acceses the remove function,
given the found index as a parameter. The title and link parameteres represent the unique elements of the tutorial which we want to remove.
*/
void Repository::remove_tutorial(std::string title, std::string link)
{
	int position = -1;
	int i = 0;
	Tutorial tutorial = { title, "", 0, 0, 0, link };
	auto iterator = std::find(this->tutorials.begin(), this->tutorials.end(), tutorial);

	if (std::distance(this->tutorials.begin(), iterator) < this->tutorials.size())
		position = std::distance(this->tutorials.begin(), iterator);

	if (position == -1)
		throw Exception("This element doesn't exist!");
	else
	{
		this->tutorials.erase(tutorials.begin() + position);
	}

	position = -1;
	int j = 0;
	iterator = std::find(this->watch_list.begin(), this->watch_list.end(), tutorial);
	if (std::distance(this->watch_list.begin(), iterator) < this->watch_list.size())
		position = std::distance(this->watch_list.begin(), iterator);

	if (position != -1)
		this->watch_list.erase(watch_list.begin() + position);

}


/*
If the element doesnt exist, the function throws an exception, if it does then it finds the index of the element and acceses the remove function,
given the found index as a parameter. The title and link parameteres represent the unique elements of the tutorial which we want to remove.
*/
void Repository::remove_tutorial_from_watch_list(std::string title, std::string link)
{
	int position = -1;
	int i = 0;
	Tutorial tutorial = { title, "", 0, 0, 0, link };
	if (this->watch_list.size() == 0)
		throw Exception("The watch list is empty!");
	auto iterator = std::find(this->watch_list.begin(), this->watch_list.end(), tutorial);

	if (std::distance(this->watch_list.begin(), iterator) < this->watch_list.size())
		position = std::distance(this->watch_list.begin(), iterator);

	if (position == -1)
		throw Exception("This element doesn't exist!");
	else
	{
		this->watch_list.erase(watch_list.begin() + position);
	}
}


/*
The function searches for our tutorial that will be updated. If there is such an element we update it with the new_parameters we have,
if not then it throws an exception. The title and link are there for the search of the old element.
*/
void Repository::update_tutorial(std::string title, std::string link, std::string new_title, std::string new_presenter, int new_minutes, int new_seconds,
	int new_likes, std::string new_link)
{
	int index = -1;
	int i = 0;
	for (auto& tutorial : this->tutorials)
	{
		if (tutorial.getTitle() == title && tutorial.getLink() == link)
			index = i;
		i++;
	}

	if (index == -1)
		throw Exception("This element does not exist!");
	else
	{
		Tutorial new_tutorial = Tutorial(new_title, new_presenter, new_minutes, new_seconds, new_likes, new_link);
		this->tutorials[index] = new_tutorial;
	}

	index = -1;
	i = 0;
	for (auto& watch_list_movie : this->watch_list)
	{
		if (watch_list_movie.getTitle() == title && watch_list_movie.getLink() == link)
			index = i;
		i++;
	}

	if (index != -1)
	{
		Tutorial new_tutorial = Tutorial(new_title, new_presenter, new_minutes, new_seconds, new_likes, new_link);
		this->watch_list[index] = new_tutorial;
	}

}


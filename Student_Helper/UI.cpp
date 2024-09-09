#include "UI.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "exceptions.h"
#include "validator.h"

using namespace std;

UI::UI()
{
	this->controller = Controller();
}

UI::~UI()
{
}

std::ostream& operator<<(std::ostream& out, const Tutorial& tutorial)
{
	char comma = ',';
	out << tutorial.title << ' ' << comma << ' '
		<< tutorial.presenter << ' ' << comma << ' '
		<< tutorial.minutes << ' ' << comma << ' ' << tutorial.seconds << ' ' << comma << ' '
		<< tutorial.likes << ' ' << comma << ' '
		<< tutorial.link;
	out << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Tutorial& tutorial)
{
	char comma = ',';
	in >> tutorial.title >> comma;
	in >> tutorial.presenter >> comma;
	in >> tutorial.minutes >> comma;
	in >> tutorial.seconds >> comma;
	in >> tutorial.likes >> comma;
	in >> tutorial.link;
	return in;
}

void UI::print_menu()
{
	cout << "Choose the type of file in which the watch list will be saved:\n";
	cout << "1.CSV\n";
	cout << "2.HTML\n";
	int file_option;
	cin >> file_option;
	cout << "Choose your desired option:\n";
	cout << "1.Administrator mode.\n";
	cout << "2.User mode.\n";
	int chosen_option;
	cin >> chosen_option;
	if (chosen_option == 1)
	{
		while (true)

		{
			try
			{
				while (true)
				{
					cout << "1.Add a tutorial.\n";
					cout << "2.Delete a tutorial.\n";
					cout << "3.Update a tutorial.\n";
					cout << "4.Display all tutorials.\n";
					cout << "5.Exit the program.\n";
					cout << "6.Go back to choice of mode.\n";
					cin >> chosen_option;
					Validator::validate_option(chosen_option);
					if (chosen_option == 1)
					{
						string title;
						string presenter;
						int minutes;
						int seconds;
						int likes;
						string link;
						cout << "Enter the title:";
						cin >> title;
						Validator::validate_title(title);
						std::cout << "Enter the presenter:";
						cin >> presenter;
						std::cout << "Enter the minutes:";
						cin >> minutes;
						Validator::validate_minutes(minutes);
						std::cout << "Enter the seconds:";
						cin >> seconds;
						Validator::validate_seconds(seconds);
						std::cout << "Enter the likes:";
						cin >> likes;
						std::cout << "Enter the link of the tutorial:";
						cin >> link;
						Validator::validate_link(link);
						this->controller.add_controller(title, presenter, minutes, seconds, likes, link);
						this->controller.writeFile("tutorials.txt");

					}
					else if (chosen_option == 2)
					{
						string title;
						string link;
						cout << "Enter the title of the tutorial you want to remove:";
						cin.get();
						getline(cin, title);
						Validator::validate_title(title);
						cout << "Enter the link of the tutorial you want to remove:";
						cin >> link;
						Validator::validate_link(link);
						this->controller.remove_controller(title, link);
						this->controller.writeFile("tutorials.txt");
					}
					else if (chosen_option == 3)
					{
						string old_title;
						string old_link;
						cout << "Enter the title of the tutorial you want to update:";
						cin.get();
						getline(cin, old_title);
						Validator::validate_title(old_title);
						cout << "Enter the link pointing to the tutorial you want to update:";
						cin >> old_link;
						Validator::validate_link(old_link);
						string title;
						string presenter;
						int minutes;
						int seconds;
						int likes;
						string link;
						cout << "Enter the title:";
						cin >> title;
						Validator::validate_title(title);
						std::cout << "Enter the presenter:";
						cin >> presenter;
						std::cout << "Enter the minutes:";
						cin >> minutes;
						Validator::validate_minutes(minutes);
						std::cout << "Enter the seconds:";
						cin >> seconds;
						Validator::validate_seconds(seconds);
						std::cout << "Enter the likes:";
						cin >> likes;
						std::cout << "Enter the link of the tutorial:";
						cin >> link;
						Validator::validate_link(link);
						this->controller.update_controller(old_title, old_link, title, presenter, minutes, seconds,
							likes, link);
						this->controller.writeFile("tutorials.txt");

					}
					else if (chosen_option == 4)
					{
						std::vector<Tutorial> array = this->controller.get_elements_controller();
						int size = array.size();

						Tutorial tutorial;
						for (auto& tutorial : array)
						{
							cout << "---------------------------------\n"
								<< "Title:" << tutorial.getTitle() << '\n'
								<< "Presenter:" << tutorial.getPresenter() << '\n'
								<< "Duration:" << tutorial.getMinutes() << ":" << tutorial.getSeconds() << '\n'
								<< "Likes:" << tutorial.getLikes() << '\n'
								<< "Link:" << tutorial.getLink() << '\n'
								<< "---------------------------------\n";
						}

					}
					else if (chosen_option == 5)
					{
						this->controller.writeFile("tutorials.txt");
						exit(0);
					}
					else if (chosen_option == 6)
						print_menu();
				}
			}
			catch (Exception& e)
			{
				std::cout << e.what() << endl;
			}
		}

	}
	else if (chosen_option == 2)
	{
		while (true)
		{
			try
			{
				while (true)
				{
					cout << "1.See the tutorials in the data base having a given presenter.\n";
					cout << "2.See the current watch list.\n";
					cout << "3.Go back to user choice mode.\n";
					cin >> chosen_option;
					Validator::validate_option2(chosen_option);
					if (chosen_option == 1)
					{
						std::vector<Tutorial> array = this->controller.get_elements_controller();
						int size = array.size();
						string presenter;
						cout << "Enter the name of the presenter:\n";
						cin.get();
						getline(cin, presenter);
						if (presenter == "")
						{
							int i = 0;
							Tutorial tutorial;
							while (i < size)
							{
								tutorial = array[i];
								cout << "---------------------------------\n"
									<< "Title:" << tutorial.getTitle() << '\n'
									<< "Presenter:" << tutorial.getPresenter() << '\n'
									<< "Duration:" << tutorial.getMinutes() << ":" << tutorial.getSeconds() << '\n'
									<< "Likes:" << tutorial.getLikes() << '\n'
									<< "Link:" << tutorial.getLink() << '\n'
									<< "---------------------------------\n";
								cout << "1.Add tutorial to the watch list.\n";
								cout << "2.Go to the next tutorial.\n";
								cout << "3.Remove the tutorial from the watch list.\n";
								cout << "4.Go back.\n";
								cin >> chosen_option;
								Validator::validate_option3(chosen_option);
								if (chosen_option == 2)
								{
									this->controller.go_to_next_tutorial(i, size);
									ShellExecuteA(0, 0, array[i].getLink().c_str(), 0, 0, SW_SHOW);
								}
								else if (chosen_option == 1)
								{
									this->controller.add_watch_controller(array[i].getTitle(), array[i].getPresenter(), array[i].getMinutes(), array[i].getSeconds(), array[i].getLikes(), array[i].getLink());
									cout << "You added in your list:\n";
									if (file_option == 1)
										this->controller.writeFileCSV("watch_list.csv");
									else if (file_option == 2)
										this->controller.writeFileHTML("watch_list.html");
								}
								else if (chosen_option == 3)
								{
									this->controller.remove_controller_watch_list(array[i].getTitle(), array[i].getLink());
									cout << "Did you like this tutorial?(y/n)\n";
									char answer;
									cin >> answer;
									if (answer == 'y')
									{
										this->controller.update_controller(array[i].getTitle(), array[i].getLink(), array[i].getTitle(), array[i].getPresenter(),
											array[i].getMinutes(), array[i].getSeconds(), array[i].getLikes() + 1, array[i].getLink());
									}
									if (file_option == 1)
										this->controller.writeFileCSV("watch_list.csv");
									else if (file_option == 2)
										this->controller.writeFileHTML("watch_list.html");
									break;
								}
								else if (chosen_option == 4)
									break;
							}
						}
						else
						{
							int i = 0;
							Tutorial tutorial;
							while (i < size)
							{
								if (array[i].getPresenter() == presenter)
								{
									tutorial = array[i];
									cout << "---------------------------------\n"
										<< "Title:" << tutorial.getTitle() << '\n'
										<< "Presenter:" << tutorial.getPresenter() << '\n'
										<< "Duration:" << tutorial.getMinutes() << ":" << tutorial.getSeconds() << '\n'
										<< "Likes:" << tutorial.getLikes() << '\n'
										<< "Link:" << tutorial.getLink() << '\n'
										<< "---------------------------------\n";

									cout << "1.Add tutorial to the watch list.\n";
									cout << "2.Go to the next tutorial.\n";
									cout << "3.Remove the tutorial from the watch list.\n";
									cout << "4.Go back.\n";
									cin >> chosen_option;
									Validator::validate_option3(chosen_option);
									if (chosen_option == 2)
									{
										this->controller.go_to_next_tutorial(i, size);
										ShellExecuteA(0, 0, array[i].getLink().c_str(), 0, 0, SW_SHOW);
									}
									else if (chosen_option == 1)
									{
										this->controller.add_watch_controller(array[i].getTitle(), array[i].getPresenter(), array[i].getMinutes(), array[i].getSeconds(), array[i].getLikes(), array[i].getLink());
										cout << "You added in your list:\n";
										if (file_option == 1)
											this->controller.writeFileCSV("watch_list.csv");
										else if (file_option == 2)
											this->controller.writeFileHTML("watch_list.html");
									}
									else if (chosen_option == 3)
									{
										this->controller.remove_controller_watch_list(array[i].getTitle(), array[i].getLink());
										cout << "Did you like this tutorial?(y/n)\n";
										char answer;
										cin >> answer;
										if (answer == 'y')
										{
											this->controller.update_controller(array[i].getTitle(), array[i].getLink(), array[i].getTitle(), array[i].getPresenter(),
												array[i].getMinutes(), array[i].getSeconds(), array[i].getLikes() + 1, array[i].getLink());
										}
										if (file_option == 1)
											this->controller.writeFileCSV("watch_list.csv");
										else if (file_option == 2)
											this->controller.writeFileHTML("watch_list.html");
										break;
									}
									else if (chosen_option == 4)
										break;
								}
								else
								{
									this->controller.go_to_next_tutorial(i, size);
								}
							}

						}

					}
					else if (chosen_option == 2)
					{
						std::vector<Tutorial> watch_list = this->controller.get_elements_watch_list();
						int size = watch_list.size();
						if (file_option == 1)
							this->controller.openFile("watch_list.csv");
						else if (file_option == 2)
							this->controller.openFile("watch_list.html");
						/*
						Tutorial tutorial;
						for (auto& tutorial : watch_list)
						{
							cout << "---------------------------------\n"
								<< "Title:" << tutorial.getTitle() << '\n'
								<< "Presenter:" << tutorial.getPresenter() << '\n'
								<< "Duration:" << tutorial.getMinutes() << ":" << tutorial.getSeconds() << '\n'
								<< "Likes:" << tutorial.getLikes() << '\n'
								<< "Link:" << tutorial.getLink() << '\n'
								<< "---------------------------------\n";
						}
						*/
						break;
					}
					else if (chosen_option == 3)
						print_menu();
				}
			}
			catch (Exception& e)
			{
				std::cout << e.what() << endl;
			}
		}
	}
}


#pragma once
#include "gui.h"

class UserWidget : public QWidget
{
	Q_OBJECT
protected:
	Controller* controller;
	std::string filepath;
	bool presenterRowAdded;
public:
	explicit UserWidget(QWidget* parent = nullptr, Controller* controller = nullptr, std::string filepath = "");

	QPushButton* seeTutorialsButton;
	QPushButton* goToNextTutorialButton;
	QPushButton* seeWatchListButton;
	QPushButton* backButton;
	QPushButton* presenterButton;
	QPushButton* addToWatchListButton;
	QPushButton* removeWatchListButton;
	QPushButton* openFileButton;

	QLineEdit* presenterLine;

	QFormLayout* listFormLayout{};

	int currentIndex;
	int currentSize;
	std::vector <Tutorial> filteredTutorials;
	std::string presenter;

	QVBoxLayout* mainLayout;

	QTableWidget* tableWidget{};

public slots:
	void seeTutorialGUI();
	void seeWatchListGUI();
	void goBackGUI();
	void filterByPresenterGUI();
	void setPresenterGUI();

	void addToWatchListGUI();
	void removeWatchListGUI();
	void openFileGUI();

	void setUpOpenButton();
	void setUpBackButton();
	void goToNextTutorialGUI();
	void setUpWatchListButton();
	void seeTutorialButton();
};
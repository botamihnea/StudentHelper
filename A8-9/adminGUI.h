#pragma once
#include "gui.h"

class AdminWidget: public QWidget
{
	Q_OBJECT
protected:
	Controller* controller;
	QPushButton* adminButton;
	QPushButton* userButton;
public:
	explicit AdminWidget(QWidget* parent = nullptr, Controller* controller = nullptr, QPushButton* adminButton = nullptr, QPushButton* userButton = nullptr);

	QPushButton* listTutorialsButton;
	QPushButton* addTutorialButton;
	QPushButton* removeTutorialButton;
	QPushButton* updateTutorialButton;
	QPushButton* backButton;
	QPushButton* backToUserButton;

	QVBoxLayout* mainLayout;
	QFormLayout* addFormLayout{};
	QFormLayout* removeFormLayout{};
	QFormLayout* updateFormLayout{};
	QTableWidget* tableWidget{};

	//QGroupBox* getTutorialDetailsGroupBox{};
	QLineEdit* titleLine{};
	QLineEdit* presenterLine{};
	QLineEdit* minutesLine{};
	QLineEdit* secondsLine{};
	QLineEdit* likesLine{};
	QLineEdit* linkLine{};

	//for adding
	QGroupBox* addTutorialGroupBox{};
	QPushButton* addTutorialDetailsButton{};

	//for removing
	QLineEdit* titleToBeRemovedLine{};
	QLineEdit* linkToBeRemovedLine{};
	QGroupBox* removeTutorialGroupBox{};
	QPushButton* removeTutorialDetailsButton{};

	//for updating
	QLineEdit* titleToBeUpdatedLine{};
	QLineEdit* linkToBeUpdatedLine{};
	QLineEdit* newTitleLine{};
	QLineEdit* newPresenterLine{};
	QLineEdit* newMinutesLine{};
	QLineEdit* newSecondsLine{};
	QLineEdit* newLikesLine{};
	QLineEdit* newLinkLine{};
	QGroupBox* updateTutorialGroupBox{};
	QPushButton* updateTutorialDetailsButton{};

	//void getTutorialDetails();
	void hideTutorialDetails();

public slots:
	void listTutorialsGUI();
	void addTutorialGUI();
	void goBackGUI();
	void setUpListButton();

	void setUpAddButton();
	void setUpAddGroupBox();
	void setUpBackToUserButton();
	void addTutorialDetails();

	void setUpRemoveButton();
	void setUpRemoveGroupBox();
	void removeTutorialDetails();
	void removeTutorialGUI();

	void setUpUpdateButton();
	void setUpUpdateGroupBox();
	void updateTutorialDetails();
	void updateTutorialGUI();

	void setUpBackButton();
	void hideButtons();
	void showButtons();

	void goBackToUserGUI();
};
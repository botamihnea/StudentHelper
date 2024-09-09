#include "adminGUI.h"
#include <iostream>
#include "exceptions.h"

AdminWidget::AdminWidget(QWidget* parent, Controller* controller, QPushButton* adminButton, QPushButton* userButton)
{
	this->setWindowTitle("Admin menu");
	this->mainLayout = new QVBoxLayout(this);
	this->setUpListButton();
	this->setUpAddButton();
	this->setUpRemoveButton();
	this->setUpUpdateButton();
	this->setUpBackButton();
	this->backButton->hide();
	this->setUpBackToUserButton();
	this->adminButton = adminButton;
	this->userButton = userButton;
	this->controller = controller;
	this->tableWidget = new QTableWidget(this);
	this->resize(850, 850);

	//this->getTutorialDetails();
	this->setUpAddGroupBox();
	this->setUpRemoveGroupBox();
	this->setUpUpdateGroupBox();
}

void AdminWidget::listTutorialsGUI()
{
	this->listTutorialsButton->hide();
	//this->controller->readFile("tutorials.txt");
	std::vector<Tutorial> tutorials = this->controller->get_elements_controller();
	int size = tutorials.size();
	this->tableWidget->setRowCount(size);
	this->tableWidget->setColumnCount(6);

	QStringList headers = { "Title", "Presenter", "Minutes", "Seconds", "Likes", "Link" };
	this->tableWidget->setHorizontalHeaderLabels(headers);

	for (int i = 0; i < size; i++)
	{
		Tutorial tutorial;
		tutorial = tutorials[i];
		this->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(tutorial.getTitle())));
		this->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(tutorial.getPresenter())));
		this->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(tutorial.getMinutes())));
		this->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(tutorial.getSeconds())));
		this->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(tutorial.getLikes())));
		this->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(tutorial.getLink())));
	}

	this->mainLayout->addWidget(this->tableWidget);
	this->tableWidget->show();
	this->mainLayout->addWidget(this->backButton);
	this->backButton->show();

}


void AdminWidget::hideTutorialDetails()
{
	//this->getTutorialDetailsGroupBox->hide();
	this->titleLine->clear();
	this->presenterLine->clear();
	this->minutesLine->clear();
	this->secondsLine->clear();
	this->likesLine->clear();
	this->linkLine->clear();
}

void AdminWidget::addTutorialGUI()
{
	this->hideButtons();
	this->addTutorialGroupBox->show();
	//this->getTutorialDetailsGroupBox->show();
}

void AdminWidget::goBackGUI()
{
	this->tableWidget->hide();
	this->backButton->hide();
	this->showButtons();
}

void AdminWidget::setUpListButton()
{
	this->listTutorialsButton = new QPushButton("List all tutorials.", this);
	this->listTutorialsButton->setGeometry(150, 300, 200, 200);
	connect(this->listTutorialsButton, &QPushButton::clicked, this, &AdminWidget::listTutorialsGUI);
}

void AdminWidget::setUpAddButton()
{
	this->addTutorialButton = new QPushButton("Add a tutorial.", this);
	this->addTutorialButton->setGeometry(350, 300, 200, 200);
	connect(this->addTutorialButton, &QPushButton::clicked, this, &AdminWidget::addTutorialGUI);
}

void AdminWidget::setUpAddGroupBox()
{
	addTutorialGroupBox = new QGroupBox("Add tutorial", this);

	this->titleLine = new QLineEdit();
	this->presenterLine = new QLineEdit();
	this->minutesLine = new QLineEdit();
	this->secondsLine = new QLineEdit();
	this->likesLine = new QLineEdit();
	this->linkLine = new QLineEdit();

	this->addFormLayout = new QFormLayout();
	this->addFormLayout->addRow("Title: ", titleLine);
	this->addFormLayout->addRow("Presenter: ", presenterLine);
	this->addFormLayout->addRow("Minutes: ", minutesLine);
	this->addFormLayout->addRow("Seconds: ", secondsLine);
	this->addFormLayout->addRow("Likes: ", likesLine);
	this->addFormLayout->addRow("Link: ", linkLine);

	auto vbox = new QVBoxLayout();
	vbox->addLayout(this->addFormLayout);

	addTutorialDetailsButton = new QPushButton("Add tutorial", addTutorialGroupBox);
	vbox->addWidget(addTutorialDetailsButton);
	connect(addTutorialDetailsButton, &QPushButton::clicked, this, &AdminWidget::addTutorialDetails);

	addTutorialGroupBox->setLayout(vbox);
	mainLayout->addWidget(addTutorialGroupBox);

	this->addTutorialGroupBox->hide();
}

void AdminWidget::setUpBackToUserButton()
{
	this->backToUserButton = new QPushButton("Go back to user choice menu.", this);
	this->backToUserButton->setGeometry(550, 300, 200, 200);
	connect(this->backToUserButton, &QPushButton::clicked, this, &AdminWidget::goBackToUserGUI);
}

void AdminWidget::addTutorialDetails()
{
	this->addTutorialGroupBox->show();
	QString title = titleLine->text();
	QString presenter = presenterLine->text();
	int minutes = minutesLine->text().toInt();
	int seconds = secondsLine->text().toInt();
	int likes = likesLine->text().toInt();
	QString link = linkLine->text();

	//Tutorial new_tutorial = Tutorial(title.toStdString(), presenter.toStdString(), minutes, seconds, likes, link.toStdString());

	try
	{
		this->controller->add_controller(title.toStdString(), presenter.toStdString(), minutes, seconds, likes, link.toStdString());
	}
	catch (Exception& e)
	{
		QMessageBox::information(nullptr, "Error", QString::fromUtf8(e.what()));
	}

	this->addTutorialGroupBox->hide();
	this->hideTutorialDetails();
	this->controller->writeFile("tutorials.txt");
	this->showButtons();
}

void AdminWidget::setUpRemoveButton()
{
	this->removeTutorialButton = new QPushButton("Remove a tutorial.", this);
	this->removeTutorialButton->setGeometry(350, 500, 200, 200);
	connect(this->removeTutorialButton, &QPushButton::clicked, this, &AdminWidget::removeTutorialGUI);
}

void AdminWidget::setUpRemoveGroupBox()
{
	removeTutorialGroupBox = new QGroupBox("Remove tutorial", this);

	this->titleToBeRemovedLine = new QLineEdit();
	this->linkToBeRemovedLine = new QLineEdit();
	this->removeFormLayout = new QFormLayout();
	this->removeFormLayout->addRow("Title: ", titleToBeRemovedLine);
	this->removeFormLayout->addRow("Link: ", linkToBeRemovedLine);

	auto vbox = new QVBoxLayout();
	vbox->addLayout(removeFormLayout);

	removeTutorialDetailsButton = new QPushButton("Remove tutorial", removeTutorialGroupBox);
	vbox->addWidget(removeTutorialDetailsButton);
	connect(removeTutorialDetailsButton, &QPushButton::clicked, this, &AdminWidget::removeTutorialDetails);

	removeTutorialGroupBox->setLayout(vbox);
	mainLayout->addWidget(removeTutorialGroupBox);

	this->removeTutorialGroupBox->hide();
}

void AdminWidget::removeTutorialDetails()
{
	this->removeTutorialGroupBox->show();
	QString title_to_remove = this->titleToBeRemovedLine->text();
	QString link_to_remove = this->linkToBeRemovedLine->text();
	try
	{
		this->controller->remove_controller(title_to_remove.toStdString(), link_to_remove.toStdString());
	}
	catch (Exception& e)
	{
		QMessageBox::information(nullptr, "Error", QString::fromUtf8(e.what()));
	}
	this->removeTutorialGroupBox->hide();
	this->controller->writeFile("tutorials.txt");
	this->titleToBeRemovedLine->clear();
	this->linkToBeRemovedLine->clear();
	this->showButtons();
}

void AdminWidget::removeTutorialGUI()
{
	this->hideButtons();
	this->removeTutorialGroupBox->show();
}

void AdminWidget::setUpUpdateButton()
{
	this->updateTutorialButton = new QPushButton("Update a tutorial.", this);
	this->updateTutorialButton->setGeometry(150, 500, 200, 200);
	connect(this->updateTutorialButton, &QPushButton::clicked, this, &AdminWidget::updateTutorialGUI);
}

void AdminWidget::setUpUpdateGroupBox()
{
	updateTutorialGroupBox = new QGroupBox("Update tutorial", this);

	this->titleToBeUpdatedLine = new QLineEdit();
	this->linkToBeUpdatedLine = new QLineEdit();
	this->newTitleLine = new QLineEdit();
	this->newPresenterLine = new QLineEdit();
	this->newMinutesLine = new QLineEdit();
	this->newSecondsLine = new QLineEdit();
	this->newLikesLine = new QLineEdit();
	this->newLinkLine = new QLineEdit();

	this->updateFormLayout = new QFormLayout();
	this->updateFormLayout->addRow("Title: ", titleToBeUpdatedLine);
	this->updateFormLayout->addRow("Link: ", linkToBeUpdatedLine);
	this->updateFormLayout->addRow("New title: ", newTitleLine);
	this->updateFormLayout->addRow("New presenter: ", newPresenterLine);
	this->updateFormLayout->addRow("New minutes: ", newMinutesLine);
	this->updateFormLayout->addRow("New seconds: ", newSecondsLine);
	this->updateFormLayout->addRow("New likes: ", newLikesLine);
	this->updateFormLayout->addRow("New link: ", newLinkLine);

	auto vbox = new QVBoxLayout();
	vbox->addLayout(updateFormLayout);

	updateTutorialDetailsButton = new QPushButton("Update tutorial", updateTutorialGroupBox);
	vbox->addWidget(updateTutorialDetailsButton);
	connect(updateTutorialDetailsButton, &QPushButton::clicked, this, &AdminWidget::updateTutorialDetails);

	updateTutorialGroupBox->setLayout(vbox);
	mainLayout->addWidget(updateTutorialGroupBox);

	this->updateTutorialGroupBox->hide();
}

void AdminWidget::updateTutorialDetails()
{
	this->updateTutorialGroupBox->show();
	QString title_to_update = this->titleToBeUpdatedLine->text();
	QString link_to_update = this->linkToBeUpdatedLine->text();
	QString new_title = this->newTitleLine->text();
	QString new_presenter = this->newPresenterLine->text();
	int new_minutes = this->newMinutesLine->text().toInt();
	int new_seconds = this->newSecondsLine->text().toInt();
	int new_likes = this->newLikesLine->text().toInt();
	QString new_link = this->newLinkLine->text();

	try
	{
		this->controller->update_controller(title_to_update.toStdString(), link_to_update.toStdString(), new_title.toStdString(), new_presenter.toStdString(), new_minutes, new_seconds, new_likes, new_link.toStdString());
	}
	catch (Exception& e)
	{
		QMessageBox::information(nullptr, "Error", QString::fromUtf8(e.what()));
	}
	this->updateTutorialGroupBox->hide();
	this->controller->writeFile("tutorials.txt");
	this->titleToBeUpdatedLine->clear();
	this->linkToBeUpdatedLine->clear();
	this->newTitleLine->clear();
	this->newPresenterLine->clear();
	this->newMinutesLine->clear();
	this->newSecondsLine->clear();
	this->newLikesLine->clear();
	this->newLinkLine->clear();
	this->showButtons();
}

void AdminWidget::updateTutorialGUI()
{
	this->hideButtons();
	this->updateTutorialGroupBox->show();

}

void AdminWidget::setUpBackButton()
{
	this->backButton = new QPushButton("Go back.", this);
	this->backButton->setGeometry(550, 400, 200, 200);
	connect(this->backButton, &QPushButton::clicked, this, &AdminWidget::goBackGUI);
}

void AdminWidget::hideButtons()
{
	this->addTutorialButton->hide();
	this->removeTutorialButton->hide();
	this->updateTutorialButton->hide();
	this->listTutorialsButton->hide();
	this->backButton->hide();
	this->backToUserButton->hide();
}

void AdminWidget::showButtons()
{
	this->addTutorialButton->show();
	this->removeTutorialButton->show();
	this->updateTutorialButton->show();
	this->listTutorialsButton->show();
	this->backToUserButton->show();
	//this->backButton->show();
}

void AdminWidget::goBackToUserGUI()
{
	hideButtons();
	this->mainLayout->addWidget(this->adminButton);
	this->adminButton->show();
	this->mainLayout->addWidget(this->userButton);
	this->userButton->show();
}



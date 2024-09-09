#include "userGUI.h"
#include <windows.h>
#include <exceptions.h>

UserWidget::UserWidget(QWidget* parent, Controller* controller, std::string filepath)
{
	this->setWindowTitle("User menu");
	this->mainLayout = new QVBoxLayout(this);
	this->filepath = filepath;
	this->resize(850, 850);
	this->setUpWatchListButton();
	this->setUpBackButton();
	this->backButton->hide();
	this->seeTutorialButton();
	this->setUpOpenButton();
	this->controller = controller;
	this->presenter = "";
	this->tableWidget = new QTableWidget(this);
	this->currentIndex = 0;
	//this->resize(850, 850);
}


void UserWidget::seeWatchListGUI()
{
	
	this->seeWatchListButton->hide();
	std::vector<Tutorial> tutorials = this->controller->get_elements_watch_list();
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

void UserWidget::seeTutorialGUI()
{
	this->seeTutorialsButton->hide();
	std::vector<Tutorial> tutorials = this->controller->get_elements_controller();
	this->tableWidget->setRowCount(1);
	this->tableWidget->setColumnCount(6);

	this->presenterLine = new QLineEdit();
	this->listFormLayout = new QFormLayout();

	this->listFormLayout->addRow("", this->presenterLine);


	QStringList headers = { "Title", "Presenter", "Minutes", "Seconds", "Likes", "Link" };
	this->tableWidget->setHorizontalHeaderLabels(headers);
	int size = tutorials.size();
	this->currentSize = size;
	this->currentIndex = 0;
	auto vbox = new QVBoxLayout();
	
	this->mainLayout->insertLayout(0, listFormLayout);


	this->presenterButton = new QPushButton("Filter by presenter.", this);
	this->presenterButton->setGeometry(150, 300, 200, 200);
	connect(this->presenterButton, &QPushButton::clicked, this, &UserWidget::setPresenterGUI);

	this->goToNextTutorialButton = new QPushButton("Go to next tutorial.", this);
	this->goToNextTutorialButton->setGeometry(150, 300, 200, 200);
	connect(this->goToNextTutorialButton, &QPushButton::clicked, this, &UserWidget::goToNextTutorialGUI);

	this->addToWatchListButton = new QPushButton("Add to watch list.", this);
	this->addToWatchListButton->setGeometry(150, 300, 200, 200);
	connect(this->addToWatchListButton, &QPushButton::clicked, this, &UserWidget::addToWatchListGUI);

	this->removeWatchListButton = new QPushButton("Remove from watch list.", this);
	this->removeWatchListButton->setGeometry(150, 300, 200, 200);
	connect(this->removeWatchListButton, &QPushButton::clicked, this, &UserWidget::removeWatchListGUI);
    
	this->mainLayout->addWidget(this->presenterButton);
	this->presenterButton->show();
	this->mainLayout->addWidget(this->tableWidget);
	this->tableWidget->show();
	this->mainLayout->addWidget(this->goToNextTutorialButton);
	this->goToNextTutorialButton->show();
	this->mainLayout->addWidget(this->addToWatchListButton);
	this->addToWatchListButton->show();
	this->mainLayout->addWidget(this->removeWatchListButton);
	this->removeWatchListButton->show();
	this->mainLayout->addWidget(this->backButton);
	this->backButton->show();
}

void UserWidget::goToNextTutorialGUI()
{
	std::vector<Tutorial> tutorials = this->controller->get_elements_controller();
	this->currentSize = tutorials.size();
	if (this->presenter != "")
	{
		tutorials = this->filteredTutorials;
		this->currentSize = this->filteredTutorials.size();
	}

    this->tableWidget->clearContents();
	Tutorial currentTutorial;
	currentTutorial = tutorials[this->currentIndex];

	QTableWidgetItem* titleItem = new QTableWidgetItem(QString::fromStdString(currentTutorial.getTitle()));
	this->tableWidget->setItem(0 , 0, titleItem);
	QTableWidgetItem* presenterItem = new QTableWidgetItem(QString::fromStdString(currentTutorial.getPresenter()));
	this->tableWidget->setItem(0 , 1, presenterItem);
	QTableWidgetItem* minutesItem = new QTableWidgetItem(QString::number(currentTutorial.getMinutes()));
	this->tableWidget->setItem(0 , 2, minutesItem);
	QTableWidgetItem* secondsItem = new QTableWidgetItem(QString::number(currentTutorial.getSeconds()));
	this->tableWidget->setItem(0 , 3, secondsItem);
	QTableWidgetItem* likesItem = new QTableWidgetItem(QString::number(currentTutorial.getLikes()));
	this->tableWidget->setItem(0, 4, likesItem);
	QTableWidgetItem* linkItem = new QTableWidgetItem(QString::fromStdString(currentTutorial.getLink()));
	this->tableWidget->setItem(0, 5, linkItem);
	
	try
	{
		this->controller->go_to_next_tutorial(this->currentIndex, this->currentSize);
	}
	catch (Exception& e)
	{
		QMessageBox::information(nullptr, "Error", QString::fromUtf8(e.what()));
	}
	if (this->currentIndex != 0)
		ShellExecuteA(0, 0, tutorials[this->currentIndex - 1].getLink().c_str(), 0, 0, SW_SHOW);
	else
		ShellExecuteA(0, 0, tutorials[this->currentIndex].getLink().c_str(), 0, 0, SW_SHOW);
}

void UserWidget::goBackGUI()
{
	this->tableWidget->hide();
	this->backButton->hide();
	this->removeWatchListButton->hide();
	this->presenterButton->hide();
	this->goToNextTutorialButton->hide();
	this->presenterLine->hide();
	this->addToWatchListButton->hide();
	this->tableWidget->clearContents();
	//this->listFormLayout->removeRow(this->presenterLine);
	this->seeWatchListButton->show();
	this->seeTutorialsButton->show();
}

void UserWidget::filterByPresenterGUI()
{
	std::vector<Tutorial> tutorials = this->controller->get_elements_controller();
	this->filteredTutorials.clear();

	for (auto tutorial : tutorials)
	{
		if (tutorial.getPresenter() == this->presenter)
			this->filteredTutorials.push_back(tutorial);
	}
}

void UserWidget::setPresenterGUI()
{
	this->presenter = this->presenterLine->text().toStdString();
	filterByPresenterGUI();
}

void UserWidget::addToWatchListGUI()
{
	std::vector<Tutorial> tutorials = this->controller->get_elements_controller();
	this->currentSize = tutorials.size();
	if (this->presenter != "")
	{
		tutorials = this->filteredTutorials;
		this->currentSize = this->filteredTutorials.size();
	}

	try
	{
		if(this->currentIndex == 0)
			this->controller->add_watch_controller(tutorials[this->currentSize - 1].getTitle(), tutorials[this->currentSize - 1].getPresenter(), tutorials[this->currentSize - 1].getMinutes(), tutorials[this->currentSize - 1].getSeconds(),
				tutorials[this->currentSize - 1].getLikes(), tutorials[this->currentSize - 1].getLink());
		else
			this->controller->add_watch_controller(tutorials[this->currentIndex - 1].getTitle(), tutorials[this->currentIndex - 1].getPresenter(), tutorials[this->currentIndex - 1].getMinutes(), tutorials[this->currentIndex - 1].getSeconds(), 
				tutorials[this->currentIndex - 1].getLikes(), tutorials[this->currentIndex - 1].getLink());


	}
	catch (Exception& e)
	{
		QMessageBox::information(nullptr, "Error", QString::fromUtf8(e.what()));
	}

	if (this->filepath == "watch_list.html")
	{
		this->controller->writeFileHTML(this->filepath);
	}
	else
	{
		this->controller->writeFileCSV(this->filepath);
	}
}

void UserWidget::removeWatchListGUI()
{
	std::vector<Tutorial> tutorials = this->controller->get_elements_watch_list();
	std::vector<Tutorial>all_tutorials = this->controller->get_elements_controller();
	this->currentSize = tutorials.size();
	int size = tutorials.size();
	int indexforRemove = -1;

	if (this->presenter != "")
	{
		tutorials = this->filteredTutorials;
		this->currentSize = this->filteredTutorials.size();
	}

	if (this->currentIndex != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (tutorials[i].getTitle() == all_tutorials[this->currentIndex - 1].getTitle() && tutorials[i].getLink() == all_tutorials[currentIndex - 1].getLink())
				indexforRemove = i;
		}
	}

	try
	{
		if(this->currentIndex == 0 || indexforRemove == -1)
			this->controller->remove_controller_watch_list(tutorials[0].getTitle(), tutorials[0].getLink());
		else
			this->controller->remove_controller_watch_list(tutorials[indexforRemove].getTitle(), tutorials[indexforRemove].getLink());
	}
	catch (Exception& e)
	{
		QMessageBox::information(nullptr, "Error", QString::fromUtf8(e.what()));
	}

	if (this->filepath == "watch_list.html")
	{
		this->controller->writeFileHTML(this->filepath);
	}
	else
	{
		this->controller->writeFileCSV(this->filepath);
	}
}

void UserWidget::openFileGUI()
{
	if (this->filepath == "watch_list.html")
		system("watch_list.html");
	else
		system("watch_list.csv");
}

void UserWidget::setUpOpenButton()
{
	this->openFileButton = new QPushButton("Open file.", this);
	this->openFileButton->setGeometry(50, 300, 200, 200);
	connect(this->openFileButton, &QPushButton::clicked, this, &UserWidget::openFileGUI);
}

void UserWidget::setUpBackButton()
{
	this->backButton = new QPushButton("Go back.", this);
	this->backButton->setGeometry(150, 300, 200, 200);
	connect(this->backButton, &QPushButton::clicked, this, &UserWidget::goBackGUI);
}


void UserWidget::setUpWatchListButton()
{
	this->seeWatchListButton = new QPushButton("See watch list.", this);
	this->seeWatchListButton->setGeometry(350, 300, 200, 200);
	connect(this->seeWatchListButton, &QPushButton::clicked, this, &UserWidget::seeWatchListGUI);
}

void UserWidget::seeTutorialButton()
{
	this->seeTutorialsButton = new QPushButton("See each tutorial in the list.", this);
	this->seeTutorialsButton->setGeometry(550, 300, 200, 200);
	connect(this->seeTutorialsButton, &QPushButton::clicked, this, &UserWidget::seeTutorialGUI);
}

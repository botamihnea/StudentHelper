#include "gui.h"
#include "adminGUI.h"
#include "userGUI.h"

MainWidget::MainWidget(QWidget* parent): QWidget(parent)
{
	this->selectAdminButton = new QPushButton;
	this->selectUserButton = new QPushButton;
	this->HTMLButton = new QPushButton;
	this->CSVButton = new QPushButton;
	this->controller = new Controller();
	this->resize(850, 850);
	this->mainLayout = new QVBoxLayout();
	this->mainLayout->setAlignment(Qt::AlignCenter);
	this->mainLayout->setSpacing(20);
	this->mainLayout->setContentsMargins(10, 10, 10, 10);

	this->setUpController();
}

void MainWidget::selectMode()
{
	this->setWindowTitle("Select the desired mode:");

	this->selectAdminButton = new QPushButton("Admin", this);
	this->selectAdminButton->resize(100, 100);
	this->selectAdminButton->setGeometry(150, 300, 200, 200);
	this->selectAdminButton->show();
	connect(selectAdminButton, &QPushButton::clicked, this, &MainWidget::selectAdmin);

	this->selectUserButton = new QPushButton("User", this);
	this->selectUserButton->resize(100, 100);
	this->selectUserButton->setGeometry(450, 300, 200, 200);
	this->selectUserButton->show();
	connect(selectUserButton, &QPushButton::clicked, this, &MainWidget::selectUser);
}

void MainWidget::setUpController()
{
	this->setWindowTitle("Select the desired type of file:");

	this->HTMLButton = new QPushButton("HTML", this);
	this->HTMLButton->resize(100, 100);
	this->HTMLButton->setGeometry(150, 300, 200, 200);
	connect(HTMLButton, &QPushButton::clicked, this, &MainWidget::selectHTML);

	this->CSVButton = new QPushButton("CSV", this);
	this->CSVButton->resize(100, 100);
	this->CSVButton->setGeometry(450, 300, 200, 200);
	connect(CSVButton, &QPushButton::clicked, this, &MainWidget::selectCSV);

	this->mainLayout->addWidget(this->HTMLButton);
	this->mainLayout->addWidget(this->CSVButton);

}

void MainWidget::selectAdmin()
{
	this->close();
	auto adminMenu = new AdminWidget(nullptr, this->controller, this->selectAdminButton, this->selectUserButton);
	adminMenu->show();
}

void MainWidget::selectHTML()
{
	this->HTMLButton->hide();
	this->CSVButton->hide();
	this->filepath = "watch_list.html";
	this->function = &Controller::writeFileHTML;
	this->selectMode();
	//(controller->*function)(filepath);
}

void MainWidget::selectCSV()
{
	this->HTMLButton->hide();
	this->CSVButton->hide();
	this->filepath = "watch_list.csv";
	this->function = &Controller::writeFileCSV;
	this->selectMode();
}

void MainWidget::selectUser()
{
	this->close();
	auto userMenu = new UserWidget(nullptr, this->controller, this->filepath);
	userMenu->show();
}

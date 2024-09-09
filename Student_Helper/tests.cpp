#include "tests.h"
#include <assert.h>
#include "exceptions.h"
//#include <vector>

Tests::Tests()
{
	this->controller = Controller();
}

void Tests::testAdd()
{
	assert(this->controller.get_elements_controller().size() == 10);
	this->controller.add_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	assert(this->controller.get_elements_controller().size() == 11);
	bool exceptionThrown = false;
	try
	{
		this->controller.add_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	}
	catch (const Exception& e)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown == true);
	assert(this->controller.get_elements_controller().size() == 11);
}

void Tests::testRemove()
{
	this->controller.add_watch_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	assert(this->controller.get_elements_watch_list().size() == 1);
	this->controller.remove_controller("TestTutorial", "https://test");
	assert(this->controller.get_elements_controller().size() == 10);
	this->controller.remove_controller("Loops", "https://Loops");
	assert(this->controller.get_elements_controller().size() == 9);
	bool exception_thrown = false;
	try
	{
		this->controller.remove_controller("NuExista", "https://NuExista");
	}
	catch (const std::exception& e)
	{
		exception_thrown = true;
	}
	assert(exception_thrown == true);
	this->controller.add_controller("Loops", "Greg", 10, 10, 100, "https://Loops");
	assert(this->controller.get_elements_controller().size() == 10);
	assert(this->controller.get_elements_watch_list().size() == 0);
}

void Tests::testUpdate()
{
	this->controller.add_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	this->controller.add_watch_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	this->controller.update_controller("TestTutorial", "https://test", "new_tutorial", "Gabi", 15, 15, 900, "https://new");
	assert(this->controller.get_elements_controller()[10].getPresenter() == "Gabi");
	assert(this->controller.get_elements_controller()[10].getTitle() == "new_tutorial");
	assert(this->controller.get_elements_controller()[10].getMinutes() == 15);
	assert(this->controller.get_elements_controller()[10].getSeconds() == 15);
	assert(this->controller.get_elements_controller()[10].getLikes() == 900);
	assert(this->controller.get_elements_controller()[10].getLink() == "https://new");
	assert(this->controller.get_elements_watch_list()[0].getPresenter() == "Gabi");
	assert(this->controller.get_elements_watch_list()[0].getTitle() == "new_tutorial");
	assert(this->controller.get_elements_watch_list()[0].getMinutes() == 15);
	assert(this->controller.get_elements_watch_list()[0].getSeconds() == 15);
	assert(this->controller.get_elements_watch_list()[0].getLikes() == 900);
	assert(this->controller.get_elements_watch_list()[0].getLink() == "https://new");
	assert(this->controller.get_elements_controller().size() == 11);
	assert(this->controller.get_elements_watch_list().size() == 1);
	this->controller.remove_controller_watch_list("new_tutorial", "https://new");
	bool exception_thrown = false;
	try
	{
		this->controller.update_controller("NuExista", "https://NuExista", "new_tutorial", "Gabi", 15, 15, 900, "https://new");
	}
	catch (const std::exception& e)
	{
		exception_thrown = true;
	}

	assert(exception_thrown == true);
	assert(this->controller.get_elements_controller().size() == 11);
}


void Tests::testisAlready()
{
	this->controller.add_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	assert(this->controller.get_elements_controller().size() == 12);
	bool exception_thrown = false;

	try
	{
		this->controller.add_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	}
	catch (const std::exception& e)
	{
		exception_thrown = true;
	}
	assert(exception_thrown == true);
	assert(this->controller.get_elements_controller().size() == 12);
}

void Tests::testAddWatch()
{
	assert(this->controller.get_elements_watch_list().size() == 0);
	this->controller.add_watch_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	assert(this->controller.get_elements_watch_list().size() == 1);
	bool exceptionThrown = false;
	try
	{
		this->controller.add_watch_controller("TestTutorial", "Mihnea", 10, 10, 100, "https://test");
	}
	catch (const std::exception& e)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown == true);
	assert(this->controller.get_elements_watch_list().size() == 1);
}

void Tests::testRemoveWatch()
{
	this->controller.remove_controller_watch_list("TestTutorial", "https://test");
	assert(this->controller.get_elements_watch_list().size() == 0);
	bool exceptionThrown = false;
	try
	{
		this->controller.remove_controller_watch_list("NuExista", "https://NuExista");
	}
	catch (const std::exception& e)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown == true);
	assert(this->controller.get_elements_watch_list().size() == 0);
}

void Tests::testgoToNext()
{
	int size = this->controller.get_elements_controller().size();
	Tutorial a = Tutorial();
	std::string presenter = "Paul";
	int i = 0;
	while (i < size)
	{
		if (this->controller.get_elements_controller()[i].getPresenter() == presenter)
		{
			break;
		}
		else
		{
			this->controller.go_to_next_tutorial(i, size);
		}
	}

	assert(this->controller.get_elements_controller()[i].getPresenter() == presenter);

	i = 0;

	while (i < size)
	{
		if (i == size - 1)
		{
			this->controller.go_to_next_tutorial(i, size);
			break;
		}
		else
		{
			this->controller.go_to_next_tutorial(i, size);
		}
	}
	assert(i == 0);

}


void Tests::testAll()
{
	testAdd();
	testRemove();
	testUpdate();
	testisAlready();
	testAddWatch();
	testRemoveWatch();
	testgoToNext();
}
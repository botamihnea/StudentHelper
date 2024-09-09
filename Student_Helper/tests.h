#pragma once
#include "controller.h"

class Tests
{
private:
	Controller controller;
public:
	Tests();
	void testAdd();
	void testRemove();
	void testUpdate();
	void testisAlready();
	//make tests for 98% code coverage
	void testAddWatch();
	void testRemoveWatch();
	void testgoToNext();
	void testAll();
};
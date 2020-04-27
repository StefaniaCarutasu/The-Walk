#pragma once

#include "Robot.h"
#include "map.h"

#include<iostream>
#include<string>

using namespace std;

class C3PO : public Robot
{

public:
	C3PO(string);
	string getRobotType() const { return Robot::getID(); }
	void newPosition(map&);
};


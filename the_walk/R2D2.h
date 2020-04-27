#pragma once
#include "Robot.h"
#include "map.h"
#include<string>
#include<iostream>
using namespace std;

class R2D2 : public Robot
{
	static int lives;
public:
	R2D2(string);
	string getRobotType() const { return Robot::getID(); }
	void newPosition(map&);
};


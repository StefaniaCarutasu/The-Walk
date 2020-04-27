#pragma once
#include "Robot.h"
#include "map.h"
#include<string>
#include<iostream>
using namespace std;

class BB8 : public Robot
{
	static int lives;
public:
	BB8(string s);
	string getRobotType() const { return Robot::getID(); }
	void newPosition(map&);
};


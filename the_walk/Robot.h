#pragma once
#include "map.h"
#include<iostream>
#include<string>
using namespace std;

class Robot
{
private:
	string ID;
	const pair<int, int> start = { 0,0 };
	pair<int, int> position;

protected:
	void setNewPosition(const pair<int, int>);

public:
	Robot();
	Robot(string);
	virtual ~Robot();
	string getID();
	pair<int, int> getCurrentPosition();
	virtual string getRobotType() const=0;
	virtual pair<int, int> newPosition(const map& harta) const = 0;
	friend class map;

};


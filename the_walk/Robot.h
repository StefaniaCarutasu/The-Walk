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
	static int items;

protected:
	void setNewPosition(const pair<int, int>);

public:
	Robot();
	Robot(string);
	virtual ~Robot();
	string getID() const;
	static int getItems();
	static void incrementItems(unsigned int);
	pair<int, int> getCurrentPosition();
	bool isFinish(int,int, map&);
	virtual string getRobotType() const=0;
	virtual void newPosition(const map& harta) const = 0;
	friend class map;

};


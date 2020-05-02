#pragma once
#include "map.h"
#include<iostream>
#include<string>
using namespace std;

class map;

class Robot
{
private:
	string ID;
	const pair<int, int> start = { 0,0 };
	pair<int, int> position=start;
	static int items;
	static int lives;
	static int traps;

protected:
	void setNewPosition(pair<int, int>);

public:
	Robot();
	Robot(string);
	virtual ~Robot();
	string getID() const;
	int getLives();
	void setLives(int);
	static int getItems();
	static int getTraps();
	static void incrementItems(unsigned int);
	static void incrementTraps(unsigned int);
	pair<int, int> getCurrentPosition();
	bool isFinish(int,int, map&);
	virtual string getRobotType() const=0;
	virtual void newPosition(map&)=0;
	friend class map;

};


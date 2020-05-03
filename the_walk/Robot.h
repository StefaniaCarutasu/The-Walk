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
	static int lives;
	static int traps;

protected:
	void setNewPosition(pair<int, int>);	//schimb pozitia robotului

public:
	Robot();
	Robot(string);
	virtual ~Robot();
	int getLives() const;
	void setLives(int);	//modifica numarul de vieti in functie de situatie
	int getItems() const;
	int getTraps() const;
	static void incrementItems(unsigned int);	//modifica nr de item-uri, in functie de caz
	static void incrementTraps(unsigned int);	//modifica nr de capcane, in functie de caz
	pair<int, int> getCurrentPosition();	//imi returneaza pozitia de la inceputul rundei
	bool isFinish(int,int, map&);	//verific daca este egal cu finish-ul
	virtual void newPosition(map&)=0;	//metoda prin care aleg noua pozitie a robotului

};


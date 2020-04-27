#pragma once
#include<string>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<set>
using namespace std;

class map
{
	int dimensiune;
	char** Matrix;
	pair<int, int> finishLine;
	set<pair<int, int>> items;
	set<pair<int, int>> traps;
public:
	map();
	map(const map& );
	virtual  ~map();
	int getDimension();
	pair<int, int> getFinish();
	void setFinish(pair<int, int>);
	char** getMatrix();
	int randomGenerator(int sup, int inf);
	void generateFinish();
	void generateItems();
	void generateTraps();
	void changeMatrix(pair<int,int>, pair<int, int>); //ilustreaza miscarea robotului
	friend ostream& operator << (ostream& out, map& M);
};
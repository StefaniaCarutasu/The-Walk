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
	char** M;
	pair<int, int> finishLine;
	set<pair<int, int>> items;
	set<pair<int, int>> traps;
public:
	map();
	map(const map& );
	virtual  ~map();
	int randomGenerator(int sup, int inf);
	void generateFinish();
	void generateItems();
	void generateTraps();
	friend ostream& operator << (ostream& out, map& M);
};



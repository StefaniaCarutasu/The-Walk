#pragma once
#include<iostream>
#include<string>
#include "map.h"
using namespace std;
class runGame
{
	map* m;
public:
	runGame();
	void round();
	void currentState();
	~runGame();
};


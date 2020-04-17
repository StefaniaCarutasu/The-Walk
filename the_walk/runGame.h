#pragma once
#include<iostream>
#include<string>
#include "map.h"
#include "Robot.h"
using namespace std;
class runGame
{
	map* m;
	Robot* r;
	static int noRound;
public:
	runGame();
	void round();
	void currentState();
	~runGame();
};


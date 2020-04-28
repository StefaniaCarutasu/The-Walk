#pragma once
#include<iostream>
#include<string>
#include "map.h"
#include "Robot.h"
#include "C3PO.h"
#include "R2D2.h"
#include "BB8.h"
using namespace std;
class runGame
{
	map* m;		// harta generata
	Robot* r;		//robotul ales de utilizator pentru a juca
	static int noRound;		//runda la care s-a ajuns
public:
	runGame();
	void round();
	int isFinish();
	void currentState();
	~runGame();
};


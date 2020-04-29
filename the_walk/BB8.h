#pragma once
#include "Robot.h"
#include "map.h"
#include<string>
#include<iostream>
using namespace std;

class BB8 : public Robot
{
	static int lives;
	static int marginBottom, marginTop, marginLeft, marginRight, row, column;
public:
	BB8(string s);
	string getRobotType() const { return Robot::getID(); }
	void newPosition(map&);
};

//Strategia lui BB8 este de a merge prin matrice in forma de spirala
//El va colectiona item urile si le va folosi daca are in drum capcane
//Daca are item el va putea da capcana la o parte
//In cazul in care nu are item are de ales: poate sta 1 tura pe loc sau daca linia de finish este in aria sa vizuala si vietile ii permit va trece prin capcana si va pierde o viata
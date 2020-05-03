#include "Robot.h"
int Robot::items = 0;
int Robot::lives = 3;
int Robot::traps = 0; 
Robot::Robot() : ID(" "), position({ 0,0 }) {}
Robot::Robot(string s) : ID("#"+s), position({ 0,0 }) {} 
Robot::~Robot()
{
	this->ID = " ";
	this->position = { -1,-1 };
}
void Robot::incrementItems(unsigned int i) { items += i; }

void Robot::incrementTraps(unsigned int i) { traps += i; }

int Robot::getItems() const { return items; }

int Robot::getTraps() const { return traps; }

int Robot::getLives() const { return lives; }

void Robot::setLives(int i) { this->lives += i; }

pair<int, int> Robot::getCurrentPosition() { return this->position; }

bool Robot::isFinish(int i,int j, map& m)
{
	if (i == m.getFinish().first && j == m.getFinish().second)
		return true;
	return false;
}
void Robot::setNewPosition(const pair<int, int> newPosition)
{
	this->position.first = newPosition.first;
	this->position.second = newPosition.second;
}

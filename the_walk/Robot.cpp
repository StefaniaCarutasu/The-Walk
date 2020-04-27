#include "Robot.h"
int Robot::items = 0;

Robot::Robot() : ID(" "), position({ 0,0 }) {}
Robot::Robot(string s) : ID("#"+s), position({ 0,0 }) {}
Robot::~Robot()
{
	this->ID = " ";
	this->position = { -1,-1 };
}
void Robot::incrementItems(unsigned int i)
{
	items += i;
}
int Robot::getItems() { return items; }
string Robot::getID() const
{
	return this->ID;
}
pair<int, int> Robot::getCurrentPosition()
{
	return this->position;
}
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

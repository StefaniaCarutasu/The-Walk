#include "Robot.h"

Robot::Robot() : ID(" "), position({ 0,0 }) {}
Robot::Robot(string s) : ID(s), position({ 0,0 }) {}
Robot::~Robot()
{
	this->ID = " ";
	this->position = { -1,-1 };
}
string Robot::getID()
{
	return this->ID;
}
pair<int, int> Robot::getCurrentPosition()
{
	return this->position;
}
void Robot::setNewPosition(const pair<int, int> newPosition)
{
	this->position.first = newPosition.first;
	this->position.second = newPosition.second;
}

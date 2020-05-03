#pragma once
#include<string>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<ctime>
#include<random>
#include<set>
using namespace std;

class map
{
	int dimensiune;
	char** Matrix;
	pair<int, int> finishLine;
public:
	map();
	map(const map& );
	virtual  ~map();
	int getDimension() const;
	pair<int, int> getFinish() const;
	void setFinish(pair<int, int>);
	char** getMatrix();
	int randomGenerator(int sup, int inf);	//functie auxiliara pentrua genera aleator coordonate si dimensiunea matricei
	void generateFinish();	//genereaza random coordonatele liniei de finish
	void generateItems();	//genereaza random coordonatele item-urilor; numarul lor este de asemenea generat random
	void generateTraps();	//genereaza random coordonatele capcanelor; numarul lor este de asemenea generat random
	void changeMatrix(pair<int,int>, pair<int, int>); //ilustreaza miscarea robotului
	friend ostream& operator << (ostream& out, map& M);	//supraincarcare auxiliara de operator pentru a afisa harta la fiecare stadiu
};
#pragma once
#include "Robot.h"
#include "map.h"
#include<string>
#include<iostream>
using namespace std;

class R2D2 : public Robot
{
	static int sus, jos;
public:
	R2D2(string);
	string getRobotType() const { return Robot::getID(); }
	void newPosition(map&);
};

//R2-D2 se va misca in principal pe diagonale paralele cu diagonala secundara a hartii
//Incepe din coltul din stanga sus, merge o patratica in jos si dupa incepe miscarea pe diagonale
//Fiind un droid mai vechi, el are nevoie de putea a 2 itemi pentru a putea trece de o capcana
//Daca totusi are un singur item il poate folosi si va fi dat pe pozitia anterioara, 
//dar capcana dispare si ulterior isi poate continua drumul cu o itarziere
//Daca are capcana si totusi linia de finish se afla in fata lui (pe diagonala pe care e si pe directia lui de mers) 
//poate alege sa isi piarda o viata pentru a se apropia de finish
//Pe parcurs el colecteaza item urile pe care le intalneste
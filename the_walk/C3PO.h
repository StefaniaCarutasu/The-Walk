#pragma once

#include "Robot.h"
#include "map.h"

#include<iostream>
#include<string>

using namespace std;

class C3PO : public Robot
{

public:
	C3PO(string);
	string getRobotType() const { return Robot::getID();}
	void newPosition(map&);
};

//Strategia lui C-3PO este sa mearga serpui prin matrice, pe linii
//Va colectiona item urile pe care le va utiliza ulterior cand intalneste capcane
//Pentru el capcana este ca un zid, nu poate trece pe acolo
//In cazul in care are item ar putea sa il utilizeze pentru a "sparge" zidul si a merge mai departe 
//In caz contrar, el incearca sa isi gaseasca alta alta cale. Se poate misca pe linie, coloana sau diagonala
//In cazul in care este blocat intre capcane, noua pozitie este generata random intr-o parte nevizitata a hartii
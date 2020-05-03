#pragma once

#include "Robot.h"
#include "map.h"

#include<iostream>
#include<string>

using namespace std;

class C3PO : public Robot
{
	static pair<int, int> pozitiaAnterioara;
public:
	C3PO(string);
	void newPosition(map&);
};

//Strategia lui C-3PO este sa mearga serpuit prin matrice, pe linii
//Va colectiona atat item urile care il ajuta, dar si capcanele care il slabesc
//Daca el a colectionat 2 capcane atunci va avea nevoie de item:
//Daca are 2 item uri atunci le va folosi si va sparge capcana, va merge mai departe
//Daca are un singur item atunci va putea sterge capcana dar va fi dat o pozitie inapoi
//Daca are 5 item uri colectionate si mai putin de 3 vieti (cat este maxim) le va schimba pentru o viata suplimentara 
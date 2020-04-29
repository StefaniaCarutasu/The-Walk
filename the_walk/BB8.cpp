#include "BB8.h"

int BB8::lives = 3;	//numarul initial de vieti
//variabilele margin sunt folosite pentru a putea simula spirala
int BB8::marginBottom = -1;
int BB8::marginLeft = 1;
int BB8::marginRight = -1;
int BB8::marginTop = 0;
int BB8::down = 1; //down==1 => merg in jos
int BB8::right = 1;	//right==1 => merg in dreapta
int BB8::row = 0;		//inseamna ca nu ma misc pe rand
int BB8::column = 1;	//incep sa ma misc pe coloana in jos

BB8::BB8(string s): Robot(s) {}

void BB8::newPosition(map& map)
{
	if (marginBottom == marginRight && marginRight == -1)	//la prima runda ii setez marginea de jos si din dreapta ca fiind ultimul rand, respectiv ultima coloana
	{
		marginBottom = map.getDimension()-1;
		marginRight = map.getDimension()-1;
	}

	pair<int, int> p = this->getCurrentPosition();
	pair<int, int> newPoz;
	int n = map.getDimension();
	pair<int, int> finish = map.getFinish();

	//cazul1: ma aflu pe coloana
	//exista 2 pozibilitati: sunt la o margine sau nu
	//daca sunt la marginea de jos atunci incep sa ma deplasez spre dreapta, altfel ma deplasez spre stanga
	//daca nu sunt la margine ori merg in sus ori merg in jos
	if (column) 
	{
		if (p.first == marginBottom && down) //am ajuns jos deci ma mut pe linie in dreapta
		{
			newPoz = { p.first, p.second + 1 };
			row = 1; column = 0;
			right = 1;
			marginBottom++;
		}
		else if (p.first == marginTop && down == 0)	//am ajuns sus si ma mut pe linie in stanga
		{
			newPoz = { p.first, p.second - 1 };
			row = 1; column = 0;
			right = 0;
			marginTop++;
		}
		else if (down==1) //inseamna ca merg in jos
		{
			newPoz = { p.first + 1, p.second }; //ma mut in jos o casuta
		}
		else //altfel inseamna ca merg in sus
			newPoz = { p.first - 1, p.second };

	}
	//cazul 2: merg pe rand
	//exista 2 posibilitati: ma aflu la o margine sau nu
	//daca ma aflu la marginea stanga o iau in jos pe coloana, daca sunt in dreapta o iau in sus
	//altfel inseamna ca merg in stg sau dr in functie de variabila right
	else
	{
		if (row)
		{
			if (p.second == marginRight && right) //am ajuns la marginea din dreapta
			{
				newPoz = { p.first - 1, p.second };
				marginRight--;  //decrementez marginea pentru a restrictiona
				column = 1; row = 0; //incep sa merg iar pe coloana
				down = 0;  //in sus
			}
			else if (p.second == marginLeft && right == 0)  //am ajuns la marginea din stanga
			{
				newPoz = { p.first + 1, p.second };
				marginLeft++;  //incrementez marginea pentru a restrictiona
				column = 1; row = 0;	//incep sa merg iar pe coloana
				down = 1;	//in jos
			}
			else if (right)	//merg in dreapta
			{
				newPoz = { p.first, p.second + 1 };		//ma mut in dreapta cu o casuta
			}
			else newPoz = { p.first, p.second - 1 };	//altfel inseamna ca merg in stanga
		}
	}


	if (map.getMatrix()[newPoz.first][newPoz.second] == 'T' && getItems() == 0)		//am dat de capcana si nu mai am item uri
	{
		if (finish.second < newPoz.second + 3 && Robot::getLives()>1)		//vad daca e finish ul pe aceeasi linie si mai am vieti
		{
			map.changeMatrix(p, newPoz);	//schimb matricea si mut robotul pe urmatoarea pozitie
			this->setNewPosition(newPoz);	//merg pe pozitia urmatoare
			Robot::setLives(-1);		//scad numarul de vieti
			if (Robot::getLives() == 2)
				cout << "Just two lives you have. Careful you must be\n";
			else cout << "On life left you have. Choose wisely you must\n";
		}
		else	//altfel vreau sa stea pe loc o tura ca sa nu mai piarda vieti
		{
			map.getMatrix()[newPoz.first][newPoz.second] = '_'; //sterg capcana si las robotul pe pozitia pe care era
		}
	}
	else
	{
		if (getItems() > 0)
		{
			incrementItems(-1);		//decrementez numarul de itemi
			map.changeMatrix(p, newPoz);	//mut robotul in matrice
			this->setNewPosition(newPoz);	//schimb pozitia robotului
		}
		else
		{
			map.changeMatrix(p, newPoz);	//mut robotul in matrice
			this->setNewPosition(newPoz);	//schimb pozitia
		}
	}
	if (map.getMatrix()[newPoz.first][newPoz.second] == 'I')
	{
		Robot::incrementItems(1);	//daca pe noua pozitie gaseste item il ia
	}
}
#include "BB8.h"

int BB8::lives = 3;
int BB8::marginBottom = -1;
int BB8::marginLeft = 0;
int BB8::marginRight = -1;
int BB8::marginTop = 0;
int BB8::row = 0;		//inseamna ca nu ma misc pe rand
int BB8::column = 1;	//incep sa ma misc pe coloana in jos
BB8::BB8(string s): Robot(s) {}

void BB8::newPosition(map& map)
{
	if (marginBottom == marginRight && marginRight == -1)
	{
		marginBottom = map.getDimension() - 1;
		marginRight = map.getDimension() - 1;
	}
	pair<int, int> p = this->getCurrentPosition();
	pair<int, int> newPoz;
	int n = map.getDimension();
	pair<int, int> finish = map.getFinish();
	if (p.second < n / 2 && p.first > marginBottom && column==1)
		newPoz = { p.first + 1, p.second };
	else if (p.first == marginBottom && column==1)
	{
		marginBottom--;		//decrementez marginea pana pe care poate ajunge robotul
		column = 0; row = 1;	//schimb directia: incep sa ma misc pe rand
		newPoz = { p.first, p.second + 1 };
	}
	if (p.second >= n / 2 && p.first < marginTop)
		newPoz = { p.first - 1, p.second };
	else if(p.first==marginTop && column==1)
	{
		marginTop++;	//incrementez marginea de sus pana la care poate merge robotul
		column = 0; row = 1;	//schimb directia si merg pe rand
		newPoz = { p.first, p.second - 1 };
	}
	if (p.first < n / 2 && p.first > marginLeft)
		newPoz = { p.first, p.second - 1 };
	else if (p.first==marginLeft && row==1)
	{
		marginLeft++;	//incrementez marginea stanga pana la care poate inainta robotul
		column = 1; row = 1;	//incep sa merg pe coloana
		newPoz = { p.first + 1, p.second };
	}
	if (p.first >= n / 2 && p.first < marginRight)
		newPoz = { p.first, p.second + 1 };
	else if (p.first == marginRight && row == 1)
	{
		marginRight--;	//decrementez marginea dreapta pana la care poate ajunge robotul
		column = 1; row = 0;
		newPoz = { p.first - 1, p.second };
	}
	

	if (map.getMatrix()[newPoz.first][newPoz.second] == 'T' && getItems() == 0)		//am dat de capcana si nu mai am item uri
	{
		if (finish.second < newPoz.second + 3 && this->lives>1)		//vad daca e finish ul pe aceeasi linie si mai am vieti
		{
			map.changeMatrix(p, newPoz);	//schimb matricea si mut robotul pe urmatoarea pozitie
			this->setNewPosition(newPoz);	//merg pe pozitia urmatoare
			this->lives--;		//scad numarul de vieti
			cout << "A live you have lost. " << lives << " lives you have\n";
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

}
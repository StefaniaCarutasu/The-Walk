#include "map.h"



map::map() : dimensiune(randomGenerator(15, 30))  //constructor cu parametru
{
	M = new char * [dimensiune - 1];
	for (int i = 0; i < dimensiune; i++)
		M[i] = new char[dimensiune - 1];
	for (int i = 0; i < dimensiune; i++)
		for (int j = 0; j < dimensiune; j++)
			M[i][j] = '_';
}

map::map(const map& m)   // constructor de copiere
{
	this->dimensiune = m.dimensiune;
	this->M = m.M;
	this->finishLine = m.finishLine;
	this->items = m.items;
	this->traps = m.traps;
}

map::~map()  //destructor
{
	for (int i = 0; i < dimensiune; i++)
		delete[] M[i];
	delete[] M;
	this->dimensiune = 0;
}

ostream& operator << (ostream& out, map& harta)		//supraincarcare <<
{
	for(int i=0; i < harta.dimensiune; i++)
	{
		for (int j = 0; j < harta.dimensiune; j++)
			out << harta.M[i][j] << " ";
		out << '\n';
	}
	return out;
}

int map::randomGenerator(int inf, int sup)   //functie care imi genereaza un numar random intre inf si sup
{
	srand(time(NULL));
	int d = rand() % sup + inf;
	if (d > sup)
		d -= 10;
	return d;
}

void map::generateFinish()   //generez random pozitia liniei de finish
{
	this->finishLine.first=randomGenerator(1, this->dimensiune-1);
	this->finishLine.second = randomGenerator(1, this->dimensiune-1);
	M[this->finishLine.first][this->finishLine.second] = 'F';
}

void map::generateItems()   //generez random numarul de items si pozitia lor pe harta
{
	int noOfItems = randomGenerator(15, 25);
	int i = 0;
	while(i < noOfItems)
	{
		int j = randomGenerator(1, this->dimensiune - 1);
		int k = randomGenerator(1, this->dimensiune - 1);
		if (M[j][k] != 'F' && M[j][k] != 'I' && k != j)
		{
			this->M[j][k] = 'I';
			this->items.insert({ j,k });
			cout << i << ":   " << j << "   " << k<<'\n';
			i++;
			
		}

	}
}

void map::generateTraps()   //generez random numarul de capcane si pozitia lor pe harta
{
	int noOfTraps = randomGenerator(15, 26);
	int i = 0;
	while (i < noOfTraps)
	{

		int j = randomGenerator(1, this->dimensiune - 1);
		int k = randomGenerator(1, this->dimensiune - 1);
		if (M[j][k] != 'F' && M[j][k] != 'I' && M[j][k] != 'T' && k != j)
		{
			this->M[j][k] = 'T';
			this->traps.insert({ j,k });
			cout << i << ":   " << j << "   " << k<<'\n';
			i++;
		}
	}
	
}

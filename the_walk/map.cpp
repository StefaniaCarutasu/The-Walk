#include "map.h"

map::map() : dimensiune(randomGenerator(15, 30))  //constructor fara parametru
{
	Matrix = new char * [dimensiune];
	for (int i = 0; i < dimensiune; i++)
		Matrix[i] = new char [dimensiune];
	for (int i = 0; i < dimensiune; i++)
		for (int j = 0; j < dimensiune; j++)
			Matrix[i][j] = '_';
	Matrix[0][0] = 'R';
}

map::map(const map& m)   // constructor de copiere
{
	this->dimensiune = m.dimensiune;
	this->Matrix = m.Matrix;
	this->finishLine = m.finishLine;
	this->items = m.items;
	this->traps = m.traps;
}

map::~map()  //destructor
{
	for (int i = 0; i < dimensiune; i++)
		delete[] Matrix[i];
	delete[] Matrix;
	this->dimensiune = 0;
}

ostream& operator << (ostream& out, map& harta)		//supraincarcare <<
{
	for(int i=0; i < harta.dimensiune; i++)
	{
		for (int j = 0; j < harta.dimensiune; j++)
			out << harta.Matrix[i][j] << " ";
		out << '\n';
	}
	return out;
}

int map::randomGenerator(int inf, int sup)   //functie care imi genereaza un numar random intre inf si sup
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(inf, sup); 
	return dist(rng);
}

int map::getDimension() { return this->dimensiune; }

pair<int, int> map::getFinish() { return this->finishLine; }

char** map::getMatrix() { return this->Matrix; }

void map::setFinish(pair<int, int> p)
{
	this->finishLine = p;
}

void map::generateFinish()   //generez random pozitia liniei de finish
{
	this->finishLine.first=randomGenerator(1, this->dimensiune-1);
	this->finishLine.second = randomGenerator(1, this->dimensiune-1);
	Matrix[this->finishLine.first][this->finishLine.second] = 'J';
}

void map::generateItems()   //generez random numarul de items si pozitia lor pe harta
{
	int noOfItems = randomGenerator(20, 40);
	int i = 0;
	while(i < noOfItems)
	{
		int j = randomGenerator(1, this->dimensiune - 1);
		int k = randomGenerator(1, this->dimensiune - 1);
		if (Matrix[j][k] != 'J' && Matrix[j][k] != 'I')
		{
			this->Matrix[j][k] = 'I';
			this->items.insert({ j,k });
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
		if (Matrix[j][k] != 'J' && Matrix[j][k] != 'I' && Matrix[j][k] != 'T')
		{
			this->Matrix[j][k] = 'T';
			this->traps.insert({ j,k });
			i++;
		}
	}
	
}

void map::changeMatrix(pair<int, int> oldPosition, pair<int,int> newPosition)
{
	Matrix[oldPosition.first][oldPosition.second] = '_';
	Matrix[newPosition.first][newPosition.second] = 'R';
}

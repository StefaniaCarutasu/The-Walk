#include "R2D2.h"

//cand se misca pe diagonalele paralele robotul o ia ori "in sus" ori "in jos" si cu aceste variabile contorizez acest lucru
int R2D2::sus=1; 
int R2D2::jos = 0;

R2D2::R2D2(string s): Robot(s) {}

void R2D2::newPosition(map& map)
{
	pair<int, int> p = this->getCurrentPosition();
	pair<int, int> newPoz;
	int n = map.getDimension();
	pair<int, int> finish = map.getFinish();

	if (p.first % 2 == 0 && (p.second == 0 || p.second == n - 1))  
	//sunt pe prima sau ultima coloana, linia e para si vreau sa mearga o pozitie in jos pentru a trece la urmatoarea diagonala
	{
		//exista probleme cand matricea este de dimensiune impara:
		//cand ajunge in stanga jos linia va fi para dar nu o va putea lua in jos pentru ca ar iesi din matrice
		//cand ajunge in dreapta sus nu o va putea lua in jos deoarece ar rata diagonala principala
		if (p.first == 0 && n % 2 && p.second==n-1)  //ma aflu pe coltul din dreapta sus
		{
			newPoz = { p.first + 1, p.second - 1 };  //ma mut pe diagonala
			sus = 0; jos = 1;   //noul sens de miscare pe diagonala: jos
		}
		if (p.first == n - 1 && n % 2 && p.second == 0)		//ma aflu in coltul din stanga jos
		{
			newPoz = { p.first, p.second + 1 };		//ma mut in dreapta 
			sus = 1; jos = 0;	//noul sens de miscare pe diagonala: sus
		}
		else
		{
			newPoz = { p.first + 1, p.second };	//cobor cu o pozitie
			if (p.second == 0)
			{
				jos = 0; sus = 1;	//noul sens de miscare pe diagonala: sus
			}
			else
			{
				jos = 1; sus = 0;	//noul sens de miscare pe diagonala: jos
			}
		}
		
	}

	if (p.second % 2 && (p.first == 0 || p.first == n - 1) && (p.second != 0 && p.second != n - 1))
		//sunt ori pe marginea superioara ori pe cea inferioara a matricei si are dimensiune para
		//nu ma aflu in coltul din stanga jos sau dreapta sus unde se intampla altceva
	{
		newPoz = { p.first, p.second + 1 }; //ma mut in dreapta cu o pozitie
		if (p.first == 0)	//sunt pe prima linie
		{
			sus = 0; jos = 1; //noul sens de miscare pe diagonala: jos
		}
		else   //sunt pe ultima linie
		{
			sus = 1; jos = 0;	//noul sens de miscare pe diagonala: sus
		}
	}

	if (p.second != n - 1 && sus == 1) //ma aflu pe diagonala si urc, nu am ajuns inca la ultima coloana
	{
		newPoz = { p.first - 1, p.second + 1 };
	}

	if (p.second != 0 && jos == 1)	//ma aflu pe diagonala si cobor, nu am ajuns inca la prima coloana
	{
		newPoz = { p.first + 1, p.second - 1 };
	}
	/*if (p.first != 0 && sus == 1)   //ma aflu in urcare pe diagonala si nu am ajuns sus de tot
	{
		newPoz = { p.first - 1, p.second + 1 };
	}

	if (p.first != n-1 && jos == 1)	 //ma aflu in coborare pe diagonala si nu am ajuns jos de tot
	{
		newPoz = { p.first + 1, p.second - 1 };
	}

	if (p.first == 0 && p.second != n - 1)   
		//am ajuns pe prima linie si vreau sa merg in dreapta pentru a putea incepe coborarea pe diagonala
		// aceasta mutare este posibila doar daca matricea e de dimensiune para
	{	
		newPoz = { p.first, p.second + 1 };
		sus = 0; jos = 1;	//noul sens de miscare pe diagonala: jos
	}*/


	

	

}
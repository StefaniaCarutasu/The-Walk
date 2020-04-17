#include "C3PO.h"

C3PO::C3PO(string s): Robot(s){}

void C3PO::newPosition(map& map)
{
	pair<int, int> p = { 0,0 };
	int n = map.getDimension();

	//daca ajunge sa se loveasca de marginea din dreapta a hartii de joc il pun sa o ia in jos pe urmatoarea linie
	if (this->getCurrentPosition().second == n - 1)  
	{
		p = { this->getCurrentPosition().first+1, this->getCurrentPosition().second }; //posibila noua pozitie
		if (map.getMatrix()[p.first][p.second] == 'T' && getItems() == 0)  //daca nu mai are niciun item pe care sa il foloseasca si pozitia are o capcana
		{
			if (map.getMatrix()[getCurrentPosition().first][getCurrentPosition().second - 1] == '_')  //incerc pozitia din stanga
				p = { getCurrentPosition().first,getCurrentPosition().second - 1 };
			else
			{
				if (map.getMatrix()[getCurrentPosition().first - 1][getCurrentPosition().second] == '_')  //incerc pozitia de deasupra
					p = { getCurrentPosition().first - 1,getCurrentPosition().second };
				else  //in toate aceste locuri erau capcane si robotul nu mai are item-uri care sa il ajute
				{
					if (getCurrentPosition().first != n - 1)
					{
						p.first = map.randomGenerator(getCurrentPosition().first + 1, n - 1); //merg pe o pozitie aleatoare in partea de matrice nevizitata
						p.second = map.randomGenerator(0, n - 1);
					}
					else
					{
						p.first = getCurrentPosition().first; //merg pe o pozitie aleatoare in partea de matrice nevizitata
						p.second = map.randomGenerator(getCurrentPosition().second, n - 1);
					}
				}
			}
		}
		else
		{
			incrementItems(-1);  //continui pe pozitia urmatoare dar ma folosesc de item
			map.getMatrix()[p.first][p.second] = '_';  //scap de capcana
			if (map.getMatrix()[p.first][p.second] == 'I')   //daca pe noua pozitie gasesc un item il iau 
			{
				incrementItems(1);
				map.getMatrix()[p.first][p.second] = '_'; 
			}
		}

		map.changeMatrix(this->getCurrentPosition(), p); // pun in matrice noua pozitie a robotului
		Robot::setNewPosition(p); //setez noua pozititie a robotului
	}
	//daca ajunge sa se loveasca de marginea din stanga a hartii de joc
	if (this->getCurrentPosition().second == 0 && this->getCurrentPosition().first != 0)
	{
		p = { this->getCurrentPosition().first + 1, this->getCurrentPosition().second }; //posibila noua pozitie
		if (map.getMatrix()[p.first][p.second] == 'T' && getItems() == 0)  //daca nu mai are niciun item pe care sa il foloseasca si pozitia are o capcana
		{
			if (map.getMatrix()[getCurrentPosition().first][getCurrentPosition().second + 1] == '_')  //incerc pozitia din stanga
				p = { getCurrentPosition().first,getCurrentPosition().second + 1 };
			else
			{
				if (map.getMatrix()[getCurrentPosition().first - 1][getCurrentPosition().second] == '_')  //incerc pozitia de deasupra
					p = { getCurrentPosition().first - 1,getCurrentPosition().second };
				else  //in toate aceste locuri erau capcane si robotul nu mai are item-uri care sa il ajute
				{
					if (getCurrentPosition().first != n - 1)
					{
						p.first = map.randomGenerator(getCurrentPosition().first + 1, n - 1); //merg pe o pozitie aleatoare in partea de matrice nevizitata
						p.second = map.randomGenerator(0, n - 1);
					}
					else
					{
						p.first = getCurrentPosition().first; //merg pe o pozitie aleatoare in partea de matrice nevizitata
						p.second = map.randomGenerator(getCurrentPosition().second, n - 1);
					}
				}
			}
		}
		else
		{
			incrementItems(-1);  //continui pe pozitia urmatoare dar ma folosesc de item
			map.getMatrix()[p.first][p.second] = '_';   //scap de capcana
			if (map.getMatrix()[p.first][p.second] == 'I')   //daca pe noua pozitie gasesc un item il iau 
			{
				incrementItems(1);
				map.getMatrix()[p.first][p.second] = '_';
			}
		}

		map.changeMatrix(this->getCurrentPosition(), p); // pun in matrice noua pozitie a robotului
		Robot::setNewPosition(p); //setez noua pozititie a robotului
	}
	//daca se afla pe un rand cu indice par
	if (this->getCurrentPosition().first % 2 == 0)
	{
		p = { this->getCurrentPosition().first, this->getCurrentPosition().second + 1 }; //posibila noua pozitie
		if (map.getMatrix()[p.first][p.second] == 'T' && getItems() == 0)  //pozitia pe care vreau eu sa mearga are capcana si nu mai are item-uri sa il protejeze
		{
			bool ok = false;
			if (getCurrentPosition().second != 0)  //daca se poate merge in stanga
			{
				if (map.getMatrix()[getCurrentPosition().first][getCurrentPosition().second - 1] == '_' && ok == false)  //incerc pozitia din stanga
				{
					p = { getCurrentPosition().first,getCurrentPosition().second - 1 };
					ok = true;
				}
			}
			if (getCurrentPosition().first != n - 1)  //daca se poate merge in jos
			{
				if (map.getMatrix()[getCurrentPosition().first + 1][getCurrentPosition().second] == '_' && ok == false)  //incerc pozitia de jos
				{
					p = { getCurrentPosition().first + 1,getCurrentPosition().second };
					ok = true;
				}
			}
			if (getCurrentPosition().second != n - 1)  //daca se poate merge in dreapta
			{
				if (map.getMatrix()[getCurrentPosition().first + 1][getCurrentPosition().second] == '_' && ok == false)  //incerc pozitia din dreapta
				{
					p = { getCurrentPosition().first + 1,getCurrentPosition().second };
					ok = true;
				}
			}
			if (getCurrentPosition().first != 0)  //daca se poate merge deasupra
			{
				if (map.getMatrix()[getCurrentPosition().first - 1][getCurrentPosition().second] == '_' && ok == false)  //incerc pozitia de deasupra
				{
					p = { getCurrentPosition().first - 1,getCurrentPosition().second };
					ok = true;
				}
			}
			
			else  //in toate aceste locuri erau capcane sau sunt inaccesibile si robotul nu mai are item-uri care sa il ajute
			{
				if (getCurrentPosition().first != n - 1)
				{
					p.first = map.randomGenerator(getCurrentPosition().first + 1, n - 1); //merg pe o pozitie aleatoare in partea de matrice nevizitata
					p.second = map.randomGenerator(0, n - 1);
				}
				else
				{
					p.first = getCurrentPosition().first; //merg pe o pozitie aleatoare in partea de matrice nevizitata
					p.second = map.randomGenerator(getCurrentPosition().second, n - 1);
				}
			}
		}
		else
		{
			incrementItems(-1);  //continui pe pozitia urmatoare dar ma folosesc de item
			map.getMatrix()[p.first][p.second] = '_';  // scap de capcana
			if (map.getMatrix()[p.first][p.second] == 'I')   //daca pe noua pozitie gasesc un item il iau 
			{
				incrementItems(1);
				map.getMatrix()[p.first][p.second] = '_';
			}
		}
		map.changeMatrix(this->getCurrentPosition(), p); // pun in matrice noua pozitie a robotului
		Robot::setNewPosition(p); //setez noua pozititie a robotului
	}

}
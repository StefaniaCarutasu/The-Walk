#include "C3PO.h"

C3PO::C3PO(string s): Robot(s){}

void C3PO::newPosition(map& map) 
{
	pair<int, int> p = { 0,0 };
	int n = map.getDimension();
	pair<int, int> poz=poz;

	//daca ajunge sa se loveasca de marginea din dreapta a hartii de joc il pun sa o ia in jos pe urmatoarea linie
	if (poz.second == n - 1)  
	{
			p = { poz.first + 1, poz.second }; //posibila noua pozitie: jos
			if (map.getMatrix()[p.first][p.second] == 'T' && getItems() == 0)  //daca nu mai are niciun item pe care sa il foloseasca si pozitia are o capcana
			{
				if (poz.first % 2 == 1)
					p = { poz.first + 1, poz.second - 1 };
				else
				{
					bool ok = false;
					if (poz.first != 0 && ok == false)
					{

						if (map.getMatrix()[poz.first - 1][poz.second] == '_')  //incerc pozitia de deasupra
						{
							p = { poz.first - 1,poz.second };
							ok = true;
						}
					}
					else  //in toate aceste locuri erau capcane si robotul nu mai are item-uri care sa il ajute
					{
						if (poz.first != n - 1)
						{
							p.first = map.randomGenerator(poz.first + 1, n - 1); //merg pe o pozitie aleatoare in partea de matrice nevizitata
							p.second = map.randomGenerator(0, n - 1);
						}
						else
						{
							p.first = poz.first; //merg pe o pozitie aleatoare in partea de matrice nevizitata
							p.second = map.randomGenerator(poz.second, n - 1);
						}

					}
				}
			}
			else
			{
				if (map.getMatrix()[p.first][p.second] == 'T')
				{
					incrementItems(-1);  //continui pe pozitia urmatoare dar ma folosesc de item
					map.getMatrix()[p.first][p.second] = '_';  //scap de capcana
				}
				if (map.getMatrix()[p.first][p.second] == 'I')   //daca pe noua pozitie gasesc un item il iau 
				{
					incrementItems(1);
					map.getMatrix()[p.first][p.second] = '_';
				}
			}
		

		map.changeMatrix(poz, p); // pun in matrice noua pozitie a robotului
		Robot::setNewPosition(p); //setez noua pozititie a robotului
	}
	//daca ajunge sa se loveasca de marginea din stanga a hartii de joc
	if (poz.second == 0 && poz.first != 0)
	{
		p = { poz.first + 1, poz.second }; //posibila noua pozitie: jos
		if (map.getMatrix()[p.first][p.second] == 'T' && getItems() == 0)  //daca nu mai are niciun item pe care sa il foloseasca si pozitia are o capcana
		{
			if (poz.first % 2 == 0)
				p = { poz.first + 1, poz.second + 1 };
			else
			{
				bool ok = false;
				if (map.getMatrix()[poz.first][poz.second + 1] == '_')  //incerc pozitia din stanga
				{
					p = { poz.first,poz.second + 1 };
					ok = true;
				}
				if (poz.first != 0 && ok == false)
				{
					if (map.getMatrix()[poz.first - 1][poz.second] == '_')  //incerc pozitia de deasupra
					{
						p = { poz.first - 1,poz.second };
						ok = true;
					}
				}
				else  //in toate aceste locuri erau capcane si robotul nu mai are item-uri care sa il ajute
				{
					if (poz.first != n - 1)
					{
						p.first = map.randomGenerator(poz.first + 1, n - 1); //merg pe o pozitie aleatoare in partea de matrice nevizitata
						p.second = map.randomGenerator(0, n - 1);
					}
					else
					{
						p.first = poz.first; //merg pe o pozitie aleatoare in partea de matrice nevizitata
						p.second = map.randomGenerator(poz.second, n - 1);
					}
				}
			}
			
		}
		else
		{
			if (map.getMatrix()[p.first][p.second] == 'T')
			{
				incrementItems(-1);  //continui pe pozitia urmatoare dar ma folosesc de item
				map.getMatrix()[p.first][p.second] = '_';  //scap de capcana
			}
			if (map.getMatrix()[p.first][p.second] == 'I')   //daca pe noua pozitie gasesc un item il iau 
			{
				incrementItems(1);
				map.getMatrix()[p.first][p.second] = '_';
			}
		}

		map.changeMatrix(poz, p); // pun in matrice noua pozitie a robotului
		Robot::setNewPosition(p); //setez noua pozititie a robotului
	}
	//daca se afla pe un rand cu indice par
	if (poz.first % 2 == 0)
	{
		p = { poz.first, poz.second + 1 }; //posibila noua pozitie: dreapta
		if (map.getMatrix()[p.first][p.second] == 'T' && getItems() == 0)  //pozitia pe care vreau eu sa mearga are capcana si nu mai are item-uri sa il protejeze
		{
			bool ok = false;
			if (poz.first != n - 1)  //daca se poate merge in jos
			{
				if (map.getMatrix()[poz.first + 1][poz.second] == '_' && ok == false)  //incerc pozitia de jos
				{
					p = { poz.first + 1,poz.second };
					ok = true;
				}
			}
			if (poz.first != 0)  //daca se poate merge deasupra
			{
				if (map.getMatrix()[poz.first - 1][poz.second] == '_' && ok == false)  //incerc pozitia de deasupra
				{
					p = { poz.first - 1,poz.second };
					ok = true;
				}
			}
			
			else  //in toate aceste locuri erau capcane sau sunt inaccesibile si robotul nu mai are item-uri care sa il ajute
			{
				if (poz.first != n - 1)
				{
					p.first = map.randomGenerator(poz.first + 1, n - 1); //merg pe o pozitie aleatoare in partea de matrice nevizitata
					p.second = map.randomGenerator(0, n - 1);
				}
				else
				{
					p.first = poz.first; //merg pe o pozitie aleatoare in partea de matrice nevizitata
					p.second = map.randomGenerator(poz.second, n - 1);
				}
			}
		}
		else
		{
			if (map.getMatrix()[p.first][p.second] == 'T')
			{
				incrementItems(-1);  //continui pe pozitia urmatoare dar ma folosesc de item
				map.getMatrix()[p.first][p.second] = '_';  //scap de capcana
			}
			if (map.getMatrix()[p.first][p.second] == 'I')   //daca pe noua pozitie gasesc un item il iau 
			{
				incrementItems(1);
				map.getMatrix()[p.first][p.second] = '_';
			}
		}
		map.changeMatrix(poz, p); // pun in matrice noua pozitie a robotului
		Robot::setNewPosition(p); //setez noua pozititie a robotului
	}
	//se afla pe un rand cu indice impar
	if (poz.first % 2)
	{
		p = { poz.first, poz.second - 1 }; //posibila noua pozitie: stanga

		if (map.getMatrix()[p.first][p.second] == 'T' && getItems() == 0)  //pozitia pe care vreau eu sa mearga are capcana si nu mai are item-uri sa il protejeze
		{
			bool ok = false;
			if (poz.first != n - 1)  //daca se poate merge in jos
			{
				if (map.getMatrix()[poz.first + 1][poz.second] == '_' && ok == false)  //incerc pozitia de jos
				{
					p = { poz.first + 1,poz.second };
					ok = true;
				}
			}
			if (poz.first != 0)  //daca se poate merge deasupra
			{
				if (map.getMatrix()[poz.first - 1][poz.second] == '_' && ok == false)  //incerc pozitia de deasupra
				{
					p = { poz.first - 1,poz.second };
					ok = true;
				}
			}

			else  //in toate aceste locuri erau capcane sau sunt inaccesibile si robotul nu mai are item-uri care sa il ajute
			{
				if (poz.first != n - 1)
				{
					p.first = map.randomGenerator(poz.first + 1, n - 1); //merg pe o pozitie aleatoare in partea de matrice nevizitata
					p.second = map.randomGenerator(0, n - 1);
				}
				else
				{
					p.first = poz.first; //merg pe o pozitie aleatoare in partea de matrice nevizitata
					p.second = map.randomGenerator(poz.second, n - 1);
				}
			}
		}
		else
		{
			if (map.getMatrix()[p.first][p.second] == 'T')
			{
				incrementItems(-1);  //continui pe pozitia urmatoare dar ma folosesc de item
				map.getMatrix()[p.first][p.second] = '_';  //scap de capcana
			}
			if (map.getMatrix()[p.first][p.second] == 'I')   //daca pe noua pozitie gasesc un item il iau 
			{
				incrementItems(1);
				map.getMatrix()[p.first][p.second] = '_';
			}
		}
		map.changeMatrix(poz, p); // pun in matrice noua pozitie a robotului
		Robot::setNewPosition(p); //setez noua pozititie a robotului
	}

}
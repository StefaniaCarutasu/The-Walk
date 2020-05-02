#include "C3PO.h"

C3PO::C3PO(string s) : Robot(s) {}

pair<int, int> C3PO::pozitiaAnterioara = { 0,0 };

void C3PO::newPosition(map& map)
{
	pair<int, int> p = this->getCurrentPosition();
	pair<int, int> newPoz;
	int n = map.getDimension();	//dimensiunea va fi numarul ultimei linii/coloare
	pair<int, int> finish = map.getFinish();

	if (p.second == 0)	//s-a lovit de marginea din stanga a hartii
	{
		if (p.first % 2 == 0)
			newPoz = { p.first, p.second + 1 };	//daca se afla pe rand par atunci il fac sa mearga spre dreapta
		else
			newPoz = { p.first + 1, p.second }; // daca se afla pe rand impar atunci il pun sa coboare cu o pozitie in jos
	}

	else if (p.second == n - 1)	//s-a lovit de marginea din dreapta a hartii
	{
		if (p.first % 2 == 0)
			newPoz = { p.first + 1, p.second};	//daca se afla pe rand par atunci il pun sa coboare pe randul de jos
		else
			newPoz = { p.first, p.second - 1 };	//daca se afla pe rand impar atunci il fac sa mearga spre stanga
	}
	
	else if (0 < p.second && p.second < n - 1)
	{
		if (p.first % 2)	//se afla pe rand impar
			newPoz = { p.first, p.second - 1 };	//se deplaseaza spre stanga
		else
			newPoz = { p.first, p.second + 1 };	//se deplaseaz spre dreapta
	}

	if (map.getMatrix()[newPoz.first][newPoz.second] == 'T' && getItems() ==0)	//am capcana dar nu mai am item uri
	{
		incrementTraps(1);	//maresc numarul de capcane colectate
		if (getTraps() == 2)	//daca are 2 capcane
		{
			setLives(-1); //a pierdut o viata
			incrementTraps(-getTraps());	//ii scad numarul de capcane pe care le - a intalnit
				if (getLives() == 2)	//afisez un mesaj prin care il instiintez pe utilizator cate vieti mai are
					cout << "Just two lives you have. Careful you must be\n";
				else cout << "On life left you have. Choose wisely you must\n";
		}
		map.getMatrix()[newPoz.first][newPoz.second] = '_';
	}

	else if (getItems() == 1 && map.getMatrix()[newPoz.first][newPoz.second]== 'T')	//daca am un singur item ma pot folosi de el sa scap de capcana dar il va da pe robot pe pozitia anterioara
	{
		incrementItems(-1);		//decrementez nr de item-uri pe care le am
		newPoz = this->pozitiaAnterioara;	//pozitia noua devine pozitia din runda precednta
		map.getMatrix()[newPoz.first][newPoz.second] = '_';
	}

	if (map.getMatrix()[newPoz.first][newPoz.second] == 'I')
	{
		incrementItems(1);
		if (getItems() == 5 && getLives() < 3)	//daca ajung sa am 5 item - uri si nu mai are numarul maxim de vieti atunci le inlocuiesc cu o viata inplus
		{
			setLives(1);	//incremez nr de vieti
			incrementItems(-getItems());	//decrementez nr de item uri
		}
		map.getMatrix()[newPoz.first][newPoz.second] = '_'; //arat ca a luat item ul
	}

	setNewPosition(newPoz);	//setez noua pozitie a robotului cu cea rezultata in urma algoritmului
	map.changeMatrix(p, newPoz);	//transform matricea

	//urmeaza sa setez pozitia anterioara pentru a o putea utiliza in runda  urmatoare, daca este cazul
	if (newPoz.second == 0 || newPoz.second == n - 1)
			pozitiaAnterioara = { newPoz.first - 1, newPoz.second };
		else
		{
			if (newPoz.first % 2 == 0)
				pozitiaAnterioara = { newPoz.first, newPoz.second - 1 };
			else pozitiaAnterioara = { newPoz.first, newPoz.second + 1 };
		}
}
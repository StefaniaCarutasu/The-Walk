#include "runGame.h"

runGame::runGame()
{
	cout << "Este creata harta pe care se va misca robotul ales.";
	cout << "Atat dimensiunea cat si pozitiile liniei de finish si ale item-ilor si capcanelor sunt generate aleator.";
	m = new map();
	cout << "Acum urmeaza sa alegeti robotul astfel:\n";
	cout << "-> pentru C-3PO introduceti 1\n";
	cout << "-> pentru R2-D2 introduceti 2\n";
	cout << "-> pentru BB-8 introduceti 3\n";
	int x;
	cout << "Introduceti optiunea\n";
	cin >> x;
	switch (x)
	{
	case 1: 
	{
		cout << "Ati ales: C-3PO. SUCCES!\n";
		r = new C3PO("1_C-3PO");

	}
	case 2: 
	{
		cout << "Ati ales: R2-D2. SUCCES!\n ";
		r = new R2D2("2_R2-D2");
	}
	case 3:
	{
		cout << "Ati ales: BB-8. SUCCES!\n";
		r = new BB8("3_BB-8");
	}
	default:
		break;
	}
}

int runGame::noRound = 0;
void runGame::round()
{

}


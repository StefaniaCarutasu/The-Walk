#include "runGame.h"

runGame::runGame()
{
	cout << "Este creata harta pe care se va misca robotul ales.";
	cout << "Atat dimensiunea cat si pozitiile liniei de finish si ale item-ilor si capcanelor sunt generate aleator.\n\n";
	m = new map();
	m->generateFinish();
	m->generateItems();
	m->generateTraps();
	cout << "Acum urmeaza sa alegeti robotul astfel:\n";
	cout << "-> pentru C-3PO introduceti 1\n";
	cout << "-> pentru R2-D2 introduceti 2\n";
	cout << "-> pentru BB-8 introduceti 3\n\n";
	int x;
	cout << "Introduceti optiunea\n\n";
	cin >> x;
	switch (x)
	{
	case 1: 
	{
		cout << "Ati ales: C-3PO. SUCCES!\n";
		r = new C3PO("1_C-3PO");
		break;
	}
	case 2: 
	{
		cout << "Ati ales: R2-D2. SUCCES!\n ";
		r = new R2D2("2_R2-D2");
		break;
	}
	case 3:
	{
		cout << "Ati ales: BB-8. SUCCES!\n";
		r = new BB8("3_BB-8");
		break;
	}
	default:
		break;
	}
}

int runGame::noRound = 0;
void runGame::round()
{
	noRound++;
	cout << "Ati inceput runda: " << noRound << "\n";
	pair<int, int> oldPoz, newPoz;
	Robot* robot = this->r;
	oldPoz = robot->getCurrentPosition();
	robot->newPosition(*m);
	newPoz = robot->getCurrentPosition();
	cout << "Noua pozitie pe care se afla robotul este: (" << newPoz.first << ", " << newPoz.second << ")\n";
	if (newPoz == m->getFinish())
	{
		cout << "Felicitari, robotul a ajuns la final!";
		m->setFinish(make_pair(-1, -1));
	}
		
	if (robot->getVieti() == 0 && newPoz != m->getFinish())
	{
		cout << "Robotul nu a juns la final si a pierdut toate vietile! :(";
		m->setFinish(make_pair(-1, -1));
	}
	cout << '\n';
}

void runGame::currentState()
{
	cout << *this->m;
}

runGame::~runGame() 
{ 
	delete r; 
	delete m;
}

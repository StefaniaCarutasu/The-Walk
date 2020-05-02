#include "runGame.h"

runGame::runGame()
{
	cout << "Not so long ago, in an OOP course far, far away, there were three brave droids\ntrying to find a Jedi Master\n\n";
	//cout << "Este creata harta pe care se va misca robotul ales.";
	//cout << "Atat dimensiunea cat si pozitiile liniei de finish si ale item-ilor si capcanelor sunt generate aleator.\n\n";
	m = new map();
	m->generateFinish();
	m->generateItems();
	m->generateTraps();
	cout << "Choose the droid:\n";
	cout << "-> for C-3PO press 1\n";
	cout << "-> for R2-D2 press 2\n";
	cout << "-> for BB-8 press 3\n\n";
	int x;
	cout << "The galaxy awaits your choice!\n\n";
	cin >> x;

	try
	{
		if (x > 3 || x < 1)
			throw("invalid");
	}

	catch (string s)
	{
		cout << "This is not the droid you are looking for";
	}

	switch (x)
	{
	case 1: 
	{
		cout << "You chose: C-3PO. MAY THE FORCE BE WITH YOU!\n\n";
		r = new C3PO("1_C-3PO");
		break;
	}
	case 2: 
	{
		cout << "You chose: R2-D2.  MAY THE FORCE BE WITH YOU!\n\n ";
		r = new R2D2("2_R2-D2");
		break;
	}
	case 3:
	{
		cout << "Yout chose: BB-8.  MAY THE FORCE BE WITH YOU!\n\n";
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
	cout << "You started round: " << noRound << "\n";
	pair<int, int> oldPoz, newPoz;
	Robot* robot = this->r;
	oldPoz = robot->getCurrentPosition();
	robot->newPosition(*m);
	newPoz = robot->getCurrentPosition();
	cout << "The new position is: (" << newPoz.first << ", " << newPoz.second << ")\n";
	if (newPoz == m->getFinish())
	{
		cout << "Congratulations! The droid has found its master!";
		m->setFinish(make_pair(-1, -1));
	}
		
	if (robot->getLives() == 0 && newPoz != m->getFinish())
	{
		cout << "Your droid did't find his Jedi Master. Better luck next time!";
		m->setFinish(make_pair(-1, -1));
	}
	cout << '\n';
}
int runGame::isFinish()
{
	if (m->getFinish() == make_pair(-1, -1))
		return 1;
	return 0;
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

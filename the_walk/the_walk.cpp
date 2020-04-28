#include <iostream>
#include "map.h"
#include "Robot.h"
#include "C3PO.h"
#include "R2D2.h"
#include "BB8.h"
#include "runGame.h"
using namespace std;

int main()
{
 
    cout << "Starea initiala are urmatoarele caracteristici:\n";
    cout << "-> robotul se afla in coltul din stanga sus al hartii;\n";
    cout << "-> dimensiunea hartii este generata random si va avea dimensiune de maxim 30x30;\n";
    cout << "-> pe harta se vor afla atat item-uri care il vor ajuta pe robot, cat si capcane care sa il incurce;\n\n";
    cout << "Dupa fiecare mutare veti fi intrebat daca doriti sa continuati. Introduce 1 daca doriti, 0 altfel.\n\n";
    runGame game;
    game.currentState(); // afisam starea initiala cu robotul la (0,0), linia de finish, item urile si capcanele generate random
    int i = 1;
    do
    {
        game.round();
        game.currentState();
        if (game.isFinish())
            i = 0;
        else
        {
            cout << "\nDoriti sa continuati?\n";
            cin >> i;
        }
       
    } while (i == 1);
    return 0;
}

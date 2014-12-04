#include "joueur.h"
#include "plateau.h"

using namespace std;

bool Joueur::repetition(int x, int y)
{
    return false;
}

bool Joueur::libre(int x, int y)                // true si la case est libre
{
    for (int i = p->pierres.size()-1; i >= 0; i--)      
    {
        if (p->pierres[i]->getX() == x && p->pierres[i]->getY() == y)    // On cherche la derniere pierre à avoir ces coordonees
        {
            if (p->pierres[i]->estVivant())                         // On regarde si elle est morte : true
            {
                return false;
            }
            else
            {
                return false;
            }
        }
    } 
    return true;
}

bool Joueur::jouable(int x, int y)
{
    if ( !repetition(x, y) && libre(x, y))
    {
        return true;
    }
    return false;
}


bool Joueur::jouer(int x, int y)
{
    if (jouable(x, y))
    {
        Pierre *a = new Pierre (x, y, this->lettre, true);
        p->pierres.push_back(a);
        return true;
    }
    return false;
}
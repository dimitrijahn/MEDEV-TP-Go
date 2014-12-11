#include "plateau.h"


void deplacerCurseur(int x, int y)
{
    ostringstream os;
    os << "\033[" << (x+1) << ";" << (y+1) << "H";
    cout << os.str();
}

Pierre::Pierre(int x, int y, char lettre, bool vivant)
{
    this->x = x;
    this->y = y;
    this->lettre = lettre;
    this->vivant = vivant;
}

Plateau::Plateau(int taille)
{
    this->taille = taille;
    curseurX = 0;
    curseurY = 0;
}

void Plateau::afficher()
{
    for(int i=0; i < taille; i++)
    {
        for(int j=0; j < taille; j++)
        {
            cout << ".";
        }
        cout << endl;
    }
    
    for(int i=0; i < pierres.size(); i++)
    {
        Pierre pierre = *pierres[i];
        cout << "\033[1;12H";
        cout << pierre.getLettre() << endl;
    }
}

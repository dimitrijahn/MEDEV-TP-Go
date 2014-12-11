#include "plateau.h"




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

void Plateau::deplacerCurseur(int x, int y)
{
    ostringstream os;
    int lignesVidesDebut = 2;
    os << "\033[" << (x+1+lignesVidesDebut) << ";" << (y+1) << "H";
    cout << os.str();
}

void Plateau::deplacerCurseurFin()
{
    ostringstream os;
    int lignesVidesDebut = 2;
    os << "\033[" << (1+taille+lignesVidesDebut) << ";" << (1) << "H";
    cout << os.str();
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
    
    char charCurseur = '?';
    for(int i=0; i < pierres.size(); i++)
    {
        Pierre pierre = *pierres[i];
        if(pierre.estVivant())
        {
            deplacerCurseur(pierre.getX(), pierre.getY());
            cout << pierre.getLettre() << endl;
            if(pierre.getX() == curseurX && pierre.getY() == curseurY)
            {
                charCurseur = pierre.getLettre() == 'B' ? 'b' : 'n';
            }
        }
    }
    
    deplacerCurseur(curseurX, curseurY);
    cout << charCurseur;
    deplacerCurseurFin();
}

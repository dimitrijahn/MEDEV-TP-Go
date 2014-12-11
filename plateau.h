#ifndef PLATEAU_H
#define	PLATEAU_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Pierre
{
private:
    int x;
    int y;
    char lettre; // B ou N
    bool vivant;

public:
    Pierre(int x, int y, char lettre, bool vivant);
    int getX() { return x; };
    int getY() { return y; };
    char getLettre() { return lettre; };
    bool estVivant() { return vivant; };
    
    //ajouté par KANG pour réaliser "capturer"
    void setVivant(bool v){ this->vivant = v;};
};

class Plateau
{
public:
    vector<Pierre*> pierres;
    int taille;
    int curseurX;
    int curseurY;
    
    Plateau(int taille);
    void deplacerCurseur(int x, int y);
    void deplacerCurseurFin();
    void afficher();
};

#endif	/* PLATEAU_H */


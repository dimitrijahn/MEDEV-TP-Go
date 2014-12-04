#ifndef JOUEUR_H
#define	JOUEUR_H

#include <vector>
#include "plateau.h"

using namespace std;

class Joueur {
private:
    Plateau* p;
    char lettre; // B ou N
    bool repetition(int x, int y); // true si repetition
    bool libre(int x, int y);      // true si la case est libre
    bool jouable(int x, int y);
    void capturer();
    int pierresCapturees();
    int pierresTuees();
    
public:
    Joueur(char lettre, Plateau *p) { this->lettre = lettre; };
    char getLettre() { return lettre; };
    int compterPoints();
    bool jouer(int x, int y);
};

#endif	/* JOUEUR_H */


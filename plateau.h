#ifndef PLATEAU_H
#define	PLATEAU_H

#include <iostream>
#include <vector>

using namespace std;

class Pierre {
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
};

class Plateau {
public:
    vector<Pierre*> pierres;
    
    Plateau();
    void afficher();
    
};

#endif	/* PLATEAU_H */


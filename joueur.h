#ifndef JOUEUR_H
#define	JOUEUR_H

#include <vector>
#include <gtest/gtest.h>

#include "plateau.h"

using namespace std;

/*!
 * @class Joueur
 * @brief La classe qui place les pierres
 * 
 * La classe qui place les pierres et
 * effectue toutes les vérifications des règles.
 */
class Joueur {
private:
    Plateau* p;
    char lettre; // B ou N
    bool repetition(int x, int y); // true si repetition
    bool libre(int x, int y); // true si la case est libre
    bool jouable(int x, int y);
    //créé par KANG Yabin pour réaliser "capturer"
    bool contenirDans(Pierre* p,vector<Pierre*>* groupe);
    void groupeContenir(Pierre* p,vector<Pierre*> *groupe);
    bool pierreAIntersectionsVides(Pierre* pierre);
    bool groupeALiberte(vector<Pierre*> *groupe);
    void capturer();
    
    int pierresCapturees();
    int pierresTuees();
    int intersectionsLibres();
    
    FRIEND_TEST(TestGuillaume, testRepetition);
    
public:
    Joueur(char lettre, Plateau *p) { this->lettre = lettre; this->p = p; };
    char getLettre() { return lettre; };
    int compterPoints();
    bool jouer(int x, int y);
};

#endif	/* JOUEUR_H */


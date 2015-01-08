#include <gtest/gtest.h>
#include "joueur.h"
#include "plateau.h"

TEST(TestDimitri, testLibre)
{
    Plateau p = Plateau(5);
 
    p.pierres.push_back(new Pierre(0, 1, 'N', true));
    
    Joueur jB = Joueur('B', &p);
    
    EXPECT_FALSE(jB.jouer(0, 1));
    
    EXPECT_TRUE(jB.jouer(1, 1));
    EXPECT_FALSE(jB.jouer(1, 1));
}

TEST(TestGuillaume, testRepetition)
{
    Plateau p = Plateau(5);
    Joueur jN = Joueur('N', &p);
    Joueur jB = Joueur('B', &p);

    p.pierres.push_back(new Pierre(1, 2, 'N', true));
    p.pierres.push_back(new Pierre(1, 2, 'N', false));
    
    EXPECT_TRUE(jN.repetition(1, 2));
    EXPECT_FALSE(jN.repetition(0, 2));
}

/*TEST(JoueurTest, testCarreJN)
{
    Plateau p = Plateau(5);
    Joueur jN = Joueur('N', &p);
    Joueur jB = Joueur('B', &p);
    
    p.pierres.push_back(new Pierre(0, 1, 'N', true));
    p.pierres.push_back(new Pierre(1, 0, 'N', true));
    p.pierres.push_back(new Pierre(1, 2, 'N', true));
    p.pierres.push_back(new Pierre(2, 1, 'N', true));
    
    EXPECT_TRUE(true);
    EXPECT_FALSE(jB.jouer(1, 1));
}*/
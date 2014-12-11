#include <gtest/gtest.h>

#include "plateau.h"
#include "joueur.h"

TEST(TestGuillaume, testRepetition)
{
    Plateau p = Plateau(5);
    Joueur jN = Joueur('N', &p);
    Joueur jB = Joueur('B', &p);

    p.pierres.push_back(new Pierre(1, 2, 'N', true));
    p.pierres.push_back(new Pierre(1, 2, 'N', false));
    
    EXPECT_EQ(true, jN.repetition(1, 2));
}
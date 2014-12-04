
#include "plateau.h"

include "plateau.h";

Plateau::Plateau() {
    
}


Pierre::Pierre(int x, int y, char lettre, bool vivant)
{
    this->x = x;
    this->y = y;
    this->lettre = lettre;
    this->vivant = vivant;
}
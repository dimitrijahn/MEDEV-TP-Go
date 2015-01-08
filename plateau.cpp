#include "plateau.h"



/*!
 * @brief Constructeur
 * 
 * Constructeur de la classe Pierre.
 * 
 * @param x : position x de la pierre
 * @param y : position y de la pierre
 * @param lettre : indique le joueur, N ou B en majuscule
 * @param vivant : si false, la pierre disparait du plateau
 * mais est gardée dans l'historique de jeu 
 */
Pierre::Pierre(int x, int y, char lettre, bool vivant)
{
    this->x = x;
    this->y = y;
    this->lettre = lettre;
    this->vivant = vivant;
}


/*!
 * @brief Constructeur
 * 
 * Constructeur de la classe Plateau.
 * 
 * @param taille : taille du plateau (hauteur et largeur)
 */
Plateau::Plateau(int taille)
{
    this->taille = taille;
    curseurX = 0;
    curseurY = 0;
}

/*!
 * @brief Déplace le curseur
 * 
 * Déplace le curseur dans le plateau, de 0 à taille-1.
 * 
 * @param x : destination en x (0 à taille-1)
 * @param y : destination en y (0 à taille-1)
 */
void Plateau::deplacerCurseur(int x, int y)
{
    ostringstream os;
    int lignesVidesDebut = 2;
    os << "\033[" << (x+1+lignesVidesDebut) << ";" << (y+1) << "H";
    cout << os.str();
}

/*!
 * @brief Déplace le curseur après le plateau
 * 
 * Déplace le curseur à la ligne en dessous du plateau.
 */
void Plateau::deplacerCurseurFin()
{
    ostringstream os;
    int lignesVidesDebut = 2;
    os << "\033[" << (1+taille+lignesVidesDebut) << ";" << (1) << "H";
    cout << os.str();
}

/*!
 * @brief Affiche le plateau
 * 
 * Affiche le plateau et le curseur, un carré de taille par taille. 
 */
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
    
    // Corrige la lettre sous le curseur (?, b ou n)
    deplacerCurseur(curseurX, curseurY);
    cout << charCurseur;
    
    deplacerCurseurFin();
}

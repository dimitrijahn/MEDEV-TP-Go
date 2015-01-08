#include <iostream>

#include "plateau.h"
#include "joueur.h"

using namespace std;

int main(int argc, char** argv)
{
    Plateau p = Plateau(5);
    Joueur jN = Joueur('N', &p);
    Joueur jB = Joueur('B', &p);
    
    int tour = 0;
    bool passerN = false;
    bool passerB = false;
    /*
     * Boucle principale
     * Continue tant que les deux joueurs n'ont pas passé
     */
    while(passerN == false || passerB == false)
    {
        tour++;
        
        bool tourEnCours = true;
        char key;
        /*
         * Boucle du tour en cours
         * Continue tant que le joueur ne joue pas un coup valide
         * 
         * 1) Vide la console
         * 2) Affichage l'interface et le plateau
         * 3) Attends un input utilisateur
         * 4) Traite l'input utilisateur
         */
        while(tourEnCours)
        {
            // 1) Vide la console
            cout << "\033[H\033[J";
            
            // 2) Affichage l'interface et le plateau
            if(tour % 2 == 1) // Tour Noir
            {
                passerN = false;
                cout << "*** Tour " << tour << " - Joueur Noir ***" << endl;
                cout << (passerB ? "Joueur Blanc a passe son tour" : "") << endl;
            }
            else // Tour Blanc
            {
                passerB = false;
                cout << "*** Tour " << tour << " - Joueur Blanc ***" << endl;
                cout << (passerN ? "Joueur Noir a passe son tour" : "") << endl;
            }
            
            p.afficher();
            
            // 3) Attends un input utilisateur
            cin >> key;
            
            // 4) Traite l'input utilisateur
            switch(key)
            {
                /*
                 * Deplacements curseur
                 */
                case 'z':
                    p.curseurX = (p.curseurX-1+p.taille)%p.taille;
                    break;
                case 's':
                    p.curseurX = (p.curseurX+1+p.taille)%p.taille;
                    break;
                case 'q':
                    p.curseurY = (p.curseurY-1+p.taille)%p.taille;
                    break;
                case 'd':
                    p.curseurY = (p.curseurY+1+p.taille)%p.taille;
                    break;
                    
                /*
                 * Passer
                 */
                case 'p':
                    if(tour % 2 == 1) // Tour Noir
                    {
                        passerN = true;
                        tourEnCours = false;
                    }
                    else // Tour Blanc
                    {
                        passerB = true;
                        tourEnCours = false;
                    }
                    break;
                
                /*
                 * Jouer
                 */
                case 'a':
                    if(tour % 2 == 1) // Tour Noir
                    {
                        if(jN.jouer(p.curseurX, p.curseurY))
                        {
                            tourEnCours = false;
                        }
                    }
                    else // Tour Blanc
                    {
                        if(jB.jouer(p.curseurX, p.curseurY))
                        {
                            tourEnCours = false;
                        }
                    }
                    break;
            }
        }
    }
    
    return 0;
}

#include <iostream>
#include <ncurses.h>

#include "plateau.h"
#include "joueur.h"
using namespace std;

int main(int argc, char** argv)
{
    //initscr();
    
    Plateau p = Plateau(5);
    Joueur jN = Joueur('N', &p);
    Joueur jB = Joueur('B', &p);
    
    Pierre p = Pierre(2, 3, 'i', true);
    
    int tour = 0;
    bool passerN = false;
    bool passerB = false;
    while(passerN == false || passerB == false)
    {
        tour++;
        
        cout << "\033[H\033[J";
        
        if(tour % 2 == 1) // Tour Noir
        {
            passerN = false;
            cout << "*** Tour " << tour << " - Joueur Noir ***" << endl << endl;
        }
        else // Tour Blanc
        {
            passerB = false;
            cout << "*** Tour " << tour << " - Joueur Blanc ***" << endl << endl;
        }
        
        p.afficher(); 
        
        ostringstream os;
        bool tourEnCours = true;
        char key;
        while(tourEnCours)
        {
            cin >> key;
            
            switch(key)
            {
                /*
                 * Deplacements curseur
                 */
                case 'z':
                    p.curseurX = (p.curseurX-1)%p.taille;
                    cout << "\033[1;12H";
                    break;
                case 's':
                    p.curseurX = (p.curseurX+1)%p.taille;
                    cout << "\033[10;1H";
                    break;
                case 'q':
                    p.curseurY = (p.curseurY-1)%p.taille;
                    
                    deplacerCurseur(2,3);
                    break;
                case 'd':
                    p.curseurY = (p.curseurY+1)%p.taille;
                    //move(2,3);
                    //refresh();
                    break;
                
                /*
                 * Passer
                 */
                case 'p':
                    if(tour % 2 == 1) // Tour Noir
                    {
                        cout << "Noir passe" << endl;
                        passerN = true;
                        tourEnCours = false;
                    }
                    else // Tour Blanc
                    {
                        cout << "Blanc passe" << endl;
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
                        else
                        {
                            cout << "Nope" << endl;
                        }
                    }
                    else // Tour Blanc
                    {
                        if(jB.jouer(p.curseurX, p.curseurY))
                        {
                            tourEnCours = false;
                        }
                        else
                        {
                            cout << "Nope" << endl;
                        }
                    }
                    break;
            }
        }
    }
    
    return 0;
}

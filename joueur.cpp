#include "joueur.h"
#include "plateau.h"
#include<vector>

using namespace std;


bool egalMat (char tableauPlateau [5][5], char tableauPlateau2 [5][5])
{
    for (int i=0; i<5; i++)
        {
            for (int j=0; j<5; j++)
            {
                if (tableauPlateau2[i][j] != tableauPlateau[i][j])
                {
                    return false;
                }
            }
        }
    return true;
}


bool Joueur::repetition(int x, int y)
{
    char tableauPlateau [5][5] = {' '}; // On définie un tableau représentant le plateau
    char tableauPlateau2 [5][5] = {' '};
    
    for (int i=0; i < p->pierres.size(); i++)
    {
        if (p->pierres[i]->estVivant() == false )
        { 
            tableauPlateau[p->pierres[i]->getX()][p->pierres[i]->getY()]= ' ';
        }
        else 
        {
            tableauPlateau[p->pierres[i]->getX()][p->pierres[i]->getY()]= p->pierres[i]->getLettre();
        }
    }
    tableauPlateau[x][y] = this->lettre; //on obtient un tableau représentant le plateau après le dernier tour de jeu



    for (int i=0; i < p->pierres.size(); i++)
    {
        if (p->pierres[i]->estVivant() == false)
        {
            tableauPlateau2[p->pierres[i]->getX()][p->pierres[i]->getY()] = ' ';
        }
        else 
        {
            tableauPlateau2[p->pierres[i]->getX()][p->pierres[i]->getY()]= p->pierres[i]->getLettre();
        }
        

        if (egalMat(tableauPlateau, tableauPlateau2))
        {
            return true;
        }
    }
    return false;
}


/*!
 * @brief Teste si la case est libre
 * 
 * @param x : position en x (0 à taille-1)
 * @param y : position en y (0 à taille-1)
 * @return true si la case est libre, false sinon
 */
bool Joueur::libre(int x, int y)
{
    for (int i = p->pierres.size()-1; i >= 0; i--)      
    {
        if (p->pierres[i]->getX() == x && p->pierres[i]->getY() == y) // On cherche la derniere pierre à avoir ces coordonees
        {
            if (p->pierres[i]->estVivant()) // On regarde si elle est morte : true
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    } 
    return true;
}


/*!
 * @brief Teste si la case est jouable
 * 
 * @param x : position en x (0 à taille-1)
 * @param y : position en y (0 à taille-1)
 * @return true si la case est jouable, false sinon
 */
bool Joueur::jouable(int x, int y)
{    
    if ( !repetition(x, y) && libre(x, y))
    {
        return true;
    }
    return false;
}

/*!
 * @brief Essaye de jouer
 * 
 * @param x : position en x (0 à taille-1)
 * @param y : position en y (0 à taille-1)
 * @return true si le coup a été joué, false sinon
 */
bool Joueur::jouer(int x, int y)
{
    if (jouable(x, y))
    {
        p->pierres.push_back(new Pierre (x, y, this->lettre, true));
        return true;
    }
    return false;
}


//créé par KANG Yabin pour réaliser "capturer"
bool Joueur::contenirDans(Pierre* p,vector<Pierre*>* groupe)//vérifier si le groupe contient p
{
    vector<Pierre*>:: iterator itG ;
    for(itG=(*groupe).begin();itG!=(*groupe).end();itG++)
    {
        if((*itG) == p)return true;
    }
    return false;
}


void Joueur::groupeContenir(Pierre* pierre,vector<Pierre*> *groupe)//trouver le groupe qui contient certain pierre
{
    groupe->push_back(pierre);
    vector<Pierre*>:: iterator itG ;
    int x = pierre->getX();
    int y = pierre->getY();
    vector<Pierre*>:: iterator itP ;
    for(itG=(*groupe).begin();itG!=(*groupe).end();itG++)
    {
        //verifier si les pierres vivants de la même couleur autour de (*itG) sont dans le même groupe
        //sinon,l'ajouter dans le groupe
        for(itP=((this->p)->pierres).begin();itP!=((this->p)->pierres).end();itP++)
        {
            if(!(*itP)->estVivant()) continue;
            if((*itP)->getX()==x+1 && (*itP)->getY()==y)
            {
                if( (*itG)->getLettre() == (*itP)->getLettre() && 
                        !contenirDans((*itP),groupe)) groupe->push_back((*itP));
            }
            else if((*itP)->getX()==x && (*itP)->getY()==y+1)
            {
                if( (*itG)->getLettre() == (*itP)->getLettre() && 
                        !contenirDans((*itP),groupe)) groupe->push_back((*itP));
            }
            else if((*itP)->getX()==x-1 && (*itP)->getY()==y)
            {
                if( (*itG)->getLettre() == (*itP)->getLettre() && 
                        !contenirDans((*itP),groupe)) groupe->push_back((*itP));
            }
            else if((*itP)->getX()==x && (*itP)->getY()==y-1)
            {
                if( (*itG)->getLettre() == (*itP)->getLettre() && 
                        !contenirDans((*itP),groupe)) groupe->push_back((*itP));
            }
        } 
    }
}


//hypothèses par KANG Yabin:
//1.l'origine du plateau est (0,0),pas (1,1)
//2.le nombre des pierres est suffisamment grand,donc des pierres capturés n'est pas réutilisables
bool Joueur::pierreAIntersectionsVides(Pierre* pierre)//vérifier si un pierre a des intersections vides
{
    vector<Pierre*>:: iterator itP ;
    int taille = (this->p)->taille; //le taille du plateau
    //coordonnées du pierre
    int px = pierre->getX();
    int py = pierre->getY();
    
    //si le gauche du pierre est occupé, gauche =2;si  était occupé mais n'est pas occupé,gauche = 1;si jamais occupé, gauche = 0.
    //droit ,avant,derriere ont la même définition
    int gauche = 0;
    int droit = 0;
    int avant = 0;
    int derriere = 0;
    //
    for(itP=((this->p)->pierres).begin();itP!=((this->p)->pierres).end();itP++)
    {
        if((*itP)->getX()== px+1 && (*itP)->getY()== py)
        {
             //si le derriere  était occupé,on change la valeur de derriere à 1
            if(!(*itP)->estVivant()) derriere = 1;  
            //si le derriere  était occupé,on change la valeur de derriere à 2
            else derriere = 2;
        }
                
        else if((*itP)->getX()== px && (*itP)->getY()== py+1)
        {
            
            if(!(*itP)->estVivant()) droit = 1;  //
            else droit = 2;
        }
            
        else if((*itP)->getX()== px-1 && (*itP)->getY()== py)
        {
            
            if(!(*itP)->estVivant()) avant = 1;  //
            else avant = 2;
        }
        else if((*itP)->getX()== px && (*itP)->getY()== py-1)
        {
            
            if(!(*itP)->estVivant()) gauche = 1;  //
            else gauche = 2;
        } 
    }
    
    //si le pierre est à la frontière,les intersections correspondants sont traités comme être occupé.(est occupé)
    if(px == 0) avant=2;
    else if(px == taille - 1) derriere = 2;
    if(py = 0) gauche = 2;
    else if(py =taille - 1) droit = 2;
    if(!gauche*droit*avant*derriere) return true;//au moins un intersection autour du pierre n'est jamais occupé
    if(derriere == 1 || droit == 1 || avant == 1 || gauche == 1)return true;//au moins un intersection autour du pierre qui étais occupé et qui n'est pas occupé
}


bool Joueur::groupeALiberte(vector<Pierre*> *groupe)//vérifier si un groupe a de la liberté
{
    vector<Pierre*>:: iterator itG;
    //si au moins un pierre dans le groupe a des intersections vides,le groupe a liberté;
    //sinon,le groupe n'a pas de liberté
    for(itG=(*groupe).begin();itG!=(*groupe).end();itG++)
    {
        if(this->pierreAIntersectionsVides((*itG)))return true;
    }
    return false;
}


void Joueur::capturer() //capturer les groupes (un pierre seul est un groupe spécial) qui n'ont pas de liberté
{
    vector<Pierre*>:: iterator it;
    char l = this->lettre;
    vector<Pierre*> *groupe;
    for(it=((this->p)->pierres).begin();it!=((this->p)->pierres).end();it++)
    {
        if((*it)->getLettre()!=l && (*it)->estVivant())  //trouver un pierre du adversaire  qui est vivant
        {
            this->groupeContenir((*it),groupe); //trouver le groupe qui contenir ce pierre
            if(!this->groupeALiberte(groupe)) //si le goupe trouvé n'a pas de liberté,on les capture.(mettre vivant = false)
            {
                vector<Pierre*>:: iterator itG ;
                for(itG=(*groupe).begin();itG!=(*groupe).end();itG++)
                {
                    (*itG)->setVivant(false);
                }
            }
        }
    }  
}


int Joueur::pierresTuees()
{
    int pierresMortes=0;
    for (int i=0; i<p->pierres.size(); i++)
    {
        if (p->pierres[i]->estVivant() == false && p->pierres[i]->getLettre() == this->getLettre())
        {
            pierresMortes ++;
        }
    }
    return pierresMortes;
}


int Joueur::intersectionsLibres()
{
    
}

/*!
 * @brief Compte les points en fin de partie
 * 
 * @return le nombre de points du joueur
 */
int Joueur::compterPoints()
{
    return (intersectionsLibres() - pierresTuees());
}
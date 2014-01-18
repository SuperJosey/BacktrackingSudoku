//
//  grille.cpp
//  Resolution sudoku via backtracking recursif
//
//  Created by Clément on 15/01/14.
//  Copyright (c) 2014 Clément. All rights reserved.
//

#include "grille.h"
#define VIDE 0


using namespace std;


grille::grille(){
    
    initialiser();
    
}


grille::~grille(){
    
}


void grille::initialiser(){
    
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            _grille[i][j]=-1;
        }
    }
}

/* chargerGrille est un mutateur sur l'attribut _grille 
 * il permet de charger une grille de sudoku de dim 9*9 
 */
void grille::chargerGrille(int Mat[9][9]){
    
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            _grille[i][j]=Mat[i][j];
        }
    }
}



/* afficherGrille permet un affichage pseudo graphique de la grille 
 */
void grille::afficherGrille(){
    
    cout << "-------------------"<<endl;
    
    for(int i=0; i<9; i++)
    {
        cout<< "|";
        for(int j=0; j<9; j++)
        {
            if(!((j+1)%3 == 0)){
                cout << _grille[i][j] << " ";
            }
            else{
                cout << _grille[i][j] << "|";
            }
            
        }
        cout << endl;
        if((i+1)%3 == 0){
            
            cout<< "-------------------"<<endl;
        }
    }
}


/* condition est une methode verifiant l'existance    
 * de la valeur que l'on teste si cette valeur trouve
 * trouve une occurence dans une ligne, colonne ou
 * bloc alors la condition n'est pas respecté: false
 * dans tout les autres cas cette methode renvoie true
 */

bool grille::condition(int lign, int col, int val)
{
    //absent ligne:
    
    for(int i=0; i<9; i++)
    {
        if(_grille[lign][i]==val)
        {
            return false;
        }
    }
    
    //absent colonne:
    
    for(int j=0; j<9; j++)
    {
        if(_grille[j][col]==val)
        {
            return false;
        }
    }
    
    
    //absent bloc:
    
    int blocLigne = lign-(lign%3), blocCol = col-(col%3);
    for(lign=0; lign<3; lign++){
        for(col=0; col<3; col++)
        {
            if(_grille[lign+blocLigne][col+blocCol]==val)
            {
                return false;
            }
        }
    }
    
    //dans tout les autres cas:
    
    return true;
}

void grille::setTemp(double x){
    
    _temp=x;
}

double grille::getTemp(){
    return _temp;
}

/* resoudre est une methode qui resoud une grille pré rempli via
 * l'algorithme de backtracking. La méthode trouve une position
 * non assigné dans la grille (VIDE), et considere les entier de 1
 * à 9 comme possibilité, cette possibilité est vrai si il n'y-a
 * aucun conflit en verifiant les conditions de resolution d'un sudoku
 * via la methode condition, si ce n'est pas le cas on effectue un retour
 * en arriere dans nos entier possible
 */

bool grille::resoudre(int position){
    
    clock_t debut=clock();
    
    int lign=position/9, col=position%9;
    if(position==9*9) return true;
    if(_grille[lign][col] != VIDE)
    {
        return resoudre(position+1);
    }
        for(int val=1; val<=9; val++) 
        {
  
            if(condition(lign,col,val)==true) 
            {
                
                _grille[lign][col]=val; 
                if(resoudre(position))  
                {
                    return true;
                }
            }
            _grille[lign][col]=VIDE;
                        
        }
    
    clock_t fin=clock();
    double temp=(double)(debut-fin)/CLOCKS_PER_SEC * 1000.0;
    setTemp(temp);
    
    return false;
}

/*
 * Methode d'affichage de la resolution
 */

void grille::afficheResol(){
    
    if(resoudre(0)==true)
    {
        afficherGrille();
    }
    else{
        cout<<"Pas de solution trouvé"<<endl;
    }
}




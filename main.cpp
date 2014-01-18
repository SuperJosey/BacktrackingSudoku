//
//  main.cpp
//  sudoku
//
//  Created by Clément on 15/01/14.
//  Copyright (c) 2014 Clément. All rights reserved.
//

#include <iostream>
#include "grille.h"

using namespace std;


int main(int argc, const char * argv[])
{
    int exempleG[9][9]={  {7,8,9,1,2,3,4,5,6},
        {3,0,0,0,4,0,0,0,8},
        {5,0,0,0,9,0,0,0,1},
        {8,0,0,0,3,0,0,0,4},
        {1,2,3,4,5,6,7,8,9},
        {6,0,0,0,7,0,0,0,2},
        {9,0,0,0,1,0,0,0,5},
        {2,0,0,0,6,0,0,0,7},
        {4,5,6,7,8,9,1,2,3} };
    
    grille grille1;
    
    grille1.chargerGrille(exempleG);
    
    cout<<"\nGrille avant resolution:"<<endl;
    grille1.afficherGrille();
    
    cout<<"\nGrille après resolution:"<<endl;
    grille1.afficheResol();
    
    cout<<"\nLe temp d'execution pour la methode 1 est de: "<<grille1.getTemp() <<endl;
    

    return 0;
}






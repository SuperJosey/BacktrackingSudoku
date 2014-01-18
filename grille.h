//
//  grille.h
//  testBor
//
//  Created by Clément on 17/01/14.
//  Copyright (c) 2014 Clément. All rights reserved.
//

#ifndef __testBor__grille__
#define __testBor__grille__

#include <iostream>

class grille{
    
private:
    int _grille[9][9];
    double _temp;

public:
    grille();
    ~grille();
    void initialiser();
    void chargerGrille(int Mat[9][9]);
    void afficherGrille();
    bool condition(int lign, int col, int val);
    void setTemp(double x);
    double getTemp();
    //Mehtode 1:
    bool resoudre(int position);
    void afficheResol();
    //Methode 2:

};

#endif /* defined(__testBor__grille__) */

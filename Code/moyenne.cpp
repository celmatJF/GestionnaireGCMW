#include <iostream>
#include <windows.h>
#include <clocale>
#include "moyenne.h"
#include <string>
#include "struct.hpp"
using namespace std;





float moyenne(eleve tab[30])
{ /*Rôle   : Calcule la moyenne de la clase et la retourne.
    Entrée : Nombre réel tabNote(tableau de 30 indices).
    Sortie : Nombre réel res retourné par la fonctions*/
    float r = 0.0;
    float res = 0.0;
    for(int i=0; i < 30; i++){
        if(tab[i].nom != ""){
            res = res + tab[i].note;
            r++;
        }
    }
    res = res / r;
    return res;
}
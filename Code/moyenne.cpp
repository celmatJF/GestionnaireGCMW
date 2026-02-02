#include <iostream>
#include <windows.h>
#include <clocale>
using namespace std;

// Importation des headers
#include "moyenne.h"
#include "struct.hpp"





float moyenne(eleve tab[30])
{ /*Rôle   : Calcule la moyenne de la clase et la retourne.
    Entrée : Nombre réel tabNote(tableau de 30 indices).
    Sortie : Nombre réel res retourné par la fonctions*/
    float r = 0.0;
    float res = 0.0;
    for(int i=0; i < 30; i++){
        if(tab[i].nom != ""){ // Si l'indice n'est pas vide
            res = res + tab[i].note; // Additionne la note à res
            r++; // Incrémente le compteur d'élèves pour la moyenne
        }
    }
    res = res / r; // Calcule la moyenne
    return res;
}
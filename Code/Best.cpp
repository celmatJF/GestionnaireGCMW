#include <iostream>
#include <windows.h>
#include <clocale>
#include "Best.h"
#include <string>
#include "struct.hpp"
using namespace std;

float bestNote(eleve tab[30])
{ /*Rôle   : Recherche dans tab la meilleur note et la retourne.
    Entrée : Structure eleve tab(tableau de 30 indices).
    Sortie : Nombre réel Best retourné par la fonctions*/

    float Best = tab[0].note; // Initialisation de Best avec la première note du tableau
    for(int h = 0; h < 30; h++){ 
        if (Best <= tab[h].note) { // Comparaison de chaque note avec Best
            Best = tab[h].note; //  Mise à jour de Best si une note plus élevée est trouvée
        }
    }
    return Best; // Retourne la meilleure note trouvée
}
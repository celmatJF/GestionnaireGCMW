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
    float Best = tab[0].note;
    for(int h = 0; h < 30; h++){
        if (Best <= tab[h].note) {
            Best = tab[h].note;
        }
    }
    return Best;
}
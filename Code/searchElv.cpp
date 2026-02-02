#include <iostream>
#include <windows.h>
#include <clocale>
using namespace std;

// Importation des headers
#include "SearchElv.h"
#include "struct.hpp"

void searchElv(eleve tab[30], string& nom, int& index, float& note)
{ /*Rôle    : Recherche dans tab par le nom et donne son numéro et sa note.
    Entrées : Chaine de cractères tab(tableau de 30 indices) et nom, 
              nombres réel tab(tableau de 30 indices) et note, entier index.
    Sorties : Entier index(passage par référence), nombre réel note(passage par référence)*/

    if (index == 0){ // Recherche par nom si index vaut 0
        for(int i = 0; i < 30; ++i) {
            if (nom == tab[i].nom) { // Si le nom est trouvé
                index = i + 1;   // Met à jour l'index (i+1 pour correspondre au numéro d'élève)
                note  = tab[i].note; // Met à jour la note
                return;// Quitte la fonction après avoir trouvé l'élève     
            }
        }
    }
    else{ // Recherche par index sinon
        if(index > 30 || index < 1){ // Si l'index est invalide
            index = 0;
        }
        else{ // Si l'index est valide
            note = tab[index - 1].note; // Met à jour la note à l'indice index -1
            nom = tab[index - 1].nom; // Met à jour le nom index -1 pour correspondre à l'indice du tableau
        }
        
    }
}
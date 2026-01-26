#include <iostream>
#include <windows.h>
#include <clocale>
#include "SearchElv.h"
#include <string>
#include "struct.hpp"
using namespace std;

void searchElv(eleve tab[30], string& nom, int& index, float& note)
{ /*Rôle    : Recherche dans tab par le nom et donne son numéro et sa note.
    Entrées : Chaine de cractères tab(tableau de 30 indices) et nom, 
              nombres réel tab(tableau de 30 indices) et note, entier index.
    Sorties : Entier index(passage par référence), nombre réel note(passage par référence)*/
    if (index == 0){
        for(int i = 0; i < 30; ++i) {
            if (nom == tab[i].nom) {
                index = i + 1;   
                note  = tab[i].note;
                return;          
            }
        }
    }
    else{
        if(index > 30 || index < 1){
            index = 0;
        }
        else{
            note = tab[index - 1].note;
            nom = tab[index - 1].nom;
        }
        
    }
}
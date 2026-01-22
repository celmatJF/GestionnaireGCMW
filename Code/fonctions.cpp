#include <iostream>
#include <windows.h>
#include <clocale>
#include "fonctions.h"
#include "colors.h"
#include <string>
using namespace std;



void liste(eleve tab[30])
{ /*Rôle   : Liste tous les éleves et donne le nombre le nombre d'éleves dans la classe.
    Entrée : Chaine de caractères tabElv(tableau de 30 indices).
    Sortie : cout */
    cout << BLUE << endl;
    int nb = 0;
    int j = 0;
    for(int i = 0; i < 30; i++)
    {
        cout << tab[i].nom;
        nb++;
        if(tab[i + 1].nom == ""){
        }else{
            cout << ", ";
        }
        if(j == 5){
            cout << endl;
            j = 0;
        }
        j++;
    }
    cout << "\nIl y a " << RED << nb << BLUE << " élèves dans la classe !"<< RESET;
}

float moyenne(eleve tab[30])
{ /*Rôle   : Calcule la moyenne de la clase et la retourne.
    Entrée : Nombre réel tabNote(tableau de 30 indices).
    Sortie : Nombre réel res retourné par la fonctions*/
    float res = 0;
    for(int i=0; i < 30; i++){
        res = res + tab[i].note;
    }
    res = res / 30.0f;
    return res;
}

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
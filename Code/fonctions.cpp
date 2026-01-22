#include <iostream>
#include <windows.h>
#include <clocale>
#include "fonctions.h"
#include "colors.h"
#include <string>
using namespace std;

void liste(string tabElv[30])
{ /*Rôle   : Liste tous les éleves et donne le nombre le nombre d'éleves dans la classe.
    Entrée : Chaine de caractères tabElv(tableau de 30 indices).
    Sortie : cout */
    cout << BLUE << endl;
    int nb = 0;
    int j = 0;
    for(int i = 0; i < 30; i++)
    {
        cout << tabElv[i];
        if(tabElv[i + 1] != "")
        {
            cout << ", ";
            nb++;
        }
        if(j == 5)
        {
            cout << endl;
            j = 0;
        }
        j++;
    }
    cout << "\nIl y a " << RED << nb << BLUE << " élèves dans la classe !"<< RESET;
}

float moyenne(float tabNote[30])
{ /*Rôle   : Calcule la moyenne de la clase et la retourne.
    Entrée : Nombre réel tabNote(tableau de 30 indices).
    Sortie : Nombre réel res retourné par la fonctions*/
    float res = 0;
    for(int i=0; i < 30; i++){
        res = res + tabNote[i];
    }
    res = res / 30.0f;
    return res;
}

void searchElv(std::string tabElv[30], float tabNote[30],std::string& nom, int& index, float& note)
{ /*Rôle    : Recherche dans tabElv par le nom et donne son numéro et sa note.
    Entrées : Chaine de cractères tabElv(tableau de 30 indices) et nom, 
              nombres réel tabNote(tableau de 30 indices) et note, entier index.
    Sorties : Entier index(passage par référence), nombre réel note(passage par référence)*/
    if (index == 0){
        for(int i = 0; i < 30; ++i) {
            if (nom == tabElv[i]) {
                index = i + 1;   
                note  = tabNote[i];
                return;          
            }
        }
    }
    else{
        if(index > 30 || index < 1){
            index = 0;
        }
        else{
            note = tabNote[index - 1];
            nom = tabElv[index - 1];
        }
        
    }
}

float bestNote(float tabNote[30])
{ /*Rôle   : Recherche dans tabNote la meilleur note et la retourne.
    Entrée : Nombre réel tabNote(tableau de 30 indices).
    Sortie : Nombre réel Best retourné par la fonctions*/
    float Best = tabNote[0];
    for(int h = 0; h < 30; h++)
        if (Best <= tabNote[h]) {
            Best = tabNote[h];
        }
    return Best;
}
#include <iostream>
#include <windows.h>
#include <clocale>
using namespace std;

// Importation des headers
#include "liste.h"
#include "struct.hpp"

void liste(eleve tab[30])
{ /*Rôle   : Liste tous les éleves et donne le nombre le nombre d'éleves dans la classe.
    Entrée : Chaine de caractères tabElv(tableau de 30 indices).
    Sortie : Eleves et nombre d'eleves par cout */

    cout << BLUE << endl; // Couleur bleu pour l'affichage
    int nb = 0; // Compteur d'élèves
    int j = 0; // Compteur pour le saut de ligne
    for(int i = 0; i < 30; i++)
    {

        if(tab[i].nom != ""){ // Si l'indice n'est pas vide
            cout << tab[i].nom << ", "; // Affiche le nom de l'élève
            nb++; // Incrémente le compteur d'élèves
            j++; // Incrémente le compteur pour le saut de ligne
        }else{
        }
        if(j == 5) // Après 5 élèves, faire un saut de ligne
        {
            cout << endl;
            j = 0;
        }
        
    }
    cout << "\nIl y a " << RED << nb << BLUE << " élèves dans la classe !"<< RESET; // Affiche le nombre d'élèves
}
#include <iostream>
#include <windows.h>
#include <clocale>
#include "liste.h"
#include <string>
#include "struct.hpp"
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
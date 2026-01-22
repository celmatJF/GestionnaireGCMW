#include <iostream>
#include <windows.h>
#include <clocale>
#include "AddStudent.h"
#include "colors.h"
#include <string>
#include <fstream>
#include "struct.hpp"
using namespace std;

void AddStudent(eleve tab[30])
{ /*Rôle   : Ajouter un éleve au tableau.
    Entrée : Nombre réel tabNote(tableau de 30 indices),
    chaine de cractères tabElv(tableau de 30 indices).
    Sortie : cout */
    int index;
    for(int i(0); i < 30; i++)
    {    
        if(tab[i].nom == "")
        {
            string StudentName;
            cout << BLUE << "Entrez le nom de l'élève : " << RED;
            cin >> StudentName;
            tab[i].nom = StudentName;
            index = i;
            break;
        }
    }
    cout << BLUE << "Entrez sa note : " << RED;
    cin >> tab[index].note;
    cout << RESET;
}
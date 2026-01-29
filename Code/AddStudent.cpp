#include <iostream>
#include <windows.h>
#include <clocale>
#include "AddStudent.h"
#include <string>
#include "struct.hpp"
using namespace std;

void AddStudent(eleve tab[30])
{ /*Rôle   : Ajouter un éleve au tableau.
    Entrée : Nombre réel tabNote(tableau de 30 indices),
    chaine de cractères tabElv(tableau de 30 indices).
    Sortie : cout */
    int index;
    float note;
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
        else if(i == 29 && tab[i].nom != "")
        {
            cout << RED << "\nLe tableau est plein, impossible d'ajouter un éleve.\n" << RESET;
            return;
        }
    }
    do 
    {
        cout << BLUE << "Entrez sa note : " << RED;
        cin >> note;
        if(note > 20 || note < 0)
        {
            cout << "Cette note n'est pas valide !" << endl;
        }
        else
        {
            tab[index].note = note;
        }
    } while (note > 20 || note < 0);

    cout << RESET;
}
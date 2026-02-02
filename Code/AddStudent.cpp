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

    int index; // Indice où ajouter le nouvel élève
    float note; // Note de l'élève
    for(int i(0); i < 30; i++)
    {    
        if(tab[i].nom == "") // Trouver le premier emplacement vide
        {
            string StudentName; // Nom de l'élève
            cout << BLUE << "Entrez le nom de l'élève : " << RED;
            cin >> StudentName; //  Lecture du nom de l'élève
            tab[i].nom = StudentName; // Stockage du nom dans le tableau
            index = i; //   Stockage de l'indice pour la note
            break;// Sortir de la boucle
        }
        else if(i == 29 && tab[i].nom != "") // Vérification si le tableau est plein
        {
            cout << RED << "\nLe tableau est plein, impossible d'ajouter un éleve.\n" << RESET;
            return; //  Sortir de la fonction
        }
    }
    do 
    {
        cout << BLUE << "Entrez sa note : " << RED;
        cin >> note;// Lecture de la note
        if(note > 20 || note < 0) // vérification de la validité de la note
        {
            cout << "Cette note n'est pas valide !" << endl;
        }
        else // Si la note est valide
        {
            tab[index].note = note; //  Stockage de la note dans le tableau
        }
    } while (note > 20 || note < 0); // Répéter jusqu'à obtenir une note valide
    // Confirmation de l'ajout
    cout << GREEN << "\nL'élève " << tab[index].nom ;
    cout << " avec la note de " << RED  << tab[index].note << GREEN << "/20 a bien été ajouté !\n" << RESET;
}
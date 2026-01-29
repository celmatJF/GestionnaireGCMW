#include <iostream>
#include <fstream>
#include <windows.h>
#include <clocale>
#include "struct.hpp"
#include "ExportFile.h"
using namespace std;

string const FichierClasse = "ListeClasse.csv"; // Création du nom du fichier

void ExportFile(eleve tab[30])
{
    /* Usage: Exporter la liste des élèves ainsi 
    que leurs notes dans un fichier .csv

    Entrée: Variable tab[30] de type eleve 
    (venant de la structure du struct.hpp) 
    
    Sortie: Création d'un fichier .csv
    */

    ofstream AccesFichier(FichierClasse.c_str()); // Création du fichier

    if(AccesFichier) // Vérifie si le fichier a bien été créer
    {
        AccesFichier << "Nom,Note" << endl; // Ecris la premiere ligne
        for(int i = 0; i < 30; i++) // Boucle pour les trentes élèves
        {
            if(tab[i].nom != "") // Vérifie si la case numéro i n'est pas vide
            {
                AccesFichier << tab[i].nom << ',' << tab[i].note << endl; // Rajoute la ligne du nom et de la note de l'èleve au fichier .csv
            }
        }
        cout << BLUE << "Le fichier a été exporter avec succès" << endl; // Affichage confirmations de l'export
    } 
    else
    {
        cout << BLUE << "Le fichier n'a pas été exporter" << endl; // Affichage mauvais export
    }
    cout << RESET; // Fin
}
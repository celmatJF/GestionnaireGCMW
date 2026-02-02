#include <iostream>
#include <windows.h>
#include <clocale>
using namespace std;

// Importation des headers
#include "AddStudent.h"
#include "liste.h"
#include "moyenne.h"
#include "searchElv.h"
#include "Best.h"
#include "struct.hpp"
#include "ExportFile.h"

int main()
{
    // Configuration de la console pour UTF-8
    SetConsoleCP(CP_UTF8);          
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP(CP_UTF8);
    
    // Déclaration de la variable v de type structure
    Variables v;

    // Déclaration du tableau d'élèves à partir de la structure
    eleve tab[30];
    for(int i = 0; i < 30; i++) { // Initialisation avec des valeurs par défaut
        tab[i].nom = "";
        tab[i].note = 0.0f;
    }
    
    
    
    //----------------------- Boucle principale du programme------------------------

    cout << GREEN << "Bienvenu sur votre gestionaire de classe 👽" << RESET;
    while(v.exit == false){ // Boucle principale jusqu'à ce que v.exit soit vrai
        // Affichage du menu
        cout << GREEN << "\n\nQuelle opération souhaitez-vous réaliser ?\n\n" << RESET;
        cout << LIGHTBLUE  << ".1 Ajouter un Étudiant\n";
        cout <<".2 Afficher la liste complète des éleves\n";
        cout <<".3 Afficher la moyenne de la classe\n";
        cout <<".4 Chercher un éleve par son nom ou son numéro\n";
        cout <<".5 Afficher la meilleure note\n";
        cout <<".6 Exporter la list en fichier .csv (Tableur)\n";
        cout <<".7 Quitter\n" << RESET;

        cin >> v.choix; // Lecture du choix de l'utilisateur vers v.choix
        switch(v.choix){ // Exécution de l'action en fonction du choix
            case '1':
                AddStudent(tab);    // Appel de la fonction pour ajouter un étudiant
                break;
            case '2':
                liste(tab); // Appel de la fonction pour afficher la liste des étudiants
                break;
            case '3':
                v.res = moyenne(tab); // Appel de la fonction pour calculer la moyenne
                cout << BLUE << "\nLa moyenne de la classe est à " << RED << v.res << BLUE << "/20 \n\n" << RESET;
                break;
            case '4':
            // Recherche d'un élève par nom ou numéro
                v.nom = "";
                cout << BLUE << "\nEntrez le nom ou le numéro d'un éleve : ";
                cin >> v.nom;
                try {
                    v.index = stoi(v.nom); // Tente de convertir en entier
                    searchElv(tab, v.nom, v.index, v.note);
                    if (v.index == 0) {
                    cout << BLUE << "\nÉlève introuvable.\n" << RESET;
                    } else {
                    cout << BLUE << "\nLe nom de cet éleve est " << RED << v.nom;
                    cout << BLUE << " et sa note est " << RED << v.note << BLUE << "/20\n" << RESET;
                    }
                }
                catch(const invalid_argument&){ // Si la conversion échoue, c'est un nom
                    v.index = 0; // Réinitialiser l'index
                    searchElv(tab, v.nom, v.index, v.note);
                    if (v.index == 0) {
                    cout << BLUE << "\nÉlève introuvable.\n";
                    } else {
                    cout << BLUE << "\nLe numéro de cet éleve est " << RED << v.index;
                    cout << BLUE << " et sa note est " << RED << v.note << BLUE << "/20\n" << RESET;
                    }
                }
                v.index = 0;
                v.note = 0;
                break;
            case '5':
                v.Best  = bestNote(tab); // Appel de la fonction pour trouver la meilleure note
                cout << BLUE << "\nLa meilleure note c'est " << RED << v.Best << BLUE << "/20\n" << RESET;
                break;
            case '6':
                ExportFile(tab); // Appel de la fonction pour exporter la liste en fichier .csv
                break;
            case '7':
                v.exit = true; // Mettre fin à la boucle principale
                cout << YELLOW << "\n   Bye 🖐️\n\n" << RESET;
                break;
            default:
                break;
        }
    }
    return 0; // Fin du programme
}
/*
  Programme : gestoinaire d'élève
  Auteur,    : Célian, William, Gabriel, Matthieu 
  Date      : 02/02/2026
  Objet     : gestoinaire 
*/
#include <iostream>
#include <windows.h>
#include <clocale>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Importation des headers des fonctions
#include "AddStudent.h"
#include "liste.h"
#include "moyenne.h"
#include "searchElv.h"
#include "Best.h"
#include "struct.hpp" //Pour importer les structures et les variables globales
#include "ExportFile.h"

int main()
{
    // Configuration de la console pour UTF-8
    SetConsoleCP(CP_UTF8);          
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<float>(time(0)));
    char choix;
    bool sortie = false;
    float res;
    string nom;
    int index; 
    float Best; 
    float note;     

    // Déclaration du tableau d'élèves 
    // depuis de la structure
    eleve tab[30];
    // Initialisation avec des valeurs par défaut
    for(int i = 0; i < 30; i++) { 
        tab[i].nom = "";
        tab[i].note = 0.0f;
    }
    string pretab[22] = {"goku", "vegeta", "gohan", "trunks", "piccolo", "krillin", "ten shin han", "yamcha", "chaozu", "bulma",
                 "chi chi", "majin boo", "kid buu", "beerus", "whis", "broly", "kefla",
                 "c-16", "c-17", "c-18", "c-19", "c-20"};
    
    
    //----------------------- Boucle principale du programme------------------------

    cout << GREEN << "Bienvenu sur votre gestionaire de classe 👽" << RESET;
    while(sortie == false){ // Boucle principale jusqu'à ce que exit soit vrai
        // Affichage du menu
        cout << GREEN << "\n\nQuelle opération souhaitez-vous réaliser ?\n\n" << RESET;
        cout << LIGHTBLUE  << ".1 Ajouter un Étudiant\n";
        cout <<".2 Afficher la liste complète des éleves\n";
        cout <<".3 Afficher la moyenne de la classe\n";
        cout <<".4 Chercher un éleve par son nom ou son numéro\n";
        cout <<".5 Afficher la meilleure note\n";
        cout <<".6 Exporter la liste en fichier .csv (Tableur)\n";
        cout <<".7 Quitter\n" << RESET;

        cin >> choix; // Lecture du choix de l'utilisateur vers choix
        switch(choix){ // Exécution de l'action en fonction du choix
            case '1':
                AddStudent(tab);    // Appel de la fonction pour ajouter un étudiant
                break;
            case '2':
                liste(tab); // Appel de la fonction pour afficher la liste des étudiants
                break;
            case '3':
                res = moyenne(tab); // Appel de la fonction pour calculer la moyenne
                cout << fixed << setprecision(2) << BLUE << "\nLa moyenne de la classe est à " << RED << res << BLUE << "/20 \n\n" << RESET;
                // fixed et setprecision(2) pour afficher la moyenne avec 3 décimales
                break;
            case '4':
            // Recherche d'un élève par nom ou numéro
                nom = "";
                cout << BLUE << "\nEntrez le nom ou le numéro d'un éleve : ";
                cin >> nom;
                try {
                    index = stoi(nom); // Tente de convertir en entier
                    searchElv(tab, nom, index, note);
                    if (index == 0) {
                    cout << BLUE << "\nÉlève introuvable.\n" << RESET;
                    } else {
                    cout << BLUE << "\nLe nom de cet éleve est " << RED << nom;
                    cout << BLUE << " et sa note est " << RED << note << BLUE << "/20\n" << RESET;
                    }
                }
                catch(const invalid_argument&){ // Si la conversion échoue, c'est un nom
                    index = 0; // Réinitialiser l'index
                    searchElv(tab, nom, index, note);
                    if (index == 0) {
                    cout << BLUE << "\nÉlève introuvable.\n";
                    } else {
                    cout << BLUE << "\nLe numéro de cet éleve est " << RED << index;
                    cout << BLUE << " et sa note est " << RED << note << BLUE << "/20\n" << RESET;
                    }
                }
                index = 0;
                note = 0;
                break;
            case '5':
                Best  = bestNote(tab); // Appel de la fonction pour trouver la meilleure note
                cout << BLUE << "\nLa meilleure note c'est " << RED << Best << BLUE << "/20\n" << RESET;
                break;
            case '6':
                ExportFile(tab); // Appel de la fonction pour exporter la liste en fichier .csv
                break;
            case '7':
                sortie = true; // Mettre fin à la boucle principale
                cout << YELLOW << "\n   Bye 🖐️\n\n" << RESET;
                break;
            case 'p':
                for(int i = 0; i < 22; i++) {
                    tab[i].nom = pretab[i];
                    tab[i].note = rand() % 21; // Note aléatoire entre 0 et 20
                }
                break;
            default:
                break;
        }
    }
    return 0; // Fin du programme
}
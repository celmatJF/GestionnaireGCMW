#include <iostream>
#include <windows.h>
#include "fonctions.h"
#include <clocale>
#include "colors.h"
using namespace std;

   


int main()
{
    SetConsoleCP(CP_UTF8);          
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP(CP_UTF8);
    string tabElv[30] = {"Élie","Emma","", "Léa","Hugo","Célian","Thomas","Manon","Louis","Camille","Noah","Chloé","Enzo","Sarah"
                         "Paul","Inès","Arthur","Zoé","Adam","Juliette","Maxime","Lina","Gabriel","Eva","Matthieu","William","Raphaël","Nora","Antoine","Mila"};
    float tabNote[30] = {12, 15, 8, 17.3, 10, 17.11, 6, 18, 9, 16, 11, 13, 7, 19, 5, 20, 4, 18.5, 9.5, 14.5, 10.5, 12.5, 16.5, 6.5, 3, 2, 1, 17.5, 8.5, 11.5};
    char choix;
    bool exit = false;
    float res;
    string nom;
    int index;
    float Best;
    float note;
    
    cout << GREEN << "Bienvenu sur votre gestionaire de classe 👽" << RESET;
    while(exit == false){
        cout << GREEN << "\n\nQuelle opération souhaitez-vous réaliser ?\n\n" << RESET;
        cout << LIGHTBLUE  << ".1 Ajouter un Étudiant\n";
        cout <<".2 Afficher la liste complète des éleves\n";
        cout <<".3 Afficher la moyenne de la classe\n";
        cout <<".4 Chercher un éleve par son nom ou son numéro\n";
        cout <<".5 Afficher la meilleure note\n";
        cout <<".6 Quitter\n" << RESET;

        cin >> choix;
        switch(choix){
            case '1':
                AddStudent(tabElv, tabNote);
                break;
            case '2':
                liste(tabElv);
                break;
            case '3':
                res = moyenne(tabNote);
                cout << BLUE << "\nLa moyenne de la classe est à " << RED << res << BLUE << "/20 \n\n" << RESET;
                break;
            case '4':
                nom = "";
                cout << "\nEntrez le nom ou le numéro d'un éleve : ";
                cin >> nom;
                try {
                    index = stoi(nom);
                    searchElv(tabElv, tabNote, nom, index, note);
                    if (index == 0) {
                    cout << "\nÉlève introuvable.\n";
                    } else {
                    cout << "\nLe nom de cet éleve est " << nom;
                    cout << " et sa note est " << note << "/20\n";
                    }
                }
                catch(const invalid_argument&){
                    index = 0;
                    searchElv(tabElv, tabNote, nom, index, note);
                    if (index == 0) {
                    cout << "\nÉlève introuvable.\n";
                    } else {
                    cout << "\nLe numéro de cet éleve est " << index;
                    cout << " et sa note est " << note << "/20\n";
                    }
                }
                index = 0;
                note = 0;
                break;
            case '5':
                Best  = bestNote(tabNote);
                cout << BLUE << "\nLa meilleure note c'est " << RED << Best << BLUE << "/20\n" << RESET;
                break;
            case '6':
                exit = true;
                cout << YELLOW << "\n   Bye 🖐️\n\n" << RESET;
                break;
            default:
                break;
        }
    }
    return 0;
}
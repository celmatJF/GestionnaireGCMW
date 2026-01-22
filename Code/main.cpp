#include <iostream>
#include <windows.h>
#include "fonctions.h"
#include <clocale>
#include "colors.h"
using namespace std;


struct variable{
    char choix;
    bool exit = false;
    float res;
    int index;
    float Best;
    string nom;
    float note;
};

int main()
{
    SetConsoleCP(CP_UTF8);          
    setlocale(LC_ALL, ".UTF8");
    SetConsoleOutputCP(CP_UTF8);
    eleve tab[30];
    
    variable v;
    
    cout << GREEN << "Bienvenu sur votre gestionaire de classe 👽" << RESET;
    while(exit == false){
        cout << GREEN << "\n\nQuelle opération souhaitez-vous réaliser ?\n\n" << RESET;
        cout << LIGHTBLUE  << ".1 Ajouter un Étudiant\n";
        cout <<".2 Afficher la liste complète des éleves\n";
        cout <<".3 Afficher la moyenne de la classe\n";
        cout <<".4 Chercher un éleve par son nom ou son numéro\n";
        cout <<".5 Afficher la meilleure note\n";
        cout <<".6 Quitter\n" << RESET;

        cin >> v.choix;
        switch(v.choix){
            case '1':
                //AddStudent(tab);
                break;
            case '2':
                liste(tab);
                break;
            case '3':
                v.res = moyenne(tab);
                cout << BLUE << "\nLa moyenne de la classe est à " << RED << v.res << BLUE << "/20 \n\n" << RESET;
                break;
            case '4':
                v.nom = "";
                cout << "\nEntrez le nom ou le numéro d'un éleve : ";
                cin >> v.nom;
                try {
                    v.index = stoi(v.nom);
                    searchElv(tab, v.nom, v.index, v.note);
                    if (v.index == 0) {
                    cout << "\nÉlève introuvable.\n";
                    } else {
                    cout << "\nLe nom de cet éleve est " << v.nom;
                    cout << " et sa note est " << v.note << "/20\n";
                    }
                }
                catch(const invalid_argument&){
                    v.index = 0;
                    searchElv(tab, v.nom, v.index, v.note);
                    if (v.index == 0) {
                    cout << "\nÉlève introuvable.\n";
                    } else {
                    cout << "\nLe numéro de cet éleve est " << v.index;
                    cout << " et sa note est " << v.note << "/20\n";
                    }
                }
                v.index = 0;
                v.note = 0;
                break;
            case '5':
                v.Best  = bestNote(tab);
                cout << BLUE << "\nLa meilleure note c'est " << RED << v.Best << BLUE << "/20\n" << RESET;
                break;
            case '6':
                v.exit = true;
                cout << YELLOW << "\n   Bye 🖐️\n\n" << RESET;
                break;
            default:
                break;
        }
    }
    return 0;
}
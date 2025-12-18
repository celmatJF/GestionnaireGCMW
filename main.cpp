#include <iostream>
#include <windows.h>
using namespace std;


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string tabElv[30];
    float tabNote[30];
    char choix;
    const char* RED   = "\033[31m";
    const char* GREEN = "\033[32m";
    const char* BLUE  = "\033[34m";
    const char* RESET = "\033[0m";
    cout << GREEN << "Bienvenu sur votre gestionaire de classe 👽" << RESET << endl;
    cout << GREEN << "Quelle opération souhaitez-vous réaliser ?" << RESET << endl << endl;
    cout << BLUE << ".1 Ajouter un Étudiant" << RESET << endl;
    cout << BLUE << ".2 Afficher la liste complète des éleves" << RESET << endl;
    cout << BLUE << ".3 Afficher la moyenne de la classe" << RESET << endl;
    cout << BLUE << ".4 Chercher un éleve par son nom" << RESET << endl;
    cout << BLUE << ".5 Afficher la meilleure note" << RESET << endl;
    cin >> choix;

    switch(choix){
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
    }
    return 0;
}
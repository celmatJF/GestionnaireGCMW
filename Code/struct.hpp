#pragma once
#include <string>
using namespace std;

struct eleve   
{/*Rôle   : Structure contenant les informations d'un élève.
        nom  : Chaine de caractères représentant le nom de l'élève.
        note : Nombre réel représentant la note de l'élève.*/
    string nom;
    float note;
};

struct Variables{
    //Rôle   : Structure contenant les variables globales utilisées dans le programme.
    char choix; // Caractère représentant le choix de l'utilisateur dans le menu.
    bool exit = false; // booléen pour quitter le programme.
    float res; // Variable pour stocker des résultats intermédiaires.
    string nom; // Chaine de caractères pour stocker un nom d'élève.
    int index; // Entier pour stocker un index d'élève.
    float Best; // Nombre réel pour stocker la meilleure note.
    float note; // Nombre réel pour stocker une note d'élève.
};
// Couleurs pour l'affichage dans la console
inline constexpr const char* RED = "\033[31m";
inline constexpr const char* GREEN = "\033[32m";
inline constexpr const char* YELLOW = "\033[33m";
inline constexpr const char* LIGHTBLUE = "\033[34m";
inline constexpr const char* PURPLE = "\033[35m";
inline constexpr const char* BLUE = "\033[36m";
inline constexpr const char* RESET = "\033[0m";
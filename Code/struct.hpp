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



    


// Couleurs pour l'affichage dans la console
inline constexpr const char* RED = "\033[31m";
inline constexpr const char* GREEN = "\033[32m";
inline constexpr const char* YELLOW = "\033[33m";
inline constexpr const char* LIGHTBLUE = "\033[34m";
inline constexpr const char* PURPLE = "\033[35m";
inline constexpr const char* BLUE = "\033[36m";
inline constexpr const char* RESET = "\033[0m";
#pragma once
#include <string>

struct eleve{
    string nom;
    float note;
};

void liste(eleve tab[30]);
float moyenne(eleve tab[30]);

void searchElv(eleve tab[30], std::string& nom, int& index, float& note);
float bestNote(eleve tab[30]);
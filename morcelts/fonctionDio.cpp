//###
//Créer la fonction pour chercher un élève par son nom et celle pour trouver la meilleure note.
//fonctionDio
//###
#include <iostream>
#include <windows.h>
using namespace std;

int fonctionElv(string tabElv [30], string nom){
    int o = 0;
    for(int Elv = 0; Elv < 30; Elv++){
        if (nom == tabElv [Elv]) {
            o = Elv + 1;
        }
    }
    return o;
}
void fonctionNote(float tabNote[30], float &Best, int &index){
    Best = tabNote[0];
    for(int h = 0; h < 30; h++)
        if (Best <= tabNote[h]) {
            Best = tabNote[h];
            index = h;
        }
}
int main(){
SetConsoleOutputCP(CP_UTF8);
float tabNote [30] = {12, 18, 7, 14, 20, 9, 16, 11, 13, 19, 8, 10, 15, 6, 17, 4, 5, 3, 2, 1, 20, 19, 18, 17, 16, 14, 13, 12, 11, 10};
string tabElv [30] = {"Bjorn","Erik","Ragnar","Leif","Sven","Olaf","Ivar","Harald","Sigurd","Gunnar","Astrid","Freya","Ingrid","Sigrid","Liv","Helga","Dagny","Solveig","Ragnhild","Ylva","Magnus","Odin","Torvald","Ulf","Hakon","Nils","Anders","Soren","Loki","Frida"};
int nombreElv;
float Best = 0;
int index = 0;
string nom;

cout << "choisir un nom parmis :  ";
for(int i = 0; i < 30; i++){
    cout << i + 1 << ": " << tabElv[i] << "  ";}
cout <<endl;
cout << "Saisie : ";
    cin >> nom;

nombreElv = fonctionElv(tabElv, nom);
fonctionNote(tabNote, Best, index);
cout << "l'élève " << nom << " est indexée en : " << nombreElv <<endl;
cout << "note max : " << Best <<endl;
cout << "indexée en : " << index;
}
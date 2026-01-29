#include <iostream>
#include <windows.h>
#include <clocale>
#include "AddStudent.h"
#include "liste.h"
#include "moyenne.h"
#include "searchElv.h"
#include "Best.h"
#include "struct.hpp"
#include <fstream>
using namespace std;

string const FichierClasse = "ListeClasse.csv";

void ExportFile(eleve tab[30])
{
    ofstream AccesFichier(FichierClasse.c_str());

    if(AccesFichier)
    {
        AccesFichier << "Nom,Note" << endl;
        for(int i = 0; i < 30; i++)
        {
            if(tab[i].nom != "")
            {
                AccesFichier << tab[i].nom << ',' << tab[i].note << endl; 
            }
        }
        cout << BLUE << "Le fichier a été exporter avec succès" << endl;
    } 
    else
    {
        cout << BLUE << "Le fichier n'a pas été exporter" << endl;
    }
    cout << RESET;
}
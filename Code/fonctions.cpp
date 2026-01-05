#include <iostream>
#include <windows.h>
#include <clocale>
#include "fonctions.h"
using namespace std;

    const char* RED   = "\033[31m";
    const char* GREEN = "\033[32m";
    const char* YELLOW  = "\033[33m";
    const char* LIGHTBLUE  = "\033[34m";
    const char* PURPLE  = "\033[35m";
    const char* BLUE  = "\033[36m";
    const char* RESET = "\033[0m";

void serchElv(string tabElv[30], float tabNote[30], const string &nom, int &index, float &note)
{
    index = 0; 
    for(int i = 0; i < 30; ++i) {
        if (nom == tabElv[i]) {
            index = i + 1;   
            note  = tabNote[i];
            return;          
        }
    }

    note = 0;
}
void bestNote(float tabNote[30], float &Best, int &index){
    Best = tabNote[0];
    for(int h = 0; h < 30; h++)
        if (Best <= tabNote[h]) {
            Best = tabNote[h];
            index = h;
        }
}

void liste(string tabElv[30])
{
    cout << BLUE << endl;
    int nb = 0;
    int j = 0;
    for(int i=0; i<30; i++)
    {
        cout << tabElv[i];
        nb++;
        if(tabElv[(i+1)] == ""){
        }else{
            cout << ", ";
        }
        if(j == 5){
            cout << endl;
            j = 0;
        }
        j++;
    }
    cout << "\nIl y a " << RED << nb << BLUE << " élèves dans la classe !"<< RESET;
}

float moyenne(float tabNote[30])
{
    float res = 0;
    for(int i=0; i < 30; i++){
        res = res + tabNote[i];
    }
    res = res / 30.0;
    return res;
}

void AddStudent(string TabStudent[30], float TabNotation[30])
{
    int index;
    for(int i(0); i < 30; i++)
    {    
        if(TabStudent[i] == "")
        {
            string StudentName;
            cout << BLUE << "Entrez le nom de l'élève : " << RED;
            cin >> StudentName;
            TabStudent[i] = StudentName;
            index = i;
            break;
        }
    }
    cout << BLUE << "Entrez sa note : " << RED;
    cin >> TabNotation[index];
    cout << RESET;
}
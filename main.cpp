#include <iostream>
#include <windows.h>
#include <clocale>
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
        cout <<".4 Chercher un éleve par son nom\n";
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
                cout << BLUE << "\nEntrez le nom d'un éleve pour obtenir son numéro : " << RED;
                cin >> nom;
                serchElv(tabElv, tabNote, nom, index, note);
                if (index == 0) {
                    cout << BLUE << "\nÉlève introuvable.\n";
                } else {
                    cout << BLUE << "\nLe numéro de cet éleve est " << RED << index << BLUE << " et sa note est " << RED << note << BLUE << "/20\n" << RESET;
                }
                break;
            case '5':
                bestNote(tabNote, Best, index);
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
#include <iostream>
#include <windows.h>
using namespace std;

int serchElv(string tabElv [30], string nom){
    int o = 0;
    for(int Elv = 0; Elv < 30; Elv++){
        if (nom == tabElv [Elv]) {
            o = Elv + 1;
        }
    }
    if(o == 0){
        o = 1;
    }
    return o;
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
    cout << endl;
    int j = 0;
    for(int i=0; i<30; i++)
    {
        cout << tabElv[i];
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
            cout << "Entrez le nom de l'élève : ";
            cin >> StudentName;
            TabStudent[i] = StudentName;
            index = i;
            break;
        }
    }
    cout << "Entrez sa note : ";
    cin >> TabNotation[index];
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string tabElv[30] = {"Élie","Emma","", "Léa","Hugo","Célian","Thomas","Manon","Louis","Camille","Noah","Chloé","Enzo","Sarah"
                         "Paul","Inès","Arthur","Zoé","Adam","Juliette","Maxime","Lina","Gabriel","Eva","Matthieu","William","Raphaël","Nora","Antoine","Mila"};
    float tabNote[30] = {12, 15, 8, 17, 10, 14, 6, 18, 9, 16, 11, 13, 7, 19, 5, 20, 4, 18.5, 9.5, 14.5, 10.5, 12.5, 16.5, 6.5, 3, 2, 1, 17.5, 8.5, 11.5};
    char choix;
    bool exit = false;
    float res;
    string nom;
    int index;
    float Best;
    const char* RED   = "\033[31m";
    const char* GREEN = "\033[32m";
    const char* YELLOW  = "\033[33m";
    const char* BLUE  = "\033[34m";
    const char* RESET = "\033[0m";
    
    cout << GREEN << "Bienvenu sur votre gestionaire de classe 👽" << RESET;
    while(exit == false){
        cout << GREEN << "\n\nQuelle opération souhaitez-vous réaliser ?\n\n" << RESET;
        cout << BLUE << ".1 Ajouter un Étudiant\n";
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
                cout << "\nLa moyenne de la classe est à " << res << "/20 \n\n";
                break;
            case '4':
                cout << "\nEntrez le nom d'un éleve pour obtenir son numéro : ";
                cin >> nom;
                index = serchElv(tabElv, nom);
                cout << "\nLe numéro de cet éleve est " << index << endl;
                break;
            case '5':
                bestNote(tabNote, Best, index);
                cout << "\nLa meilleure note c'est " << Best << "/20\n";
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
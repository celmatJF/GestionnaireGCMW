#include <iostream>
#include <windows.h>
using namespace std;
// string tabElv et int tabNote

void liste(string tabElv[30])
{
    for (int i=0; i<30; i++)
    {
        cout << tabElv[i] << endl;
    }
}

int moyene  ()
{
   moyenne = 336 / 30
}
int main () {
    SetConsoleOutputCP(CP_UTF8);
    string tabElv [30] = {"Lucas","Emma","Nathan", "Léa","Hugo","Célian","Thomas","Manon","Louis","Camille","Noah","Chloé","Enzo","Sarah"
        "Paul","Inès","Arthur","Zoé","Adam","Juliette","Maxime","Lina","Gabriel","Eva","Matthieu","William","Raphaël","Nora","Antoine","Mila"
     } ;
     
    float tabNote [30] = {12,15,8,17,10,14,6,18,9,16,11,13,7,19,5,20,4,18.5,9.5,14.5,10.5,12.5,16.5,6.5,3,2,1,17.5,8.5,11.5 } ;


     liste(tabElv);

} 
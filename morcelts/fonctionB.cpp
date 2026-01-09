#include <iostream>
using namespace std;

bool IsClassFull(string TabClassName[30])
{
    if(TabClassName[29] != "")
    {
        return true;
    } else
    {
        return false;
    }
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
    string tabElv[30];
    float tabNote[30];

    int a;
    while(a !=0)
    {
        cout << "Que voulez vous faire ?" << endl;
        cout << "1 : Ajoutez un élève | 2 : Afficher la liste d'élèves | 0 : Quitter" << endl;
        cin >> a;
        if(a == 1)
        {
            AddStudent(tabElv,tabNote);
        }
        if(a == 2)
        {
            for(int i(0); i < 30; i++)
            {
                if (tabElv[i] != "")
                {
                    cout << "Elève : " << tabElv[i] << " note : " << tabNote[i] << endl;
                }
            }
        }
    }
    return 0;
}
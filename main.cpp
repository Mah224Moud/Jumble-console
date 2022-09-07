#include <iostream>
#include "jumble.cpp"
#include <fstream>

using namespace std;

int main()
{
    srand((unsigned int) time(0));
    string const fileName("mot.txt");
    ifstream monFlux(fileName.c_str(), ios::app);

    vector <string> liste;
    if(monFlux)
    {
       string file;

        while(getline(monFlux, file))
        {
            liste.push_back(file);
        }
    }
    else
        cout<<"Impossible d'ouvrir le fichier"<<endl;
    

    jumble start;
    cout<<"****************************************************************************\n*********************   BIENVENUE SUR DEVINE LE MOT    *********************\n****************************************************************************"<<endl;

    string jumbleWord;
    jumbleWord= liste[rand() % liste.size()];
    
    start.play(jumbleWord);
    while (start.getEnd()==true)
    {
        switch (start.replay())
        {
            case 1:
                jumbleWord= liste[rand() % liste.size()];
                start.play(jumbleWord);
                break;
            case 2:
                cout<<"Vous avez choisi(e) de quitter\nA la prochaine ;)"<<endl;
                start.setEnd(false);
            default:
                break;
        }
    }
    
    
    
    

    return 0;
}
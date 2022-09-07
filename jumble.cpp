#include "jumble.hpp"

using namespace std;

jumble::jumble()
{
    this->_word="None";
    this->_end= true;
};


string jumble::shuffle(string word)
{
    srand((unsigned int) time(0));
    int cpt= word.size();
    int x;
    for(int i=0; i< word.size(); i++)
    {
        x= rand()%cpt;
        char tmp;
        tmp= word[i];
        word[i]= word[x];
        word[x]= tmp;
        cpt--;
    }

    return word;
}




void jumble::setWord(string mot)
{
    this->_word= mot;
}

string jumble::getWord()
{
    return this->_word;
}


bool jumble::getEnd()
{
    return this->_end;
}

void jumble::setEnd(bool end)
{
    this->_end= end;
}


void jumble::play(string word)
{   
    int cpt= 5;
    string shuffledWord;

    
    shuffledWord= shuffle(word);
    setWord(shuffledWord);

    cout<<"Le mot a deviné est: "<<getWord()<<"\nATTENTION AUX MAJUSCULES LE PROGRAMME EST SENSIBLE A LA CASSE :)\n"<<endl;

    while (cpt>0)
    {
        string userTry;
        cout<<"Entrer le mot: ";

        cin>>userTry;
        if(userTry==word)
        {
            cout<<"Felicitations !!! Vous avez trouvé(e) le mot"<<endl;
            cpt=0;
        }
        else
        {   
            cpt--;
            if(cpt!=0)
                cout<<"\nVous n'avez pas trouvée\nRessayez à nouveau\nIl vous reste: "<<cpt<<" essais\n"<<endl;
        }
    }
    cout<<"\nLe mot à deviner mot etait: "<<word<<"\n*********** FIN DU JEU**********\n"<<endl;
}

int jumble::replay()
{
    int state=0;
    while (state != 1 and state != 2)
    {
        cout<<"\n********** MENU **********\nTapez 1 pour rejouer ou 2 pour quitter\nAlors? ";
        cin>>state;
    }

    return state;
}
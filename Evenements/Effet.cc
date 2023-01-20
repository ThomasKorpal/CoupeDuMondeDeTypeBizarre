#include "Effet.hh"

Effet::Effet(){
    this->blessureJoueur=0;
    this->butMarque=0;
    this->interventionDesDieux=0;
    this->maladieJoueur=0;
};

Effet::Effet(int a, int b, int c, int d){
    this->blessureJoueur=a;
    this->butMarque=b;
    this->interventionDesDieux=c;
    this->maladieJoueur=d;
}

Effet::~Effet(){}

void Effet::changementChoix(int choix)
{
    switch(choix)
    {
        
    }
}

int* Effet::getEffet()
{
    //int tab[4] = {this->blessureJoueur, this->butMarque, this->interventionDesDieux, this->maladieJoueur};
    int *tab=new int(4);
    tab[0]=this->blessureJoueur;
    tab[1]=this->butMarque;
    tab[2]=this->interventionDesDieux;
    tab[3]=this->maladieJoueur;
    std::cout<<"Pas oublier de désallouer" << std::endl;
    return tab;
}
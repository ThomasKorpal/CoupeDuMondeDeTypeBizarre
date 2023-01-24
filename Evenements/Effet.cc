#include "Effet.hh"

Effet::Effet(){
    this->blessureJoueur=0;
    this->butMarque=0;
    this->interventionDesDieux=0;
    this->maladieJoueur=0;
};

Effet::Effet(int a, int b, int c, int d, typeEvent type){
    this->blessureJoueur=a;
    this->butMarque=b;
    this->interventionDesDieux=c;
    this->maladieJoueur=d;
    this->type = type;
}

Effet::~Effet(){}

void Effet::changementChoix(int choix)
{
    int proba;
    switch(this->type)
    {
        case TBUT:
            switch(choix)
            {
                case 1:
                    proba = randomDoubleGenerator(0,1);
                    if(proba >= 0.5)
                    {
                        this->butMarque = -1;
                        std::cout << "La chance n'est pas en votre faveur à ce que je vois..." << std::endl;
                    }
                    else
                    {
                        this->butMarque -=1;
                        if(this->butMarque < -1)
                            this->butMarque = -1;
                        std::cout << "Quelle chance !" << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "Rien ne s'est donc passé" << std::endl;
                    break;
                default:
                    break;
            }
            break;
        case TJOUEUR:
            switch(choix)
            {
                case 1:
                    proba = randomDoubleGenerator(0,1);
                    if(proba >= 0.75)
                    {
                        this->blessureJoueur = 1;
                        this->maladieJoueur = 1;
                        std::cout << "La chance n'est pas en votre faveur à ce que je vois..." << std::endl;
                    }
                    else
                    {
                        this->blessureJoueur -=1;
                        if(this->blessureJoueur < -1)
                            this->blessureJoueur = -1;
                        std::cout << "Quelle chance !" << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "Rien ne s'est donc passé" << std::endl;
                    break;
                default:
                    break;
            }
            break;
        case TEQUIPE:
            switch(choix)
            {
                case 1:
                    proba = randomDoubleGenerator(0,1);
                    if(proba >= 0.75)
                    {
                        this->blessureJoueur = 1;
                        this->maladieJoueur = 1;
                        std::cout << "La chance n'est pas en votre faveur à ce que je vois..." << std::endl;
                    }
                    else
                    {
                        this->blessureJoueur -=1;
                        if(this->blessureJoueur < -1)
                            this->blessureJoueur = -1;
                        std::cout << "Quelle chance !" << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "Rien ne s'est donc passé" << std::endl;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
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
    return tab;
}
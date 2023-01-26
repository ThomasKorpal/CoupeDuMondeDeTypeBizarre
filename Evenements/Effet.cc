#include "Effet.hh"

Effet::Effet(){
    this->blessureJoueur=0;
    this->butMarque=0;
    this->interventionDesDieux=0;
    this->maladieJoueur=0;
};

//Constructeur qui recueilli tous les effets d'un evenement
Effet::Effet(int a, int b, int c, int d, typeEvent type, int isRandom, std::string op1, std::string op2){
    this->blessureJoueur=a;
    this->butMarque=b;
    this->interventionDesDieux=c;
    this->maladieJoueur=d;
    this->type = type;
    this->isRandom=isRandom;
    this->options.push_back(op1);
    this->options.push_back(op2);
}

Effet::~Effet(){}

//Change les données selon le type de l'evenement
void Effet::changementChoix(int choix)
{
    switch(this->type)
    {
        case TBUT:
            this->effetBut(choix);
            break;
        case TJOUEUR:
            this->effetJ_E(choix);
            break;
        case TEQUIPE:
            this->effetJ_E(choix);
            break;
        default:
            break;
    }
}

//Change les données selon le choix de l'utilisateur lors d'un evenement de type BUT
void Effet::effetBut(int choix){
    int proba;
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
                this->butMarque = 1;
                std::cout << "Quelle chance !" << std::endl;
            }
            break;
        case 2:
            std::cout << "Rien ne s'est donc passé" << std::endl;
            break;
        default:
            break;
    }
}

//Change les données selon le choix de l'utilisateur lors d'un evenement de type JOUEUR ou EQUIPE
void Effet::effetJ_E(int choix){
    int proba;
    switch(choix)
    {
        case 1:
            //lorsque l'utilisateur choisit l'option 1
            //l'evenement se realise si seulement on genere un nombre au dessus de 0.75
            proba = randomDoubleGenerator(0,1);
            std::cout<<proba<<std::endl;
            if(proba >= 0.55)
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
}

//Des getter pour recuper certains attributs

typeEvent Effet::getType(){
    return this->type;
}

std::vector<std::string> Effet::getOptions(){
    return this->options;
}

int Effet::getRandom(){
    return this->isRandom;
}

std::string Effet::operator()(int i){
    return this->options[i];
}

int Effet::operator[](int i){
    switch(i){
        case 0:
            return this->blessureJoueur;
            break;
        case 1:
            return this->butMarque;
            break;
        case 2:
            return this->interventionDesDieux;
            break;
        case 3:
            return this->maladieJoueur;
            break;
    }
    return -1;
}
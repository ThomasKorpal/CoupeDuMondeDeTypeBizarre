#include "JoueurGold.hh"

JoueurGold::JoueurGold(std::string Nom, std::string pays):Joueur(Nom,pays)
{
    this->connerie = 0;
    this->potentiel=rand()%50+50;
}

JoueurGold::JoueurGold(JoueurGold& j):Joueur(j)
{
    this->connerie = 0;
    this->potentiel=rand()%50+50;
}

JoueurGold::~JoueurGold()
{
}
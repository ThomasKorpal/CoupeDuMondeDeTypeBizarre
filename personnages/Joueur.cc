#include "Joueur.hh"

Joueur::Joueur(std::string Nom, std::string pays):participant(Nom,pays)
{
    this->role = JOUEUR;
    this->connerie = (rand() % 101);
    this->potentiel = rand() % 101;
}

Joueur::Joueur():participant()
{
    this->role = JOUEUR;
    this->connerie = (rand() % 101);
    this->potentiel = rand() % 101;
}

Joueur::Joueur(Joueur& j):participant(j.Nom,j.pays)
{
    this->role = JOUEUR;
    this->connerie = (rand() % 101);
    this->potentiel = rand() % 101;
}

Joueur::~Joueur()
{
}

void Joueur::presentation()
{
    std::cout << "Nom : " << this->Nom << " Pays : " << this->pays << " Role : " << vers_string(this->role) << " Taux de connerie : " << std::to_string(this->connerie) << "Taux potentiel : " << std::to_string(this->potentiel) << "\n" << std::endl;
}

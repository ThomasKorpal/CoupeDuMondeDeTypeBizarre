#include "participant.hh"

participant::participant()
{
    this->Nom = "";
    this->pays = "";
    this->role = UNDEFINED;
}

participant::participant(participant& p)
{
    this->Nom = p.Nom;
    this->pays = p.pays;
    this->role = UNDEFINED;
}

participant::participant(std::string Nom, std::string pays)
{
    this->Nom = Nom;
    this->pays = pays;
    this->role = UNDEFINED;
}

participant::~participant()
{
}

void participant::presentation()
{
    std::cout << "Nom : " << this->Nom << " Pays : " << this->pays << "\n" << std::endl;
}
#include "Coach.hh"

Coach::Coach(std::string Nom, std::string pays):participant(Nom,pays)
{
    this->role = COACH;
    this->rage = (rand() % 101);
    this->experience = rand() % 101;
}

Coach::Coach():participant()
{
    this->role = COACH;
    this->rage = (rand() % 101);
    this->experience = rand() % 101;
}

Coach::~Coach()
{
}

void Coach::presentation()
{
    std::cout << "Nom : " << this->Nom << " Pays : " << this->pays << " Role : " << vers_string(this->role) << " Taux de rage : " << std::to_string(this->rage) << " Taux d'experience : " << std::to_string(this->experience) << "\n" << std::endl;
}

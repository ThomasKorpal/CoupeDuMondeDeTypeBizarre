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
    std::cout << this->Nom << " " << this->pays << " : " << vers_string(this->role) << ", " << std::to_string(this->rage) << std::endl;
}

#include "Equipe.hh"

int main()
{
    std::ifstream fichier("Random/prenom.txt");
    std::string pays="France";
    Equipe eq(pays,fichier);
    Equipe eq2("Japon",fichier);
}
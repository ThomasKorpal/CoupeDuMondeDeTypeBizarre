#include "match.hh"

int main()
{
    std::ifstream fichier("Random/prenom.txt");
    std::string pays="France";
    Equipe eq(pays,fichier);
    Equipe eq2("Japon",fichier);
    match m(eq, eq2);
    std::ifstream fi("Evenements/evenement_effet.csv");
    evenement eent(1,fi);
    std::cout << std::to_string(m.getMatchState()) << std::endl;
}
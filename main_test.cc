#include "match.hh"

int main()
{   
    std::ifstream fichier("Random/prenom.txt");
    std::string pays="France";
    Equipe eq(pays,fichier);
    Equipe eq2("Japon",fichier);
    match m(eq, eq2);
    std::ifstream fi("Evenements/evenement_effet.csv");
    std::string poub;
    fi>>poub;
    m.play_match(fi);
    /*
    std::ifstream fi("Evenements/evenement_effet.csv");
    std::string poub;
    fi>>poub;
    evenement eent(1,fi);
    eent.playEvenement();
    */
    std::cout << std::to_string(m.getMatchState()) << std::endl;
    fi.close();
}
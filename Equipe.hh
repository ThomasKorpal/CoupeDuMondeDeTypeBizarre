#include <iostream>
#include <vector>
#include <fstream>
#include "personnages/Joueur.hh"
#include "personnages/Coach.hh"

#define NJOUEURS 11

class Equipe
{
private:
    std::vector<Joueur> eq;
    Coach tb;
    std::string nom;

public:
    Equipe();
    Equipe(std::string pays, std::string nom_eq, std::fstream fichierPrenom);
    ~Equipe();

    void GoodBye(std::string nom);
};

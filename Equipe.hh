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
    int valeur;

public:
    Equipe();
    Equipe(std::string pays, std::ifstream& fichierPrenom);
    ~Equipe();
    int getValeur(){return this->valeur;};
    std::string getNom(){return this->nom;};
    void setValeur(int changement){(this->valeur)-changement;};
    void GoodBye(std::string nom);
};

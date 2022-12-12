#include <iostream>
#include <fstream>
#include <vector>
#include "Equipe.hh"

Equipe::Equipe(std::string pays, std::string nom_eq, std::fstream fichierPrenom)
{
    std::string nom;

    for(int i=0; i<NJOUEURS; i++){
        fichierPrenom>>nom;

        Joueur j(nom, pays);
        this->eq.push_back(j);
    }

    fichierPrenom>>nom;
    Coach c(nom, pays);
    this->tb=c;

    this->nom="Equipe de " + pays;
}

Equipe::~Equipe()
{
}

void Equipe::GoodBye(std::string nom){
    std::vector<Joueur>::iterator it;
    for(it=this->eq.begin(); it!=eq.end(); it++){
        if(it->Nom==nom){
            
        }
    }
}
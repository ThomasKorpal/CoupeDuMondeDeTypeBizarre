#include <iostream>
#include <fstream>
#include <vector>
#include "Equipe.hh"

Equipe::Equipe(){}

Equipe::Equipe(std::string pays, std::fstream fichierPrenom)
{
    std::string nom;

    for(int i=0; i<NJOUEURS; i++){
        fichierPrenom>>nom;
        Joueur j(nom, pays);
        this->eq.push_back(j);
        this->valeur+=j.getPotentiel();
        this->valeur-=j.getConnerie();
    }

    fichierPrenom>>nom;
    Coach c(nom, pays);
    this->tb=c;
    this->valeur+=c.getExperience();
    this->valeur-=c.getRage();
    this->nom="Equipe de " + pays;
}

Equipe::~Equipe()
{
}

void Equipe::GoodBye(std::string nom){
    std::vector<Joueur>::iterator it;
    for(it=this->eq.begin(); it!=eq.end(); it++){
        if(it->getNom()==nom){
            this->eq.erase(it);
        }
    }
}
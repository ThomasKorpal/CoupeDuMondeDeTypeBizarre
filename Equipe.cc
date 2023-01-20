#include "Equipe.hh"

Equipe::Equipe(){}

Equipe::Equipe(Equipe& e){
    this->eq=e.eq;
    this->nom=e.getNom();
    this->valeur=e.getValeur();
    Coach c(e.tb.getNom(), e.tb.getPays());
    this->tb=c;
}

Equipe::Equipe(std::string pays, std::ifstream& fichierPrenom)
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

    for(size_t i=0; i<this->eq.size(); i++){
        if(eq[i].getNom()==nom){
            this->eq.erase(eq.begin()+i);
        }
    }
}
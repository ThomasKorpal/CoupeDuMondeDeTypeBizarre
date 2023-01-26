#include "Equipe.hh"

Equipe::Equipe(){}

//Contruction d'un equipe qui representera un pays et dont le noms des joueurs est tiree au hasard
Equipe::Equipe(std::string pays, std::ifstream& fichierPrenom)
{
    std::string nom;
    int tir;

    //Creation des joueurs
    for(int i=0; i<NJOUEURS; i++){
        fichierPrenom>>nom;
        
        //Si la chance est de votre cote vous pourrez avoir un joueur gold avec vous
        tir = rand()%101;
        if(tir>98)
        {
            JoueurGold j(nom,pays);
            this->eq.push_back(j);
            this->valeur+=j.getPotentiel();
            this->valeur-=j.getConnerie();
        }
        else
        {
            Joueur j(nom, pays);
            this->eq.push_back(j);
            this->valeur+=j.getPotentiel();
            this->valeur-=j.getConnerie();
        }
    }

    //Creation du coach
    fichierPrenom>>nom;
    Coach c(nom, pays);
    this->tb=c;

    //Evaluation du niveau de l'équipe
    this->valeur+=c.getExperience();
    this->valeur-=c.getRage();

    this->nom="Equipe de " + pays;
}

Equipe::~Equipe()
{
}

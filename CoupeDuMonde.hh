#ifndef __COUPE_DU_MONDE_HH__
#define __COUPE_DU_MONDE_HH__

#include <iostream>
#include <vector>
#include "match.hh"
#include "Equipe.hh"
#include "Random/fonctions_random.hh"
#include "personnages/Coach.hh"
#include "personnages/Joueur.hh"
#include "personnages/JoueurGold.hh"
#include "Evenements/evenement.hh"

class CoupeDuMonde
{
private:
    Equipe eqControlee;
    std::vector<Equipe> eqRencontree;
    int nbPoints;
public:
    CoupeDuMonde();
    ~CoupeDuMonde();
    void playCDM();
};

CoupeDuMonde::CoupeDuMonde(/* args */)
{
}

CoupeDuMonde::~CoupeDuMonde()
{
}


#endif
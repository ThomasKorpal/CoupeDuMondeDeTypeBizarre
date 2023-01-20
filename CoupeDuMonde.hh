#ifndef __COUPE_DU_MONDE_HH__
#define __COUPE_DU_MONDE_HH__

#include <iostream>
#include <vector>
#include <fstream>
#include "match.hh"
#include "Equipe.hh"
#include "Random/fonctions_random.hh"
#include "personnages/Coach.hh"
#include "personnages/Joueur.hh"
#include "personnages/JoueurGold.hh"
#include "Evenements/evenement.hh"

std::string tab_pays[20]={"FRANCE","ESPAGNE","ANGLETERRE","COREE","ITALIE","GRECE","ALLEMAGNE","MEXIQUE","JAPON","ARGENTINE","BELGIQUE","CROATIE","MAROC","PORTUGAL","LIBAN","PAYS-BAS","EGYPTE","ALGERIE","CHINE"};

class CoupeDuMonde
{
private:
    Equipe eqControlee;
    std::vector<Equipe> eqRencontree;
    int nbPoints;
public:
    CoupeDuMonde();
 //   CoupeDuMonde(const CoupeDuMonde& c);
    ~CoupeDuMonde();
    int playCDM(std::fstream f);
    void presentation();
};

#endif
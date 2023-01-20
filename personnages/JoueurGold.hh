#ifndef __JOUEUR_GOLD_HH__
#define __JOUEUR_GOLD_HH__

#include <iostream>
#include <string>
#include <time.h>
#include "Joueur.hh"
#include "participant.hh"
//#include "../Random/fonctions_random.hh"
#include <cstdlib>

class JoueurGold : public Joueur
{
private:
    /* data */
public:
    JoueurGold(std::string Nom, std::string pays);
    JoueurGold(JoueurGold& j);
    ~JoueurGold();
};

#endif
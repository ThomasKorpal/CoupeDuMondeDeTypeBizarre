#ifndef __MATCH_HH__
#define __MATCH_HH__

#include "Equipe.hh"
#include "Random/fonctions_random.hh"
#include "Evenements/evenement.hh"
#include <iostream>
#include <string>
#include <vector>

class match
{
private:
    int score; //1 si eq1 gagne, 0 si match nul, -1 si eq2 gagne
    double probaEvent;
    Equipe* tab_eq;
public:
    match();
    match(Equipe& eq1, Equipe& eq2);
    ~match();
    int play_match();
    int interpreteEffet(Effet ef, int* tabButs, Equipe* eqs);
    int getScore(){return this->score;};
};

#endif
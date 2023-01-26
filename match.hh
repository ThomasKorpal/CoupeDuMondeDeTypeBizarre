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
    double probaEvent;
    Equipe* tab_eq;
public:
    match();
    match(Equipe& eq1, Equipe& eq2);
    ~match();
    int play_match();
    int interpreteEffet(Effet ef, int* tabButs, Equipe* eqs);
};

#endif
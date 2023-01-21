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
    int matchPlayed; //0 si le match n'a pas encore été joué, 1 sinon
    //std::vector<Equipe> tab_eq;
    Equipe* tab_eq;
public:
    match();
    match(Equipe& eq1, Equipe& eq2);
    ~match();
    int play_match();
    int getScore(){return this->score;};
    int getMatchState(){return this->matchPlayed;};
};

#endif
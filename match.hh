#ifndef __MATCH_HH__
#define __MATCH_HH__

#include "Equipe.hh"

class match
{
private:
    int score //1 si eq1 gagne, 0 si match nul, -1 si eq2 gagne
public:
    match();
    match(Equipe eq1, Equipe eq2);
    ~match();
};

match::match(/* args */)
{
}

match::~match()
{
}


#endif
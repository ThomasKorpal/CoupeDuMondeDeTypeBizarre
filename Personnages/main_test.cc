#include "participant.hh"
#include "Coach.hh"
#include "Joueur.hh"
#include <iostream>

int main()
{
    Coach c1("Jean-Bernard","FRANCE");
    Joueur j1("Denis","FRANCE");
    Joueur j2("Denis Robert","FRANCE");
    j1.presentation();
    c1.presentation();
    j2.presentation();
}
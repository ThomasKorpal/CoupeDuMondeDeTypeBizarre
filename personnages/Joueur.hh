#ifndef __JOUEUR_HH__
#define __JOUEUR_HH__

#include <iostream>
#include <string>
#include <time.h>
#include "participant.hh"
#include "vers_string.hh"
#include <cstdlib>

class Joueur : public participant 
{
private:
    double connerie;
    int potentiel;
public:
    Joueur(std::string Nom, std::string pays);
    Joueur();
    Joueur(Joueur& j);
    ~Joueur();
    void presentation();
};

#endif
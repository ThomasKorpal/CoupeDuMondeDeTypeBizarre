#ifndef __JOUEUR_HH__
#define __JOUEUR_HH__

#include <iostream>
#include <string>
#include <time.h>
#include "participant.hh"
#include <cstdlib>

class Joueur : public participant 
{
protected:
    double connerie;
    int potentiel;
public:
    Joueur(std::string Nom, std::string pays);
    Joueur();
    Joueur(const Joueur& j);
    ~Joueur();
    void presentation();
    int getPotentiel(){return this->potentiel;};
    double getConnerie(){return this->connerie;};
};

#endif
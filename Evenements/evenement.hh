#ifndef __EVENEMENT_HH__
#define __EVENEMENT_HH__

#include <iostream>
#include "Effet.hh"
#include <vector>
#include <functional>
#include <utility>
#include <fstream>

#define NEVENTS 8

class evenement
{
    private:
        std::map<std::string,Effet> event;
        int isRandom;
        std::vector<std::string> options; // si isRandom = 0 -> evenement à choix donc options
    public:
        evenement();
        evenement(int lieuEvent); //int lieuEvent pour dire si c'est un evenement dans un match ou entre deux matchs
        ~evenement();
        Effet playEvenement();
        typeEvent vers_type(std::string t);
};

#endif
#ifndef __EVENEMENT_HH__
#define __EVENEMENT_HH__

#include <iostream>
#include "Effet.hh"
#include <vector>
#include <utility>
#include <fstream>

#define NEVENTS 8

typedef enum {BUT,JOUEUR,EQUIPE} typeEvent;

class evenement
{
    private:
        std::pair<std::string,Effet> event = std::make_pair("",Effet());
        int isRandom;
        std::vector<std::string> options; // si isRandom = 0 -> evenement à choix donc options
        typeEvent type;
    public:
        evenement();
        evenement(int lieuEvent, std::fstream fichierEvent); //int lieuEvent pour dire si c'est un evenement dans un match ou entre deux matchs
        ~evenement();
        Effet playEvenement();
};

#endif
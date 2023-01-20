#ifndef __COACH_HH__
#define __COACH_HH__

#include <iostream>
#include <string>
#include <time.h>
#include "participant.hh"
//#include "../Random/fonctions_random.hh"
#include <cstdlib>

class Coach : public participant
{
private:
    double rage;
    int experience;
public:
    Coach(std::string Nom, std::string pays);
    Coach();
    ~Coach();
    void presentation();
    int getRage(){return this->rage;};
    double getExperience(){return this->experience;};
};

#endif
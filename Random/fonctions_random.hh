#ifndef __VERSSTRING_HH__
#define __VERSSTRING_HH__

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "../Equipe.hh"
#include "../Evenements/evenement.hh"

typedef enum {JOUEUR,COACH, UNDEFINED} type;

std::string intros;

std::string vers_string(type role);

double randomDoubleGenerator(double lower, double upper);

void randomIntroGenerator(std::vector<Equipe> tab_eq);

int interpreteEffet(Effet ef, int tabButs[2], std::vector<Equipe> eqs);

#endif 
#ifndef __VERSSTRING_HH__
#define __VERSSTRING_HH__

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "../Equipe.hh"

typedef enum {JOUEUR,COACH, UNDEFINED} type;
std::string intros;

std::string vers_string(type role);

double randomDoubleGenerator(double lower, double upper);

void randomIntroGenerator(std::vector<Equipe> tab_eq);


#endif 
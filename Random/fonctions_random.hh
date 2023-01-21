#ifndef __FONCTIONSRANDOM_HH__
#define __FONCTIONSRANDOM_HH__

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "../Equipe.hh"
#include "../Evenements/evenement.hh"

//typedef enum {JOUEUR,COACH, UNDEFINED} type;

//std::string intros;

//std::string vers_string(type role);

double randomDoubleGenerator(double lower, double upper);

void randomIntroGenerator(Equipe tab_eq[]);

int interpreteEffet(Effet ef, int tabButs[2], Equipe* eqs);

void changementVal(Equipe* eqs, int val, int perte);

void gainBut(int* tabButs, int val);

void appelSup(int val);

bool tabContient(int array[], int size, int number);

#endif 
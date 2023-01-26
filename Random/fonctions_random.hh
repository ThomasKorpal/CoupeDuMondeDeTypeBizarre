#ifndef __FONCTIONSRANDOM_HH__
#define __FONCTIONSRANDOM_HH__

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "../Equipe.hh"

double randomDoubleGenerator(double lower, double upper);

void changementVal(Equipe* eqs, int val, int perte);

void gainBut(int* tabButs, int val);

void appelSup(int val);

#endif 
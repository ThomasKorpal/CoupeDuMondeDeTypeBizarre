#include "fonctions_random.hh"

std::string vers_string(type role)
{
    std::string res;
    switch(role)
    {
        case 0:
            res="JOUEUR";
            break;
        case 1:
            res="COACH";
            break;
        default:
            res="UNDEFINED";
            break;
    }
    return res;
}

double randomDoubleGenerator(double lower, double upper)
{
   std::uniform_real_distribution<double> unif(lower,upper);
   std::default_random_engine re;
   double a_random_double = unif(re);
   return a_random_double;
}
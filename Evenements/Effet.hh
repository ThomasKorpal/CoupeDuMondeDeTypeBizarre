#ifndef __EFFET_HH__
#define __EFFET_HH__

#include <iostream>
#include <map>
#include "../Random/fonctions_random.hh"
typedef enum {TBUT,TJOUEUR, TEQUIPE} typeEvent;

class Effet
{
    private:
        //Ensemble d'indicateurs de l'effet d'un evenement
        //-1: correspond à l'équipe adversaire
        //1: correspond à votre équipe
        //0: correspond à aucun effet
        int blessureJoueur;
        int butMarque;
        int interventionDesDieux;
        int maladieJoueur;
        typeEvent type;
        int isRandom;
        std::vector<std::string> options;
    public:
        Effet();
        Effet(int a, int b, int c, int d, typeEvent type, int isRandom, std::string op1, std::string op2);
        ~Effet();
        void changementChoix(int choix);
        typeEvent getType();
        std::vector<std::string> getOptions();
        std::string operator()(int i);
        int operator[](int i);
        int getRandom();
        void effetBut(int choix);
        void effetJ_E(int choix);
};

#endif
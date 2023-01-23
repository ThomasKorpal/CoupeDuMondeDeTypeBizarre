#ifndef __EFFET_HH__
#define __EFFET_HH__

#include <iostream>
#include "../Random/fonctions_random.hh"
typedef enum {TBUT,TJOUEUR, TEQUIPE} typeEvent;

class Effet
{
    private:
        //Ensemble d'indicateurs de l'effet d'un evenement
        //J'ai mis des -1 pour dire que ça intervient sur l'equipe d'adverse
        int blessureJoueur;
        int butMarque;
        int interventionDesDieux;
        int maladieJoueur;
        typeEvent type; 
    public:
        Effet();
        Effet(int a, int b, int c, int d, typeEvent type);
        ~Effet();
        void changementChoix(int choix);
        int* getEffet();
};

#endif
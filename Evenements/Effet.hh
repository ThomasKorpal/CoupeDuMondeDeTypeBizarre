#ifndef __EFFET_HH__
#define __EFFET_HH__

class Effet
{
    private:
        //Ensemble d'indicateurs de l'effet d'un evenement
        //J'ai mis des -1 pour dire que ça intervient sur l'equipe d'adverse
        int blessureJoueur;
        int butMarqué;
        int interventionDesDieux;
        int maladieJoueur; 
    public:
        Effet();
        Effet(int a, int b, int c, int d);
        ~Effet();
        void changementChoix(int choix);
};

#endif
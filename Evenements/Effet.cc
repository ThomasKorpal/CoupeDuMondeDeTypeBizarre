#include "Effet.hh"

void Effet::changementChoix(int choix)
{
    switch(choix)
    {
        
    }
}

int* Effet::getEffet()
{
    int tab[4] = {this->blessureJoueur, this->butMarque, this->interventionDesDieux, this->maladieJoueur};
    return tab;
}
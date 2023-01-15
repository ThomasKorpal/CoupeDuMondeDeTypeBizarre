#include <iostream>
#include "evenement.hh"
#include <functional>

evenement::evenement(){}

evenement::evenement(int lieuEvent, std::fstream fichierEvent)
{
    int blessureJoueur;
    int butMarqué;
    int interventionDesDieux;
    int maladieJoueur;
    std::string intitulé;
    typeEvent type;

    switch(lieuEvent)
    {
        char* event_effet_type;
        case 1:
            while(this->event.first != "")
            {
                fichierEvent >> event_effet_type;
                sscanf(event_effet_type,"%s,%d,%d,%d,%d,%d",intitulé,&blessureJoueur,&butMarqué,&interventionDesDieux,&maladieJoueur,&type);
                if(type!=2)
                {
                    this->event = std::make_pair(intitulé,Effet(blessureJoueur,butMarqué,interventionDesDieux,maladieJoueur));
                    this->type = type;
                }
            }
            
            break;
        case 2:
            break;
        default:
            break;
    }
}

evenement::~evenement(){}

Effet evenement::playEvenement()
{

}
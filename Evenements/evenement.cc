#include <iostream>
#include "evenement.hh"
#include <functional>

evenement::evenement(){}

evenement::evenement(int lieuEvent, std::fstream fichierEvent)
{
    int blessureJoueur, butMarqué, interventionDesDieux, maladieJoueur, isRandom;
    std::string intitule,r1,r2;
    typeEvent type;
    char* reste;
    char* event_effet_type;

    fichierEvent >> event_effet_type;
    sscanf(event_effet_type,"%s,%d,%d,%d,%d,%d,%d,%s",intitule,&blessureJoueur,&butMarqué,&interventionDesDieux,&maladieJoueur,&type,&isRandom,reste);

    if((lieuEvent==1 && type!=2) || (lieuEvent==2 && type==2)){
        while(this->event.first == "") //&& eventFound == 0)
            {
                //fichierEvent >> event_effet_type;
                //sscanf(event_effet_type,"%s,%d,%d,%d,%d,%d,%d,%s",intitulé,&blessureJoueur,&butMarqué,&interventionDesDieux,&maladieJoueur,&type,&isRandom,reste);
                if(type!=2)
                {
                    this->event = std::make_pair(intitule,Effet(blessureJoueur,butMarqué,interventionDesDieux,maladieJoueur));
                    this->type = type;
                    // eventFound = 1;
                    this->isRandom=isRandom;
                    if(this->isRandom)
                    {
                        sscanf(reste,"%s,%s",r1,r2);
                        this->options.push_back(r1);
                        this->options.push_back(r2);
                    }
                }
            }
    }

/*
    switch(lieuEvent)
    {
        //char* event_effet_type;
        int eventFound = 0;
        case 1:
            while(this->event.first == "" && eventFound == 0)
            {
                //fichierEvent >> event_effet_type;
                //sscanf(event_effet_type,"%s,%d,%d,%d,%d,%d,%d,%s",intitulé,&blessureJoueur,&butMarqué,&interventionDesDieux,&maladieJoueur,&type,&isRandom,reste);
                if(type!=2)
                {
                    this->event = std::make_pair(intitulé,Effet(blessureJoueur,butMarqué,interventionDesDieux,maladieJoueur));
                    this->type = type;
                    eventFound = 1;
                    this->isRandom=isRandom;
                    if(this->isRandom)
                    {
                        sscanf(reste,"%s,%s",r1,r2);
                        this->options.push_back(r1);
                        this->options.push_back(r2);
                    }
                }
            }
            break;
        case 2:
            while(this->event.first == "" && eventFound == 0)
            {
                //fichierEvent >> event_effet_type;
                //sscanf(event_effet_type,"%s,%d,%d,%d,%d,%d,%d,%s",intitulé,&blessureJoueur,&butMarqué,&interventionDesDieux,&maladieJoueur,&type,&isRandom,reste);
                if(type==2)
                {
                    this->event = std::make_pair(intitulé,Effet(blessureJoueur,butMarqué,interventionDesDieux,maladieJoueur));
                    this->type = type;
                    this->isRandom=isRandom;
                    if(this->isRandom)
                    {
                        sscanf(reste,"%s,%s",r1,r2);
                        this->options.push_back(r1);
                        this->options.push_back(r2);
                    }
                    eventFound = 1;
                }
            }
            break;
        default:
            break;
    } */
}

evenement::~evenement(){}

Effet evenement::playEvenement()
{
    switch(this->isRandom)
    {
        case 0:
            std::cout << this->event.first << "\n" << std::endl;
            return this->event.second;
        case 1:
            std::cout << this->event.first << "\n" << std::endl;
            for (int i = 0; i < this->options.size(); i++) 
            {
                std::cout << i + 1 << ") " << options[i] << std::endl;
            }
            int choix;
            std::cin >> choix;
            switch(choix)
            {
                case 1: //Choix positif
                    this->event.second.changementChoix(choix);
                    break;
                case 2: //Choix négatif
                    this->event.second.changementChoix(choix);
                    break;
                default:
                    break;
            }
            return this->event.second;
        default:
            break;
    }
}


void evenement::stockEvent(std::fstream fichierEvent)
{

}
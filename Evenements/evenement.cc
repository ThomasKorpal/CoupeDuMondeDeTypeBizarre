#include "evenement.hh"


evenement::evenement(){}

evenement::evenement(int lieuEvent, std::ifstream& fichierEvent)
{
    std::string intitule, blessureJoueur, butMarque, interventionDesDieux, maladieJoueur, type, isRandom, r1, r2;

    while(this->event.first == ""){
        std::getline(fichierEvent, intitule, ',');
        std::getline(fichierEvent, blessureJoueur, ',');
        std::getline(fichierEvent, butMarque, ',');
        std::getline(fichierEvent, interventionDesDieux, ',');
        std::getline(fichierEvent, maladieJoueur, ',');
        std::getline(fichierEvent, type, ',');
        std::getline(fichierEvent, isRandom, ',');

        std::cout<< intitule<<" "<<blessureJoueur<<" "<<butMarque<<" "<<interventionDesDieux<<" "<<maladieJoueur<<" "<<type<<" "<<isRandom<<std::endl;

        if((lieuEvent==1 && type=="BUT") || (lieuEvent==2 && type=="JOUEUR")){
            this->event = std::make_pair(intitule,Effet(std::stoi(blessureJoueur),std::stoi(butMarque),std::stoi(interventionDesDieux),std::stoi(maladieJoueur)));
            this->type = this->vers_type(type);
            this->isRandom=std::stoi(isRandom);
            if(this->isRandom)
            {
                std::getline(fichierEvent, r1, ',');
                std::getline(fichierEvent, r2);
                this->options.push_back(r1);
                this->options.push_back(r2);
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
            for (size_t i = 0; i < this->options.size(); i++) 
            {
                std::cout << i + 1 << ") " << options[i] << std::endl;
            }
            int choix;
            std::cin >> choix;
            this->event.second.changementChoix(choix);
            /*
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
            }*/
            return this->event.second;
        default:
            break;
    }
    return this->event.second;
}

typeEvent evenement::vers_type(std::string t){
    if(t=="JOUEUR"){
        return TJOUEUR;
    }else if(t=="BUT"){
        return TBUT;
    }else{
        return TEQUIPE;
    }
}
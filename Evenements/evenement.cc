#include "evenement.hh"


evenement::evenement(){}

evenement::evenement(int lieuEvent)
{
    std::string intitule, blessureJoueur, butMarque, interventionDesDieux, maladieJoueur, type, isRandom, r1, r2;


    std::ifstream fichierEvent("Evenements/evenement_effet.csv");
    std::string poub;
    fichierEvent>>poub;

    while(!fichierEvent.eof()){
        std::getline(fichierEvent, intitule, ',');
        std::getline(fichierEvent, blessureJoueur, ',');
        std::getline(fichierEvent, butMarque, ',');
        std::getline(fichierEvent, interventionDesDieux, ',');
        std::getline(fichierEvent, maladieJoueur, ',');
        std::getline(fichierEvent, type, ',');
        std::getline(fichierEvent, isRandom, ',');
        std::getline(fichierEvent, r1, ',');
        std::getline(fichierEvent, r2);

        //std::cout<< intitule<<" "<<blessureJoueur<<" "<<butMarque<<" "<<interventionDesDieux<<" "<<maladieJoueur<<" "<<type<<" "<<isRandom<<std::endl;

        if((lieuEvent==1 && (type=="BUT" || type=="JOUEUR")) || (lieuEvent==2 && type=="EQUIPE")){
            this->event.insert(std::make_pair(intitule,Effet(std::stoi(blessureJoueur),std::stoi(butMarque),std::stoi(interventionDesDieux),std::stoi(maladieJoueur), this->vers_type(type), std::stoi(isRandom), r1, r2)));
        }
    }
    fichierEvent.close();
}

evenement::~evenement(){}

Effet evenement::playEvenement()
{

    int i=rand()%this->event.size();

    std::map<std::string, Effet>::iterator it=this->event.begin();
    std::advance(it,i);
    std::cout << "\n" <<it->first << std::endl;


    if(it->second.getRandom()==1){
        for (size_t i = 0; i < it->second.getOptions().size(); i++) 
        {
            std::cout << i + 1 << ") " << it->second(i) << std::endl;
        }
            int choix;
            std::cin >> choix;
            it->second.changementChoix(choix);
    }
    return it->second;
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
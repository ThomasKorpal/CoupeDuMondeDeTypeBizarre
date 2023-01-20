#include "match.hh"


match::match(){
}

match::match(Equipe& eq1, Equipe& eq2)
{
    this->probaEvent = randomDoubleGenerator((double)0,(double)1);
    this->tab_eq[0]=eq1;
    this->tab_eq[1]=eq2;
    this->matchPlayed = 0;
}

match::~match()
{
}
/*
int match::play_match()
{
    int buts[2];
    randomIntroGenerator(this->tab_eq);
    for(int i=0; i<2; i++)
    {
        if(!i)
        {
            std::cout << "La première mi-temps commence !" << std::endl;
        }
        else
        {
            std::cout << "C'est parti pour la seconde mi-temps !" << std::endl;
        }
        for(int j=0; j<45; j++)
        {
            double randDou = randomDoubleGenerator(0,1);
            
            if(randDou<=this->probaEvent)
            {
                std::cout<<"Mis les valerus au pif : match.cc" <<std::endl;
                std::ifstream fichier("evenement_effet.csv");
                evenement event(1,fichier);
                Effet ef = event.playEvenement();
                interpreteEffet(ef,buts,this->tab_eq);
            }
            std::cout << "Temps du jeu " << std::to_string((45*i)+j) << " : " << this->tab_eq[0].getNom() << " " << std::to_string(buts[0]) << ": " << std::to_string(buts[1]) << " " << this->tab_eq[1].getNom() << std::endl;
        }
    }
    this->matchPlayed = 1;
    if(buts[0] > buts[1]){return 3;}
    if(buts[0] == buts[1]){return 0;}
    if(buts[0] < buts[1]){return -3;}
}
*/
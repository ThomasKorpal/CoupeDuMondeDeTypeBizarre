#include "match.hh"
#include "Random/fonctions_random.hh"
#include "Evenements/evenement.hh"

match::match(Equipe eq1, Equipe eq2)
{
    this->probaEvent = randomDoubleGenerator((double)0,(double)1);
    this->tab_eq.push_back(eq1);
    this->tab_eq.push_back(eq1);
    this->matchPlayed = 0;
}

match::~match()
{
}

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
            /*
            if(randDou > this->probaEvent)
            {
                std::cout << std::to_string((45*i)+j) << ": " << this->tab_eq[0].getNom() << " " << std::to_string(buts[0]) << ": " << std::to_string(buts[1]) << " " << this->tab_eq[1].getNom() << std::endl;
            }
            else
            {
                evenement event = evenement();
                Effet ef = event.playEvenement();
                interpreteEffet(ef,buts,this->tab_eq);
                std::cout << std::to_string((45*i)+j) << ": " << this->tab_eq[0].getNom() << " " << std::to_string(buts[0]) << ": " << std::to_string(buts[1]) << " " << this->tab_eq[1].getNom() << std::endl;
            }
            */
            if(randDou<=this->probaEvent)
            {
                evenement event = evenement();
                Effet ef = event.playEvenement();
                interpreteEffet(ef,buts,this->tab_eq);
            }
            std::cout << "Temps du jeu " << std::to_string((45*i)+j) << " : " << this->tab_eq[0].getNom() << " " << std::to_string(buts[0]) << ": " << std::to_string(buts[1]) << " " << this->tab_eq[1].getNom() << std::endl;
        }
    }
    this->matchPlayed = 1;
}
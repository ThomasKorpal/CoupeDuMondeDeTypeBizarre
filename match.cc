#include "match.hh"


match::match(){
}

match::match(Equipe& eq1, Equipe& eq2)
{
    this->probaEvent = randomDoubleGenerator((double)0,(double)1);
    this->tab_eq=new Equipe[2];
    this->tab_eq[0]=eq1;
    this->tab_eq[1]=eq2;
    //this->matchPlayed = 0;
}

match::~match()
{
    delete [] this->tab_eq;
}


int match::interpreteEffet(Effet ef, int* tabButs, Equipe* eqs)
{
    changementVal(eqs, ef[0], 100);
    gainBut(tabButs, ef[1]);
    appelSup(ef[2]);
    changementVal(eqs, ef[3], 50);
    return 1;
}




int match::play_match()
{
    int buts[2]={0,0};
    std::cout << "\nBonjour et bienvenue dans ce match qui opposera " << this->tab_eq[0].getNom() << " et " << this->tab_eq[1].getNom() << " ! " << std::endl;
    std::cout << "N'attendons pas plus !" << std::endl;

    evenement event(1);

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

        std::cout << "\n(Pour continuer, entrez une touche)" << std::endl;
        std::string entrer;
        std::cin>>entrer;

        for(int j=0; j<7; j++)
        {
            double randDou = randomDoubleGenerator(0,1);
            if(randDou<=this->probaEvent)
            {
                Effet ef = event.playEvenement();
                interpreteEffet(ef,buts,this->tab_eq);
            }
            std::cout << "Temps du jeu " << std::to_string((45*i)+j) << " : " << this->tab_eq[0].getNom() << " " << std::to_string(buts[0]) << ": " << std::to_string(buts[1]) << " " << this->tab_eq[1].getNom() << std::endl;
            std::cout << "\n(Pour continuer, entrez une touche)" << std::endl;
            std::string entrer;
            std::cin>>entrer;
        }
    }
    if(buts[0] > buts[1]){
        std::cout<<"Félicitation vous avez gagné!!!"<<std::endl;
        return 3;
    }else if(buts[0] < buts[1]){
        std::cout<<"Quel dommage, vous avez perdu ce match!"<<std::endl;
        return -3;
    }else{
        std::cout<<"Ce match fini sur une égalité quel deception...."<< std::endl;
        return 0;
    }
}
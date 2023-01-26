#include "match.hh"


match::match(){
}

//Constructeur d'un match entre deux équipes
match::match(Equipe& eq1, Equipe& eq2)
{
    this->probaEvent = randomDoubleGenerator((double)0,(double)1); //generer un nombre qui servira de comparatif pour l'apparition d'un evenement lors d'un match
    this->tab_eq=new Equipe[2];
    this->tab_eq[0]=eq1;
    this->tab_eq[1]=eq2;
}

match::~match()
{
    delete [] this->tab_eq;
}

//permet de modifier les données d'une equipe selon les effets d'un evenement
int match::interpreteEffet(Effet ef, int* tabButs, Equipe* eqs)
{
    changementVal(eqs, ef[0], 10);
    gainBut(tabButs, ef[1]);
    appelSup(ef[2]);
    changementVal(eqs, ef[3], 5);
    return 1;
}


//Simulation d'un match avec apparition d'evenements
int match::play_match()
{
    int buts[2]={0,0};
    std::cout << "\nBonjour et bienvenue dans ce match qui opposera " << this->tab_eq[0].getNom() << " et " << this->tab_eq[1].getNom() << " ! " << std::endl;
    std::cout << "N'attendons pas plus !" << std::endl;

    //permet de recuperer tous les evenements qui vont apparaitre dans un match
    evenement event(1);

    //regler l'affichage sur le terminal
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

        for(int j=0; j<10; j++)
        {
            //Selon le nombre generée un evenement va apparaitre ou non
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

    //Selon si vous avez gagne ou non vous cumulez un certain nombre de points
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
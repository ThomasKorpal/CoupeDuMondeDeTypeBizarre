#include "CoupeDuMonde.hh"

CoupeDuMonde::CoupeDuMonde()
{
    //Choix de l'équipe de l'utilisateur
    std::string pays;
    for(int i=0; i<6; i++)
    {
        std::cout << std::to_string((3*i)+1) << ") " << tab_pays[3*i] << "        " << std::to_string((3*i)+2) << ") " << tab_pays[(3*i)+1] << "        " << std::to_string((3*i)+3) << ") " << tab_pays[(3*i)+2] << std::endl;
        //printf("%d) %s",(3*i)+1,tab_pays[3*i]);
        //printf("%d) %s",(3*i)+2,tab_pays[(3*i)+1]);
        //printf("%d) %s\n\n",(3*i)+3,tab_pays[(3*i)+2]);
    }
    std::cout<<"Choisissez l'équipe que vous souhaitez contrôler : " << std::endl;
    int choix = -1;
    while(choix == -1 || choix > 18)
    {
        std::cin >> choix;
    }
    pays = tab_pays[choix-1];
    std::ifstream fichier("Random/prenom.txt");
    Equipe equi(pays,fichier);
    this->eqControlee = equi;

    this->eqRencontree=new Equipe[4];
    int it = 0;
    while(it<4){
        int tirage=rand()%18;
        int test = 0;
        for(int j=0; j<4; j++)
        {
            if("Equipe de " + tab_pays[tirage] == this->eqControlee[j].getNom()){
                test = 1;
            }
        }
        if(!test){
            Equipe eq(tab_pays[tirage],fichier);
            tab[it]=eq;
            it++;
        }
    }
/*
    int tab[4];
    while(this->eqRencontree.size() != 4)
    {
        int tirage=rand()%18;
        if(!(tabContient(tab,4,tirage)) && tab_pays[tirage] != this->eqControlee.getNom())
        {
            Equipe eq(tab_pays[tirage],fichier);
            this->eqRencontree.push_back(eq);
            //this->eqRencontree.push_back(Equipe(tab_pays[tirage],fichier));
        }
    }*/
    this->nbPoints = 0;
}

CoupeDuMonde::~CoupeDuMonde()
{
}

int CoupeDuMonde::playCDM(std::ifstream f)
{
    std::cout << "Bonjour et bienvenue dans cette coupe du monde !" << std::endl;
    std::cout << "Sans plus attendre, passons au premier match !" << std::endl;
    for(int i=0; i<3; i++)
    {
        match m(this->eqControlee,this->eqRencontree[i]);
        this->nbPoints += m.play_match();
    }
    if(this->nbPoints <= 3)
    {
        std::cout << "Coup dur pour l'utilisateur du jeu français, sa coupe du monde s'arrête ici.." << std::endl;
        return 0;
    }
    else if(this->nbPoints >= 4 && this->nbPoints < 6)
    {
        evenement eaf(2,f);
        eaf.playEvenement();
    }
    match mf(this->eqControlee,this->eqRencontree[4]);
    int final = mf.play_match();
    switch(final)
    {
        case 3:
            std::cout << "C'est une victoire triomphale ! Grand bravo a vous !" << std::endl;
            break;
        case 0:
            std::cout << "L'arbitre ayant un TGV a Gare du Nord dans 30 min, le match s'arrête sans vainqueur." << std::endl;
            break;
        case -3:
            std::cout << "Ah bah c'est la loose, en finale en plus c'est chaud..." << std::endl;
            break;
        default:
            break;
    }
    return 1;
}

void CoupeDuMonde::presentation()
{
    std::cout << this->eqControlee.getNom() << "\n" << std::endl;
    for(int i=0; i<4; i++)
    {
        std::cout << this->eqRencontree[i].getNom() << "\n" << std::endl;
    }
    std::cout << std::to_string(this->nbPoints) << std::endl;
}

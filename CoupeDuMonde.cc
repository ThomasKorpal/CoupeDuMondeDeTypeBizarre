#include "CoupeDuMonde.hh"


std::string tab_pays[20]={"FRANCE","ESPAGNE","ANGLETERRE","COREE","ITALIE","GRECE","ALLEMAGNE","MEXIQUE","JAPON","ARGENTINE","BELGIQUE","CROATIE","MAROC","PORTUGAL","LIBAN","PAYS-BAS","EGYPTE","ALGERIE","CHINE"};


//Mise en place de la coupe du monde : choix de votre equipe et des equipe que vous allez affronter
CoupeDuMonde::CoupeDuMonde()
{
    //Choix de l'équipe de l'utilisateur
    std::string pays;
    srand(time(NULL));
    for(int i=0; i<6; i++)
    {
        std::cout << std::to_string((3*i)+1) << ") " << tab_pays[3*i] << "        " << std::to_string((3*i)+2) << ") " << tab_pays[(3*i)+1] << "        " << std::to_string((3*i)+3) << ") " << tab_pays[(3*i)+2] << std::endl;
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
            if("Equipe de " + tab_pays[tirage] == this->eqRencontree[j].getNom() || tirage==choix-1){
                test = 1;
            }
        }
        if(!test){
            Equipe eq(tab_pays[tirage],fichier);
            this->eqRencontree[it]=eq;
            it++;
        }
    }
    this->nbPoints = 0;
}

CoupeDuMonde::~CoupeDuMonde()
{
    delete [] this->eqRencontree;
}

//Lancement du jeu de la coupe du monde
int CoupeDuMonde::playCDM()
{
    std::cout << "Bonjour et bienvenue dans cette coupe du monde !" << std::endl;
    std::cout << "Sans plus attendre, passons au premier match !" << std::endl;
    std::cout << "\n(Pour continuer, entrez une touche)" << std::endl;
    std::string entrer;
    std::cin>>entrer;

    //D'abord trois premier match que vous allez disputer pour voir si vous allez en final
    for(int i=0; i<3; i++)
    {
        match m(this->eqControlee,this->eqRencontree[i]);
        this->nbPoints += m.play_match();
        std::cout << "\n(Pour continuer, entrez une touche)" << std::endl;
        std::cin>>entrer;

    }
    //Si vous avez reussi a cumuler assez de point votre aventure s'arrete ici
    if(this->nbPoints <= 3)
    {
        std::cout << "Coup dur pour l'utilisateur du jeu français, sa coupe du monde s'arrête ici.." << std::endl;
        return 0;
    }
    //Apparition d'evenement entre deux matchs
    else if(this->nbPoints >= 4 && this->nbPoints < 6)
    {
        evenement eaf(2);
        eaf.playEvenement();
    }
    //match final
    match mf(this->eqControlee,this->eqRencontree[4]);
    int final = mf.play_match();

    //Resulat de la coupe du monde
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

//Presentation des participant à la coupe du monde
void CoupeDuMonde::presentation()
{
    std::cout<<"\nLes équipes de cette coupe :"<<std::endl;
    std::cout << this->eqControlee.getNom() << std::endl;
    for(int i=0; i<4; i++)
    {
        std::cout << this->eqRencontree[i].getNom() << std::endl;
    }
    std::cout << "\nNombre de points actuelle de votre équipe : " <<std::to_string(this->nbPoints) << "\n" << std::endl;
}

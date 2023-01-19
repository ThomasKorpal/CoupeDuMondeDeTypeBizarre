#include "CoupeDuMonde.hh"

CoupeDuMonde::CoupeDuMonde()
{
    //Choix de l'équipe de l'utilisateur
    std::string pays;
    for(int i=0; i<6; i++)
    {
        printf("%d) %s",(3*i)+1,tab_pays[3*i]);
        printf("        ");
        printf("%d) %s",(3*i)+2,tab_pays[(3*i)+1]);
        printf("        ");
        printf("%d) %s\n\n",(3*i)+3,tab_pays[(3*i)+2]);
    }
    printf("Choisissez l'équipe que vous souhaitez contrôler : \n");
    int choix = -1;
    while(choix == -1 && choix < 18)
    {
        std::cin >> choix;
    }
    pays = tab_pays[choix-1];
    std::ifstream fichier("Random/prenom.txt");
    this->eqControlee = Equipe(pays,fichier);
    int tab[4];
    while(this->eqRencontree.size() != 4)
    {
        int tirage=rand()%18;
        if(!(tabContient(tab,4,tirage)) && tab_pays[tirage] != this->eqControlee.getNom())
        {
            this->eqRencontree.push_back(Equipe(tab_pays[tirage],fichier));
        }

    }
    this->nbPoints = 0;
}

CoupeDuMonde::CoupeDuMonde(CoupeDuMonde& c)
{
    this->eqControlee = c.eqControlee;
    this->eqRencontree = c.eqRencontree;
    this->nbPoints = c.nbPoints;
}

CoupeDuMonde::~CoupeDuMonde()
{
}

void CoupeDuMonde::playCDM(std::fstream f)
{
    
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
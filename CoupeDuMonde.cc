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
}

CoupeDuMonde::~CoupeDuMonde()
{
}

void CoupeDuMonde::playCDM()
{
    

}
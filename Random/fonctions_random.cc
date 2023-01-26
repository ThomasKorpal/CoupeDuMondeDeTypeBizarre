#include "fonctions_random.hh"

//fonction permettant de genere un chiffre à virgule entre lower et upper
double randomDoubleGenerator(double lower, double upper)
{
   std::uniform_real_distribution<double> unif(lower,upper);
   std::default_random_engine re;
   double a_random_double = unif(re);
   return a_random_double;
}

//permet de changer la valeur d'une equipe
void changementVal(Equipe* eqs, int val, int perte)
{
    switch(val)
    {
        case 1:
            eqs[0].setValeur(perte);
            break;
        case -1:
            eqs[1].setValeur(perte);
            break;
        default:
            break;
    }
}

//permet de changer le nombre de but d'un equipe
void gainBut(int* tabButs, int val)
{
    switch(val)
    {
        case 1:
            tabButs[0]++;
            break;
        case -1:
            tabButs[1]++;
            break;
        default:
            break;
    }
}

//lorsque un evenement est de type intervention d'un etre superieur
void appelSup(int val)
{
    switch(val)
    {
        case 1:
            printf("Les dieux du foot et de la pizza vous démontent\n");
            break;
        case -1:
            printf("Les dieux du foot et de la pizza vous bénissent et démontent l'autre équipe\n");
            break;
        default:
            break;
    }
}

#include "fonctions_random.hh"

std::string vers_string(type role)
{
    std::string res;
    switch(role)
    {
        case 0:
            res="JOUEUR";
            break;
        case 1:
            res="COACH";
            break;
        default:
            res="UNDEFINED";
            break;
    }
    return res;
}

double randomDoubleGenerator(double lower, double upper)
{
   std::uniform_real_distribution<double> unif(lower,upper);
   std::default_random_engine re;
   double a_random_double = unif(re);
   return a_random_double;
}

int interpreteEffet(Effet ef, int* tabButs, std::vector<Equipe> eqs)
{
    int* tab = ef.getEffet();
    switch(tab[0])
    {
        case 1:
            eqs[0].setValeur(100);
            break;
        case 0:
            break;
        case -1:
            eqs[1].setValeur(100);
            break;
        default:
            break;
    }

    switch(tab[1])
    {
        case 1:
            tabButs[0]++;
            break;
        case 0:
            break;
        case -1:
            tabButs[1]++;
            break;
        default:
            break;
    }

    switch(tab[2])
    {
        case 1:
            printf("Les dieux du foot et de la pizza vous démontent");
            break;
        case 0:
            break;
        case -1:
            printf("Les dieux du foot et de la pizza vous bénissent et démontent l'autre équipe");
            break;
        default:
            break;
    }

    switch(tab[3])
    {
         case 1:
            eqs[0].setValeur(50);
            break;
        case 0:
            break;
        case -1:
            eqs[1].setValeur(50);
            break;
        default:
            break;
    }
    return 1;
}

bool tabContient(int array[], int size, int number) 
{
    for (int i = 0; i < size; i++) 
    {
        if (array[i] == number) 
        {
            return true;
        }
    }
    return false;
}

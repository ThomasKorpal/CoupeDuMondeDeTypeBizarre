#include "fonctions_random.hh"

/*
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
*/

double randomDoubleGenerator(double lower, double upper)
{
   std::uniform_real_distribution<double> unif(lower,upper);
   std::default_random_engine re;
   double a_random_double = unif(re);
   return a_random_double;
}

void randomIntroGenerator(Equipe tab_eq[]){

}


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

/*
int interpreteEffet(Effet ef, int* tabButs, Equipe* eqs)
{
    int* tab = ef.getEffet();
    changementVal(eqs, tab[0], 100);
    gainBut(tabButs, tab[1]);
    appelSup(tab[2]);
    changementVal(eqs, tab[3], 50);

    delete [] tab;    
    return 1;
}
*/

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

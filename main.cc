#include <iostream>
#include "CoupeDuMonde.hh"

int main()
{
    CoupeDuMonde cdm;
    std::ifstream fi("Evenements/evenement_effet.csv");
    std::string poub;
    fi>>poub;
    cdm.presentation();
    cdm.playCDM(fi);
}
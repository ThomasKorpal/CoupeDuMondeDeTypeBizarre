#include <iostream>
#include <iostream>
#include <string>
#include <time.h>
#include "participant.hh"
#include "vers_string.hh"
#include <cstdlib>

class Coach : public participant
{
private:
    double rage;
    int experience;
public:
    Coach(std::string Nom, std::string pays);
    Coach();
    ~Coach();
    void presentation();
};

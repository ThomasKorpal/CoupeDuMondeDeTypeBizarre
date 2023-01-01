#ifndef __PARTICIPANT_HH__
#define __PARTICIPANT_HH__

#include <iostream>
#include <string>
#include <time.h>
#include "vers_string.hh"

class participant
{
private:
protected:
    std::string Nom;
    std::string pays;
    type role;
public:
    participant(std::string Nom, std::string pays);
    participant();
    participant(participant& p);
    ~participant();
    std::string getNom() const;
    virtual void presentation();
};

#endif
#ifndef __PARTICIPANT_HH__
#define __PARTICIPANT_HH__

#include <iostream>
#include <string>
#include <time.h>

typedef enum {JOUEUR,COACH, UNDEFINED} type;

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
    std::string getNom() const{return this->Nom;}
    std::string getPays() const{return this->pays;}
    virtual void presentation();
    std::string vers_string(type role);
};

#endif
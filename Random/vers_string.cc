#include "vers_string.hh"

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
#ifndef __VERSSTRING_HH__
#define __VERSSTRING_HH__

#include <iostream>
#include <string>

typedef enum {JOUEUR,COACH, UNDEFINED} type;

std::string vers_string(type role);

#endif 
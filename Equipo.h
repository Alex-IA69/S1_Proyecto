#ifndef EQUIPO_H
#define EQUIPO_H

#include "Pokemon.h"

#include <string>

class Equipo
{
    public:
        Equipo();
        Equipo(std::string, Pokemon, Pokemon, Pokemon);

    private:
        std::string nombre;
        Pokemon poke1, poke2, poke3;
};

#endif //EQUIPO_H
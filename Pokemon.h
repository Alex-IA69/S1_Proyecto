#ifndef POKEMON_H
#define POKEMON_H

#include "Movimientos.h"

#include <string>

class Pokemon
{
    public:
        Pokemon();
        Pokemon(std::string, std::string, int);

    private:
        std::string tipo,
                    nombre;
        int nivel;
        Movimientos movimiento1, movimiento2;
};

#endif //POKEMON_H
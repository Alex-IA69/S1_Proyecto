#ifndef POKEMON_H
#define POKEMON_H

#include "Movimientos.h"

#include <iostream>
#include <string>

class Pokemon
{
    public:
        //Constructores
        Pokemon();
        Pokemon(std::string, std::string);

        //Setters y Getters
        void setPoki(std::string);
        void setNombre(std::string);
        std::string getPoki();
        std::string getNombre();

        std::string getTipo();

        //Interacciones
        bool pelear(std::string);

    private:
        std::string poki, nombre;
        Movimientos movimiento1, movimiento2;
};

#endif //POKEMON_H
#ifndef EQUIPO_H
#define EQUIPO_H

#include "Pokemon.h"

#include <string>

class Equipo
{
    public:
        //Constructores
        Equipo();

        //Setters y Getters
        void setNombre(std::string);
        std::string getNombre();
        void setPokemon(Pokemon, int);
        Pokemon getPokemon(int);    

    private:
        std::string nombre;
        Pokemon poke[3];
};

#endif //EQUIPO_H
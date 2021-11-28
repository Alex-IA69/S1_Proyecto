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
        void setPokemon1(Pokemon);
        Pokemon getPokemon1();
        void setPokemon2(Pokemon);
        Pokemon getPokemon2();
        void setPokemon3(Pokemon); 
        Pokemon getPokemon3();       
        
        //Interacciones
        std::string getRandPokeType();

    private:
        std::string nombre;
        Pokemon poke1, poke2, poke3;
};

#endif //EQUIPO_H
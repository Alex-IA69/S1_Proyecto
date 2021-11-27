#ifndef EQUIPO_H
#define EQUIPO_H

#include "Pokemon.h"

#include <string>

class Equipo
{
    public:
        //Constructores
        Equipo();
        Equipo(std::string, Pokemon, Pokemon, Pokemon);

        //Setters y Getters
        void setNombre(std::string);
        std::string getNombre();
        
        
        //Interacciones
        std::string getRandPokeType();

    private:
        std::string nombre;
        Pokemon poke1, poke2, poke3;
};

#endif //EQUIPO_H
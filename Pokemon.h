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
        void setMov();

        std::string getPoki();
        std::string getNombre();
        std::string getTipo();
        Movimientos getMov1();
        Movimientos getMov2();

        //Interacciones
        int pelear(std::string[], std::string[]);

        void dibujar(int, std::string[]);
        void descripcion(int, std::string[]);

    private:
        std::string poki, nombre;
        Movimientos mov1, mov2;
};

#endif //POKEMON_H
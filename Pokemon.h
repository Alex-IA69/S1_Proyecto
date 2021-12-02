#ifndef POKEMON_H
#define POKEMON_H

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
        void setTipo();

        std::string getPoki();
        std::string getNombre();
        std::string getTipo();
        std::string getMov(int);
        //Interacciones
        int pelear(Pokemon);

        void dibujar(int, std::string[]);
        void descripcion(int, std::string[]);

    private:
        std::string poki, nombre, tipo;
        std::string mov[2];
};

#endif //POKEMON_H
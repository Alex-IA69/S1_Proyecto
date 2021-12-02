#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <string>
#include "Equipo.h"

class Entrenador
{
    public:
        //Constructores
        Entrenador();
        Entrenador(std::string);

        //Setters y Getters
        void setNombre(std::string);
        std::string getNombre();
        void setTeam(Equipo, int);
        Equipo getTeam(int);
        
        //Funciones
        void editarNombre();
        void mostrarEntrenador();

    private:
        std::string nombre;
        Equipo team[2];
};

#endif //ENTRENADOR_H
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
        void setTeam1(Equipo);
        void setTeam2(Equipo);
        Equipo getTeam1();
        Equipo getTeam2();
        
        //Funciones
        void editarNombre();
        void mostrarEntrenador();

    private:
        std::string nombre;
        Equipo team1, team2;
};

#endif //ENTRENADOR_H
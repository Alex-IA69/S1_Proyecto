#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <string>
#include "Equipo.h"

class Entrenador
{
    public:
        Entrenador();
        Entrenador(std::string);
        void cambiarNombre(std::string);

        //SetTers y getTers
        void setNombre(std::string);
        std::string getNombre();

    private:
        std::string nombre;
        Equipo team1, team2;
};

#endif //ENTRENADOR_H
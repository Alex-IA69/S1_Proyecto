#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <string>

class Entrenador
{
    public:
        Entrenador();
        Entrenador(std::string, int);
        void cambiarNombre(std:string);

    private:
        std::string nombre;
        int medallas;
        Equipo team1, team2, team3;
};

#endif //ENTRENADOR_H
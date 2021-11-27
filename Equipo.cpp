#include <iostream>
#include <string>
#include <time.h>

#include "Equipo.h"
#include "Pokemon.h"

//------------------------------------------Constructores
Equipo::Equipo()
{
    nombre = "";
    Pokemon poke1(), poke2(), poke3();
};

Equipo::Equipo(std::string _nombre, Pokemon _poke1, Pokemon _poke2, Pokemon _poke3)
{
    nombre = _nombre;
    Pokemon poke1(_poke1.getPoki(), _poke1.getNombre()),
            poke2(_poke2.getPoki(), _poke2.getNombre()),
            poke3(_poke3.getPoki(), _poke3.getNombre());
};

//------------------------------------------Setters y Getters
void Equipo::setNombre(std::string _nombre)
{
    nombre = _nombre;
}

std::string Equipo::getNombre()
{
    return nombre;
}

//------------------------------------------Interacciones
std::string Equipo::getRandPokeType()
{
    srand(time(NULL));
    int auxiliar = rand() % 3;
    switch (auxiliar)
    {
        case 0:
            return poke1.getTipo();
            break;
        case 1:
            return poke2.getTipo();
            break;
        case 2:
            return poke3.getTipo();
            break;

        default:
            std::cout << "Equipo:getRandPokeType:Error";
            exit(EXIT_FAILURE);
            break;
    }
}

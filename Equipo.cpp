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


//------------------------------------------Setters y Getters
void Equipo::setNombre(std::string _nombre)
{
    nombre = _nombre;
}

std::string Equipo::getNombre()
{
    return nombre;
}

void Equipo::setPokemon1(Pokemon _pok)
{
    poke1.setPoki(_pok.getPoki());
    poke1.setNombre(_pok.getNombre());
}

void Equipo::setPokemon2(Pokemon _pok)
{
    poke2.setPoki(_pok.getPoki());
    poke2.setNombre(_pok.getNombre());
}

void Equipo::setPokemon3(Pokemon _pok)
{
    poke3.setPoki(_pok.getPoki());
    poke3.setNombre(_pok.getNombre());
}

Pokemon Equipo::getPokemon1()
{
    return poke1;
}

Pokemon Equipo::getPokemon2()
{
    return poke2;
}

Pokemon Equipo::getPokemon3()
{
    return poke3;
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

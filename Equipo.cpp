#include <iostream>
#include <string>
#include <time.h>

#include "Equipo.h"
#include "Pokemon.h"

//------------------------------------------Constructores
Equipo::Equipo()
{
    nombre = "3quipoX002";
    Pokemon poke[3];
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

void Equipo::setPokemon(Pokemon _pok, int pos)
{
    poke[pos] = _pok;
}

Pokemon Equipo::getPokemon(int pos)
{
    return poke[pos];
}
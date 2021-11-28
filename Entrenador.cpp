#include <iostream>
#include <string>
#include <time.h>

#include "Entrenador.h"

//Constructores
Entrenador::Entrenador(){
    nombre = "";
}

Entrenador::Entrenador(std::string _nombre){
    nombre = _nombre;
}

//Setters y Getters
void Entrenador::setNombre(std::string _nombre)
{
    nombre = _nombre;
}

std::string Entrenador::getNombre()
{
    return nombre;
}

void Entrenador::setTeam1(Equipo _team)
{
    team1.setNombre(_team.getNombre());
    team1.setPokemon1(_team.getPokemon1());
    team1.setPokemon2(_team.getPokemon2());
    team1.setPokemon3(_team.getPokemon3());
}

void Entrenador::setTeam2(Equipo _team)
{
    team2.setNombre(_team.getNombre());
    team2.setPokemon1(_team.getPokemon1());
    team2.setPokemon2(_team.getPokemon2());
    team2.setPokemon3(_team.getPokemon3());
}

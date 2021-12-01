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

Equipo Entrenador::getTeam1()
{
    return team1;
}

Equipo Entrenador::getTeam2()
{
    return team2;
}

void Entrenador::editarNombre()
{
    std::cout << "Cual seria el nuevo nombre? Solo se permite una palabra sin espacios\n>>> ";
    std::cin >> nombre;
    system("cls");
    std::cout << "Nombre de entrenador 1 cambiado excitosamente!\n";
}

void Entrenador::mostrarEntrenador()
{
    std::cout << "Este es el perfil de " << nombre << std::endl;
    std::cout << "Su primer equipo se llama " << team1.getNombre() << " y tiene los siguientes pokemones:\n\t" << team1.getPokemon1().getNombre() << " como " << team1.getPokemon1().getPoki() << "\n\t" << team1.getPokemon2().getNombre() << " como " << team1.getPokemon2().getPoki() << "\n\t" << team1.getPokemon3().getNombre() << " como " << team1.getPokemon3().getPoki() << std::endl;
    if(team2.getNombre() != "")
    {
        std::cout << "Su segundo equipo se llama " << team2.getNombre() << " y tiene los siguientes pokemones:\n\t" << team2.getPokemon1().getNombre() << " como " << team2.getPokemon1().getPoki() << "\n\t" << team2.getPokemon2().getNombre() << " como " << team2.getPokemon2().getPoki() << "\n\t" << team2.getPokemon3().getNombre() << " como " << team2.getPokemon3().getPoki() << std::endl;
    }
    system("pause");
}
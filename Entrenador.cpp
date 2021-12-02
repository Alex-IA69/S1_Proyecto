#include <iostream>
#include <string>
#include <time.h>

#include "Entrenador.h"


//Constructores
Entrenador::Entrenador(){
    nombre = "Juan";
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

void Entrenador::setTeam(Equipo _team, int pos)
{
    team[pos] = _team;
}


Equipo Entrenador::getTeam(int pos)
{
    return team[pos];
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
    std::cout << "Su primer equipo se llama " << team[0].getNombre() << " y tiene los siguientes pokemones:\n";
    for (int i = 0; i < 3; i++)
        std::cout << "\t" << team[0].getPokemon(i).getNombre() << " como " << team[0].getPokemon(i).getPoki() << ", es un tipo " << team[0].getPokemon(i).getTipo() << " y puede usar los movimientos: " << team[0].getPokemon(i).getMov(0) << " y " << team[0].getPokemon(i).getMov(1) << std::endl;
    if (team[1].getNombre() != "3quipoX002")
    {
        std::cout << "Su segundo equipo se llama " << team[1].getNombre() << " y tiene los siguientes pokemones:\n\t";
        for (int i = 0; i < 3; i++)
            std::cout << "\t" << team[1].getPokemon(i).getNombre() << " como " << team[1].getPokemon(i).getPoki() << ", es un tipo " << team[1].getPokemon(i).getTipo() << " y puede usar los movimientos: " << team[1].getPokemon(i).getMov(0) << " y " << team[1].getPokemon(i).getMov(1) << std::endl;
    
    }
    system("pause");
}
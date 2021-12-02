#include <iostream>
#include <string>
#include <vector>

#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <fstream>

#include "Pokemon.h"
#include "Entrenador.h"

Pokemon auxiliar;

void dibujoAtaque1(std::string);
void dibujoAtaque2(std::string);

//------------------------------------------Constructores
Pokemon::Pokemon()
{
    poki = "Rattata";
    nombre = "Rattata";
    setTipo();
    setMov();
};

Pokemon::Pokemon(std::string _poki, std::string _nombre)
{
    poki = _poki;
    nombre = _nombre;
    setTipo();
    setMov();
};

//------------------------------------------Setters y Getters

void Pokemon::setPoki(std::string _poki)
{
    poki = _poki;
    setTipo();
    setMov();
}

void Pokemon::setNombre(std::string _nombre)
{
    nombre = _nombre;
}

void Pokemon::setMov()
{
    std::ifstream archivo;
    srand(time(NULL));
    
    archivo.open("pokemones/Movimientos.txt", std::ios::in);
    std::string auxiliar;
    std::vector<std::string> movis;

    while (archivo >> auxiliar)
        movis.push_back(auxiliar);
    
    int n = movis.size();
    int rand1 = rand() % n, rand2 = rand() % n;

    mov[0] = movis[rand1];
    mov[1] = movis[rand2];
    
    archivo.close();
}

void Pokemon::setTipo()
{
    if(poki == "Rattata")           tipo = "normal";
    else if(poki == "Zubat")        tipo = "volador";
    else if(poki == "Machop")       tipo = "lucha";
    else if(poki == "Squirtle")     tipo = "agua";
    else if(poki == "Vulpix")       tipo = "fuego";
    else if(poki == "Bulbasaur")    tipo = "planta";
    else if(poki == "Lapras")       tipo = "hielo";
    else if(poki == "Caterpie")     tipo = "insecto";
    else if(poki == "Geodude")      tipo = "roca";
    else if(poki == "Cubone")       tipo = "tierra";
    else if(poki == "Ghastly")      tipo = "fantasma";
    else if(poki == "Abra")         tipo = "psiquico";
    else if(poki == "Voltorb")      tipo = "electrico";
    else if(poki == "Ekans")        tipo = "toxina";
}

std::string Pokemon::getPoki()
{
    return poki;
}

std::string Pokemon::getNombre()
{
    return nombre;
}

std::string Pokemon::getTipo()
{
    return tipo;
}

std::string Pokemon::getMov(int pos)
{
    return mov[pos];
}

//------------------------------------------Interacciones
int Pokemon::pelear(Pokemon enemigo_)
{
    std::string dato1 = getTipo(), dato2 = enemigo_.getTipo();

    // Declaramos _X y _Y para sacar la cordenada de nuestra matriz y saber que pokemon ganara la pelea
    int _X, _Y, auxiliar = 0, contador = 0;

    // Esta matriz es un arreglo donde guardamos los tipos de pokemones que usaremos y saber si se genera un ataque (nulo, normal o critico)
    std::string debilidades[15][15] = {
    {"tabla", "normal", "volador", "lucha", "agua", "fuego", "planta", "hielo", "insecto", "roca", "tierra", "fantasma", "psiquico", "electrico", "toxina"},
    {"normal",    "1", "1", "0", "1", "1", "1", "1", "1", "0", "1", "0", "1", "1", "1"}, 
    {"volador",   "1", "1", "2", "1", "1", "2", "0", "2", "0", "1", "1", "1", "0", "1"},
    {"lucha",     "2", "0", "1", "1", "1", "1", "2", "0", "2", "1", "0", "0", "1", "0"},
    {"agua",      "1", "1", "1", "1", "2", "0", "1", "1", "2", "2", "1", "1", "0", "1"}, 
    {"fuego",     "1", "1", "1", "0", "1", "2", "2", "2", "0", "0", "1", "1", "1", "1"},
    {"planta",    "1", "0", "1", "2", "0", "1", "0", "0", "2", "2", "1", "1", "1", "0"},
    {"hielo",     "1", "2", "0", "1", "0", "2", "1", "1", "1", "2", "1", "1", "1", "1"}, 
    {"insecto",   "1", "0", "2", "1", "0", "2", "1", "1", "1", "1", "1", "2", "1", "2"},
    {"roca",      "2", "2", "0", "0", "2", "0", "1", "1", "1", "0", "1", "1", "1", "1"},
    {"tierra",    "1", "1", "1", "0", "2", "0", "0", "1", "2", "1", "1", "1", "2", "2"}, 
    {"fantasma",  "2", "1", "2", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
    {"psiquico",  "1", "1", "2", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "2"}, 
    {"electrico", "1", "2", "1", "2", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1"},
    {"toxina",    "1", "1", "2", "1", "1", "2", "1", "0", "1", "0", "1", "0", "1", "1"}};
    
  
    for(int y = 1; y <= 14; y++)
    {
        if(debilidades[y][0] == dato1)
            _Y = y;
    }
    for(int x = 1; x <= 14; x++)
    {
        if(debilidades[0][x] == dato2)
            _X = x;
    }
    
    //-----Pintar escenario
    dibujoAtaque2(enemigo_.getPoki());//Enemigo
    dibujoAtaque1(getPoki());         //Entrenador 1

    srand(time(NULL));

    if(debilidades[_Y][_X] == "1")
    {
        auxiliar = rand() % 2;
        if (auxiliar == 1)
        {
            std::cout << "\nLa suerte hoy no estuvo de tu lado, el " << enemigo_.getPoki() << " enemigo supero a tu " << getPoki() << "!!\n";
            return 0;
        }
        else
        {
            std::cout << "\nBien hecho! El " << enemigo_.getPoki() << " contrincante fue vencido por tu " << getPoki() << "!!\n";
            return 1;
        }
            
    }
    else if(debilidades[_Y][_X] == "2")
    {
        std::cout << "\nLe sabes a los tipos, " << getTipo() << " siempre le gana a " << enemigo_.getTipo() << "!\n";
        return 1;
    }
    else if(debilidades[_Y][_X] == "0")
    {
        std::cout << "\nTienes que entrenar mas" << enemigo_.getTipo()  << " siempre le gana a " << getTipo() << "!!\n";
        return 0;
    }
}

//--------------------------------------------------------Dibujar sprites-----------------------------------//
//----------------------------------------------------------------Dibujar pokemones en Ascii
void Pokemon::dibujar(int opcion, std::string pokemones[]){
    std::ifstream archivo;
    std::string sprite;

    opcion--;
    archivo.open("pokemones/" + pokemones[opcion] + ".txt",std::ios::in);

    if(archivo.fail()){
        std::cout << "trite";
        exit(1);
    }

    while(!archivo.eof()){
        getline(archivo,sprite);
        std::cout<<sprite<<std::endl;
    }

    archivo.close(); 
}

//----------------------------------------------------------------Dibujar Descripcion de pokemones
void Pokemon::descripcion(int opcion, std::string pokemones[]){
    std::ifstream archivo;
    std::string sprite;

    opcion--;
    archivo.open("pokemones/Descripcion_" + pokemones[opcion] + ".txt",std::ios::in);

    if(archivo.fail()){
        std::cout << "trite";
        exit(1);
    }

    while(!archivo.eof()){
        std::getline(archivo,sprite);
        std::cout<<sprite<<std::endl;
    }

    archivo.close(); 
}

//--------------------------------------------------------Dibujar peleas-----------------------------------//
//----------------------------------------------------------------Dibujar Ataque
void dibujoAtaque1(std::string pokemones){
    std::ifstream archivo;
    std::string sprite;

    archivo.open("pokemones/Pelea/Pelea1_" + pokemones + ".txt",std::ios::in);

    if(archivo.fail()){
        std::cout << "trite";
        exit(1);
    }

    while(!archivo.eof()){
        getline(archivo,sprite);
        std::cout<<sprite<<std::endl;
    }

    archivo.close(); 
}

//----------------------------------------------------------------Dibujar Ataque 2
void dibujoAtaque2(std::string pokemones){
    std::ifstream archivo;
    std::string sprite;

    archivo.open("pokemones/Pelea/Pelea2_" + pokemones + ".txt",std::ios::in);

    if(archivo.fail()){
        std::cout << "trite";
        exit(1);
    }

    while(!archivo.eof()){
        getline(archivo,sprite);
        std::cout<<sprite<<std::endl;
    }

    archivo.close(); 
}
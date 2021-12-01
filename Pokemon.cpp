#include <iostream>
#include <string>
#include <vector>

#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <fstream>

#include "Pokemon.h"

Pokemon auxiliar;

void dibujoAtaque1(std::string);
void dibujoAtaque2(std::string);

//------------------------------------------Constructores
Pokemon::Pokemon()
{
    poki = "";
    nombre = "";
    Movimientos mov1, mov2;
};

Pokemon::Pokemon(std::string _poki, std::string _nombre)
{
    poki = _poki;
    nombre = _nombre;
    Movimientos mov1, mov2;
};

//------------------------------------------Setters y Getters

void Pokemon::setPoki(std::string _poki)
{
    poki = _poki;
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

    mov1.setMov(movis[rand1]); 
    mov2.setMov(movis[rand2]);
    
    archivo.close();
}

std::string Pokemon::getPoki()
{
    return poki;
}

std::string Pokemon::getNombre()
{
    return nombre;
}

//Set para saber de que tipo es tal pokemon
std::string Pokemon::getTipo()
{
    if(poki == "Rattata")           return "normal";
    else if(poki == "Zubat")        return "volador";
    else if(poki == "Machop")       return "lucha";
    else if(poki == "Squirtle")     return "agua";
    else if(poki == "Vulpix")       return "fuego";
    else if(poki == "Bulbasaur")    return "planta";
    else if(poki == "Lapras")       return "hielo";
    else if(poki == "Caterpie")     return "insecto";
    else if(poki == "Geodude")      return "roca";
    else if(poki == "Cubone")       return "tierra";
    else if(poki == "Ghastly")      return "fantasma";
    else if(poki == "Abra")         return "psiquico";
    else if(poki == "Voltorb")      return "electrico";
    else if(poki == "Ekans")        return "toxina";

    else    std::cout << "No existe el pokimon en la db"  << std::endl;
}

Movimientos Pokemon::getMov1()
{
    return mov1;
}

Movimientos Pokemon::getMov2()
{
    return mov2;
}

//------------------------------------------Interacciones
int Pokemon::pelear(std::string dato1[], std::string dato2[])
{
    // Declaramos _X y _Y para sacar la cordenada de nuestra matriz y saber que pokemon ganara la pelea
    int _X, _Y, ataque, auxiliar, contador = 0;

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
    
    for(int Z = 1; Z <= 3; Z++)
    {
        //En este for anidado estamos buscando la cordenada de _Y, que es donde esta el "dato1" osea, si dato1 es = a alguno de los tipos de pokemones de la matris _Y = i
        for(int i = 0; i <= 14; i++)
        {
            for(int j = 0; j <= 14; j++)
            {
                if(dato2[Z] == debilidades[i][j].c_str())
                {
                    _Y = i;
                }
            }
        }
        
        //En este for anidado estamos buscando la cordenada de _X, que es donde esta el "dato2" osea, si dato2 es = a alguno de los tipos de pokemones de la matris _X = j
        for(int i = 0; i <= 14; i++)
        {
            for(int j = 0; j <= 14; j++)
            {
                if(dato1[Z] == debilidades[i][j].c_str())
                {
                    _X = j;
                    i = 15;
                    j = 15;
                }
            }
        }

        //-----Pintar escenario
        dibujoAtaque2(dato2[Z + 3]);
        dibujoAtaque1(dato1[Z + 3]);
        
        //Despues de que se encuentran las cordenadas de _X y _Y convertimos el caracter que se encuentre en la posicion (x, y) de la matriz a uno tipo entero
        ataque = atoi(debilidades[_X][_Y].c_str());
        
        //Generamos un numero aleatorio del 0 al 1 para determinar quien gana si se usa un ataque tipo "normal"
        srand(time(NULL));
        auxiliar = rand() % 2;
        
        //Si el equivalente de la tabla del atacante contra el contrincante es = 2, el atacante gana
        if(ataque == 2)
        {
            std::cout << "izzi" << std::endl;
            contador++;
            //return true;
        }
        //Si el equivalente de la tabla del atacante contra el contrincante es = 0, el atacante pierde
        else if(ataque == 0)
        {
            std::cout << "GGnt" << std::endl;
            //return false;
        }
        //Si el resultado de la matriz es = 1, quiere decir que ambos tienen la misma provabilidad de ganar, por lo tanto al generar un numero random se determina al azar en ambos casos   
        else if(auxiliar == 0)
        {
            std::cout << "Fue una gran batalla muy cerrada, pero lastimosamente fuiste derrotado, hay que seguir entrenando :(" << std::endl;
            //return false;
        }
        
        else{
            std::cout << "Fue una gran batalla muy cerrada, viendo el lado bueno es que conseguiste la victoria, sigue asi aventurero :D" << std::endl;
            contador++;
            //return true;
        }

        system("pause");
        if(Z == 3)
        {
            switch(contador)
            {
            case 0:
                std::cout << "Tuviste una derrota aplastante con " << contador << " victorias, deverias practicar :(" << std::endl;
                system("pause");
                break;

            case 1:
                std::cout << "Fueron combates vastante parejos, lastima que solo tuviste  " << contador << " victoria, sigue entrenadno y mejoraras mucho :)" << std::endl;
                system("pause");
                break;

            case 2:
                std::cout << "Estuviste a nada de destrosar a tu rival, ganaste con" << contador << " victorias, bien hecho!!!" << std::endl;
                system("pause");
                break;

            case 3:
                std::cout << "DAAM!! eso fue brutal!!, " << contador << " victorias seguidas!!!, cada dia mejoras mas!!" << std::endl;
                system("pause");
                break;
            
            default:
                break;
            }
        }
    }
}

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

//----------------------------------------------------------------Descripcion de pokemones
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
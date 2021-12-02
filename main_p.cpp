#include <iostream>
#include <string>

#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <stdexcept>

#include "Entrenador.h"
#include "Pokemon.h"
#include "Equipo.h"

using namespace std;

//--------------------------------------------------------------DECLARACION FUNCIONES
void intro();
void crearEquipo(Entrenador &entrenador_, int n);
bool editarEntrenador(Entrenador &entrenador_, char opc);

//--------------------------------------------------------------GLOBALES
Entrenador trainer1, trainer2;
Pokemon tempPoke;
int victorias = 0;
string listaPoke[14] = {"Rattata", "Zubat", "Machop", "Squirtle", "Vulpix", "Bulbasaur", "Voltorb", "Lapras", "Caterpie", "Geodude", "Cubone", "Abra", "Ghastly", "Ekans"};


//--------------------------------------------------------------MAIN

int main()
{
    char opcion, perfil;
    int opcioni;
    string nombre;
    bool ciclo = true, resultado;
    int puntos1, puntos2;

    intro();
    crearEquipo(trainer1, 0);

    while (ciclo)
    {
        cout << "Bienvenido al menu principal, que te gustaria hacer primero?\n1) Checar Entrenadores\n2) Checar Pokedex\n3) Batalla Pokemon\n4) Salir\n" << ">>> ";
        cin >> opcion;

        switch (opcion)
        {
            //-------------------------------------------------------------Caso entrenador
            case '1':
                Sleep(1500);
                system("cls");
                while(ciclo)
                {
                    cout << "Que entrenador quiere seleccionar?\n1) Entrenador 1\n2) Entrenador 2\n3) Regresar\n" << ">>> ";
                    cin >> perfil;
                    //Menu entrenador
                    if (perfil == '1' || perfil == '2')
                    {
                        while(ciclo)
                        {
                            cout << "Que quiere hacer?\n1) Mostrar entrenador\n2) Editar nombre\n3) Editar equipo 1\n4) Editar equipo 2\n5) Salir\n>>> ";
                            cin >> opcion;
                            if (perfil == '1')
                                ciclo = editarEntrenador(trainer1, opcion);
                            else
                                ciclo = editarEntrenador(trainer2, opcion);
                        }
                    }else{
                        ciclo = false;
                        Sleep(1500);
                        system("cls");
                    }
                }
                ciclo = true;
                break;
            //-------------------------------------------------------------Caso pokedex
            case '2':
                Sleep(1500);
                system("cls");
                while (ciclo)
                {
                    cout << "Bienvenido a la Pokedex\nElija el numero de alguno de los pokemones para ver su descripción en la pokedex\n\n"
                            << "Lista de pokemones:\n" <<
                            "\t 1.  Rattata 2.   Zubat     3.  Machop   4. Squirtle   5. Vulpix   6. Bulbasaur   7. Voltorb\n" <<
                            "\t 8.  Lapras  9.   Caterpie 10. Geodude  11.  Cubone   12.  Abra   13.  Ghastly   14.  Ekans\n" <<
                            "\t15.  Regresar\n";
                    cout << "\n\n>>> ";
                    cin >> opcioni;
                    Sleep(500);
                    system("cls");
                    if (opcioni <= 14 && opcioni >= 1)
                    {
                        tempPoke.dibujar(opcioni, listaPoke);
                        tempPoke.descripcion(opcioni, listaPoke);
                        system("pause");
                        Sleep(500);
                        system("cls");
                    }
                    else if (opcioni == 15)
                    {
                        ciclo = false;
                        Sleep(1500);
                        system("cls");
                    }
                    else
                    {
                        cout << "Respuesta no valida, porfavor escriba un numero del 1 al 15\n\n";
                    }
                }
                ciclo = true;
                break;
            //-------------------------------------------------------------Caso batalla
            case '3':
                Sleep(1500);
                system("cls");
                puntos1 = 0;
                puntos2 = 0;
                cout << "Estas listo para la batalla? selecciona con que equipo vas a jugar\n" <<
                        "1) Equipo ( " << trainer1.getTeam(0).getNombre() << " )\n" << 
                        "2) Equipo ( " << trainer1.getTeam(1).getNombre() << " )\n" <<
                        "3) Regresar\n" << ">>> ";
                
                cin >> opcioni;
                if (opcioni == 1 || opcioni == 2)
                {
                    for(int i = 0; i < 3; i++)
                    {
                        resultado = trainer1.getTeam(opcioni-1).getPokemon(i).pelear(trainer2.getTeam(opcioni-1).getPokemon(i));
                        //resultados
                        if (resultado == 1)
                            puntos1++;
                        else
                            puntos2++;
                        system("pause");
                        system("cls");
                        //breakear
                        if (puntos1 == 2){
                            cout << "Wow ganaste " << puntos1 << " a " << puntos2 << ", eso es muy impresionante!!" << endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                        else if (puntos2 == 2){
                            cout << "Fue una derrota muy aplastante... pero al menos ganaste " << puntos1 << " veces... jeje" << endl;
                            system("pause");
                            system("cls");
                            break;
                        }     
                    }
                }
                else if(opcioni == 3)
                {
                    cout << "Regresando." << endl;
                    Sleep(1500);
                    system("cls");
                }
                else{
                    cout << "Esa opcion no es valida, regresando al menu..." << endl;
                }
                break;
            
            default:
                if(opcion == '4')
                {
                    ciclo = false;
                    cout << "Vuelve proto, hasta la proxima!!!" << endl;
                    Sleep(1500);
                    system("cls");
                }
                else{
                    cout << "Por favor solo utiliza opciones del 1 al 4" << endl;
                }
                break;
        }
    }
    return 0;
}


//--------------------------------------------------------------DEFINICION FUNCIONES
void intro()
{
    char opc1 = 'x';
	string tempNombre;

	cout << "Bienvenido a una mini aventura pokemon!\n" << 
			"Aqui puedes realizar diversas acciones, pero para comenzar\n" <<
			"hay que comenzar con una explicacion.\n" <<  
			"Quieres leer la explicacion? S/N\n" <<
			">>> ";
    Sleep(1000);
	//Try y catch para explicación
    while (opc1 == 'x')
    {
        try
        {
            cin >> opc1;
            if (opc1 != 'S' && opc1 != 's' && opc1 != 'N' && opc1 != 'n') throw std::invalid_argument(":c");
        }
        catch (std::invalid_argument)
        {
            system("cls");
            opc1 = 'x';
            cout << "Opcion no valida,\n Quieres leer la explicacion? S/N\n" << ">>> ";
        }
    }

	system("cls");

	if (opc1 == 's' || opc1 == 'S')
	{
		cout << "Muy bien\n" << "Dentro de este programa, simulamos como seria tener pokemones,\n" <<
				"puedes darles de comer o pelear. Hay muchas posibilidades!\n" <<
				"Para comenzar, este programa tiene un limite de dos entrenadores pokemon.\n" <<
				"Cada entrenador puede tener dos equipos de tres pokemones cada uno.\n" <<
				"Muchos amiguitos para conocer!\n\n" <<
				"Este programa te da la libertad de jugar con tus pokemones (de forma simplistica),\n" <<
				"darles de comer, pelear, ver tus medallas, etc.!\n\n";
	}

	cout << "Comencemos con tu perfil de entrenador. Como te llamas? Solo se permite una palabra sin espacios\n>>> ";
    
    cin >> tempNombre;
    Sleep(1000);
    trainer1.setNombre(tempNombre);

	Sleep(1000);
	system("cls");

	cout << "Mucho gusto, " << tempNombre << "!\n";
    cout << "Lo siguiente que haremos va a ser crear un equipo, podras crear hasta un maximo de 2 equipos\n" <<
			"Estos cuentan con 3 pokemones por equipo\n" <<
			"Nuestra guarderia es algo pequena, asi que solo tenemos actualmente 14 tipos de pokemon distintos\n";
    Sleep(1000);
}

void crearEquipo(Entrenador &entrenador_, int n)
{
    string tempNombre;

    Equipo tempEquipo;
    
    char tempAns;
    int numPoke;

    for(int i = 0; i < 3; i++)
    {
        numPoke = 0;
        cout << "Lista de pokemones disponibles:\n" <<
            "\t1.  Rattata 2.   Zubat     3.  Machop   4. Squirtle   5. Vulpix   6. Bulbasaur   7. Voltorb\n" <<
            "\t8.  Lapras  9.   Caterpie 10. Geodude  11.  Cubone   12.  Abra   13.  Ghastly   14.  Ekans\n";
        cout << "------------------------------\n" <<
                "Que pokemon deseas integrar al equipo? Porfavor escribe el numero del pokemon\n" <<
                ">>> ";
        //Elige Pokemon
        while (numPoke == 0)
        {
            try
            {
                cin >> numPoke;
                if (numPoke <= 14 && numPoke >= 1) 
                    cout << "";
                else 
                    throw std::invalid_argument("Invalid Number");
            }
            catch (std::invalid_argument)
            {
                numPoke = 0;
                cout << "Opcion no valida, porfavor escriba el nombre del pokemon\n";
            }
        }
        system("cls");
        tempPoke.dibujar(numPoke, listaPoke);

        //Nombre a pokemon
        cout << "Quieres ponerle nombre al " << listaPoke[numPoke-1] << "?\n" << "S/N\n" << ">>> ";
        try
        {
            cin >> tempAns;
            if (tempAns != 'S' && tempAns != 's') 
                throw std::invalid_argument(":c");
            else
            {
                cout << "Muy bien, como se va a llamar?\n" << ">>> ";
                cin >> tempNombre;
                tempPoke.setNombre(tempNombre);
            }
        }
        catch (std::invalid_argument)
        {
            tempPoke.setNombre(listaPoke[numPoke-1]);
        }
        //Asigna a equipo temporal
        tempPoke.setPoki(listaPoke[numPoke-1]);
        tempEquipo.setPokemon(tempPoke, i);

        system("cls");
        cout << "Pokemon agregado excitosamente\n";
    }
    cout << "Como se va a llamar el equipo?\n>>> ";
    cin >> tempNombre;
    tempEquipo.setNombre(tempNombre);

    entrenador_.setTeam(tempEquipo, n); 
    
}

bool editarEntrenador(Entrenador &entrenador_, char opc)
{
    string nom;

    if (opc == '1'){
        entrenador_.mostrarEntrenador();
        return true;

    }else if (opc == '2'){
        cout << "Cual seria el nuevo nombre?\n>>> ";
        cin >> nom;
        entrenador_.setNombre(nom);
        return true;

    }else if (opc == '3'){
        crearEquipo(entrenador_, 0);
        return true;

    }else if (opc == '4'){
        crearEquipo(entrenador_, 1);
        return true;

    }else{
        return false;
    }
}
#include <iostream>
#include <string>

#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <stdexcept>

#include "Pokemon.h"
#include "Entrenador.h"
#include "Equipo.h"
#include "Movimientos.h"


using namespace std;


//--------------------------------------------------------------DECLARACION FUNCIONES
void initMain();
void crearPokemon();
void inicio();
void puntitos();
bool verificarPlayer2();

//--------------------------------------------------------------GLOBALES
Entrenador trainer1, trainer2;
Equipo team;
Pokemon tempPoke;
Movimientos tempMove;
string pokemonConjunto1[3], pokemonConjunto2[3];

//--------------------------------------------------------------MAIN
int main(){
    //Inicializa un perfil, 1 equipo y sus 3 pokemones
    initMain();
    inicio();

    trainer1.setTeam1(team);

    //Variables Menu
    string nombre;
    char opcion, eq;
    int opc;    
    string pokemones[14] = {"Abra", "Bulbasaur", "Caterpie", "Cubone", "Ekans", "Gastly", "Geodude", "Lapras", "Machop", "Rattata", "Squirtle", "Voltorb", "Vulpix", "Zubat"};
    bool ciclo = true;

    ReinicioMenu:
    cout << "Que te gustaria realizar?\n" << "1) Checar entrenador\n" << "2) Checar Pokemones\n" << "3) Pelear\n" << "4) Salir\n" << ">>> ";
    
    try
    {
        cin >> opcion;
        if (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4') throw std::invalid_argument("Porfavor siga instrucciones");
    }
    catch (std::invalid_argument& x)
    {	
    	cerr << x.what() << endl;
        goto ReinicioMenu;
    }

    //puntitos();
    switch(opcion)
    {
        //---------------------------------------------------------Caso entrenador
        case '1':
            casoEntrenador:
            cout << "Cual entrenador te gustaria checar?\n" << "\t1) Entrenador 1\n" << "\t2) Entrenador 2\n" << "\t3) Regresar al menu\n" << ">>> ";
            cin >> opcion;
            if (opcion == '1')//Entrenador 1
            {
                Entrenador1:
                cout << "Que quiere hacer?\n\t1) Editar entrenador\n\t2) Mostrar entrenador\n\t3) Regresar\n>>> ";
                cin >> opcion;
                if (opcion == '1')
                {
                    Entrenador1Edit:
                    cout << "Que quiere editar?\n\t1) Nombre\n\t2) Equipo\n\t3) Regresar\n>>> ";
                    cin >> opcion;      CrearPerfil2:
                    if (opcion == '1')//Editar nombre
                    {
                        trainer1.editarNombre();
                        goto Entrenador1Edit;
                    }
                    else if (opcion == '2')//Editar equipo
                    {
                        Equipo1Edit:
                        cout << "Que equipo desea modificar? 1 o 2?\n>>> ";
                        cin >> eq;
                        if (eq == '1' || eq == '2')
                        {
                            cout << "Para modificar un equipo, se reemplazan los 3 pokemones y se debe elegir un nuevo nombre. \nEl proceso no se puede interrumpir. Esta seguro? S/N\n>>> ";
                            cin >> opcion;
                            if(opcion == 'S' || opcion == 's')
                            {
                                system("cls");
                                inicio();
                                if (eq == '1')
                                    trainer1.setTeam1(team);
                                else
                                    trainer1.setTeam2(team);
                                goto Entrenador1Edit;
                            }
                            else
                            {goto Equipo1Edit;}
                        }else
                        {goto Entrenador1Edit;}
                    }else
                    {goto Entrenador1;}
                }  
                else if (opcion == '2')//Mostrar entrenador
                    {trainer1.mostrarEntrenador();  
                    goto Entrenador1;}       
                else
                    goto casoEntrenador;
            }
            else if (opcion == '2')//____________________________________________________________________________Entrenador 2
            {
                Entrenador2:
                if (trainer2.getNombre() == "")//No tiene datos previos
                {
                    cout << "Parece que Entrenador 2 esta vacio, te gustaria crear Entrenador 2? S/N\n" << ">>> ";
                    cin >> opcion;
                    if (opcion == 'S' || opcion == 's')
                    {
                        cout << "Que nombre te gustaria ponerle a este entrenador?" << "\n>>> ";
                        cin >> nombre;
                        trainer2.setNombre(nombre);
                        inicio();
                        trainer2.setTeam1(team);
                        goto Entrenador2;
                    }else
                        goto Entrenador2;
                }
                else                          //Ya tiene datos previos
                {
                    cout << "Que quiere hacer?\n\t1) Editar entrenador\n\t2) Mostrar entrenador\n\t3) Regresar\n>>> ";
                    cin >> opcion;
                    if (opcion == '1')
                    {
                        Entrenador2Edit:
                        cout << "Que quiere editar?\n\t1) Nombre\n\t2) Equipo\n\t3) Regresar\n>>> ";
                        cin >> opcion;
                        if (opcion == '1')//Editar nombre
                        {
                            trainer2.editarNombre();
                            goto Entrenador2Edit;
                        }
                        else if (opcion == '2')//Editar equipo
                        {
                            Equipo2Edit:
                            cout << "Que equipo desea modificar? 1 o 2?\n>>> ";
                            cin >> eq;
                            if (eq == '1' || eq == '2')
                            {
                                cout << "Para modificar un equipo, se reemplazan los 3 pokemones y se debe elegir un nuevo nombre. \nEl proceso no se puede interrumpir. Esta seguro? S/N\n>>> ";
                                cin >> opcion;
                                if(opcion == 'S' || opcion == 's')
                                {
                                    system("cls");
                                    inicio();
                                    if (eq == '1')
                                        trainer2.setTeam1(team);
                                    else
                                        trainer2.setTeam2(team);
                                    goto Entrenador2Edit;
                                }
                                else
                                {goto Equipo2Edit;}
                            }else
                            {goto Entrenador2Edit;}
                        }else
                        {goto Entrenador2;}
                    }
                    else if (opcion == '2')//Mostrar entrenador
                        {trainer2.mostrarEntrenador();
                        goto Entrenador2Edit;}
                    else
                        goto casoEntrenador;
                }
            }
            else
                goto ReinicioMenu;
            break;
        //---------------------------------------------------------Caso Pokemones (Pokedex)
        case '2':
            while(ciclo){
                cout << "Bienvenido a la pokedex!! de que pokemon te gustaria saber su descripcion?\n";
                for(int i = 0; i < 14; i++)
                    cout << i + 1 << ") " << pokemones[i] << endl;

                cout << "15) Salir de pokedex\n" << ">>> ";
                cin >> opc;

                if(opc == 15)
                    ciclo = false;
                else{
                    tempPoke.dibujar(opc, pokemones);
                    printf("\n");
                    tempPoke.descripcion(opc, pokemones);
                    system("pause");
                    puntitos();
                }
            }
            goto ReinicioMenu;
            break;
        //---------------------------------------------------------Caso Pelear
        case '3':
        Pelea:
            if(verificarPlayer2())
            {
                pokemonConjunto1[1] = trainer1.getTeam1().getPokemon1();
                pokemonConjunto1[2] = trainer1.getTeam1().getPokemon2();
                pokemonConjunto1[3] = trainer1.getTeam1().getPokemon3();

                pokemonConjunto2[1] = trainer2.getTeam1().getPokemon1();
                pokemonConjunto2[2] = trainer2.getTeam1().getPokemon2();
                pokemonConjunto2[3] = trainer2.getTeam1().getPokemon3();

                for(int i = 1; i <= 3; i++)
                {
                    tempPoke.
                    /*switch(i)
                    {
                        case 1:
                            break;

                        case 2:
                            break;

                        case 3:
                            break;

                        default:
                            break;
                    }*/
                }
            }

            else{
                cout << "Error, el perfil numreo 2 tiene que estar creado para poder pelear, te gustaria crearlo? S/N\n" << ">>>";
                cin >> opcion;
                if (opcion == 'S' || opcion == 's')
                {
                    cout << "Te estamos redirigiendo a C:/Pokemon/main.cpp/Menu/Editar perfil/Perfil 2/Crear";
                    puntitos();
                    opcion = '1';
                    goto CrearPerfil2;
                }else if(opcion == 'N' || opcion == 'n'){
                    cout << "Regresando.";
                    puntitos();
                    goto Pelea;
                }
                else{
                    cout << "por favor ingresa una S o N";
                    puntitos();
                    goto Pelea;
                }
            }
            goto ReinicioMenu;
            break;
            
        case '4':
            cout << "Hasta la proxima, espero verte aqui de nuevo!!" << endl;
            puntitos();
            break;
    }

    return 0;
}

//--------------------------------------------------------------DEFINICION FUNCIONES
//--------------------------------------initMain
void initMain()
{
	char opc1;
	string tempNombre;

	cout << "Bienvenido a una mini aventura pokemon!\n" << 
			"Aqui puedes realizar diversas acciones, pero para comenzar\n" <<
			"hay que comenzar con una explicacion.\n" <<  
			"Quieres leer la explicacion? S/N\n" <<
			">>> ";
	//Try y catch para explicación
	initError1:
	try
	{
		cin >> opc1;
		if (opc1 != 'S' && opc1 != 'N' && opc1 != 's' && opc1 != 'n') throw std::invalid_argument(":c");
	}
	catch (std::invalid_argument)
	{
		system("cls");
		cout << "Opcion no valida,\n Quieres leer la explicacion? S/N\n" << ">>> ";
		cin >> opc1;
		goto initError1;
	}
	system("cls");

	if (opc1 == 's' || opc1 == 'S')
	{
		cout << "Muy bien\n" << "Dentro de este programa, simulamos como seria tener pokemones,\n" <<
				"puedes darles de comer o pelear. Hay muchas posibilidades!\n" <<
				"Para comenzar, este programa tiene un limite de 2 entrenadores pokemon.\n" <<
				"Cada entrenador puede tener dos equipos de tres pokemones cada uno.\n" <<
				"Muchos amiguitos para conocer!\n\n" <<
				"Este programa te da la libertad de jugar con tus pokemones (de forma simplistica),\n" <<
				"darles de comer, pelear, ver tus medallas, etc.!\n\n";
	}

	cout << "Comencemos con tu perfil de entrenador. Como te llamas? \n>>> ";
    cin >> tempNombre;

	Sleep(2000);
	system("cls");

	cout << "Mucho gusto, " << tempNombre << "!\n";
    cout << "Lo siguiente que haremos va a ser crear un equipo, podras crear hasta un maximo de 2 equipos\n" <<
			"Estos cuentan con 3 pokemones por equipo\n" <<
			"Nuestra guarderia es algo pequena, asi que solo tenemos actualmente 14 tipos de pokemon distintos\n";
    cout << endl;
    Sleep(1000);
    
    trainer1.setNombre(tempNombre);

}

//--------------------------------------crearPokemon
void crearPokemon()

{
    string listaPoke[14] = {"Rattata", "Zubat", "Machop", "Squirtle", "Vulpix", "Bulbasaur", "Voltorb", "Lapras", "Caterpie", "Geodude", "Cubone", "Abra", "Ghastly", "Ekans"};
    string tempNombre, tempPokemon;
    char tempAns;
    int numPoke;

    //initError2
    initError2:
    cout << "He aqui la lista de pokemones:\n" <<
            "\t1.  Rattata 2.   Zubat     3.  Machop   4. Squirtle   5. Vulpix   6. Bulbasaur   7. Voltorb\n" <<
            "\t8.  Lapras  9.   Caterpie 10. Geodude  11.  Cubone   12.  Abra   13.  Ghastly   14.  Ekans\n";
    cout << "------------------------------\n" <<
            "Que pokemon deseas integrar al equipo? Porfavor escribe el numero del pokemon\n" <<
            ">>> ";
    try
    {
        cin >> numPoke;
        //Sleep(500);
        if (numPoke <= 14 && numPoke >= 1) cout << "";
        else throw std::invalid_argument("Invalid Number");
    }
    catch (std::invalid_argument)
    {
        system("cls");
        cout << "Opcion no valida, porfavor siga instrucciones\n";
        goto initError2;
    }

    //puntitos();
    tempPokemon = listaPoke[numPoke-1];
    //initError3
    initError3:
    cout << "Quieres ponerle nombre al " << listaPoke[numPoke-1] << "?\n" << "S/N\n" << ">>> ";
    try
    {
        cin >> tempAns;
        Sleep(1000);
        if (tempAns != 'S' && tempAns != 'N' && tempAns != 's' && tempAns != 'n') throw std::invalid_argument(":c");
    }
    catch (std::invalid_argument)
    {
        system("cls");
        cout << "Opcion no valida\n";
        goto initError3;
    }

    if (tempAns == 'S' || tempAns == 's')
    {
        //initError4
        initError4:
        cout << "Muy bien, como se va a llamar?\n" << ">>> ";
        cin >> tempNombre;
        
        Sleep(1000);
        initError5:
        cout << "Quieres ponerle " << tempNombre << " a " << listaPoke[numPoke-1] << "?\n" <<
                "S/N\n" << ">>> ";
        try
        {
            cin >> tempAns;
            Sleep(1000);
            if (tempAns != 'S' && tempAns != 'N' && tempAns != 's' && tempAns != 'n') throw std::invalid_argument(":c");
            else if (tempAns == 'n' || tempAns == 'N')
            {
                system("cls");
                goto initError4;
            }
        }
        catch (std::invalid_argument)
        {
            system("cls");
            cout << "Opcion no valida\n";
            goto initError5;
        }
        
        tempPoke.setPoki(tempPokemon);
        tempPoke.setNombre(tempNombre);
    }
    else
    {
        tempPoke.setPoki(tempPokemon);
        tempPoke.setNombre(tempPokemon);
    }
    tempPoke.setMov();
    cout << tempPoke.getMov1().getMovimiento() << endl;
    cout << tempPoke.getMov2().getMovimiento() << endl;
    cout << "El pokemon ha sido integrado a su equipo con exito!" << endl;
    
}

//--------------------------------------inicio
void inicio()
{
    string x;
    crearPokemon();
    team.setPokemon1(tempPoke);
    cout << "Ahora hay que agregar los otros dos pokemones\n";
    crearPokemon();
    team.setPokemon2(tempPoke);
    cout << "Y el ultimo del equipo...\n";
    crearPokemon();
    team.setPokemon3(tempPoke);
    cout << "Para terminar la preparacion... Como quieres llamar al equipo?\n" <<
            ">>> ";
    cin >> x;
    team.setNombre(x);
    system("cls");
    cout << "Perfecto, has completado el proceso, revisa el menu para mas opciones\n";
}

//--------------------------------------Puntos
void puntitos(){
    for(int i = 0; i < 5; i++){
        printf(".");
        Sleep(250);
    }
    system("cls");
}

bool verificarPlayer2(){
    if(trainer2.getNombre() == "")
        return false;   //false = esta vacio y no hay entrenador 1

    else    
        return true;    //Si estan llenos los campos de entrenador
}
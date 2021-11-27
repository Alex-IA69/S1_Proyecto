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


using namespace std;


//--------------------------------------------------------------DECLARACION FUNCIONES
void initMain();
void crearPokemon();

//--------------------------------------------------------------MAIN
int main(){
	initMain();     

    char opcion;
    cout << "Que te gustaria relaizar?:\n" <<
            "1) Checar perfil\n" <<
            "2) Checar equipo\n" <<
            "3) Checar pokemones\n" <<
            "4) Salir\n";
    try
    {
        cin >> opcion;
        if (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4') throw std::invalid_argument("UTILIZA LOS NUMEROS DEL 1 AL 4 WEON CTM!!!");
        else cout << "Todo bien\n";
    }
    catch (std::invalid_argument& x)
    {	Menu:
    	cerr<<x.what()<<endl;
    	for(int i = 0; i < 10; i++){
            Sleep(250);
            printf(".");
        }
        system("cls");
        
    	cout << "Por favor ingresa de nuevo una opcion valida:\n1) Checar perfil\n" <<
            "2) Checar equipo\n" <<
            "3) Checar pokemones\n" <<
            "4) Salir\n" << endl;
        cin >> opcion;
        if(opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4')
        	goto Menu;
    }

    switch(opcion){
        case '1':
            //Checar perfil
            break;

        case '2':
            //Checar equipo
            break;

        case '3':
            //Checar pokimons
            break;
            
        case '4':
            cout << "Hasta la proxima, espero verte aqui de nuevo!!" << endl;
            for(int i = 0; i < 10; i++){
                Sleep(250);
                printf(".");
            }
            system("cls");
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
			"Estos cuentan con un limite de 3 pokemones por equipo\n" <<
			"Nuestra guarderia es algo pequena, asi que solo tenemos actualmente 14 tipos de pokemon distintos\n";
	Sleep(2000);
    
}

//--------------------------------------crearPokemon
void crearPokemon()
{
    string listaPoke[14] = {"Rattata", "Zubat", "Machop", "Squirtle", "Vulpix", "Bulbasaur", "Voltorb", "Lapras", "Caterpie", "Geodude", "Cubone", "Abra", "Ghastly", "Ekans"};
    string tempNombre, tempPoke;
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
        Sleep(1000);
        if (numPoke > 14 && numPoke < 1) throw std::invalid_argument("Invalid Number");
    }
    catch (std::invalid_argument)
    {
        system("cls");
        cout << "Opcion no valida, porfavor siga instrucciones\n";
        goto initError2;
    }
    //initError3
    initError3:
    cout << "Quieres ponerle nombre a tu " << listaPoke[numPoke-1] << "?\n" <<
            "S/N\n" << ">>> ";
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

    system("cls");
    cout << "Muy bien, como se va a llamar?";
}
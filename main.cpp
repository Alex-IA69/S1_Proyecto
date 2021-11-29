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
void inicio();
void puntitos();

//--------------------------------------------------------------GLOBALES
Entrenador trainer1, trainer2;
Equipo team;
Pokemon tempPoke;

//--------------------------------------------------------------MAIN
int main(){
    inicio();
    //variables del switch
    char opcionC[15];

    string nombre;
    char opcion;    
ReinicioMenu:
    cout << "Que te gustaria realizar?\n" <<
            "1) Checar perfil\n" <<
            "2) Checar equipo\n" <<
            "3) Checar pokemones\n" <<
            "4) Salir\n";
    try
    {
        cin >> opcion;
        if (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4') throw std::invalid_argument("UTILIZA LOS NUMEROS DEL 1 AL 4 WEON CTM!!!");
    }
    catch (std::invalid_argument& x)
    {	Menu:
    	cerr<<x.what()<<endl;
    	puntitos();
        goto ReinicioMenu;
    }

    puntitos();
    switch(opcion){
//---------------------------------------------------------Caso entrenador
        case '1':
            perfilnt2:
            cout << "Cual perfil te gustaria checar?\n" <<
            "1) Perfil 1\n" <<
            "2) Perfil 2\n" <<
            "3) Regresar al menu\n";
            cin>>opcionC[1];
            puntitos();

            if(trainer2.getNombre() == "" && opcionC[1] == '2'){
            crear_perfil:
                cout << "Opcion invalida ya que el perfil 2 esta vacio, te gustaria crear un segundo perfil? S/N" << endl;
                cin>>opcionC[4];
                try
                {
                    cin >> opcionC[4];
                    Sleep(1000);
                    if (opcionC[4] != 'S' && opcionC[4] != 'N' && opcionC[4] != 's' && opcionC[4] != 'n')       throw std::invalid_argument("ingresa solo (S) o (N)");

                    else{
                        cout << "Cagando" << endl;
                        puntitos();
                    }
                }
                catch (std::invalid_argument& x)
                {
                    cerr << x.what() << endl;
                    puntitos();
                    goto crear_perfil;
                }

                if(opcionC[4] == 'S' || opcionC[4] == 's'){
                    printf("Que nombre te gustaria ponerle a este perfil?: ");
                    cin>>nombre;
                    puntitos();
                    trainer2.setNombre(nombre);
                    inicio();
                    trainer2.setTeam1(team);
                }
                if(opcionC[4] == 'N' || opcionC[4] == 'n'){
                    puntitos();
                    goto perfilnt2;
                }
            }

            else if(opcionC[1] == '1' || opcionC[1] == '2'){
                perfil_ingreso1:
                cout << "Que quiere hacer?\n" <<
                "1) Editar nombre\n" <<
                "2) Mostrar perfil\n" <<
                "3) Volver atras\n";
                cin>>opcionC[2];
                puntitos();
                
                if(opcionC[2] == '3'){
                    goto perfilnt2;
                }

                if(opcionC[2] == '1'){
                    printf("Que nombre le vas a poner al perfil?: ");
                    cin>>nombre;
                    puntitos();
                perfil1:
                    cout << "Estas seguro que quieres ponerle: " << nombre << " al perfil " << opcionC[1] << "? S/N" << endl;
                    try
                    {
                        cin >> opcionC[3];
                        Sleep(1000);
                        if (opcionC[3] != 'S' && opcionC[3] != 'N' && opcionC[3] != 's' && opcionC[3] != 'n')       throw std::invalid_argument("ingresa solo (S) o (N)");

                        else{
                            cout << "guardando nombre" << endl;
                            puntitos();
                        }
                    }
                    catch (std::invalid_argument& x)
                    {
                        cerr << x.what() << endl;
                        puntitos();
                        goto perfil1;
                    }

                    if(opcionC[1] == '1'){
                        trainer1.setNombre(nombre);
                        goto ReinicioMenu;
                    }

                    else{
                        trainer2.setNombre(nombre);
                        goto ReinicioMenu;
                    }
                }

                if(opcionC[2] == '2'){
                    if(opcionC[1] == '1'){
                        cout << "El nombre del perfil 1 es: " << trainer1.getNombre() << "\n\nEs muy agradable el pibe :)\n\n" << endl;

                        cout << "Para regresar al menu principal precione cualquier tecla" << endl;
                        system("pause");
                        puntitos();
                        goto ReinicioMenu;
                    }

                    else{
                        cout << "El nombre del perfil 1 es: " << trainer2.getNombre() << "/n/nEs muy agradable el pibe :)\n\n" << endl;

                        cout << "Para regresar al menu principal precione cualquier tecla" << endl;
                        system("pause");
                        puntitos();
                        goto ReinicioMenu;
                    }
                }

                else if (opcionC[1] != '1' && opcionC[1] != '2' && opcionC[1] != '3'){
                    cout << "Opcion no valida, por favor intenta de nuevo" << endl;
                    Sleep(1500);
                    system("cls");
                    goto perfil_ingreso1;
                }
            }

            else if(opcionC[1] == '3'){
                goto ReinicioMenu;
            }

            else{
                cout << "Por favor ingresa (1), (2) o (3), ninguna otra opcion es valida" << endl;
                Sleep(1500);
                system("cls");
                goto perfilnt2;
            }
            break;

        case '2':
            //Checar equipo
            goto ReinicioMenu;
            break;

        case '3':
            //Checar pokimons
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
        Sleep(500);
        if (numPoke <= 14 && numPoke >= 1) cout << "";
        else throw std::invalid_argument("Invalid Number");
    }
    catch (std::invalid_argument)
    {
        system("cls");
        cout << "Opcion no valida, porfavor siga instrucciones\n";
        goto initError2;
    }

    puntitos();

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

    if (tempAns == 'S' || tempAns == 's')
    {
        //initError4
        initError4:
        cout << "Muy bien, como se va a llamar?\n" << ">>> ";
        cin >> tempNombre;
        
        Sleep(1000);
        initError5:
        cout << "Quieres ponerle " << tempNombre << " a tu " << listaPoke[numPoke-1] << "?\n" <<
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
        tempPoke.setNombre(tempNombre);
    }
    cout << "Tu pokemon ha sido integrado a su equipo con exito!" << endl;
    
}

//--------------------------------------inicio
void inicio()
{
    string x;
    initMain();
    crearPokemon();
    team.setPokemon1(tempPoke);
    cout << "Ahora hay que agregar tus otros dos pokemones\n";
    crearPokemon();
    team.setPokemon2(tempPoke);
    cout << "Y el ultimo de tu equipo...\n";
    crearPokemon();
    team.setPokemon3(tempPoke);
    cout << "Para terminar la preparacion... Como quieres llamar a tu equipo?\n" <<
            ">>> ";
    cin >> x;
    team.setNombre(x);
    system("cls");
    cout << "Perfecto, has completado tu perfil, revisa el menu para mas opciones\n";
}

void puntitos(){
    for(int i = 0; i < 10; i++){
        printf(".");
        Sleep(250);
    }
    system("cls");
}
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    /*string pokemones[14] = {"Abra", "Bulbasaur", "Caterpie", "Cubone", "Ekans", "Gastly", "Geodude", "Lapras", "Machop", "Rattata", "Squirtle", "Voltorb", "Vulpix", "Zubat"};
    int opcion;

    cout << "||----------Chose your pokimon!!----------||" << endl;
    for(int i = 1; i <= 14; i++)
        cout << i << ") " << pokemones[i] << endl;
    cin >> opcion;*/
    string nombre;
    int medallas;

    cout << "Hola aventurero, es un gusto verte por aqui, empecemos por crear tu perfil, por favor ingresa tu nombre en este apartado: " << endl;
    cin >> nombre;  Sleep(1000);
    cout << "Todo entrenador que se respeta presume de sus medallas, dime con cuantas medallas cuentas tu: " << endl;
    cin >> medallas;    Sleep(1000);
    cout << "Grandioso, lo siguiente que haremos va a ser crear un equipo, podras crear hasta un maximo de 2 equipos los cuales cuentan con un limite de 3 pokemones por equipo" << endl;
    //entrenador.crear(nombre, medallas);
    Sleep(1000);
    cout << "Exelente!! todos tus datos han sido guardados con exito, espera un momento por favor.";
    Sleep(500);
    for (int i = 0; i < 15; i++)
    {
        printf(".");
        Sleep(500);
    }   system("cls");
     

    int opcion = 0;     Menu:
    cout << "Hola aventurero!! eres bienvenido a esta gran aventura, primero tienes que elegir una opcion :)\n1) Crear un nuevo entrenador\n2) Crear un equipo nuevo\n3) Salir" << endl;
    cin >> opcion;
    switch (opcion){
        case 1:
            cout << "Hola aventurero, vamos a crear un nuevo perfil, por favor ingresa un nombre: " << endl;
            cin >> nombre;
            cout << "Ingresa el numero de medallas que tienes: " << endl;
            cin >> medallas;
            cout << "Lo siguiente que haremos va a ser crear un equipo, podras crear hasta un maximo de 2 equipos los cuales cuentan con un limite de 3 poquemones por equipo" << endl;
            //entrenador.crear(nombre, medallas);
            break;

        case 2:
            //equipo.crear();
            break;
        
        default:
            if(opcion == 3){
                cout << "Nos veremos la proxima vez y recuerda, al infinito y mas alla :D" << endl;
                Sleep(2000);
                break;
            }

            else{
                cout << "Por favor ingresa una opcion valida aventurero D:" << endl;
                Sleep(2000);
                system("cls");
                goto Menu;
            }
    }
    return 0;
}
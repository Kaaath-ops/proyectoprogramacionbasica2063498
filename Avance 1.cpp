#include <iostream>
#include <conio.h> 
#include <stdio.h>
#include <string>

using  namespace std;

int main()
{
    char clasificacion[20], genero[20], consola[20];
    int desicion, opcion, numero;
    string descripcion, articulo1;
    float precio, impuesto, total;

    //alta de articulos
    //modificacion de articulos
    //baja de articulos
    //lista de articulos
    //limpiar pantalla
    //salir;

    cout << "\t ***MENU DE OPCIONES***" << endl; // \t es tabulador
    cout << "1.-Alta" << endl;
    cout << "2.-Modificacion" << endl;
    cout << "3.-Baja" << endl;
    cout << "4.-Lista" << endl;
    cout << "5.-Limpiar Pantalla" << endl;
    cout << "6.-Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1: //ALTA

        cout << "ingrese articulo" << endl;
        cin.ignore();
        getline(cin,articulo1);

        cout << "ingrese la descripcion: " << endl;
        cin.ignore(0, '\n');
        getline(cin,descripcion);

        cout << "ingrese el numero de articulo: " << endl;
        cin >> numero;

        cout << "ingrese el genero: " << endl;
        cin >> genero;

        cout << "ingrese la clasificacion: " << endl;
        cin >> clasificacion;

        cout << "ingrese la consola: " << endl;
        cin >> consola;

        cout << "ingrese el precio: " << endl;
        cin >> precio;

        impuesto = precio * 0.16;

        total = impuesto + precio;
        cout << "Articulo: " << articulo1 << endl << " numero de articulo: " << numero << endl << " descripcion del articulo: " << descripcion << endl << " genero de: " <<  genero << endl << " clasificacion del articulo:  " <<  clasificacion << endl <<  " disponible para consola: " << consola << endl << " con un precio de : " << precio << endl << " y un total de : " << total << endl;

        cout << "Desea agregar otro articulo 1.-si 2.-No" << endl;
        cin >> desicion;
        if (desicion == 1)
        {
            return main();
        }

        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        system("cls"); // limpiar pantalla
        return main();
        break;
    case 6:
        exit(1); // cierra la pantalla
        break;

    }
}
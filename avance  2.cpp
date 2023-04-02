#include <iostream>
#include <math.h> // calculos matematicos
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using  namespace std;

struct articulos
{
    char clasificacion[25], genero[25], consola[25];
    int desicion, numero, num_articulos_disponibles;
    string descripcion, articulo;
    float precio, impuesto, total;
};

int main()
{
    articulos alta[3];
    int opcion;

    //alta de articulos
    //modificacion de articulos
    //baja de articulos
    //lista de articulos
    //limpiar pantalla
    //salir;
    do
    {
        printf("\t ***MENU DE OPCIONES***\n"); // \t es tabulador
        printf("1.-Alta\n");
        printf("2.-Modificacion\n");
        printf("3.-Baja\n");
        printf("4.-Lista\n");
        printf("5.-Limpiar Pantalla\n");
        printf("6.-Salir\n");
        scanf_s("%d", &opcion);


        switch (opcion)
        {
        case 1: //ALTA
            for (int i = 0; i < 3; i++)
            {   
                printf("Ingrese el numero del articulo: ");
                scanf_s("%d", &alta[i].numero);
                cin.ignore();
                printf("Ingrese articulo: ");
                
                getline(cin, alta[i].articulo);

                printf("Ingrese la descripcion del articulo: ");
                getline(cin, alta[i].descripcion);

                

                printf("Ingrese el numero de articulos disponibles: ");
                scanf_s("%d", &alta[i].num_articulos_disponibles);
                cin.ignore();

                printf("Ingrese el genero: ");
                gets_s(alta[i].genero);

                printf("Ingrese la clasificacion: ");
                gets_s(alta[i].clasificacion);

                printf("Ingrese la consola: ");
                gets_s(alta[i].consola);

                printf("Ingrese el precio: ");
                scanf_s("%f", &alta[i].precio);
                cin.ignore();

                alta[i].total = alta[i].precio * 0.16 + alta[i].precio;

            }
            break;

        case 2: 
            break;

        case 3:
            break;

        case 4:
            for (int i = 0; i < 3; i++)
            {
                printf("ARTICULO: %s\n", alta[i].articulo.c_str());
                printf("DESCRIPCION: %s\n", alta[i].descripcion.c_str());
                printf("NUMERO: %d\n", alta[i].numero);
                printf("CANTIDAD DE ARTICULOS DISPONIBLES: %d\n", alta[i].num_articulos_disponibles);
                printf("GENERO: %s\n", alta[i].genero);
                printf("CLASIFICACION: %s\n", alta[i].clasificacion);
                printf("CONSOLA: %s\n", alta[i].consola);
                printf("PRECIO: %.2f\n", alta[i].precio);
                printf("TOTAL: %.2f\n", alta[i].total);
            }
            break;

        case 5: 
            system("cls"); // limpiar pantalla
            return main();
            break;

        case 6: 
            exit(1); // cierra la pantalla
            break;
        }
    } while (opcion != 6);
}
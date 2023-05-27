#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct articulos
{
    string clasificacion, genero, consola, status;
    int decision, num_articulos_disponibles, anio_lanzamiento;
    float iva, alta, precio, total;
    string descripcion, articulo;
};

int contador, alta;
articulos* TIENDA;  // uso de punteros

// Declaración de funciones
void Alta();
void Modificacion();
void eliminar();
void Listas();
void Archivos();

int main()
{
    int opcion;

    do
    {
        system("color 0A"); // cambia el color a verde
        printf("\n\t\t     ***MENU DE OPCIONES***\n");
        printf(" ________________________________________________________\n");
        printf("|                                                        |\n");
        printf("|          1. Alta                                       |\n");
        printf("|          2. Modificacion                               |\n");
        printf("|          3. Baja                                       |\n");
        printf("|          4. Lista                                      |\n");
        printf("|          5. Limpiar Pantalla                           |\n");
        printf("|          6. Salir                                      |\n");
        printf("|________________________________________________________|\n");
        printf("\nIngrese la opcion deseada: ");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1: // ALTA
            system("color 0B"); // cambia el color a cian
            Alta();
            return main();
            break;

        case 2:
            system("color 0E"); // cambia el color a amarillo
            Modificacion();
            return main();
            break;

        case 3:
            system("color 0C"); // cambia el color a rojo
            eliminar();
            return main();
            break;

        case 4:
            system("color 0D"); // cambia el color a morado
            Listas();
            return main();
            break;

        case 5:
            system("cls");
            return main();
            break;

        case 6:
            Archivos();
            exit(1);
            break;

        default:
            printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
            break;
        }
    } while (opcion != 6);
}

void Alta()
{
    printf("\nCuantos registros desea dar de alta? \n");
    scanf_s("%d", &alta);
    TIENDA = new articulos[alta];

    for (int i = 0; i < alta; i++)
    {
        printf("\n*** Dando de Alta Registro %d ***\n", i + 1);
        printf("Ingrese el numero de articulos disponibles: ");
        scanf_s("%d", &TIENDA[i].num_articulos_disponibles);
        while (getchar() != '\n'); // Vaciar el búfer

        printf("Ingrese el articulo: ");
        getline(cin, TIENDA[i].articulo);

        printf("Ingrese la descripcion del articulo: ");
        getline(cin, TIENDA[i].descripcion);

        printf("Ingrese el genero: ");
        getline(cin, TIENDA[i].genero);

        printf("Ingrese la clasificacion: ");
        getline(cin, TIENDA[i].clasificacion);

        printf("Ingrese la consola: ");
        getline(cin, TIENDA[i].consola);

        printf("Ingrese fecha de lanzamiento del videojuego: ");
        scanf_s("%d", &TIENDA[i].anio_lanzamiento);

        printf("Ingrese el precio: ");
        scanf_s("%f", &TIENDA[i].precio);
        while (getchar() != '\n'); // Vaciar el búfer

        TIENDA[i].iva = 0.16;
        TIENDA[i].total = TIENDA[i].precio * TIENDA[i].iva + TIENDA[i].precio;

        TIENDA[i].status = "ACTIVO";
    }
}

void Listas()
{
    printf("\n*** Lista de Articulos ***\n\n");

    for (int i = 0; i < alta; i++)
    {
        if (TIENDA[i].status == "ELIMINADO")
        {
            printf("REGISTRO ELIMINADO %d\n", i + 1);
        }
        else
        {
            printf("Articulo: %s\n", TIENDA[i].articulo.c_str());
            printf("Descripcion: %s\n", TIENDA[i].descripcion.c_str());
            printf("Cantidad de articulos disponibles: %d\n", TIENDA[i].num_articulos_disponibles);
            printf("Genero: %s\n", TIENDA[i].genero.c_str());
            printf("Clasificacion: %s\n", TIENDA[i].clasificacion.c_str());
            printf("Consola: %s\n", TIENDA[i].consola.c_str());
            printf("Fecha de lanzamiento: %d\n", TIENDA[i].anio_lanzamiento);
            printf("Precio: %.2f\n", TIENDA[i].precio);
            printf("Total: %.2f\n", TIENDA[i].total);
        }
    }
}

void eliminar()
{
    printf("\n*** Eliminar Registro ***\n");

    int j;
    printf("Ingrese el registro a eliminar: ");
    scanf_s("%d", &j);
    j = j - 1;

    if (j >= 0 && j < alta)
    {
        printf("Eliminando registro %d\n", j + 1);
        TIENDA[j].status = "ELIMINADO";
        TIENDA[j].num_articulos_disponibles = 0;
        TIENDA[j].articulo = "";
        TIENDA[j].descripcion = "";
        TIENDA[j].genero = "";
        TIENDA[j].clasificacion = "";
        TIENDA[j].consola = "";
        TIENDA[j].precio = 0.0;
        TIENDA[j].total = 0.0;
        TIENDA[j].anio_lanzamiento = 0.0;
    }
    else
    {
        printf("Registro no valido.\n");
    }
}


void Modificacion()
{
    printf("\n*** Modificar Registro ***\n");

    int j, opc, op2;
    do
    {
        printf("Ingrese el numero de registro a modificar: ");
        scanf_s("%d", &j);
        j = j - 1;

        if (j >= 0 && j < alta)
        {
            if (TIENDA[j].status == "ELIMINADO")
            {
                printf("REGISTRO ELIMINADO %d\n", j + 1);
                printf("Ingrese un registro valido.\n");
                op2 = 1;
            }
            else
            {
                op2 = 2;
            }
        }
        else
        {
            printf("Registro no valido.\n");
            op2 = 1;
        }
    } while (op2 == 1);

    printf("\t Ingrese lo que desea modificar: \n");
    printf("1.- Nombre\n");
    printf("2.- Articulos disponibles\n");
    printf("3.- Genero\n");
    printf("4.- Clasificacion\n");
    printf("5.- Consola\n");
    printf("6.- Precio\n");
    printf("7.- Descripcion\n");
    printf("8.- Fecha\n");
    scanf_s("%d", &opc);

    switch (opc)
    {
    case 1:
        while (getchar() != '\n'); // Vaciar el búfer
        printf("Ingrese el nombre: ");
        getline(cin, TIENDA[j].articulo);
        break;

    case 2:
        printf("Ingrese el numero de articulos disponibles: ");
        scanf_s("%d", &TIENDA[j].num_articulos_disponibles);
        break;

    case 3:
        while (getchar() != '\n'); // Vaciar el búfer
        printf("Ingrese el genero: ");
        getline(cin, TIENDA[j].genero);
        break;

    case 4:
        while (getchar() != '\n'); // Vaciar el búfer
        printf("Ingrese la clasificacion: ");
        getline(cin, TIENDA[j].clasificacion);
        break;

    case 5:
        while (getchar() != '\n'); // Vaciar el búfer
        printf("Ingrese la consola: ");
        getline(cin, TIENDA[j].consola);
        break;

    case 6:
        printf("Ingrese el precio: ");
        scanf_s("%f", &TIENDA[j].precio);
        TIENDA[j].total = TIENDA[j].precio * TIENDA[j].iva + TIENDA[j].precio;
        break;

    case 7:
        while (getchar() != '\n'); // Vaciar el búfer
        printf("Ingrese la descripcion del articulo: ");
        getline(cin, TIENDA[j].descripcion);
        break;

    case 8:
        printf("Ingrese el fecha de lanzamiento: ");
        scanf_s("%d", &TIENDA[j].anio_lanzamiento);
        break;

    default:
        printf("Opcion invalida.\n");
        break;
    }
}



void Archivos()
{
    ofstream archivo("Videojuegosymas.txt");

    for (int i = 0; i < alta; i++)
    {
        if (TIENDA[i].status == "ELIMINADO")
        {
            archivo << "ARTICULO ELIMINADO" << endl;
            archivo << "--------------------" << endl;
        }
        else
        {
            archivo << "ARTICULO: " << TIENDA[i].articulo << endl;
            archivo << "DESCRIPCION: " << TIENDA[i].descripcion << endl;
            archivo << "CANTIDAD DE ARTICULOS DISPONIBLES: " << TIENDA[i].num_articulos_disponibles << endl;
            archivo << "GENERO: " << TIENDA[i].genero << endl;
            archivo << "CLASIFICACION: " << TIENDA[i].clasificacion << endl;
            archivo << "CONSOLA: " << TIENDA[i].consola << endl;
            archivo << "Fecha de lanzamiento: " << TIENDA[i].anio_lanzamiento << endl;
            archivo << "PRECIO: " << TIENDA[i].precio << endl;
            archivo << "TOTAL: " << TIENDA[i].total << endl;
            archivo << "--------------------" << endl;
        }
    }

    archivo.close();
    printf("Archivo guardado exitosamente.\n");
}


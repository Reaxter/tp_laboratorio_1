#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s', opcion;
    eMovie pPelicula;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n\n");

        printf("Ingrese una opcion: ");
        opcion = getche();
        printf("\n");
        system("pause");
        system("cls");

        switch(opcion)
        {
            case '1':
                agregarPelicula(pPelicula);
                break;
            case '2':
                borrarPelicula(pPelicula);
                break;
            case '3':
                modificarPelicula(pPelicula);
                break;
            case '4':
                generarPagina(pPelicula);
                break;
            case '5':
                seguir = 'n';
                break;
            default:
                printf("Error. Reingrese una opcion correcta (1-5)\n");
                break;
        }
        if(seguir == 's')
        {
            system("pause");
            system("cls");
        }
    }
    printf("Programa finalizado, gracias por usar.");
    return 0;
}

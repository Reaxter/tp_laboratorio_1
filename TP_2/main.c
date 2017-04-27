#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define MAX 20

int main()
{
    char seguir='s', opcion;
    ePersona usuarios[MAX];
    inicializarLista(usuarios, MAX);

    while(seguir=='s')
    {
        printf("Men%c de opciones:\n", 163);
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir gr%cfico de edades\n", 160);
        printf("5- Salir\n\n");
        printf("Ingrese una opci%cn: ", 162);
        opcion = getche();
        printf("\n");
        system("pause");
        system("cls");
        switch(opcion)
        {
            case '1':
                agregarUsuario(usuarios, MAX);
                break;
            case '2':
                borrarUsuario(usuarios, MAX);
                break;
            case '3':
                ordenarLista(usuarios, MAX);
                imprimirLista(usuarios, MAX);
                break;
            case '4':
                imprimirGrafico(usuarios, MAX);
                break;
            case '5':
                seguir = 'n';
                break;
            default:
                printf("Error. Reingrese una opci%cn correcta (1-5)\n", 162);
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

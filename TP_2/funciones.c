#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"


void inicializarLista(ePersona lista[], int max)
{
    int i;
    for(i=0; i<max; i++)
    {
        lista[i].estado=0;
    }
}

int obtenerEspacioLibre(ePersona lista[], int max)
{
    int i, indice = -1;
    for(i=0; i<max; i++)
    {
        if(lista[i].estado==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void agregarUsuario(ePersona lista[], int max)
{
    int indice, dni;
    indice = obtenerEspacioLibre(lista, max);
    if(indice>=0)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[indice].nombre);
        printf("Ingrese edad: ");
        scanf("%d", &lista[indice].edad);
        while(lista[indice].edad<0 || lista[indice].edad>125)
        {
            if(lista[indice].edad<0)
            {
                printf("Error. Usted no habia nacido, reingrese la edad: ");

            } else
            {
                printf("Error. Usted es demasiado viejo, reingrese la edad: ");
            }
            scanf("%d", &lista[indice].edad);
        }
        printf("Ingrese DNI: ");
        scanf("%d", &dni);
        while(dni<1000000 || dni>99999999)
        {
            if(dni<1000000)
            {
                printf("Error. Usted ha ingresado pocos digitos, reingrese el DNI: ");

            } else
            {
                printf("Error. Usted ha ingresado demasiados digitos, reingrese el DNI: ");
            }
            scanf("%d", &dni);
        }
        while(verificarDni(lista, max, dni)!=-1)
        {
        printf("Error. Reingrese el DNI: ");
        scanf("%d", &dni);
        }
        lista[indice].dni=dni;
        lista[indice].estado=1;
        system("cls");
        printf("%s ha sido dado de alta con %cxito.\n", lista[indice].nombre, 130);
    } else
    {
        printf("No quedan suficientes espacios libres.\n");
    }
}

int verificarDni(ePersona lista[], int max, int dni)
{
    int i, indice = -1;
    for(i=0; i<max; i++)
    {
        if(lista[i].dni==dni && lista[i].estado==1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void borrarUsuario(ePersona lista[], int max)
{
    int dni, indice, flag=0, i;
    for(i=0; i<max; i++)
    {
        if(lista[i].estado==1)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        imprimirLista(lista, max);
        printf("\nIngrese el DNI del usuario a borrar (0-Volver al Men%c): ", 163);
        scanf("%d", &dni);
        if(dni!=0)
        {
            indice=verificarDni(lista, max, dni);
            while(indice==-1)
            {
                printf("Error. Reingrese el DNI del usuario a borrar (0-Volver al Men%c): ", 163);
                scanf("%d", &dni);
                if(dni==0)
                {
                    break;
                }
                indice=verificarDni(lista, max, dni);
            }
            if(dni==0)
            {
                system("cls");
                printf("Usted ha elegido volver al men%c.\n", 163);
            } else
            {
                lista[indice].estado=0;
                system("cls");
                printf("%s ha sido dado de baja con %cxito.\n", lista[indice].nombre, 130);
            }

        } else
        {
            system("cls");
            printf("Usted ha elegido volver al men%c.\n", 163);
        }
    } else
    {
        printf("Debe agregar al menos un usuario para poder usar esta opci%cn.\n", 162);
    }
}

void ordenarLista(ePersona lista[], int max)
{
    int i, j;

    ePersona aux;

    for(i=0; i<max-1; i++)
    {
        for(j=i+1; j<max; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

void imprimirLista(ePersona lista[], int max)
{
    int i, flag=0;
    for(i=0; i<max; i++)
    {
        if(lista[i].estado==1)
        {
            if(flag == 0)
            {
                flag=1;
                printf("Nombre\t\tEdad\t\tDNI\n");
            }
            if(strlen(lista[i].nombre)>7)
            {
                printf("%s\t", lista[i].nombre);
            } else
            {
                printf("%s\t\t", lista[i].nombre);
            }
            printf("%d\t\t%d\n", lista[i].edad, lista[i].dni);
        }
    }
    if(flag==0)
    {
        printf("Debe agregar al menos un usuario para poder usar esta opci%cn.\n", 162);
    }
}

void imprimirGrafico(ePersona lista[], int max)
{
    int i, j, flag=0, menor=max-1, entre=max-1, mayor=max-1;
    int grafico[max][3];
    for(i=0; i<max; i++)
    {
        for(j=0; j<3; j++)
        {
            grafico[i][j]=0;
        }
    }
    for(i=max-1; i>=0; i--)
    {
        if(lista[i].estado==1)
        {
            if(lista[i].edad<18)
            {
                grafico[menor][0]=1;
                menor--;

            } else
            {
                if(lista[i].edad>35)
                {
                    grafico[mayor][2]=1;
                    mayor--;
                } else
                {
                    grafico[entre][1]=1;
                    entre--;
                }
            }
        }
    }
    for(i=0; i<max; i++)
    {
            if(grafico[i][0]==1 || grafico[i][1]==1 || grafico[i][2]==1)
            {
                if(flag == 0)
                {
                    flag=1;
                }
                if(grafico[i][0]==1)
                {
                    printf(" *");
                }
                printf("\t");
                if(grafico[i][1]==1)
                {
                    printf("  *");
                }
                printf("\t");
                if(grafico[i][2]==1)
                {
                    printf(" *");
                }
                printf("\n");
            }
    }
    if(flag==1)
    {
        printf("<18\t19-35\t>35\n");
    } else
    {
        printf("Debe agregar al menos un usuario para poder usar esta opci%cn.\n", 162);
    }
}

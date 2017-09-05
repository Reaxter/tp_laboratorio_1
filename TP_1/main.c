#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,opUno,opDos,rta,flagUno=0,flagDos=0;

    while(seguir=='s')
    {
        printf("Menu de opciones:\n");
        if(flagUno==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        } else
        {
            printf("1- Ingresar 1er operando (A=%d)\n",opUno);
        }
        if(flagDos==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        } else
        {
            printf("2- Ingresar 2do operando (B=%d)\n",opDos);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");
        printf("Ingrese una opcion: ");
        opcion = getche();
        printf("\n");
        system("pause");
        system("cls");
        switch(opcion)
        {
            case 49:
                printf("Ingrese el 1er operador: ");
                scanf("%d", &opUno);
                printf("El 1er operador fue ingresado correctamente.\n");
                flagUno=1;
                break;
            case 50:
                printf("Ingrese el 2er operador: ");
                scanf("%d", &opDos);
                printf("El 2er operador fue ingresado correctamente.\n");
                flagDos=1;
                break;
            case 51:
                if(flagUno==0 || flagDos==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                    printf("La suma es: %d\n", suma(opUno,opDos));
                }
                break;
            case 52:
                if(flagUno==0 || flagDos==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                    printf("La resta es: %d\n", resta(opUno,opDos));
                }
                break;
            case 53:
                if(flagUno==0 || flagDos==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                    if(opDos==0)
                    {
                        printf("Error. Imposible realizar la division con divisor cero.\n");
                    } else
                    {
                        printf("La division es: %.2f\n", division(opUno,opDos));
                    }
                }
                break;
            case 54:
                if(flagUno==0 || flagDos==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                printf("La multiplicacion es: %d\n", multiplicacion(opUno,opDos));
                }
                break;
            case 55:
                if(flagUno==1 && flagDos==1)
                {
                    if(opUno<0 && opDos<0)
                    {
                        printf("Error. Imposible realizar el factorial de un numero negativo.\n");
                    } else
                    {
                        printf("Cual operador desea utilizar? a-(%d) b-(%d)", opUno, opDos);
                        rta=getch();
                        while(rta!=97 && rta!=98 && rta!=65 && rta!=66)
                        {
                            printf("\nError. Cual operador desea utilizar? a-(%d) b-(%d)", opUno, opDos);
                            rta=getch();
                        }
                        if(rta==97 || rta==65)
                        {
                            if(opUno>=0)
                            {
                                printf("\nEl factorial es: %d\n", factorial(opUno));
                            } else
                            {
                                printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        } else
                        {
                            if(opDos>=0)
                            {
                                printf("\nEl factorial es: %d\n", factorial(opDos));
                            } else
                            {
                                printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        }
                    }
                } else
                {
                    if(flagUno==0 && flagDos==0)
                    {
                        printf("Error. Debe ingresar al menos un operador.\n");
                    } else
                    {
                        if(flagUno==1 && flagDos==0)
                        {
                            if(opUno>=0)
                            {
                                printf("El factorial es: %d\n", factorial(opUno));
                            } else
                            {
                                printf("Error. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        } else
                        {
                            if(opDos>=0)
                            {
                                printf("El factorial es: %d\n", factorial(opDos));
                            } else
                            {
                                printf("Error. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        }
                    }
                }
                break;
            case 56:
                if(flagUno==0 || flagDos==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                    printf("La suma es: %d", suma(opUno,opDos));
                    printf("\nLa resta es: %d", resta(opUno,opDos));
                    if(opDos==0)
                        {
                            printf("\nError. Imposible realizar la division con divisor cero.");
                        } else
                        {
                            printf("\nLa division es: %.2f", division(opUno,opDos));
                        }
                    printf("\nLa multiplicacion es: %d", multiplicacion(opUno,opDos));
                    if(opUno<0 && opDos<0)
                    {
                        printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                    } else
                    {
                        printf("\nCual operador desea utilizar? a-(%d) b-(%d)", opUno, opDos);
                        rta=getch();
                        while(rta!=97 && rta!=98 && rta!=65 && rta!=66)
                        {
                            printf("\nError. Cual operador desea utilizar? a-(%d) b-(%d)", opUno, opDos);
                            rta=getch();
                        }
                        if(rta==97 || rta==65)
                        {
                            if(opUno>=0)
                            {
                                printf("\nEl factorial es: %d\n", factorial(opUno));
                            } else
                            {
                                printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        } else
                        {
                            if(opDos>=0)
                            {
                                printf("\nEl factorial es: %d\n", factorial(opDos));
                            } else
                            {
                                printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        }
                    }
                }
                break;
            case 57:
                seguir = 'n';
                break;
            default:
                printf("Error. Reingrese una opcion correcta (1-9)\n");
                break;
        }
        if(seguir=='s')
        {
            system("pause");
            system("cls");
        }
    }
    printf("Gracias por haber usado esta calculadora.");
    return 0;
}

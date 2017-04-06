#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,n1,n2,rta,flag1=0,flag2=0;

    while(seguir=='s')
    {
        printf("Elija una de las siguientes opciones:\n");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        opcion=getch();
        while(opcion<49 || opcion>57)
        {
            system("cls");
            printf("Error. Opcion inexistente. Vuelva a elegir:\n");
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");
            opcion=getch();
        }
        system("cls");
        switch(opcion)
        {
            case 49:
                printf("Ingrese el 1er operador: ");
                scanf("%d", &n1);
                printf("El 1er operador es: %d\n", n1);
                flag1=1;
                break;
            case 50:
                printf("Ingrese el 2er operador: ");
                scanf("%d", &n2);
                printf("El 2er operador es: %d\n", n2);
                flag2=1;
                break;
            case 51:
                if(flag1==0 || flag2==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                    printf("La suma es: %d\n", suma(n1,n2));
                }
                break;
            case 52:
                if(flag1==0 || flag2==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                    printf("La resta es: %d\n", resta(n1,n2));
                }
                break;
            case 53:
                if(flag1==0 || flag2==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                    if(n2==0)
                    {
                        printf("Error. Imposible realizar la division con divisor cero.\n");
                    } else
                    {
                        printf("La division es: %.2f\n", division(n1,n2));
                    }
                }
                break;
            case 54:
                if(flag1==0 || flag2==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                printf("La multiplicacion es: %d\n", multiplicacion(n1,n2));
                }
                break;
            case 55:
                if(flag1==1 && flag2==1)
                {
                    if(n1<0 && n2<0)
                    {
                        printf("Error. Imposible realizar el factorial de un numero negativo.\n");
                    } else
                    {
                        printf("Cual operador desea utilizar? a-(%d) b-(%d)", n1, n2);
                        rta=getch();
                        while(rta!=97 && rta!=98 && rta!=65 && rta!=66)
                        {
                            printf("\nError. Cual operador desea utilizar? a-(%d) b-(%d)", n1, n2);
                            rta=getch();
                        }
                        if(rta==97 || rta==65)
                        {
                            if(n1>=0)
                            {
                                printf("\nEl factorial es: %d\n", factorial(n1));
                            } else
                            {
                                printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        } else
                        {
                            if(n2>=0)
                            {
                                printf("\nEl factorial es: %d\n", factorial(n2));
                            } else
                            {
                                printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        }
                    }
                } else
                {
                    if(flag1==0 && flag2==0)
                    {
                        printf("Error. Debe ingresar al menos un operador.\n");
                    } else
                    {
                        if(flag1==1 && flag2==0)
                        {
                            if(n1>=0)
                            {
                                printf("El factorial es: %d\n", factorial(n1));
                            } else
                            {
                                printf("Error. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        } else
                        {
                            if(n2>=0)
                            {
                                printf("El factorial es: %d\n", factorial(n2));
                            } else
                            {
                                printf("Error. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        }
                    }
                }
                break;
            case 56:
                if(flag1==0 || flag2==0)
                {
                    printf("Error. Debe ingresar ambos operadores.\n");
                } else
                {
                    printf("La suma es: %d", suma(n1,n2));
                    printf("\nLa resta es: %d", resta(n1,n2));
                    if(n2==0)
                        {
                            printf("\nError. Imposible realizar la division con divisor cero.");
                        } else
                        {
                            printf("\nLa division es: %.2f", division(n1,n2));
                        }
                    printf("\nLa multiplicacion es: %d", multiplicacion(n1,n2));
                    if(n1<0 && n2<0)
                    {
                        printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                    } else
                    {
                        printf("\nCual operador desea utilizar? a-(%d) b-(%d)", n1, n2);
                        rta=getch();
                        while(rta!=97 && rta!=98 && rta!=65 && rta!=66)
                        {
                            printf("\nError. Cual operador desea utilizar? a-(%d) b-(%d)", n1, n2);
                            rta=getch();
                        }
                        if(rta==97 || rta==65)
                        {
                            if(n1>=0)
                            {
                                printf("\nEl factorial es: %d\n", factorial(n1));
                            } else
                            {
                                printf("\nError. Imposible realizar el factorial de un numero negativo.\n");
                            }
                        } else
                        {
                            if(n2>=0)
                            {
                                printf("\nEl factorial es: %d\n", factorial(n2));
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

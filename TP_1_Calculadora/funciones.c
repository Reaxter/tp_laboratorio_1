#include "funciones.h"

/** \brief Obtiene dos operadores y realiza una suma
 *
 * \param int a Primer operador
 * \param int b Segundo operador
 * \return resultado Retorna el resultado de la suma del primer operador mas el segundo operador
 *
 */
int suma(int a, int b)
{
    int resultado;
    resultado=a+b;
    return resultado;
}

/** \brief Obtiene dos operadores y realiza una resta
 *
 * \param int a Primer operador
 * \param int b Segundo operador
 * \return resultado Retorna el resultado de la resta del primer operador menos el segundo operador
 *
 */
int resta(int a, int b)
{
    int resultado;
    resultado=a-b;
    return resultado;
}

/** \brief Obtiene dos operadores y realiza una division
 *
 * \param int a Primer operador (dividendo)
 * \param int b Segundo operador (divisor)
 * \return resultado Retorna el resultado de la division entre el primer operador dividido el segundo operador
 *
 */
float division(int a, int b)
{
    float resultado;
    resultado=(float)a/b;
    return resultado;
}

/** \brief Obtiene dos operadores y realiza una multiplicacion
 *
 * \param int a Primer operador
 * \param int b Segundo operador
 * \return resultado Retorna la multiplicacion resultado del primer operador por el segundo operador
 *
 */
int multiplicacion(int a, int b)
{
    int resultado;
    resultado=a*b;
    return resultado;
}

/** \brief Obtiene un operador y realiza un factorial
 *
 * \param int a Operador
 * \return resultado Retorna el factorial resultado del operador
 *
 */
int factorial(int a)
{
    int resultado=1, x;
    for(x=a;x>1;x--)
    {
        resultado*=x;
    }
    return resultado;
}


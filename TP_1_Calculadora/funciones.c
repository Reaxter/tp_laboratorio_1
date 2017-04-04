#include "funciones.h"

/** \brief Obtiene dos operadores recibidos como parámetros
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

/** \brief Obtiene dos operadores recibidos como parámetros
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

/** \brief Obtiene dos operadores recibidos como parámetros
 *
 * \param int a Primer operador (numerador)
 * \param int b Segundo operador (denominador)
 * \return resultado Retorna el resultado resultado de de la division entre el numerador y denominador
 *
 */
float division(int a, int b)
{
    float resultado;
    resultado=(float)a/b;
    return resultado;
}

/** \brief Obtiene dos operadores recibidos como parámetros
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

/** \brief Obtiene un operador recibido como parámetros
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


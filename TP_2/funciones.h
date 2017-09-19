#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Inicializa el estado en cero del array pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño total del array que se pasa como parametro.
 */
void inicializarLista(ePersona lista[], int max);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tamaño total del array que se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int max);

/**
 * Da de alta a un usuario en el array pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño total del array que se pasa como parametro.
 */
void agregarUsuario(ePersona lista[], int max);

/**
 * Verifica el indice del dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño total del array que se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int verificarDni(ePersona lista[], int max,int dni);

/**
 * Da de baja a un usuario elegido del array pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño total del array que se pasa como parametro.
 */
void borrarUsuario(ePersona lista[], int max);

/**
 * Ordena por nombre el array pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño total del array que se pasa como parametro.
 */
void ordenarLista(ePersona lista[], int max);

/**
 * Imprime un listado del array pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño total del array que se pasa como parametro.
 */
void imprimirLista(ePersona lista[], int max);

/**
 * Imprime un grafico de edades del array pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño total del array que se pasa como parametro.
 */
void imprimirGrafico(ePersona lista[], int max);

#endif // FUNCIONES_H_INCLUDED

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}eMovie;

/**
 *  Agrega una pelicula al archivo binario
 */
void agregarPelicula(void);

/**
 *  Borra una pelicula del archivo binario
 */
void borrarPelicula(void);

/**
 *  Modifica una pelicula del archivo binario
 */
void modificarPelicula(void);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 */
void generarPagina(void);

#endif // FUNCIONES_H_INCLUDED

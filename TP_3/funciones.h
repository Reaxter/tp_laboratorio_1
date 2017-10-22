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
 *  @param movie la estructura a ser usada como almacen temporales de la pelicula
 */
void agregarPelicula(eMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser usada como almacen temporales de las peliculas
 */
void borrarPelicula(eMovie movie);

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser usada como almacen temporales de las peliculas
 */
void modificarPelicula(eMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movie la estructura a ser usada como almacen temporales de las peliculas
 */
void generarPagina(eMovie movie);

#endif // FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void agregarPelicula(void)
{
    FILE  *pArchivo;
	eMovie pPelicula;
	if((pArchivo=fopen("peliculas.bin","rb+"))==NULL)
    {
        fclose(pArchivo);
        pArchivo=fopen("peliculas.bin","wb");
    }
	fseek ( pArchivo , 0L , SEEK_END );
	printf("Ingrese el titulo de la pelicula: ");
    gets(pPelicula.titulo);
    printf("Ingrese el genero de la pelicula: ");
    gets(pPelicula.genero);
    printf("Ingrese la duracion de la pelicula: ");
	scanf("%d",&pPelicula.duracion);
	fflush(stdin);
    printf("Ingrese la descripcion de la pelicula: ");
    gets(pPelicula.descripcion);
    printf("Ingrese el puntaje de la pelicula: ");
	scanf("%d",&pPelicula.puntaje);
	fflush(stdin);
    printf("Ingrese el link de la pelicula: ");
    gets(pPelicula.linkImagen);
    fflush(stdin);
	fwrite(&pPelicula,sizeof(eMovie),1,pArchivo);
    fclose(pArchivo);
    system("cls");
    printf("Se ha agregado una pelicula exitosamente.\n");
}

void borrarPelicula(void)
{
    FILE  *pArchivo, *pAux;
	eMovie pPelicula;
	char titulo[20];
	int flag=0;
	int cant;
	printf("Ingrese el titulo de la pelicula: ");
	gets(titulo);
	pArchivo=fopen("peliculas.bin","rb+");
	pAux=fopen("temporal.bin","wb");
	while(!feof(pArchivo))
    {
        cant=fread(&pPelicula,sizeof(eMovie),1,pArchivo);
        if(cant!=1)
        {
            if(feof(pArchivo))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        if(strcmp(titulo, pPelicula.titulo) == 0)
        {
            flag=1;
        }
        else
        {
            fwrite(&pPelicula,sizeof(eMovie),1,pAux);
        }
    }
    fclose(pAux);
    fclose(pArchivo);
    pArchivo=fopen("peliculas.bin","wb");
	pAux=fopen("temporal.bin","rb+");
    while(!feof(pAux))
    {
        cant=fread(&pPelicula,sizeof(eMovie),1,pAux);
        if(cant!=1)
        {
            if(feof(pAux))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
            fwrite(&pPelicula,sizeof(eMovie),1,pArchivo);
    }
    if(flag==0)
    {
        system("cls");
        printf("No se ha encontrado el titulo ingresado.\n");
    }
    else
    {
        system("cls");
        printf("Se ha borrado el titulo ingresado.\n");
    }

    fclose(pAux);
    fclose(pArchivo);
    remove("temporal.bin");
}

void modificarPelicula(void)
{
    FILE  *pArchivo, *pAux;
	eMovie pPelicula;
	char titulo[20];
	int flag=0;
	int cant;
	printf("Ingrese el titulo de la pelicula: ");
	gets(titulo);
	pArchivo=fopen("peliculas.bin","rb+");
	pAux=fopen("temporal.bin","wb");
	while(!feof(pArchivo))
    {
        cant=fread(&pPelicula,sizeof(eMovie),1,pArchivo);
        if(cant!=1)
        {
            if(feof(pArchivo))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        if(strcmp(titulo, pPelicula.titulo) == 0)
        {
            flag=1;
            system("cls");
            printf("Ingrese el titulo de la pelicula: ");
            gets(pPelicula.titulo);
            printf("Ingrese el genero de la pelicula: ");
            gets(pPelicula.genero);
            printf("Ingrese la duracion de la pelicula: ");
            scanf("%d",&pPelicula.duracion);
            fflush(stdin);
            printf("Ingrese la descripcion de la pelicula: ");
            gets(pPelicula.descripcion);
            printf("Ingrese el puntaje de la pelicula: ");
            scanf("%d",&pPelicula.puntaje);
            fflush(stdin);
            printf("Ingrese el link de la pelicula: ");
            gets(pPelicula.linkImagen);
            fflush(stdin);
            fwrite(&pPelicula,sizeof(eMovie),1,pAux);
        }
        else
        {
            fwrite(&pPelicula,sizeof(eMovie),1,pAux);
        }
    }
    fclose(pAux);
    fclose(pArchivo);
    pArchivo=fopen("peliculas.bin","wb");
	pAux=fopen("temporal.bin","rb+");
    while(!feof(pAux))
    {
        cant=fread(&pPelicula,sizeof(eMovie),1,pAux);
        if(cant!=1)
        {
            if(feof(pAux))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
            fwrite(&pPelicula,sizeof(eMovie),1,pArchivo);
    }
    if(flag==0)
    {
        system("cls");
        printf("No se ha encontrado el titulo ingresado.\n");
    }
    else
    {
        system("cls");
        printf("Se ha modificado el titulo ingresado.\n");
    }

    fclose(pAux);
    fclose(pArchivo);
    remove("temporal.bin");
}

void generarPagina(void)
{
    FILE  *pArchivo, *pHtml;
	eMovie pPelicula;
	int cant;
	int flag=0;

	char buffer[1080] = {};
	char numeros[4] = {};

	pHtml=fopen("peliculas.html","w");
	strcpy(buffer, "<H1>Lista De Peliculas:</H1></br>");
    fwrite(&buffer,sizeof(buffer),1,pHtml);
	fclose(pHtml);

	pArchivo=fopen("peliculas.bin","rb");
	pHtml=fopen("peliculas.html","a");
	while(!feof(pArchivo))
    {
        cant=fread(&pPelicula,sizeof(eMovie),1,pArchivo);
        if(cant!=1)
        {
            if(feof(pArchivo))
            {

                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        flag=1;
        strcpy(buffer, "<table style='width:100%'><img class='img-responsive img-rounded' src='");
        strcat(buffer, pPelicula.linkImagen);
        strcat(buffer,"' alt=''><h3>");
        strcat(buffer, pPelicula.titulo);
        strcat(buffer, "</h3><ul><li>Género:");
        strcat(buffer, pPelicula.genero);
        strcat(buffer, "</li><li>Puntaje:");
        sprintf(numeros, "%d", pPelicula.puntaje);
        strcat(buffer, numeros);
        strcat(buffer, "</li><li>Duración:");
        sprintf(numeros, "%d", pPelicula.duracion);
        strcat(buffer, numeros);
        strcat(buffer, "</li></ul><p>");
        strcat(buffer, pPelicula.descripcion);
        strcat(buffer, "</p></table>");
        fwrite(&buffer,sizeof(buffer),1,pHtml);

    }
    fclose(pHtml);
    fclose(pArchivo);
    if(flag==0)
    {
        system("cls");
        printf("Error, debe agregar al menos una pelicula.\n");
        remove("peliculas.html");
    }
    else
    {
        system("cls");
        printf("Se ha generado el archivo peliculas.html\n");
    }
}

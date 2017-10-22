#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void agregarPelicula(eMovie this)
{
    FILE  *pArchivo;
    char titulo[20];
    int flag=0;
	if((pArchivo=fopen("peliculas.bin","rb+"))==NULL)
    {
        fclose(pArchivo);
        pArchivo=fopen("peliculas.bin","wb");
        printf("Ingrese el titulo de la pelicula: ");
        gets(titulo);
    }
    else
    {
        printf("Ingrese el titulo de la pelicula: ");
        gets(titulo);
        fseek ( pArchivo , 0L , SEEK_SET );
        while(!feof(pArchivo))
        {
            if((fread(&this,sizeof(eMovie),1,pArchivo))!=1)
            {
                if(feof(pArchivo) && flag==0)
                    break;
                else
                {
                    flag=0;
                    fseek ( pArchivo , 0L , SEEK_SET );
                }
            }
            while(strcmp(titulo, this.titulo) == 0)
            {
                flag=1;
                printf("Error. Reingrese el titulo de la pelicula: ");
                gets(titulo);
            }
        }
    }
    fseek ( pArchivo , 0L , SEEK_END );
    strcpy(this.titulo, titulo);
    printf("Ingrese el genero de la pelicula: ");
    gets(this.genero);
    printf("Ingrese la duracion de la pelicula: ");
	scanf("%d",&this.duracion);
	fflush(stdin);
    printf("Ingrese la descripcion de la pelicula: ");
    gets(this.descripcion);
    printf("Ingrese el puntaje de la pelicula: ");
	scanf("%d",&this.puntaje);
	fflush(stdin);
    printf("Ingrese el link de la pelicula: ");
    gets(this.linkImagen);
    fflush(stdin);
	fwrite(&this,sizeof(eMovie),1,pArchivo);
    fclose(pArchivo);
    system("cls");
    printf("Se ha agregado una pelicula exitosamente.\n");
}

void borrarPelicula(eMovie this)
{
    FILE  *pArchivo, *pAux;
	char titulo[20];
	int flag=0;
	printf("Ingrese el titulo de la pelicula a borrar: ");
	gets(titulo);
	pArchivo=fopen("peliculas.bin","rb+");
	pAux=fopen("temporal.bin","wb");
	while(!feof(pArchivo))
    {
        if((fread(&this,sizeof(eMovie),1,pArchivo))!=1)
        {
            if(feof(pArchivo))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        if(strcmp(titulo, this.titulo) == 0)
        {
            flag=1;
        }
        else
        {
            fwrite(&this,sizeof(eMovie),1,pAux);
        }
    }
    fclose(pAux);
    fclose(pArchivo);
    pArchivo=fopen("peliculas.bin","wb");
	pAux=fopen("temporal.bin","rb+");
    while(!feof(pAux))
    {
        if((fread(&this,sizeof(eMovie),1,pAux))!=1)
        {
            if(feof(pAux))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
            fwrite(&this,sizeof(eMovie),1,pArchivo);
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

void modificarPelicula(eMovie this)
{
    FILE  *pArchivo, *pAux, *pCopia;
	char titulo[20], auxTitulo[20];
	int flag=0, flag2=0;
	printf("Ingrese el titulo de la pelicula a modificar: ");
	gets(titulo);
	strcpy(auxTitulo, titulo);
	pArchivo=fopen("peliculas.bin","rb+");
	pAux=fopen("temporal.bin","wb");
	pCopia=fopen("copia.bin","wb");
	while(!feof(pArchivo))
    {
        if((fread(&this,sizeof(eMovie),1,pArchivo))!=1)
        {
            if(feof(pArchivo))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
            fwrite(&this,sizeof(eMovie),1,pCopia);
    }
    fclose(pCopia);
    pCopia=fopen("copia.bin","rb+");
    fseek ( pArchivo , 0L , SEEK_SET );
	while(!feof(pArchivo))
    {
        if((fread(&this,sizeof(eMovie),1,pArchivo))!=1)
        {
            if(feof(pArchivo))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        if(strcmp(titulo, this.titulo) == 0)
        {
            flag=1;
            system("cls");
            printf("Ingrese el titulo de la pelicula: ");
            gets(titulo);
            fseek ( pCopia , 0L , SEEK_SET );
            while(!feof(pCopia))
            {
                if((fread(&this,sizeof(eMovie),1,pCopia))!=1)
                {
                    if(feof(pCopia) && flag2==0)
                        break;
                    else
                    {
                        flag2=0;
                        fseek ( pCopia , 0L , SEEK_SET );
                    }
                }
                while(strcmp(titulo, this.titulo) == 0)
                {
                    if (strcmp(titulo, auxTitulo) == 0)
                    {
                        break;
                    }
                    else
                    {
                        flag2=1;
                        printf("Error. Reingrese el titulo de la pelicula a modificar: ");
                        gets(titulo);
                    }
                }
            }
            strcpy(this.titulo, titulo);
            printf("Ingrese el genero de la pelicula: ");
            gets(this.genero);
            printf("Ingrese la duracion de la pelicula: ");
            scanf("%d",&this.duracion);
            fflush(stdin);
            printf("Ingrese la descripcion de la pelicula: ");
            gets(this.descripcion);
            printf("Ingrese el puntaje de la pelicula: ");
            scanf("%d",&this.puntaje);
            fflush(stdin);
            printf("Ingrese el link de la pelicula: ");
            gets(this.linkImagen);
            fflush(stdin);
            fwrite(&this,sizeof(eMovie),1,pAux);
        }
        else
        {
            fwrite(&this,sizeof(eMovie),1,pAux);
        }
    }
    fclose(pCopia);
    fclose(pAux);
    fclose(pArchivo);
    pArchivo=fopen("peliculas.bin","wb");
	pAux=fopen("temporal.bin","rb+");
    while(!feof(pAux))
    {
        if((fread(&this,sizeof(eMovie),1,pAux))!=1)
        {
            if(feof(pAux))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
            fwrite(&this,sizeof(eMovie),1,pArchivo);
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
    remove("copia.bin");
}

void generarPagina(eMovie this)
{
    FILE  *pArchivo, *pHtml;
	int flag=0;
	pHtml=fopen("peliculas.html","w");
	fprintf(pHtml, "<html>\n<H1>Lista De Peliculas:</H1></br>");
	fclose(pHtml);
	if((pArchivo=fopen("peliculas.bin","rb"))==NULL)
    {
        fclose(pArchivo);
        pArchivo=fopen("peliculas.bin","wb");
        fclose(pArchivo);
        pArchivo=fopen("peliculas.bin","rb");
    }
	pHtml=fopen("peliculas.html","a");
	while(!feof(pArchivo))
    {
        if((fread(&this,sizeof(eMovie),1,pArchivo))!=1)
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
        fprintf(pHtml, "\n\t<article class='col-md-4 article-intro'>\n\t\t<a href='#'>\n\t\t\t<img class='img-responsive img-rounded' src='%s' alt=''>\n\t\t</a>\n\t\t<h3>\n\t\t\t<a href='#'>%s</a>\n\t\t</h3>\n\t\t<ul>\n\t\t\t<li>Género:%s</li>\n\t\t\t<li>Puntaje:%d</li>\n\t\t\t<li>Duración:%d</li>\n\t\t</ul>\n\t<p>%s</p>\n\t</article>", this.linkImagen,this.titulo,this.genero,this.puntaje,this.duracion,this.descripcion);
    }
    fprintf(pHtml, "\n</html>");
    fclose(pHtml);
    fclose(pArchivo);
    if(flag==0)
    {
        system("cls");
        printf("Error, debe agregar al menos una pelicula.\n");
        remove("peliculas.html");
        remove("peliculas.bin");
    }
    else
    {
        system("cls");
        printf("Se ha generado el archivo peliculas.html\n");
    }
}

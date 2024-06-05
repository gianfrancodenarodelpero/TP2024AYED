#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdbool.h>

typedef struct Lista Lista;

Lista* crearLista();

int getTamanioLista(Lista*);
//mostrar lista
void mostrarLista(Lista*, void callback(void*));
//insertar datos a la lista
void insertarDatoAlInicioEnLaLista(Lista*, void*);
bool insertarDatoEnLaLista(Lista*, int, void*);
void insertarDatoAlFinalDeLaLista(Lista*, void*);
void insertarDatoEnOrdenEnLista(Lista*, void*, bool callback(void*, void*));
//obtener datos de la lista
void* obtenerDatoInicialDeLaLista(Lista*);
void* obtenerDatoEnLaLista(Lista*, int);
void* obtenerDatoFinalDeLaLista(Lista*);
//eliminar datos de la lista
void* eliminarDatoInicialDeLaLista(Lista*);
void* eliminarDatoDeLaLista(Lista*, int);
void* eliminarDatoFinalDeLaLista(Lista*);
//duplicar lista
Lista* duplicar(Lista*);
//ordenar lista
void ordenarLista(Lista*, bool callback(void*, void*));
//buscar dato
int buscarDato(Lista*, void*, bool callback(void*, void*));
//eliminar lista
void destruirLista(Lista*);
void destruirListaYDatos(Lista*, void callback(void*));



#endif // LISTA_H_INCLUDED

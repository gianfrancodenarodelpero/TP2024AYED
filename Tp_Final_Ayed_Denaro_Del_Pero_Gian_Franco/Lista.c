#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct Nodo {
    void* dato;
    struct Nodo* siguiente;
} Nodo;

struct Lista {
    Nodo* inicial;
    int tamanioLista;
};

Lista* crearLista(){
    return (Lista*)calloc(1, sizeof(Lista));
}

int getTamanioLista(Lista* l){
    return l->tamanioLista;
}

void mostrarLista(Lista* l, void callback(void*)){
    int tam = l->tamanioLista;
    for(int i=0; i<tam; i++){
        callback(obtenerDatoEnLaLista(l, i));
    }
}

void insertarDatoAlInicioEnLaLista(Lista* l, void* d){
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));

    n->dato = d;
    n->siguiente = l->inicial;
    l->inicial = n;

    l->tamanioLista++;
}

bool insertarDatoEnLaLista(Lista* l, int pos, void* d){
    bool bInsertado = false;

    if(pos >= 0 && pos <= l->tamanioLista){

        if(pos == 0){
            insertarDatoAlInicioEnLaLista(l, d);
            bInsertado = true;
        } else {
            Nodo* n = (Nodo*)malloc(sizeof(Nodo));
            n->dato = d;
            Nodo* actual = l->inicial;

            for(int i=0; i<pos-1; i++)
                actual = actual->siguiente;

            n->siguiente = actual->siguiente;
            actual->siguiente = n;
            bInsertado = true;
            l->tamanioLista++;
        }

    }

    return bInsertado;
}

void insertarDatoAlFinalDeLaLista(Lista* l, void* d){
    insertarDatoEnLaLista(l, l->tamanioLista, d);
}

void insertarDatoEnOrdenEnLista(Lista* l, void* d, bool callback(void*, void*)){
    Nodo* actual = l->inicial;
    Nodo* anterior = NULL;

    while(actual != NULL && callback(actual->dato, d)){
        anterior = actual;
        actual = anterior->siguiente;
    }

    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->siguiente = actual;
    if(anterior == NULL){
        l->inicial = nuevo;
    } else {
        anterior->siguiente = nuevo;
    }

    l->tamanioLista++;
}


void* obtenerDatoInicialDeLaLista(Lista* l){
    return l->inicial->dato;
}

void* obtenerDatoEnLaLista(Lista* l, int pos){
    void * d = NULL;

    if(pos >= 0 && pos < l->tamanioLista){
        Nodo* actual = l->inicial;

        for(int i=0; i<pos; i++)
            actual = actual->siguiente;

        d = actual->dato;
    }

    return d;
}

void* obtenerDatoFinalDeLaLista(Lista* l){
    return obtenerDatoEnLaLista(l, l->tamanioLista-1);
}

void* eliminarDatoInicialDeLaLista(Lista* l){
    Nodo* eliminar = l->inicial;
    void* d = eliminar->dato;
    l->inicial = eliminar->siguiente;
    free(eliminar);
    l->tamanioLista--;

    return d;
}

void* eliminarDatoDeLaLista(Lista* l, int pos){
    void* d = NULL;

    if(pos >= 0 && pos<l->tamanioLista){
        Nodo* actual = l->inicial;
        Nodo* anterior = NULL;

        for(int i=0; i<pos; i++){
            anterior = actual;
            actual = actual->siguiente;
        }

        d = actual->dato;
        if(anterior == NULL){
            l->inicial = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }

        free(actual);
        l->tamanioLista--;
    }

    return d;
}

void* eliminarDatoFinalDeLaLista(Lista* l){
    return eliminarDatoDeLaLista(l, l->tamanioLista-1);
}

Lista* duplicar(Lista* l){
    Lista* l2 = crearLista();
    int tam = l->tamanioLista;

    for(int i=0; i<tam; i++)
        insertarDatoAlFinalDeLaLista(l2, obtenerDatoEnLaLista(l, i));

    return l2;
}

void ordenarLista(Lista* l, bool callback(void*, void*)){
    int tam = l->tamanioLista;
    void* d1;
    void* d2;

    for(int i=0; i<tam;i++){
        for(int j=i+1; j<tam; j++){
            d1 = obtenerDatoEnLaLista(l, i);
            d2 = obtenerDatoEnLaLista(l, j);

            if(callback(d1, d2)){
                insertarDatoEnLaLista(l, j, d1);
                insertarDatoEnLaLista(l, i, d2);

                eliminarDatoDeLaLista(l, i+1);
                eliminarDatoDeLaLista(l, j+1);
            }
        }
    }
}

int buscarDato(Lista* l,void* d, bool callback(void*, void*)){
    int posicion = -1, contador = 0;
    Nodo* actual = l->inicial;

    while(actual != NULL && posicion == -1){

        if(callback(actual->dato, d))
            posicion = contador;

        actual = actual->siguiente;
        contador++;
    }

    return posicion;
}

void destruirLista(Lista* l){
    while(l->tamanioLista > 0)
        eliminarDatoInicialDeLaLista(l);

    free(l);
}

void destruirListaYDatos(Lista* l, void callback(void*)){
    while(l->tamanioLista > 0)
        callback(eliminarDatoInicialDeLaLista(l));

    free(l);
}

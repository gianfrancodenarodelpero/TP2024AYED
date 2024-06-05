#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


typedef struct Nodo {
    void* dato;
    struct Nodo* siguiente;
} Nodo;

struct Lista{
    Nodo* incial;
    int tamanioLista;
};



lista crearLista(){
return (lista*)calloc(1,sizeof(lista));
};

int getTamanio(lista* l){
    return l->tamanioLista;
};

//mostrar lista
void mostrarLista(lista* l , void callback (void*)){
    int tam = l->tamanioLista;
    for(int i=0; i<tam; i++){
        callback(obtenerDatoEnLaLista(l,i));
    }
};


//eliminar lista
void eliminarLista(lista* l){
    while(l->tamanioLista >0)
        eliminarDatoDeLaLista(l);
    free(l);
};



void destruirListaYDatos(lista* l, void callback(void*)){
    while(l->tamanioLista >0){
        callback(eliminarDatoInicialDeLaLista(l));
    }
    free(l);
};


//insertar datos a la lista

void insertarDatoAlInicioEnLaLista(lista* l, void* d){
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    n->dato = d;
    n->siguiente = l->inicial;
    l->tamanioLista++;

};

bool insertarDatoEnLaLista(lista* l, int pos, void* d){
    bool bInsertado = false;
    if(pos >= 0 && pos <= l->tamanio);
};
void insertarDatoAlFinalDeLaLista(lista* l, void* d){
    insertarDatoEnLaLista(l,l->tamanioLista,d);
};
void insertarDatoEnOrdenEnLista(lista* l, void* d, bool callback(void*, void*)){
    Nodo* actual = l->actual;
    Nodo* anterior = NULL;

    while(actual != NULL && callback(actual->dato,d)){
        anterior = actual;
        actual = anterior->siguiente;
    }

    Nodo* nuevo = (nodo*)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->siguiente = actual;
    if(anterior==NULL){
        l->inicial = nuevo;
    }else{
        anterior->siguiente = nuevo;
    }

    l->tamanioLista++;
};

//obtener datos de la lista
void* obtenerDatoInicialDeLaLista(lista* l){
    return l->incial->dato;
};

void* obtenerDatoEnLaLista(lista* l, int pos){
    void * d = NULL;

    if(pos>= 0 && pos < l->tamanioLista){
        Nodo* actual = l->inicial;

        for(int i=0; i<pos; i++){
            actual = actual->siguiente;


           }
            d=actual->dato;
        }
        return d;
};

void* obtenerDatoFinalDeLaLista(lista* l){
    return obtenerDatoEnLaLista(l,l->tamanioLista-1);
};

//eliminar datos de la lista
void* eliminarDatoInicialDeLaLista(lista* l){
    nodo* eliminar = l->inicial;
    void * d = eliminar->dato;
    l->inicial = eliminar->siguiente;
    free(eliminar);
    l->tamanioLista--;

    return d;
};

void* eliminarDatoDeLaLista(lista* l, int pos){
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
};
void* eliminarDatoFinalDeLaLista(lista* l){
    return eliminarDatoDeLaLista(l, l->tamanioLista-1);
};


//duplicar lista
lista* duplicar(lista* l){
 Lista *l2 = crearLista();
 int tam = l->tamanioLista;

 for(int i=0; i<tam ; i++){
    insertarDatoAlFinalDeLaLista(l2 , obtenerDatoEnLaLista(l ,i));
 }
 return l2;
};

//ordenamiento
void ordenarLista(lista* l, bool callback(void*, void*)){
    int tam= l->tamanioLista;
    void* d1;
    void* d2;

    for(int i=0; i<tam; i++){
        for(int j=0; j<tam;j++){
            d1 = obtenerDatoEnLaLista(l, i);
            d2 = obtenerDatoEnLaLista(j, i);

            if(callback(d1 , d2)){
                insertarDatoEnLaLista(l,j,d1);
                insertarDatoEnLaLista(l,i,d2);

                eliminarDatoDeLaLista(l, i+1);
                eliminarDatoDeLaLista(l, j+1);
            }
        }
    }

};


// Buscar datos

int buscarDato(lista* l, void* d, bool callback(void*, void*)){
    int posicion = -1 , contador =0;
    Nodo* actual = l->inicial;

    while(actual != NULL && posicion == -1){
        if(callback(actual->dato , d)){
            posicion = contador;
        }
        actual= actual->siguiente;
        contador++;
    }
    return posicion;
};



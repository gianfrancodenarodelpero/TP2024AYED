#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaMaterias.h"


struct Materia{
    int id;
    char nombre[45];
    int cupo;
};

//crea una materia
Materia* crearMateria(int id, char nombre[45]){
    Materia* m = (Materia*)malloc(sizeof(Materia));

    m->id = id;
    strcpy(m->nombre, nombre);

    return m;
}
//mostrar materia
void mostrarMateria(Materia* m){
    printf("ID: %d\n", m->id);
    printf("Nombre: %s\n", m->nombre);
}
//getter y setter
int getIdMateria(Materia* m){
    return m->id;
}

const char* getNombreMateria(Materia* m){
    return m->nombre;
}

int getCupo(Materia* m){
    return m->cupo;
};
void setNombreMateria(Materia* m, char nombre[45]){
    strcpy(m->nombre, nombre);
}

void setCupo(Materia* m , int nuevoCupo){
    m->cupo = nuevoCupo;
};
//Elimina materia
void destruirMateria(Materia* m){
    free(m);
}

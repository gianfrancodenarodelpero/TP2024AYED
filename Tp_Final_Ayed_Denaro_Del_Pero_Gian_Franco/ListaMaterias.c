#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaMaterias.h"

struct Materias{
    int id;
    char nombre[30];
    int cupo = 100;
};



//crea una materia
Materias* crearMateria(int id ,char nombre[30] , int cupo;){
    Materias* m = (Materias*)malloc(sizeof(Materias));
    m->id = id;
    strcpy(m->nombre,nombre);
    m->cupo = cupo-1;

    return m;
};

//mostrar materia
void mostrarMateria(materia* m){
    printf("ID: %d\n",m->id);
    printf("Nombre: %s\n",m->nombre);
    printf("Cupo: %d\n",m->cupo);
};

//getter y setter
int getId (materia* m){
    return m->id;
};

char * getNombre (materia* m){
    return m->nombre;
};
int getCupo(materia* m){
    return m->cupo;
};


void setId (materia* m, int nuevoId){
    m->id = nuevoId;;
};
void setNombre (materia* m , char nuevoNombre[30]){
    strcpy(m->nombre , nombre);
};
void setCupo(materia* m, int nuevoCupo){
    m->cupo = nuevoCupo;
};


//Elimina materia
void EliminarMateria(materia* m){
    free(m);
};

#include <stdio.h>
#include <stdlib.h>

#include "MateriaNota.h"

struct MateriaNota{
    Materia* materia;
    int nota;
};

MateriaNota* crearMateriaNota(Materia* m, int nota){
    MateriaNota* mn = (MateriaNota*)malloc(sizeof(MateriaNota));

    mn->materia = m;
    mn->nota = nota;

    return mn;
}

void mostrarMateriaNota(MateriaNota* m){
    mostrarMateria(m->materia);
    printf("Calificacion: %d\n", m->nota);
}

int getIdMateriaNota(MateriaNota* m){
    return getIdMateria(m->materia);
}

const char* getNombreMateriaNota(MateriaNota* m){
    return getNombreMateria(m->materia);
}

int getNota(MateriaNota* m){
    return m->nota;
}

void setNotaMateriaNota(MateriaNota* m, int n){
    m->nota = n;
}

void destruirMateriaNota(MateriaNota* m){
    free(m);
}

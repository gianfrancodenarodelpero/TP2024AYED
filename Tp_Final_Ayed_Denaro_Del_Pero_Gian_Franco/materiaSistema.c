#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MateriaSistema.h"
#include "Sistema.h"

struct MateriaSistema{
    Materia* materia;
    int cupo;
    Lista* inscriptos;
};

MateriaSistema* crearMateriaSistema(Materia* mat, int cupo){
    MateriaSistema* m = (MateriaSistema*)malloc(sizeof(MateriaSistema));

    m->materia = mat;
    m->cupo = cupo;
    m->inscriptos = crearLista();

    return m;
}

void mostrarMateriaSistema(MateriaSistema* m){
    puts("------------MATERIA SISTEMA------------");
    mostrarMateria(m->materia);
    printf("Cupo: %d\n", m->cupo);
}

void mostrarMateriaSistemaConInscriptos(MateriaSistema* m){
    mostrarMateriaSistema(m);
    puts("----------INSCRIPTOS----------");
    mostrarLista(m->inscriptos, mostrarEstudiantes);
}

int getIdMateriaSistema(MateriaSistema* m){
    return getIdMateria(m->materia);
}

const char* getNombreMateriaSistema(MateriaSistema* m){
    return getNombreMateria(m->materia);
}

int getCupoMateriaSistema(MateriaSistema* m){
    return m->cupo;
}

Lista* getListaInscriptosMateriaSistema(MateriaSistema* m){
    return duplicar(m->inscriptos);
}

void setCupoMateriaSistema(MateriaSistema* m, int cupo){
    m->cupo = cupo;
}

void agregarEstudianteAMateria(MateriaSistema* m, Estudiante* e){
    // Si el valor es -1 es porque no la tiene aprobada
    int materiaAprobada = buscarDato(getMateriasAprobadasDelEstudiante(e), (void*)m, esMateria);

    if(materiaAprobada == -1)
        insertarDatoAlFinalDeLaLista(m->inscriptos, (void*)e);

    if(m->cupo < getTamanioLista(m->inscriptos)){
        ordenarLista(m->inscriptos, compararPromediosEstudiantes);
        ordenarLista(m->inscriptos, compararCantidadDeMateriasAprobadas);
        eliminarDatoFinalDeLaLista(m->inscriptos);
    }

}

void destruirMateriaSistema(MateriaSistema* m){
    destruirLista(m->inscriptos);
    free(m);
}

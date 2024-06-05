#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estudiantes.h"
#include "MateriaNota.h"
#include "Sistema.h"

struct Estudiante{
    int dni;
    char apellido[30];
    char nombre[30];
    Lista* asignaturasAprobadas;
};

Estudiante* crearEstudiante(int dni, char apellido[30], char nombre[30]){
    Estudiante* e = (Estudiante*)malloc(sizeof(Estudiante));

    e->dni = dni;
    strcpy(e->apellido, apellido);
    strcpy(e->nombre, nombre);
    e->asignaturasAprobadas = crearLista();

    return e;
}





void mostrarEstudiante(Estudiante* e){
    printf("DNI: %d\n", e->dni);
    printf("Apellido: %s\n", e->apellido);
    printf("Nombre: %s\n", e->nombre);
}

void mostrarEstudianteCompleto(Estudiante* e){
    puts("-------ESTUDIANTE-------");
    mostrarEstudiante(e);
    printf("Materias aprobadas: %d\n", getCantidadDeMateriasAprobadas(e));
    printf("Promedio de carrera: %.2f\n", getPromedioEstudiante(e));
    puts("--MATERIAS APROBADAS--");
    if(getTamanioLista(e->asignaturasAprobadas) > 0){
        mostrarLista(e->asignaturasAprobadas, mostrarCalificaciones);
    } else
        puts("No tiene materias aprobadas.");
}

int getDNI(Estudiante* e){
    return e->dni;
}

const char* getApellidoEstudiante(Estudiante* e){
    return e->apellido;
}

const char* getNombreEstudiante(Estudiante* e){
    return e->nombre;
}

int getCantidadDeMateriasAprobadas(Estudiante* e){
    return getTamanioLista(e->asignaturasAprobadas);
}

Lista* getMateriasAprobadasDelEstudiante(Estudiante* e){
    return duplicar(e->asignaturasAprobadas);
}

float getPromedioEstudiante(Estudiante* e){
    float resultado = 0;
    int tam = getTamanioLista(e->asignaturasAprobadas);

    for(int i=0; i<tam; i++)
        resultado += (float)getNota((MateriaNota*)obtenerDatoEnLaLista(e->asignaturasAprobadas, i));

    if(tam > 0)
        resultado /= tam;

    return resultado;
}

void setApellidoEstudiante(Estudiante* e, char apellido[30]){
    strcpy(e->apellido, apellido);
}

void setNombreEstudiante(Estudiante* e, char nombre[30]){
    strcpy(e->nombre, nombre);
}

void agregarMateriaAprobada(Estudiante* e, Materia* m, int nota){

    if(nota >= 4){
        int contador = 0, tam = getTamanioLista(e->asignaturasAprobadas);
        bool existe = false;

        while(!existe && contador<tam){

            if(getIdMateria(m) == getIdMateriaNota((MateriaNota*)obtenerDatoEnLaLista(e->asignaturasAprobadas, contador)))
                existe = true;

            contador++;
        }

        if(!existe)
            insertarDatoAlFinalDeLaLista(e->asignaturasAprobadas, (void*)crearMateriaNota(m, nota));

    }

}

void destruirEstudiante(Estudiante* e){
    destruirListaYDatos(e->asignaturasAprobadas, destruirMateriaNota);
    free(e);
}

#ifndef ESTUDIANTES_H_INCLUDED
#define ESTUDIANTES_H_INCLUDED

#include "Lista.h"
#include "ListaMaterias.h"


typedef struct Estudiante Estudiante;

Estudiante* crearEstudiante(int dni, char apellido[30], char nombre[30]);

// muestra info basica del estudiante.
void mostrarEstudiante(Estudiante*);
// muestra el 100% de su informacion.
void mostrarEstudianteCompleto(Estudiante*);

int getDNI(Estudiante*);
const char* getApellidoEstudiante(Estudiante*);
const char* getNombreEstudiante(Estudiante*);
// Retorno un duplicado de la lista para asegurarme que no sea modificada en otra parte
// del programa.
Lista* getMateriasAprobadasDelEstudiante(Estudiante*);
int getCantidadDeMateriasAprobadas(Estudiante*);
float getPromedioEstudiante(Estudiante*);

void setApellidoEstudiante(Estudiante*, char apellido[30]);
void setNombreEstudiante(Estudiante*, char nombre[30]);

// Agrega la materia aproba al estudiante con su calificacion. Si fuera una nota
// menor a 4 o el alumno ya tuviera la materia aprobada no la carga
void agregarMateriaAprobada(Estudiante*, Materia*, int nota);

void destruirEstudiante(Estudiante*);



#endif // ESTUDIANTES_H_INCLUDED

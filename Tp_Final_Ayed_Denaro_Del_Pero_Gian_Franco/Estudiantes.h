#ifndef ESTUDIANTES_H_INCLUDED
#define ESTUDIANTES_H_INCLUDED

#include "Lista.h"
#include "ListaMaterias.h"

struct Estudiantes;

typedef struct Estudiantes * estudiante;

//crea un estudiante
Estudiantes* crearEstudiante(int dni , char apellido[30] ,char nombre[30]);

//mostrar estudiante
void mostrarEstudiante(estudiante* e);

//getters y setters

int getDni(estudiante* e);
char* getApellido(estudiante* e);
char* getnombre(estudiante* e);

int setDni(estudiante* e , int nuevoDni);
char* setApellido(estudiante* e, char nuevoApellido[30]);
char* setnombre(estudiante* e, char nuevoNombre[30]);

//Elimina estudiante
void EliminarEstudiante(estudiante* e);

// faltan agregar mas funciones de materias


#endif // ESTUDIANTES_H_INCLUDED

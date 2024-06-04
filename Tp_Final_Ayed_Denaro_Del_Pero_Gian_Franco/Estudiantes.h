#ifndef ESTUDIANTES_H_INCLUDED
#define ESTUDIANTES_H_INCLUDED


struct Estudiantes;

typedef struct Estudiantes * estudiante;

//crea un estudiante
Estudiantes* crearEstudiante(int dni , char apellido[30] ,char nombre[30]);

//mostrar estudiante
void mostrarEstudiante(estudiante*);

//getters y setters

int getDni(estudiante*);
char* getApellido(estudiante*);
char* setnombre(estudiante*, char nuevoNombre[30]);

int setDni(estudiante* , int nuevoDni);
char* setApellido(estudiante*, char nuevoApellido[30]);
char* setnombre(estudiante*, char nuevoNombre[30]);

//Elimina estudiante
void EliminarEstudiante(estudiante);


#endif // ESTUDIANTES_H_INCLUDED

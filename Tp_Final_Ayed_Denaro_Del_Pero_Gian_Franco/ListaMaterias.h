#ifndef LISTAMATERIAS_H_INCLUDED
#define LISTAMATERIAS_H_INCLUDED


struct Materias;

typedef struct Materias * materia;

//crea una materia
Materias* crearMateria(int id ,char nombre[30] , int cupo;);

//mostrar materia
void mostrarMateria(materia*);

//getter y setter
int getId (materia*);
char * getNombre (materia*);
int getCupo(materia*);


void setId (materia* , int nuevoId);
void setNombre (materia* , char nuevoNombre[30]);
void setCupo(materia* , int nuevoCupo);


//Elimina materia
void EliminarMateria(materia);


#endif // LISTAMATERIAS_H_INCLUDED

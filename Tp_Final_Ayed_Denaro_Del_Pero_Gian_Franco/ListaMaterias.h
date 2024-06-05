#ifndef LISTAMATERIAS_H_INCLUDED
#define LISTAMATERIAS_H_INCLUDED


struct Materias;

typedef struct Materias * materia;

//crea una materia
Materias* crearMateria(int id ,char nombre[30] , int cupo;);

//mostrar materia
void mostrarMateria(materia* m);

//getter y setter
int getId (materia* m);
char * getNombre (materia* m);
int getCupo(materia* m);


void setId (materia* m, int nuevoId);
void setNombre (materia* m , char nuevoNombre[30]);
void setCupo(materia* m, int nuevoCupo);


//Elimina materia
void EliminarMateria(materia* m);


#endif // LISTAMATERIAS_H_INCLUDED

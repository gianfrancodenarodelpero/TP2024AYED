#ifndef LISTAMATERIAS_H_INCLUDED
#define LISTAMATERIAS_H_INCLUDED
#include "Lista.h"

typedef struct Materia Materia;
//crea una materia
Materia* crearMateria(int id, char nombre[45]);
//mostrar materia
void mostrarMateria(Materia*);
//getter y setter
int getIdMateria(Materia*);
const char* getNombreMateria(Materia*);
int getCupo(Materia*);
void setId (Materia*, int nuevoId);
void setNombreMateria (Materia* , char nuevoNombre[45]);
void setCupo(Materia* , int nuevoCupo);

//Elimina materia
void destruirMateria(Materia*);
#endif // LISTAMATERIAS_H_INCLUDED

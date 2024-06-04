#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


struct Lista;

typedef Lista * lista;

lista crearLista();

int getTamanio(lista*);

//mostrar lista
void mostrarLista(lista*);


//eliminar lista
void eliminarLista(lista*);

//insertar datos a la lista

void insertarDatoAlInicioEnLaLista(lista*, void*);
bool insertarDatoEnLaLista(lista*, int, void*);
void insertarDatoAlFinalDeLaLista(lista*, void*);
void insertarDatoEnOrdenEnLista(lista*, void*, bool callback(void*, void*));

//obtener datos de la lista
void* obtenerDatoInicialDeLaLista(lista*);
void* obtenerDatoEnLaLista(lista*, int);
void* obtenerDatoFinalDeLaLista(lista*);

//eliminar datos de la lista
void* eliminarDatoInicialDeLaLista(lista*);
void* eliminarDatoDeLaLista(lista*, int);
void* eliminarDatoFinalDeLaLista(lista*);

lista* duplicar(lista*);
void ordenarLista(lista*, bool callback(void*, void*));
int buscarDato(lista*, void*, bool callback(void*, void*));

void destruirLista(lista*);
void destruirListaYDatos(lista*, void callback(void*));



#endif // LISTA_H_INCLUDED

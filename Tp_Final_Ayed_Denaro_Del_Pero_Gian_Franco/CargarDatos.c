#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "ListaMaterias.h"
#include "MateriaNota.h"
#include "MateriaSistema.h"
#include "Estudiantes.h"
#include "CargarDatos.h"

Lista* cargarMaterias(){
    Lista* list = crearLista();

    //cargar materias
    insertarDatoAlInicioEnLaLista(list,(void*)crearMateria(8600, "Programacion de computadoras"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8601, "Organizacion de computadoras"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8602, "Arquitectura de Computadoras"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8603, "Matematicas 1"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8604, "Matematicas 2"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8605, "Expresion de problemas y algoritmos"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8606, "Introduccion al pensamiento cientifico"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8607, "Ingenieria de software 1"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8608, "Introduccion a las bases de datos"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8609, "Algoritmos y estructuras dedatos"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8610, "Orientacion a objetos 1"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8611, "Seminario de lenguajes"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8612, "Introduccion a los sistemas operativos"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8613, "Matematicas 3"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8640, "Probabilidad y estadistica"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8614, "Programacion concurrente"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8615, "Ingenieria de software 2"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8616, "Orientacion a objetos 2"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8617, "Sistemas y organizaciones"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8618, "Base de datos 1"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8619, "proyecto de software"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8621, "concepto y paradigmas"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8622, "Redes y comunicaciones"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8623, "Ingenieria de software 3"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8624, "Base de datos 2"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8625, "Fundamentos de teoria de la computacion"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8626, "Sistemas operativos"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8627, "Desarrollo de software en sistemas"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8641, "Matematica discreta"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(5030, "Ingles 1"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(5030, "Ingles 2"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(5030, "Ingles 3"));

    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8635, "Sistemas embebidos"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8643, "Sistemas basados en conocimiento"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8636, "Prueba de software"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8638, "Espacios virtuales de trabajo colaborativo"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(8628, "Politica y gestion de la ciencia"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(11, "Seminario de DD.HH."));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(10, "Seminario de PNYL"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(5029, "Aspectos legales y profesionales"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(5030, "Nuevos escenarios"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(5037, "Ingenieria de explotacion de informacion"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(5039, "Ingenieria de software empirica"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(12, "Taller de gestion editorial y ciencia abierta"));
    insertarDatoAlFinalDeLaLista(list, (void*)crearMateria(5042, "Seminario de trabajo final"));

    return list;
}

Lista* cargarEstudiantes(Lista* materias){
    Lista* list = crearLista();
    //cargar alumnos y materias aprobadas
    //Alumno 1:
    Estudiante* e1 = crearEstudiante(4106, "Riquelme", "Juan");
    agregarMateriaAprobada(e1, (Materia*)obtenerDatoEnLaLista(materias, 6), 4);
    agregarMateriaAprobada(e1, (Materia*)obtenerDatoEnLaLista(materias, 1), 10);
    agregarMateriaAprobada(e1, (Materia*)obtenerDatoEnLaLista(materias, 35),8);
    insertarDatoAlFinalDeLaLista(list, (void*)e1);
    //Alumno 2:
    Estudiante* e2 = crearEstudiante(4045, "Adriano", "Lucas");
    insertarDatoAlFinalDeLaLista(list, (void*)e2);
    //Alumno 3:
    Estudiante* e3 = crearEstudiante(3905, "Bolaños", "Roberto");
    agregarMateriaAprobada(e3, (Materia*)obtenerDatoEnLaLista(materias, 1), 4);
    agregarMateriaAprobada(e3, (Materia*)obtenerDatoEnLaLista(materias, 20), 9);
    insertarDatoAlFinalDeLaLista(list, (void*)e3);
    //Alumno 4:
    Estudiante* e4 = crearEstudiante(4205, "Perez", "Raton");
    agregarMateriaAprobada(e4, (Materia*)obtenerDatoEnLaLista(materias, 6), 10);
    agregarMateriaAprobada(e4, (Materia*)obtenerDatoEnLaLista(materias, 12), 8);
    agregarMateriaAprobada(e4, (Materia*)obtenerDatoEnLaLista(materias, 11), 8);
    insertarDatoAlFinalDeLaLista(list, (void*)e4);
    //Alumno 5:
    Estudiante* e5 = crearEstudiante(3975, "Gutierrez", "Jeremias");
    agregarMateriaAprobada(e5, (Materia*)obtenerDatoEnLaLista(materias, 8), 5);
    agregarMateriaAprobada(e5, (Materia*)obtenerDatoEnLaLista(materias, 1), 4);
    insertarDatoAlFinalDeLaLista(list, (void*)e5);
    //Alumno 6:
    Estudiante* e6 = crearEstudiante(3845, "Messi", "Lionel");
    agregarMateriaAprobada(e6, (Materia*)obtenerDatoEnLaLista(materias, 0), 9);
    agregarMateriaAprobada(e6, (Materia*)obtenerDatoEnLaLista(materias, 1), 10);
    agregarMateriaAprobada(e6, (Materia*)obtenerDatoEnLaLista(materias, 2), 7);
    agregarMateriaAprobada(e6, (Materia*)obtenerDatoEnLaLista(materias, 4), 9);
    insertarDatoAlFinalDeLaLista(list, (void*)e6);
    //Alumno 7:
    Estudiante* e7 = crearEstudiante(4178, "Guerrero", "Pablo");
    agregarMateriaAprobada(e7, (Materia*)obtenerDatoEnLaLista(materias, 0), 4);
    agregarMateriaAprobada(e7, (Materia*)obtenerDatoEnLaLista(materias, 6), 4);
    insertarDatoAlFinalDeLaLista(list, (void*)e7);

    //Alumno 8:
    Estudiante* e8 = crearEstudiante(4214, "mendez", "Nati");
    agregarMateriaAprobada(e8, (Materia*)obtenerDatoEnLaLista(materias, 20), 8);
    agregarMateriaAprobada(e8, (Materia*)obtenerDatoEnLaLista(materias, 4), 5);
    agregarMateriaAprobada(e8, (Materia*)obtenerDatoEnLaLista(materias, 0), 4);
    insertarDatoAlFinalDeLaLista(list, (void*)e8);

    //Alumno 9:
    Estudiante* e9 = crearEstudiante(1234, "gasper", "joan");
    agregarMateriaAprobada(e9, (Materia*)obtenerDatoEnLaLista(materias, 17), 8);
    agregarMateriaAprobada(e9, (Materia*)obtenerDatoEnLaLista(materias, 12), 6);
    agregarMateriaAprobada(e9, (Materia*)obtenerDatoEnLaLista(materias, 10), 7);
    insertarDatoAlFinalDeLaLista(list, (void*)e9);
    //Alumno 10:
    Estudiante* e10 = crearEstudiante(4111, "denaro", "stefano");
    agregarMateriaAprobada(e10, (Materia*)obtenerDatoEnLaLista(materias, 13), 8);
    agregarMateriaAprobada(e10, (Materia*)obtenerDatoEnLaLista(materias, 15), 7);
    agregarMateriaAprobada(e10, (Materia*)obtenerDatoEnLaLista(materias, 10), 4);
    insertarDatoAlFinalDeLaLista(list, (void*)e10);
    //Alumno 11:
    Estudiante* e11 = crearEstudiante(3987, "cuatrini", "Nati");
    agregarMateriaAprobada(e11, (Materia*)obtenerDatoEnLaLista(materias, 3), 8);
    agregarMateriaAprobada(e11, (Materia*)obtenerDatoEnLaLista(materias, 1), 9);
    agregarMateriaAprobada(e11, (Materia*)obtenerDatoEnLaLista(materias, 2), 3);
    insertarDatoAlFinalDeLaLista(list, (void*)e11);
    //Alumno 12:
    Estudiante* e12 = crearEstudiante(4444, "Neymar", "Jr");
    agregarMateriaAprobada(e12, (Materia*)obtenerDatoEnLaLista(materias, 10), 9);
    agregarMateriaAprobada(e12, (Materia*)obtenerDatoEnLaLista(materias, 8), 2);
    agregarMateriaAprobada(e12, (Materia*)obtenerDatoEnLaLista(materias, 20), 6);
    insertarDatoAlFinalDeLaLista(list, (void*)e12);
    return list;
}

Lista* cargarMateriasSistema(Lista* lMaterias, Lista* lEstudiantes){
    Lista* list = crearLista();

    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 0), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 1), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 2), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 3), 5));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 4), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 5), 3));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 6), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 7), 7));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 8), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 9), 3));

    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 10), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 11), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 12), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 13), 5));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 14), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 15), 3));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 16), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 17), 7));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 18), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 19), 3));


    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 20), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 21), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 22), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 23), 5));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 24), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 25), 3));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 26), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 27), 7));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 28), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 29), 3));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 30), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 31), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 32), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 33), 5));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 34), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 35), 3));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 36), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 37), 7));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 38), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 39), 3));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 40), 4));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 41), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 42), 2));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 43), 5));
    insertarDatoAlFinalDeLaLista(list, (MateriaSistema*)crearMateriaSistema((Materia*)obtenerDatoEnLaLista(lMaterias, 44), 4));




    for(int i=0; i<getTamanioLista(list); i++){
        // Como es de pocos datos se hace cargando al 100% de estudiantes en
        // el 100% de materias, los metodos agregar se encargan de saber si
        // se debe o no incribir a un alumno.
        for(int j=0; j<getTamanioLista(lEstudiantes); j++)
            agregarEstudianteAMateria((MateriaSistema*)obtenerDatoEnLaLista(list, i), (Estudiante*)obtenerDatoEnLaLista(lEstudiantes, j));

    }

    return list;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "estructuras.c"

void imprimirProfesor(struct Profesor* profesor);
void imprimirEstudiante(struct Estudiante* estudiante);
void mostrarProfesor(struct Profesor** arregloProfesores, size_t cantidadProfesores);
void mostrarEstudiante(struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes);
void eliminarMateriaEstudiante(struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes);
void eliminarMateriaProfesor(struct Profesor** arregloProfesores, size_t cantidadProfesores);



///////// *************************************************** METODOS PRINCIPALES *************************************************** /////////
struct Profesor* crearProfesor(){
// ----------------------------- MALLOC PROFESOR --------------------------------
    // Asignar memoria para arreglo PROFESOR
    struct Profesor* NewProfesor = (struct Profesor*)malloc(sizeof(struct Profesor));
    // Verificar si se pudo asignar memoria correctamente
    if (NewProfesor == NULL) {
        printf("No se pudo asignar memoria para arreglo: Profesor.\n");
        exit(1);
    }

    //Ingresar datos Profesor
    printf("--------- NUEVO PROFESOR ---------\n");
    printf("- Nombre:\n");
    scanf("%s", NewProfesor->nombre);
    printf("- Carrera:\n");
    scanf("%s", NewProfesor->carrera);
    printf("¿Cuántas materias desea registrar?\n");
    scanf("%zu",&(NewProfesor->cantidadMateriasDictando));

// ----------------------------- MALLOC MATERIAS DICTANDO ---------------------------
    // Asignar memoria para arreglo MateriaDictando
    struct MateriaDictando* NewMateriaDictando = (struct MateriaDictando*)malloc( NewProfesor->cantidadMateriasDictando * sizeof(struct MateriaDictando));
    // Verificar si se pudo asignar memoria correctamente
    if (NewMateriaDictando == NULL){
        printf("No se pudo asignar memoria para el arreglo: MateriaDictando.\n");
        free(NewProfesor);
        exit(1);
    }

    //Ingresar datos MateriasDictando
    for(size_t i=0; i<(NewProfesor->cantidadMateriasDictando); i++){

        printf("REGISTRE MATERIA DICTANDO #%ld\n", i+1);
        printf("- Nombre de Materia:\n");
        scanf("%s",NewMateriaDictando[i].materia.nombreMateria);
        printf("- Paralelo:\n");
        scanf("%d", &(NewMateriaDictando[i].paralelo));
        getchar(); // Consumir el carácter de nueva línea
    }

    NewProfesor->MateriaDictando = NewMateriaDictando;

    return NewProfesor;

    // ---------- LIBREAR PUNTERO ----------
    free(NewMateriaDictando);
    free(NewProfesor);
    

}


struct Estudiante* crearEstudiante(){
// ----------------------------- MALLOC ESTUDIANTE --------------------------------
    // Asignar memoria para arreglo Estudiante
    struct Estudiante* NewEstudiante = (struct Estudiante*)malloc(sizeof(struct Estudiante));
    // Verificar si se pudo asignar memoria correctamente
    if (NewEstudiante == NULL){
        printf("No se pudo asignar memoria para el arreglo: Estudiante.\n");
        exit(1);
    }
    
    //Ingresar datos Estudiantes
    printf("--------- NUEVO ESTUDIANTE ---------\n");
    printf("- Nombre:\n");
    scanf("%s", NewEstudiante->nombre);
    printf("- Nivel:\n");
    scanf("%d",&(NewEstudiante->nivel));
    getchar(); // Consumir el carácter de nueva línea
    printf("- Carrera:\n");
    scanf("%s", NewEstudiante->carrera);
    printf("¿Cuántas materias desea registrar?\n");
    scanf("%zu", &(NewEstudiante->cantidadMateriasTomando));

// ----------------------------- MALLOC MATERIAS TOMANDO --------------------------------
    // Asignar memoria para arreglo MateriaTomando
    struct MateriaTomando* NewMateriaTomando = (struct MateriaTomando*)malloc( NewEstudiante->cantidadMateriasTomando * sizeof(struct MateriaTomando));
    // Verificar si se pudo asignar memoria correctamente
    if (NewMateriaTomando == NULL){
        printf("No se pudo asignar memoria para el arreglo: Estudiante.\n");
        exit(1);
    }

    //Ingresar datos MateriasTomando
    for(size_t i=0; i<(NewEstudiante->cantidadMateriasTomando); i++){

        printf("REGISTRE MATERIA TOMANDO #%ld\n", i+1);
        printf("- Nombre de Materia:\n");
        scanf("%s", NewMateriaTomando[i].materia.nombreMateria);
        printf("- Creditos:\n");
        scanf("%d", &(NewMateriaTomando[i].creditos));
        getchar(); // Consumir el carácter de nueva línea
    }
    NewEstudiante->MateriaTomando = NewMateriaTomando;
      

    return NewEstudiante;
    
    // ---------- LIBREAR PUNTERO ----------
    free(NewMateriaTomando);
    free(NewEstudiante);
}


void mostrarDatos(struct Profesor** arregloProfesores, size_t cantidadProfesores, struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes){
    printf("\n************************************ MUESTRA DE DATOS ************************************\n\n");
    mostrarProfesor(arregloProfesores, cantidadProfesores);
    mostrarEstudiante(arregloEstudiantes, cantidadEstudiantes);
    printf("\n******************************************************************************************\n\n");
}


void eliminarMateria(struct Profesor** arregloProfesores, size_t cantidadProfesores, struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes){

    bool inFlag = true;
    printf("\n************************************ ELIMINAR MATERIA ************************************\n\n");
    do
    {
    char opcion;
    printf("Eliga una opcion:\n");
    printf("1. Eliminar materia Profesor\n");
    printf("2. Eliminar materia Estudiante\n");
    printf("3. VOLVER\n");
    printf("Opcion: ");
    scanf("%c", &opcion);
    getchar(); // Consumir el carácter de nueva línea

    switch (opcion){

        case '1':
            if(arregloProfesores == NULL){
                printf("Accion NO disponible: Listado Profesores VACIO\n");
                break;
            }
            else{
                eliminarMateriaProfesor(arregloProfesores, cantidadProfesores);
                break;
            }
            break;

        case '2':
            if(arregloEstudiantes == NULL){
                printf("Accion NO disponible: Listado Estudiantes VACIO\n");
                break;
            }
            else{
                eliminarMateriaEstudiante(arregloEstudiantes, cantidadEstudiantes);
                break;
            }
            
            break;

        case '3':
            inFlag = false;
            break;
            
        default:
            printf("\nOpcion invalida\n");
        }

    } while (inFlag);
    printf("\n******************************************************************************************\n\n");
}



void cambiarNivel(struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes){
    printf("\n************************************ CAMBIAR NIVEL ************************************\n\n");
    char nombreEstudiante[50];
    printf("Ingrese nombre del ESTUDIANTE para cambiar nivel: ");
    scanf("%s", nombreEstudiante);
    getchar(); // Consumir el carácter de nueva línea

    for (size_t i = 0; i < cantidadEstudiantes; i++) {
        if(strcmp(nombreEstudiante, arregloEstudiantes[i]->nombre) == 0){
            printf("Estudiante ENCONTRADO!!!:\n");
            printf("- Ingrese nuevo Nivel: ");
            scanf("%d",&(arregloEstudiantes[i]->nivel));
            getchar(); // Consumir el carácter de nueva línea
            break;
        }
    else{
        printf("Estudiante NO ENCONTRADO:\n");
        break;
        }
    }  
    printf("\n******************************************************************************************\n\n");
}


///////// *************************************************** METODOS AUXILIARES *************************************************** /////////

// ---------------------------- AUXILIA mostrarDatos() ----------------------------

void mostrarProfesor(struct Profesor** arregloProfesores, size_t cantidadProfesores){
    printf("------------------------ LISTADO PROFESORES -------------------------\n");
    for (size_t i = 0; i < cantidadProfesores; i++) {
        imprimirProfesor(arregloProfesores[i]);
        printf("\n");
    }
}

void mostrarEstudiante(struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes){
    printf("------------------------ LISTADO ESTUDIANTES ------------------------\n");
    for (size_t i = 0; i < cantidadEstudiantes; i++) {
        imprimirEstudiante(arregloEstudiantes[i]);
        printf("\n");
    }
}

void imprimirProfesor(struct Profesor* profesor) {
    printf("--------- PROFESOR ---------\n");
    printf("- Nombre: %s\n", profesor->nombre);
    printf("- Carrera: %s\n", profesor->carrera);
    printf("- Cantidad de materias dictando: %zu\n", profesor->cantidadMateriasDictando);

    printf("- Materias dictando:\n");
    for (size_t i = 0; i < profesor->cantidadMateriasDictando; i++) {
        printf("  * Materia #%ld\n", i + 1);
        printf("    - Nombre de materia: %s\n", profesor->MateriaDictando[i].materia.nombreMateria);
        printf("    - Paralelo: %d\n", profesor->MateriaDictando[i].paralelo);
    }
}

void imprimirEstudiante(struct Estudiante* estudiante) {
    printf("--------- ESTUDIANTE ---------\n");
    printf("- Nombre: %s\n", estudiante->nombre);
    printf("- Nivel: %d\n", estudiante->nivel);
    printf("- Carrera: %s\n", estudiante->carrera);
    printf("- Cantidad de materias tomando: %zu\n", estudiante->cantidadMateriasTomando);

    printf("- Materias dictando:\n");
    for (size_t i = 0; i < estudiante->cantidadMateriasTomando; i++) {
        printf("  * Materia #%ld\n", i + 1);
        printf("    - Nombre de materia: %s\n", estudiante->MateriaTomando[i].materia.nombreMateria);
        printf("    - Creditos: %d\n", estudiante->MateriaTomando[i].creditos);
    }
}

// ---------------------------- AUXILIA eliminarMateria() ----------------------------

void eliminarMateriaProfesor(struct Profesor** arregloProfesores, size_t cantidadProfesores){
    char nombreProfesor[50];
    char nombreMateriaEliminar[50];
    printf("Ingrese nombre del PROFESOR para ELIMINAR MATERIA: ");
    scanf("%s", nombreProfesor);
    getchar(); // Consumir el carácter de nueva línea

    for (size_t i = 0; i < cantidadProfesores; i++) {
        if(strcmp(nombreProfesor, arregloProfesores[i]->nombre) == 0){
            printf("Profesor ENCONTRADO!!!\n");
            struct Profesor* profesor = arregloProfesores[i];

            printf("Ingrese nombre del MATERIA que desea ELIMINAR: ");
            scanf("%s", nombreMateriaEliminar);
            getchar(); // Consumir el carácter de nueva línea

            for (size_t j = 0; j < profesor->cantidadMateriasDictando; j++) {
                if(strcmp(nombreMateriaEliminar, profesor->MateriaDictando[j].materia.nombreMateria) == 0){
                
                //REMOVER LA MATERIA
                for (size_t k = j; k < profesor->cantidadMateriasDictando - 1; k++) {
                        strcpy(profesor->MateriaDictando[k].materia.nombreMateria, profesor->MateriaDictando[k + 1].materia.nombreMateria);
                        profesor->MateriaDictando[k].paralelo = profesor->MateriaDictando[k + 1].paralelo;
                    }
                    profesor->cantidadMateriasDictando--;
                    printf("Materia eliminada EXITOSAMENTE.\n");
                    return;
                }
                else{
                    printf("Materia NO ENCONTRADA:\n");
                    return;
                }
            }
        }
        else{
            printf("Profesor NO ENCONTRADO:\n");
            break;
        }
    }  
}

void eliminarMateriaEstudiante(struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes){
    char nombreEstudiante[50];
    char nombreMateriaEliminar[50];
    printf("Ingrese nombre del ESTUDIANTE para ELIMINAR MATERIA: ");
    scanf("%s", nombreEstudiante);
    getchar(); // Consumir el carácter de nueva línea

    for (size_t i = 0; i < cantidadEstudiantes; i++) {
        if(strcmp(nombreEstudiante, arregloEstudiantes[i]->nombre) == 0){
            printf("Estudiante ENCONTRADO!!!\n");
            struct Estudiante* estudiante = arregloEstudiantes[i];

            printf("Ingrese nombre del MATERIA que desea ELIMINAR: ");
            scanf("%s", nombreMateriaEliminar);
            getchar(); // Consumir el carácter de nueva línea

            for (size_t j = 0; j < estudiante->cantidadMateriasTomando; j++) {
                if(strcmp(nombreMateriaEliminar, estudiante->MateriaTomando[j].materia.nombreMateria) == 0){
                
                //REMOVER LA MATERIA
                for (size_t k = j; k < estudiante->cantidadMateriasTomando - 1; k++) {
                        strcpy(estudiante->MateriaTomando[k].materia.nombreMateria, estudiante->MateriaTomando[k + 1].materia.nombreMateria);
                        estudiante->MateriaTomando[k].creditos = estudiante->MateriaTomando[k + 1].creditos;
                    }
                    estudiante->cantidadMateriasTomando--;
                    printf("Materia eliminada EXITOSAMENTE.\n");
                    return;
                }
                else{
                    printf("Materia NO ENCONTRADA:\n");
                    return;
                }
            }
        }
        else{
            printf("Estudiante NO ENCONTRADO:\n");
            break;
        }
    }  
}
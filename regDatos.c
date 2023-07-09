#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Profesor* crearProfesor();
struct Estudiante* crearEstudiante();
void cambiarNivel(struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes);
void eliminarMateria(struct Profesor** arregloProfesores, size_t cantidadProfesores, struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes);
void mostrarDatos(struct Profesor** arregloProfesores, size_t cantidadProfesores, struct Estudiante** arregloEstudiantes, size_t cantidadEstudiantes);

int main(){

    char accion;
    bool inFlag = true;

    size_t cantidadProfesores = 0;
    size_t cantidadEstudiantes = 0;
    struct Profesor** arregloProfesores = NULL;
    struct Estudiante** arregloEstudiantes = NULL;

    do
    {
        printf("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯ Menu de Opciones (Terminal) ¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
        printf("| 1. Registrar Profesor                                   |\n");
        printf("| 2. Registrar Estudiante                                 |\n");
        printf("| 3. Mostrar Datos                                        |\n");
        printf("| 4. Eliminar Materia de Estudiante/Profesor              |\n");
        printf("| 5. Cambiar Nivel de Estudiante                          |\n");
        printf("| 6. SALIR                                                |\n");
        printf("|_________________________________________________________|\n");
        printf("Opcion: ");
        scanf("%c", &accion);
        getchar(); // Consumir el carácter de nueva línea

        switch (accion){

            case '1':
                // AGREGAR PROFESOR
                struct Profesor* NuevoProfesor = crearProfesor();
                if (NuevoProfesor == NULL) {
                    printf("Error al crear el Profesor.\n");
                    break;
                }

                cantidadProfesores++;
                arregloProfesores = (struct Profesor**)realloc(arregloProfesores, cantidadProfesores * sizeof(struct Profesor*));
                if (arregloProfesores == NULL) {
                    printf("No se pudo asignar memoria para el arreglo de profesores.\n");
                    free(NuevoProfesor);
                    break;
                }
                arregloProfesores[cantidadProfesores - 1] = NuevoProfesor;
                break;

            case '2':
                // AGREGAR ESTUDIANTE
                struct Estudiante* NuevoEstudiante = crearEstudiante();
                if (NuevoEstudiante == NULL) {
                    printf("Error al crear el Estudante.\n");
                    break;
                }

                cantidadEstudiantes++;
                arregloEstudiantes = (struct Estudiante**)realloc(arregloEstudiantes, cantidadEstudiantes * sizeof(struct Estudiante*));
                if (arregloEstudiantes == NULL) {
                    printf("No se pudo asignar memoria para el arreglo de estudiantes.\n");
                    free(NuevoEstudiante);
                    break;
                }
                arregloEstudiantes[cantidadEstudiantes - 1] = NuevoEstudiante;
                break;

            case '3':
                mostrarDatos(arregloProfesores, cantidadProfesores, arregloEstudiantes, cantidadEstudiantes);
                break;

            case '4':
                eliminarMateria(arregloProfesores, cantidadProfesores, arregloEstudiantes, cantidadEstudiantes);
                break;

            case '5':
                if(arregloEstudiantes == NULL){
                    printf("Accion NO disponible: Listado Estudiante VACIO\n");
                    break;
                }
                else{
                    cambiarNivel(arregloEstudiantes, cantidadEstudiantes);
                    break;
                }
                break;

            case '6':
                inFlag = false;
                break;
            
            default:
                printf("\nOpcion invalida\n");
        }

    } while (inFlag);

    // Liberar memoria para arregloProfesores
    for (size_t i = 0; i < cantidadProfesores; i++) {
        free(arregloProfesores[i]);
    }
    free(arregloProfesores);

    // Liberar memoria para arregloEstudiantes
    for (size_t i = 0; i < cantidadEstudiantes; i++) {
        free(arregloEstudiantes[i]);
    }
    free(arregloEstudiantes);

    return 0;
}
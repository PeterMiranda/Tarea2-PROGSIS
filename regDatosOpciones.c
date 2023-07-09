#include "libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
  int opt;
  int cantidadRegistro;
  while ((opt = getopt(argc, argv, "p:e:a:")) != -1) {
    switch (opt) {
    case 'p':
      if (atoi(optarg) < 2) {
        printf("Ingresar una cantidad de registro mayor que 1\n");
        exit(1);
      }
      printf("Opción %c: Profesor\n", opt);
      cantidadRegistro = atoi(optarg);
      struct Profesor *profesores;
      getProfesor(&profesores, cantidadRegistro);
      mostrarProfesores(profesores, cantidadRegistro);
      for (int i = 0; i < cantidadRegistro; i++) {
        free(profesores[i].NewMD);
      }
      free(profesores);
      break;

    case 'e':
      if (atoi(optarg) < 2) {
        printf("Ingresar una cantidad de registro mayor que 1");
        exit(1);
      }
      printf("Opción: %c Estudiante\n", opt);
      cantidadRegistro = atoi(optarg);
      struct Estudiante *estudiantes;
      getEstudiante(&estudiantes, cantidadRegistro);
      mostrarEstudiantes(estudiantes, cantidadRegistro);
      for (int i = 0; i < cantidadRegistro; i++) {
        free(estudiantes[i].NewMT);
      }
      free(estudiantes);
      break;

    case 'a':
      if (atoi(optarg) < 2) {
        printf("Ingresar una cantidad de registro mayor que 1");
        exit(1);
      }
      printf("Opción: %c Ambos\n", opt);
      cantidadRegistro = atoi(optarg);
      struct Profesor * profesorA;
      getProfesor(&profesorA, 1);
      struct Estudiante * estudiantesA;
      getEstudiante(&estudiantesA, cantidadRegistro - 1);
      mostrarProfesores(profesorA, 1);
      mostrarEstudiantes(estudiantesA, cantidadRegistro - 1);
      free(profesorA[0].NewMD);
      free(profesorA);
      for (int i = 0; i < cantidadRegistro - 1; i++) {
        free(estudiantesA[i].NewMT);
      }
      free(estudiantesA);
      break;
    case ':':
      printf("Opción %c: Falta argumento\n", optopt);
      break;
    case '?':
      printf("Opción no reconocida: %c\n", optopt);
      break;
    }
  }

  for (; optind < argc; optind++) {
    printf("Argumento sobrante: %s\n", argv[optind]);
  }

  return 0;
}

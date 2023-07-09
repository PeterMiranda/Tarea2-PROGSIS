#include <stdio.h>

// Estructura abstracta 
struct Materia {
    char nombreMateria[50];
};

// Estructura Profesor

struct MateriaDictando
{
    struct Materia materia;
    //char nombreMateria[50];
    int paralelo;
};

struct Profesor
{
    char nombre[50];
    char carrera[50];
    struct MateriaDictando *MateriaDictando;
    size_t cantidadMateriasDictando;
};

// Estructura Profesor
struct MateriaTomando
{
    struct Materia materia;
    //char nombreMateria[50];
    int creditos;
};

struct Estudiante
{
    char nombre[50];
    int nivel;
    char carrera[50];
    struct MateriaTomando *MateriaTomando;
    size_t cantidadMateriasTomando;
};

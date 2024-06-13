#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define NUM_ALUMNOS 6
#define NUM_NOTAS 3

void imprimirAlumnos(char alumnos[][2][20], double notas[][3]) {
    printf("Nombre\tApellido\tPromedio\tEstado\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        double promedio = (notas[i][0] + notas[i][1] + notas[i][2]);
        printf("%s\t%s\t%.2f\t%s\n", alumnos[i][0], alumnos[i][1], promedio, promedio >= 6.0 ? "Aprobado" : "Reprobado");
    }
}

void buscarAlumnoXApellido(char alumnos[][2][20], double notas[][3]) {
    char apellido[20];
    printf("Ingrese el apellido del alumno: ");
    scanf("%s", apellido);
    
    int encontrado = 0;
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        if (strcmp(alumnos[i][1], apellido) == 0) {
            double promedio = (notas[i][0] + notas[i][1] + notas[i][2]);
            printf("Nombre: %s\nApellido: %s\nNotas: %.2f, %.2f, %.2f\nPromedio: %.2f\nEstado: %s\n",
                   alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2],
                   promedio, promedio >= 6.0 ? "Aprobado" : "Reprobado");
            encontrado = 1;
        }
    }
    
    if (!encontrado) {
        printf("Alumno con apellido '%s' no encontrado.\n", apellido);
    }
}

void editarCalificaciones(char alumnos[][2][20], double notas[][3]) {
    char apellido[20];
    printf("Ingrese el apellido del alumno cuyas calificaciones desea editar: ");
    scanf("%s", apellido);
    
    int encontrado = 0;
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        if (strcmp(alumnos[i][1], apellido) == 0) {
            printf("Ingrese las nuevas calificaciones para %s %s:\n", alumnos[i][0], alumnos[i][1]);
            for (int j = 0; j < NUM_NOTAS; j++) {
                printf("Nota %d: ", j + 1);
                scanf("%lf", &notas[i][j]);
            }
            printf("Calificaciones actualizadas para %s %s.\n", alumnos[i][0], alumnos[i][1]);
            encontrado = 1;
        }
    }
} 
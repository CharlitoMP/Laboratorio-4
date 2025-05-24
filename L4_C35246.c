#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Encontrar la secuencia más larga de 1s
void encontrar_diagonal_mas_larga(int *matriz, int TAMANO, int *resultado) {

                int max_longitud = 0; //Almacena la longitud más larga encontrada de 1s consecutivos

// Recorre las diagonales que comienzan en la fila 0 y columnas de 0
                for (int i = 0; i < TAMANO; i++) {
                    int fila = 0;
                    int c = i;
                    int longitud_actual = 0;
// Se mueve hacia abajo y a la izquierda
                    while (fila < TAMANO && c >= 0) {
                        if (*(matriz + fila * TAMANO + c) == 1) {
                            longitud_actual++;
                            if (longitud_actual > max_longitud)
                                max_longitud = longitud_actual;
                        } else {
                            longitud_actual = 0;  // Si encuentra un 0, reinicia la longitud actual
                        }
                        fila++;
                        c--;
                    }
                }
// Recorre las diagonales que comienzan en la columna TAMANO-1 y filas de 1 a TAMANO-1
                for (int j = 1; j < TAMANO; j++) {
                    int f = j;
                    int col = TAMANO - 1;
                    int longitud_actual = 0;
                    while (f < TAMANO && col >= 0) {
                        if (*(matriz + f * TAMANO + col) == 1) {
                            longitud_actual++;
                            if (longitud_actual > max_longitud)
                                max_longitud = longitud_actual;
                        } else {
                            longitud_actual = 0;
                        }
                        f++;
                        col--;
                    }
                }
// Asigna el valor máximo encontrado al puntero llamado resultado
                *resultado = max_longitud;
                return;
            }
        
    // Función para imprimir la matriz que se va a usar
void imprimir_matriz(int *matriz, int TAMANO) {
    printf("Matriz generada:\n");
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%d ", *(matriz + i * TAMANO + j));
        }
        printf("\n");
    }
}


int main() {
    //Solicita le tamaño de la matriz
    int TAMANO = 0;
printf("Digite el tamaño de la matriz: ");
scanf("%i", &TAMANO);

    // Asignación de memoria dinamica 
    int *matriz = (int *)malloc(TAMANO * TAMANO * sizeof(int)); //Uso del comando malloc
    if (matriz == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }


        srand(time(NULL));

    // Rellena la matriz con valores aleatorios y de forma binaria
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            *(matriz + i * TAMANO + j) = rand() % 2; // 0 o 1
        }
    
    };

    int diagonal_mas_larga = 0;

    encontrar_diagonal_mas_larga(matriz,TAMANO, &diagonal_mas_larga);
    printf("La matriz generada es:\n");
    imprimir_matriz(matriz, TAMANO);

    printf("La secuencia de 1s más grande es: %d\n", diagonal_mas_larga);

    return 0;
}

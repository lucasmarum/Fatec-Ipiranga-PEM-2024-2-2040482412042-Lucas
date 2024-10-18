#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular              *
*          Prof. Carlos Veríssimo                            *                                
*------------------------------------------------------------*
* Objetivo do Programa: Quicksort e esquema da memória       *
* Data : 13/10/2024                                          * 
* Autor: Lucas Marum                                         *
*------------------------------------------------------------*/

/*--------------------------------------------------------------------*
| Módulo - Realizar a partição do array, maiores que pivot e menores  |
*---------------------------------------------------------------------*/
int partition(int array[], int left, int right) {
    int pivot = array[right]; 
    int i = left - 1, j;
    for (j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i = i+1;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    int temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;
    
    return i + 1;
}

/*---------------------------------------------------------*
| Módulo - Quicksort                                       |ç
*---------------------------------------------------------*/
void quicksort(int array[], int left, int right) {
    if (left < right) {
        int pivot = partition(array, left, right);
        quicksort(array, left, pivot - 1);  
        quicksort(array, pivot + 1, right); 
    }
}

/*---------------------------------------------------------*
| Módulo - Printar array                                   |
*---------------------------------------------------------*/
void printarArray(int array[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*---------------------------------------------------------*
| Módulo - Modulo principal                                |
*---------------------------------------------------------*/
int main() {
    int array[] = {100, 70, 90, 60, 10, 40, 30};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    printarArray(array, size); // Modulo de printar array

    quicksort(array, 0, size - 1); // Modulo quicksort

    printf("Array ordenado: ");
    printarArray(array, size);

    return 0;
}
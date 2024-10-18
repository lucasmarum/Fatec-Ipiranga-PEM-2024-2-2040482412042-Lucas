/*--------------------------------------------------------*
 * Disciplina: Programação Estruturada                    *
 *          Prof. Carlos verissimo                        *
 *--------------------------------------------------------*
 * Objetivo do Programa: Implementar o algoritmo Bubble   *
 * Sort e exibir o array original e ordenado.             *
 * Data - 03/10/2024                                      *
 *--------------------------------------------------------*/

#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    int arr[n];

    printf("Digite os numeros:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, n);

    printf("Array ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

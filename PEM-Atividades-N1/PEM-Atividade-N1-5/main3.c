/*--------------------------------------------------------*
 * Disciplina: Programação Estruturada                    *
 *          Prof. Carlos verissimo                        *
 *--------------------------------------------------------*
 * Objetivo do Programa: Calcular a nota final de um      *
 * candidato em um processo de seleção, excluindo a maior *
 * e a menor nota de cada conjunto de testes.             *
 * Data - 13/09/2024                                      *
 *--------------------------------------------------------*/

#include <stdio.h>

int main() {
    int N, i, j, teste = 1;
    float nota[100], maior, menor, soma, nota_final = 0;

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        for (i = 0; i < N; i++) {
            scanf("%f", &nota[i]);
        }

        maior = menor = nota[0];
        soma = 0;

        for (i = 0; i < N; i++) {
            if (nota[i] > maior) maior = nota[i];
            if (nota[i] < menor) menor = nota[i];
            soma += nota[i];
        }

        soma = soma - maior - menor;
        nota_final += soma;

        printf("Nota do teste %d = %.0f\n", teste, soma);
        teste++;
    }

    printf("Nota final do candidato = %.0f\n", nota_final);

    return 0;
}

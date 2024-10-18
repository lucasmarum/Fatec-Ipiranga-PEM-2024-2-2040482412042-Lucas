/*--------------------------------------------------------*
 * Disciplina: Programação Estruturada                    *
 *          Prof. Carlos verissimo                    *
 *--------------------------------------------------------*
 * Objetivo do Programa: Calcular a nota final de um      *
 * candidato em um processo de seleção, excluindo a maior *
 * e a menor nota de cada conjunto de testes.             *
 * Data - 16/08/2024                                      *
 *--------------------------------------------------------*/

#include <stdio.h>

int main() {
    int N, i;
    float nota, maior, menor, soma, nota_final = 0;

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        maior = -1;
        menor = 11;
        soma = 0;

        for (i = 0; i < N; i++) {
            scanf("%f", &nota);

            if (nota > maior) maior = nota;
            if (nota < menor) menor = nota;

            soma += nota;
        }

        soma = soma - maior - menor;
        nota_final += soma;

        printf("Nota do teste = %.0f\n", soma);
    }

    printf("Nota final do candidato = %.0f\n", nota_final);

    return 0;
}

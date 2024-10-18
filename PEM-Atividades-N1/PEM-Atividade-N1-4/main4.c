/*--------------------------------------------------------*
 * Disciplina: Programação Estruturada                    *
 *          Prof. Carlos verissimo                        *
 *--------------------------------------------------------*
 * Objetivo do Programa: Simular a jogada "Xeque Pastor"  *
 * no tabuleiro de xadrez.                                 *
 * Data - 21/09/2024                                      *
 *--------------------------------------------------------*/

#include <stdio.h>

void exibir_tabuleiro(char tabuleiro[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char tabuleiro[8][8] = {
        {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'}
    };

    printf("Tabuleiro inicial:\n");
    exibir_tabuleiro(tabuleiro);

    tabuleiro[4][4] = ' ';
    tabuleiro[6][4] = 'P';

    printf("Jogada #1:\n");
    tabuleiro[6][4] = ' ';
    tabuleiro[4][4] = 'P';
    exibir_tabuleiro(tabuleiro);
    
    tabuleiro[4][4] = ' ';
    tabuleiro[2][4] = 'p';
    exibir_tabuleiro(tabuleiro);

    printf("Jogada #2:\n");
    tabuleiro[2][4] = ' ';
    tabuleiro[3][2] = 'B';
    exibir_tabuleiro(tabuleiro);

    tabuleiro[3][2] = ' ';
    tabuleiro[5][1] = 'c';
    exibir_tabuleiro(tabuleiro);

    printf("Jogada #3:\n");
    tabuleiro[3][2] = ' ';
    tabuleiro[4][1] = 'D';
    exibir_tabuleiro(tabuleiro);

    tabuleiro[4][1] = ' ';
    tabuleiro[5][5] = 'c';
    exibir_tabuleiro(tabuleiro);

    printf("Jogada #4: Xeque Mate:\n");
    tabuleiro[4][1] = ' ';
 

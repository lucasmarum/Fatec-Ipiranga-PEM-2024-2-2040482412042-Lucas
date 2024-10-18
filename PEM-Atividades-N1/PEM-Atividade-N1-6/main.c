/*--------------------------------------------------------*
 * Disciplina: Programaçao Estruturada e Modular           *
 *          Prof. Carlos Veríssimo                        *
 *--------------------------------------------------------*
 * Objetivo do Programa: Simular o funcionamento da       *
 * calculadora HP12c       *
 * memórias (X, Y, Z, T)                                  *
 * Data - 20/09/2024                                      *
 *--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PILHA 4

// Estrutura para a pilha
typedef struct {
    int pilha[TAMANHO_PILHA];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return p->topo == TAMANHO_PILHA - 1;
}

// Coloca um valor na pilha
void empilhar(Pilha *p, int valor) {
    if (!pilhaCheia(p)) {
        p->pilha[++(p->topo)] = valor;
    } else {
        printf("Erro: Pilha cheia!\n");
    }
}

// Remove um valor da pilha
int desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->pilha[(p->topo)--];
    } else {
        printf("Erro: Pilha vazia!\n");
        return -1;  // Valor de erro
    }
}

// Verifica se o caractere é um operador
int ehOperador(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/';
}

// Verifica se o token é um número
int ehNumero(char *token) {
    for (int i = 0; token[i] != '\0'; i++) {
        if (token[i] < '0' || token[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Realiza a operação entre dois números da pilha
void realizarOperacao(Pilha *p, char operador) {
    int b = desempilhar(p);
    int a = desempilhar(p);
    int resultado;

    switch (operador) {
        case '+': resultado = a + b; break;
        case '-': resultado = a - b; break;
        case '*': resultado = a * b; break;
        case '/':
            if (b != 0) resultado = a / b;
            else {
                printf("Erro: Divisão por zero!\n");
                return;
            }
            break;
        default: 
            printf("Erro: Operador inválido!\n"); 
            return;
    }

    empilhar(p, resultado);
}

// Processa a expressão em RPN
void processarRPN(char *entrada) {
    Pilha p;
    inicializar(&p);

    char *token = strtok(entrada, " ");
    while (token != NULL) {
        if (ehNumero(token)) {
            empilhar(&p, atoi(token));  // Coloca o número na pilha
        } else if (ehOperador(token[0])) {
            realizarOperacao(&p, token[0]);  // Realiza a operação
        } else {
            printf("Erro: Entrada inválida!\n");
            return;
        }
        token = strtok(NULL, " ");
    }

    // Mostra o resultado final
    printf("Resultado: %d\n", desempilhar(&p));
}

int main() {
    char entrada[100];
    char opcao;

    do {
        printf("Digite a expressão RPN (exemplo: 5 2 + 3 *): ");
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = 0;  // Remove o \n do final da string

        processarRPN(entrada);

        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c", &opcao);
        getchar();  // Limpa o buffer do \n

    } while (opcao == 's');

    printf("Obrigado por usar nossa Calculadora Fatec-HP12c!\n");
    return 0;
}

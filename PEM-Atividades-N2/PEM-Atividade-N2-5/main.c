#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXPRODUTOS 500

struct Produto {
    int id;
    char nomeProduto[50];
    int quantidadeEstoque;
    float valorProduto;
};

void exibirProduto(struct Produto* ponteiroProdutos, int i) {
    printf("\nID do produto: %d\n", (ponteiroProdutos + i)->id);
    printf("Nome do produto: %s\n", (ponteiroProdutos + i)->nomeProduto);
    printf("Quantidade do produto: %d\n", (ponteiroProdutos + i)->quantidadeEstoque);
    printf("Valor do produto: %.2f\n", (ponteiroProdutos + i)->valorProduto);
}

void incluirProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos, int* ponteiroProdutosExcluidos) {
    (ponteiroProdutos + *ponteiroContadorProdutos)->id = *ponteiroContadorProdutos + (*ponteiroProdutosExcluidos + 1);
    printf("Insira o nome do produto: \n");
    scanf("%49s", (ponteiroProdutos + *ponteiroContadorProdutos)->nomeProduto);
    printf("Insira a quantidade no estoque desse produto: \n");
    while (scanf("%i", &(ponteiroProdutos + *ponteiroContadorProdutos)->quantidadeEstoque) != 1) {
        printf("Erro: valor inválido! Por favor, insira um número.\n");
        while (getchar() != '\n');
    }
    printf("Informe o valor do produto: \n");
    while (scanf("%f", &(ponteiroProdutos + *ponteiroContadorProdutos)->valorProduto) != 1) {
        printf("Erro: valor inválido! Por favor, insira um número.\n");
        while (getchar() != '\n');
    }
    printf("Produto adicionado: %s\n", (ponteiroProdutos + *ponteiroContadorProdutos)->nomeProduto);
    *ponteiroContadorProdutos = *ponteiroContadorProdutos + 1;
}

void consultarProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos) {
    int busca;
    printf("Informe o ID do produto que deseja consultar: ");
    scanf("%i", &busca);
    for (int i = 0; i < *ponteiroContadorProdutos; i++) {
        if (busca == (ponteiroProdutos + i)->id) {
            exibirProduto(ponteiroProdutos, i);
            return;
        }
    }
    printf("Produto inexistente\n");
}

void listarProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos) {
    printf("\nLista de todos os produtos:\n");
    for (int i = 0; i < *ponteiroContadorProdutos; i++) {
        exibirProduto(ponteiroProdutos, i);
    }
}

void alterarProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos) {
    int busca;
    printf("Informe o ID do produto que deseja alterar: ");
    scanf("%i", &busca);
    for (int i = 0; i < *ponteiroContadorProdutos; i++) {
        if (busca == (ponteiroProdutos + i)->id) {
            printf("Produto correspondente: ");
            exibirProduto(ponteiroProdutos, i);
            printf("Insira o novo nome do produto: ");
            scanf("%s", (ponteiroProdutos + i)->nomeProduto);
            printf("Insira a nova quantidade no estoque: ");
            scanf("%i", &(ponteiroProdutos + i)->quantidadeEstoque);
            printf("Informe o novo valor do produto: ");
            scanf("%f", &(ponteiroProdutos + i)->valorProduto);
            return;
        }
    }
    printf("Produto inexistente\n");
}

void mudarProdutos(struct Produto *ponteiroProdutos, int i) {
    int intTemporario;
    float fltTemporario;
    char stringTemporaria[50];
    
    strcpy(stringTemporaria, (ponteiroProdutos + i)->nomeProduto);
    strcpy((ponteiroProdutos + i)->nomeProduto, (ponteiroProdutos + i + 1)->nomeProduto);
    strcpy((ponteiroProdutos + i + 1)->nomeProduto, stringTemporaria);
    
    fltTemporario = (ponteiroProdutos + i)->valorProduto;
    (ponteiroProdutos + i)->valorProduto = (ponteiroProdutos + i + 1)->valorProduto;
    (ponteiroProdutos + i + 1)->valorProduto = fltTemporario;
    
    intTemporario = (ponteiroProdutos + i)->quantidadeEstoque;
    (ponteiroProdutos + i)->quantidadeEstoque = (ponteiroProdutos + i + 1)->quantidadeEstoque;
    (ponteiroProdutos + i + 1)->quantidadeEstoque = intTemporario;
}

int main() {
    struct Produto produtos[MAXPRODUTOS];
    int contadorProdutos = 0;
    int produtosExcluidos = 0;
    int opcao;
    
    do {
        printf("\n1. Incluir Produto\n2. Consultar Produto\n3. Listar Produtos\n4. Alterar Produto\n5. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                incluirProduto(produtos, &contadorProdutos, &produtosExcluidos);
                break;
            case 2:
                consultarProduto(produtos, &contadorProdutos);
                break;
            case 3:
                listarProduto(produtos, &contadorProdutos);
                break;
            case 4:
                alterarProduto(produtos, &contadorProdutos);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);
    
    return 0;
}

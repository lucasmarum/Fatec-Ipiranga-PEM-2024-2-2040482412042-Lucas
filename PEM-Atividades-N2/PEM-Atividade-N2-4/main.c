#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int estoque;
} Produto;

void inserirProduto(Produto *produtos, int *qtd) {
    Produto p;
    printf("ID: ");
    scanf("%d", &p.id);
    printf("Nome: ");
    scanf("%s", p.nome);
    printf("Descrição: ");
    scanf("%s", p.descricao);
    printf("Preço: ");
    scanf("%f", &p.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &p.estoque);
    produtos[(*qtd)++] = p;
}

void listarProdutos(Produto *produtos, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("ID: %d, Nome: %s, Descrição: %s, Preço: %.2f, Estoque: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].descricao,
               produtos[i].preco, produtos[i].estoque);
    }
}

void bubbleSort(Produto *produtos, int qtd) {
    Produto temp;
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

Produto* buscarProduto(Produto *produtos, int qtd, int id) {
    for (int i = 0; i < qtd; i++) {
        if (produtos[i].id == id) {
            return &produtos[i];
        }
    }
    return NULL;
}

void simularCompra(Produto *produtos, int qtd) {
    int id, qtdCompra;
    printf("ID do produto para compra: ");
    scanf("%d", &id);
    Produto *p = buscarProduto(produtos, qtd, id);
    if (p == NULL) {
        printf("Produto Inexistente.\n");
        return;
    }
    printf("Quantidade desejada: ");
    scanf("%d", &qtdCompra);
    if (qtdCompra > p->estoque) {
        printf("Estoque insuficiente.\n");
    } else {
        p->estoque -= qtdCompra;
        printf("Compra realizada com sucesso.\n");
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int qtdProdutos = 0;
    int opcao;

    do {
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Simular compra\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &qtdProdutos);
                break;
            case 2:
                bubbleSort(produtos, qtdProdutos);
                listarProdutos(produtos, qtdProdutos);
                break;
            case 3:
                simularCompra(produtos, qtdProdutos);
                break;
        }
    } while (opcao != 4);

    return 0;
}

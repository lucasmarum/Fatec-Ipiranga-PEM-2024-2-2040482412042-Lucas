/*--------------------------------------------------------*
 * Disciplina: Programaçao Estruturada e Modular           *
 *          Prof. Carlos Veríssimo                        *
 *--------------------------------------------------------*
 * Objetivo do Programa: Simular uma loja de produtos      *
 * eletrônicos com funcionalidades de inserção, listagem,  *
 * ordenação e simulação de compra.                       *
 * Data - 25/10/2024                                      *
 *--------------------------------------------------------*/

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

typedef struct {
    Produto produtos[MAX_PRODUTOS];
    int qtdProdutos;

    void (*inserir)(struct Loja *self);
    void (*listar)(struct Loja *self);
    void (*ordenar)(struct Loja *self);
    void (*comprar)(struct Loja *self);
} Loja;

void inserirProduto(Loja *loja) {
    if (loja->qtdProdutos >= MAX_PRODUTOS) {
        printf("Capacidade máxima atingida!\n");
        return;
    }
    
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
    
    loja->produtos[loja->qtdProdutos++] = p;
}

void listarProdutos(Loja *loja) {
    for (int i = 0; i < loja->qtdProdutos; i++) {
        Produto p = loja->produtos[i];
        printf("ID: %d, Nome: %s, Descrição: %s, Preço: %.2f, Estoque: %d\n",
               p.id, p.nome, p.descricao, p.preco, p.estoque);
    }
}

void bubbleSort(Loja *loja) {
    Produto temp;
    for (int i = 0; i < loja->qtdProdutos - 1; i++) {
        for (int j = 0; j < loja->qtdProdutos - i - 1; j++) {
            if (strcmp(loja->produtos[j].nome, loja->produtos[j + 1].nome) > 0) {
                temp = loja->produtos[j];
                loja->produtos[j] = loja->produtos[j + 1];
                loja->produtos[j + 1] = temp;
            }
        }
    }
}

Produto* buscarProduto(Loja *loja, int id) {
    for (int i = 0; i < loja->qtdProdutos; i++) {
        if (loja->produtos[i].id == id) {
            return &loja->produtos[i];
        }
    }
    return NULL;
}

void simularCompra(Loja *loja) {
    int id, qtdCompra;
    printf("ID do produto para compra: ");
    scanf("%d", &id);
    
    Produto *p = buscarProduto(loja, id);
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
    Loja loja = { .qtdProdutos = 0, .inserir = inserirProduto, .listar = listarProdutos, .ordenar = bubbleSort, .comprar = simularCompra };
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
                loja.inserir(&loja);
                break;
            case 2:
                loja.ordenar(&loja);
                loja.listar(&loja);
                break;
            case 3:
                loja.comprar(&loja);
                break;
        }
    } while (opcao != 4);

    return 0;
}

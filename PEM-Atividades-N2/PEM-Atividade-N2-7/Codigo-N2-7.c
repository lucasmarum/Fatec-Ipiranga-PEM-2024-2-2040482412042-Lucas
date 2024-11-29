#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

// Estrutura de produtos
struct Produtos {
    int idproduto;          // Identificador único
    char nomeproduto[50];   // Nome do produto
    double precoproduto;    // Preço do produto
    int qtdestoque;         // Quantidade em estoque
};

// Função para limpar o buffer de entrada
void limpar_buffer() {
    while (getchar() != '\n');  // Limpar buffer de entrada
}

// Função para adicionar produtos
void AdicionarProdutos(struct Produtos *produtos, int *quantidade) {
    int produtos_a_adicionar;
    printf("Quantos produtos serão adicionados? ");
    while (scanf("%d", &produtos_a_adicionar) != 1 || produtos_a_adicionar <= 0) {
        limpar_buffer();
        printf("Entrada inválida. Digite um número válido de produtos: ");
    }
    limpar_buffer();  // Limpar buffer de entrada

    for (int i = 0; i < produtos_a_adicionar; i++) {
        if (*quantidade >= MAX) {
            printf("Capacidade máxima de produtos atingida.\n");
            break;
        }

        struct Produtos *ptrproduto = &produtos[*quantidade];
        printf("/**************************************************/\n");
        printf("| ID do produto (valor único): ");
        while (scanf("%d", &ptrproduto->idproduto) != 1) {
            limpar_buffer();
            printf("ID inválido. Digite um número válido para o ID: ");
        }

        printf("| Nome do produto: ");
        scanf(" %[^\n]%*c", ptrproduto->nomeproduto);

        printf("| Preço: ");
        while (scanf("%lf", &ptrproduto->precoproduto) != 1 || ptrproduto->precoproduto <= 0) {
            limpar_buffer();
            printf("Preço inválido. Digite um preço válido (maior que 0): ");
        }

        printf("| Quantidade em Estoque: ");
        while (scanf("%d", &ptrproduto->qtdestoque) != 1 || ptrproduto->qtdestoque < 0) {
            limpar_buffer();
            printf("Quantidade inválida. Digite um número válido de estoque: ");
        }

        limpar_buffer();  // Limpar buffer de entrada
        printf("/**************************************************/\n");

        (*quantidade)++;  // Incrementa a quantidade de produtos cadastrados
        printf("Produto com ID %d adicionado com sucesso.\n", ptrproduto->idproduto);
    }
}

// Função para alterar produto
void AlterarProduto(struct Produtos *produtos, int *quantidade, int *id) {
    if (*quantidade == 0) {
        printf("Não há produtos cadastrados para alterar.\n");
        return;
    }

    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].idproduto == *id) {
            printf("/**************************************************/\n");
            printf("| Nome do produto: ");
            scanf(" %[^\n]%*c", produtos[i].nomeproduto);

            printf("| Preço: ");
            while (scanf("%lf", &produtos[i].precoproduto) != 1 || produtos[i].precoproduto <= 0) {
                limpar_buffer();
                printf("Preço inválido. Digite um preço válido (maior que 0): ");
            }

            printf("| Quantidade em Estoque: ");
            while (scanf("%d", &produtos[i].qtdestoque) != 1 || produtos[i].qtdestoque < 0) {
                limpar_buffer();
                printf("Quantidade inválida. Digite um número válido de estoque: ");
            }
            printf("/**************************************************/\n");

            printf("Produto com ID %d alterado com sucesso.\n", *id);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", *id);
}

// Função para consultar produto
void ConsultarProduto(struct Produtos *produtos, int quantidade, int *id) {
    if (quantidade == 0) {
        printf("Não há produtos cadastrados para consultar.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].idproduto == *id) {
            printf("/******************** Produto %d ***************************/\n", *id);
            printf("| Código: %d\n", produtos[i].idproduto);
            printf("| Nome: %s\n", produtos[i].nomeproduto);
            printf("| Preço: %.2lf\n", produtos[i].precoproduto);  // Alterado para double
            printf("| Quantidade em Estoque: %d\n", produtos[i].qtdestoque);
            printf("/**************************************************/\n\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", *id);
}

// Função para excluir produto
void ExcluirProdutos(struct Produtos *produtos, int *quantidade, int *id) {
    if (*quantidade == 0) {
        printf("Não há produtos cadastrados para excluir.\n");
        return;
    }

    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].idproduto == *id) {
            for (int j = i; j < *quantidade - 1; j++) {
                produtos[j] = produtos[j + 1];  // Desloca os produtos para a esquerda
            }
            (*quantidade)--;  // Decrementa a quantidade de produtos
            printf("Produto com ID %d excluído com sucesso.\n", *id);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", *id);
}

// Função para listar produtos
void ListarProdutos(struct Produtos *produtos, int quantidade) {
    if (quantidade == 0) {
        printf("Não há produtos cadastrados para listar.\n");
        return;
    }

    printf("\n\n/******************** Lista de Produtos ********************/\n");
    for (int i = 0; i < quantidade; i++) {
        printf("| Código: %i\n", produtos[i].idproduto);
        printf("| Nome: %s\n", produtos[i].nomeproduto);
        printf("| Preço: %.2lf\n", produtos[i].precoproduto);  // Alterado para double
        printf("| Quantidade em Estoque: %i\n", produtos[i].qtdestoque);
        printf("/**************************************************/\n\n");
    }
}

// Função para garantir que a escolha seja válida
int obter_opcao_menu() {
    int opcao;
    while (1) {
        printf("Digite um número para executar uma função do programa:\n");
        printf("1 - Cadastrar Produto\n2 - Listar Produtos\n3 - Excluir Produtos\n4 - Alterar Produtos\n5 - Consultar Produtos\n6 - Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) == 1 && opcao >= 1 && opcao <= 6) {
            limpar_buffer();  // Limpar buffer de entrada
            return opcao;
        } else {
            limpar_buffer();  // Limpar buffer de entrada
            printf("Opção inválida. Por favor, escolha uma opção entre 1 e 6.\n");
        }
    }
}

int main() {
    struct Produtos produtos[MAX];
    int quantidade = 0;
    int escolha, id;

    do {
        escolha = obter_opcao_menu();  // Obter a opção com validação

        switch (escolha) {
            case 1:
                printf("Insira um produto:\n");
                AdicionarProdutos(produtos, &quantidade);
                break;
            case 2:
                printf("\nListagem dos produtos:\n");
                ListarProdutos(produtos, quantidade);
                break;
            case 3:
                if (quantidade == 0) {
                    printf("Não há produtos cadastrados para excluir.\n");
                    break;
                }
                printf("Insira o ID do produto a ser excluído: ");
                while (scanf("%d", &id) != 1 || id <= 0) {
                    limpar_buffer();
                    printf("ID inválido. Digite um número válido para o ID: ");
                }
                ExcluirProdutos(produtos, &quantidade, &id);
                break;
            case 4:
                if (quantidade == 0) {
                    printf("Não há produtos cadastrados para alterar.\n");
                    break;
                }
                printf("Insira o ID do produto a ser alterado: ");
                while (scanf("%d", &id) != 1 || id <= 0) {
                    limpar_buffer();
                    printf("ID inválido. Digite um número válido para o ID: ");
                }
                AlterarProduto(produtos, &quantidade, &id);
                break;
            case 5:
                if (quantidade == 0) {
                    printf("Não há produtos cadastrados para consultar.\n");
                    break;
                }
                printf("Insira o ID do produto a ser consultado: ");
                while (scanf("%d", &id) != 1 || id <= 0) {
                    limpar_buffer();
                    printf("ID inválido. Digite um número válido para o ID: ");
                }
                ConsultarProduto(produtos, quantidade, &id);
                break;
            case 6:
                printf("Saindo do programa.\n");
                break;
        }
    } while (escolha != 6);

    return 0;
}

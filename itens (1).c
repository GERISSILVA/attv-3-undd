#include <stdio.h>
#include <string.h>
#include "itens.h"

// Funções de manipulação de itens
void CadastrarItem(Item itens[], int *numItens) {
    if (*numItens >= MAX_ITENS) {
        printf("Limite de cadastro de itens atingido!\n");
        return;
    }
    printf("Digite o nome do item: ");
    scanf("%39s", itens[*numItens].nome);
    printf("Digite o preço do item: ");
    scanf("%f", &itens[*numItens].preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &itens[*numItens].estoque);
    printf("O item está em promoção? (1 para sim, 0 para não): ");
    scanf("%d", (int*)&itens[*numItens].promocao);

    (*numItens)++;
    printf("Item cadastrado com sucesso!\n");
}

void ListarItens(Item itens[], int numItens) {
    if (numItens == 0) {
        printf("Nenhum item cadastrado.\n");
        return;
    }
    for (int i = 0; i < numItens; i++) {
        printf("Item %d:\n", i + 1);
        printf("Nome: %s\n", itens[i].nome);
        printf("Preço: R$%.2f\n", itens[i].preco);
        printf("Estoque: %d\n", itens[i].estoque);
        printf("Em promoção: %s\n", itens[i].promocao ? "Sim" : "Não");
        printf("--------------------------\n");
    }
}

void EditarItem(Item itens[], int numItens) {
    int id;
    printf("Digite o número do item que deseja editar: ");
    scanf("%d", &id);
    if (id < 1 || id > numItens) {
        printf("Item inválido!\n");
        return;
    }
    id--;
    printf("Digite o novo nome: ");
    scanf("%39s", itens[id].nome);
    printf("Digite o novo preço: ");
    scanf("%f", &itens[id].preco);
    printf("Digite a nova quantidade em estoque: ");
    scanf("%d", &itens[id].estoque);
    printf("O item está em promoção? (1 para sim, 0 para não): ");
    scanf("%d", (int*)&itens[id].promocao);
    printf("Item editado com sucesso!\n");
}

void ExcluirItem(Item itens[], int *numItens) {
    int id;
    printf("Digite o número do item que deseja excluir: ");
    scanf("%d", &id);
    if (id < 1 || id > *numItens) {
        printf("Item inválido!\n");
        return;
    }
    id--;
    for (int i = id; i < *numItens - 1; i++) {
        itens[i] = itens[i + 1];
    }
    (*numItens)--;
    printf("Item excluído com sucesso!\n");
}

void AplicarDesconto(Item itens[], int numItens) {
    float desconto;
    printf("Digite o percentual de desconto (ex: 10 para 10%%): ");
    scanf("%f", &desconto);
    desconto = desconto / 100;

    for (int i = 0; i < numItens; i++) {
        itens[i].preco -= itens[i].preco * desconto;
    }
    printf("Desconto aplicado com sucesso!\n");
}

void ExibirItensEmPromocao(Item itens[], int numItens) {
    printf("Itens em promoção:\n");
    for (int i = 0; i < numItens; i++) {
        if (itens[i].promocao) {
            printf("Nome: %s, Preço: R$%.2f, Estoque: %d\n", 
                    itens[i].nome, itens[i].preco, itens[i].estoque);
        }
    }
}

void SalvarItens(Item itens[], int numItens) {
    FILE *arquivo = fopen("itens.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(itens, sizeof(Item), numItens, arquivo);
    fclose(arquivo);
    printf("Itens salvos com sucesso!\n");
}

void CarregarItens(Item itens[], int *numItens) {
    FILE *arquivo = fopen("itens.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    *numItens = fread(itens, sizeof(Item), MAX_ITENS, arquivo);
    fclose(arquivo);
    printf("Itens carregados com sucesso!\n");
}

// Função de busca binária
int BuscaBinariaPorPreco(Item itens[], int numItens, float preco) {
    int esquerda = 0, direita = numItens - 1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (itens[meio].preco == preco) {
            return meio;
        } else if (itens[meio].preco < preco) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

// Função de ordenação (QuickSort)
void QuickSort(Item itens[], int esquerda, int direita) {
    int i = esquerda, j = direita;
    float pivo = itens[(esquerda + direita) / 2].preco;
    while (i <= j) {
        while (itens[i].preco < pivo) i++;
        while (itens[j].preco > pivo) j--;
        if (i <= j) {
            Item temp = itens[i];
            itens[i] = itens[j];
            itens[j] = temp;
            i++;
            j--;
        }
    }
    if (esquerda < j) QuickSort(itens, esquerda, j);
    if (i < direita) QuickSort(itens, i, direita);
}

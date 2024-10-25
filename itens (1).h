#ifndef ITENS_H
#define ITENS_H

#define MAX_ITENS 50

typedef struct {
    char nome[40];
    float preco;
    int estoque;
    bool promocao;
} Item;

void CadastrarItem(Item itens[], int *numItens);
void ListarItens(Item itens[], int numItens);
void EditarItem(Item itens[], int numItens);
void ExcluirItem(Item itens[], int *numItens);
void AplicarDesconto(Item itens[], int numItens);
void ExibirItensEmPromocao(Item itens[], int numItens);
void SalvarItens(Item itens[], int numItens);
void CarregarItens(Item itens[], int *numItens);
int BuscaBinariaPorPreco(Item itens[], int numItens, float preco);
void QuickSort(Item itens[], int esquerda, int direita);

#endif

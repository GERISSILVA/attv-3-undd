#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"

// Função para inicializar a lista
void inicializarLista(ListaUsuarios *lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

// Função para cadastrar um usuário
void cadastrarUsuario(ListaUsuarios *lista) {
    Usuario *novoUsuario = (Usuario *)malloc(sizeof(Usuario));
    if (novoUsuario == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    printf("Digite o nome do usuário: ");
    scanf("%s", novoUsuario->nome);
    printf("Digite a senha do usuário: ");
    scanf("%s", novoUsuario->senha);
    printf("Digite o email do usuário: ");
    scanf("%s", novoUsuario->email);

    // Verificar se o email já existe
    if (verificaEmail(lista, novoUsuario->email)) {
        printf("Erro: Email já cadastrado.\n");
        free(novoUsuario);
        return;
    }

    // Inserir o novo usuário na lista
    novoUsuario->proximo = lista->cabeca;
    lista->cabeca = novoUsuario;
    lista->tamanho++;
}

// Função para verificar o login de um usuário
bool verificarLogin(ListaUsuarios *lista, char login[], char senha[]) {
    Usuario *atual = lista->cabeca;
    while (atual != NULL) {
        if (strcmp(atual->nome, login) == 0 && strcmp(atual->senha, senha) == 0) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

// Função para verificar se o email já existe na lista
bool verificaEmail(ListaUsuarios *lista, char email[]) {
    Usuario *atual = lista->cabeca;
    while (atual != NULL) {
        if (strcmp(atual->email, email) == 0) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

// Função para liberar a memória alocada para a lista
void liberarLista(ListaUsuarios *lista) {
    Usuario *atual = lista->cabeca;
    while (atual != NULL) {
        Usuario *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->cabeca = NULL;
    lista->tamanho = 0;
}




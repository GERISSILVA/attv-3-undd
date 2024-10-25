#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"

void inicializarLista(ListaUsuarios *lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

void cadastrarUsuario(ListaUsuarios *lista) {
    Usuario *novoUsuario = (Usuario *)malloc(sizeof(Usuario));
    if (novoUsuario == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    printf("Digite o nome de usuário: ");
    scanf("%39s", novoUsuario->nome);

    printf("Digite o e-mail: ");
    char email[TAM_MAX_EMAIL];
    scanf("%79s", email);

    if (verificaEmail(lista, email)) {
        strcpy(novoUsuario->email, email);
    } else {
        printf("E-mail inválido ou já cadastrado.\n");
        free(novoUsuario);
        return;
    }

    printf("Digite a senha: ");
    scanf("%39s", novoUsuario->senha);

    // Adicionando o novo usuário ao início da lista
    novoUsuario->proximo = lista->cabeca;
    lista->cabeca = novoUsuario;
    lista->tamanho++;

    printf("Usuário cadastrado com sucesso!\n");
}

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

bool verificaEmail(ListaUsuarios *lista, char email[]) {
    if (strchr(email, '@') == NULL || strlen(email) >= TAM_MAX_EMAIL) {
        return false;
    }
    Usuario *atual = lista->cabeca;
    while (atual != NULL) {
        if (strcmp(atual->email, email) == 0) {
            return false;
        }
        atual = atual->proximo;
    }
    return true;
}

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

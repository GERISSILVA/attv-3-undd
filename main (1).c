#include <stdio.h>
#include "usuarios.h"
#include "itens.h"

int main() {
    Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;

    Item itens[MAX_ITENS];
    int numItens = 0;

    CarregarItens(itens, &numItens);

    char login[40], senha[40];
    bool logado = false;

    // Loop para login
    do {
        printf("Digite o login: ");
        scanf("%39s", login);
        printf("Digite a senha: ");
        scanf("%39s", senha);

        if (verificar_login(usuarios, numUsuarios, login, senha)) {
            logado = true;
        } else {
            printf("Login ou senha incorretos!\n");
        }
    } while (!logado);

    printf("Bem-vindo à Loja de Sapatos!\n");

    int opcao;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Item\n");
        printf("2. Listar Itens\n");
        printf("3. Editar Item\n");
        printf("4. Excluir Item\n");
        printf("5. Aplicar Desconto\n");
        printf("6. Exibir Itens em Promoção\n");
        printf("7. Salvar e Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                CadastrarItem(itens, &numItens);
                break;
            case 2:
                ListarItens(itens, numItens);
                break;
            case 3:
                EditarItem(itens, numItens);
                break;
            case 4:
                ExcluirItem(itens, &numItens);
                break;
            case 5:
                AplicarDesconto(itens, numItens);
                break;
            case 6:
                ExibirItensEmPromocao(itens, numItens);
                break;
            case 7:
                SalvarItens(itens, numItens);
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 7);

    return 0;
}


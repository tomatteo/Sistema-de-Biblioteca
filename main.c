#include <stdio.h>
#include <stdlib.h>

#include "livro.h"
#include "lista.h"

int main() {

    No* biblioteca = criar_lista();

    int opcao;

    do {

        printf("\n===== SISTEMA BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Exibir biblioteca\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {

            case 1: {

                struct Livro novoLivro;

                novoLivro = criar_livro();

                inserir_livro(&biblioteca, novoLivro);

                printf("\nLivro cadastrado com sucesso!\n");

                break;
            }

            case 2: {

                printf("\n===== LIVROS CADASTRADOS =====\n");

                exibir_biblioteca(biblioteca);

                break;
            }

            case 0: {

                printf("\nEncerrando sistema...\n");

                break;
            }

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
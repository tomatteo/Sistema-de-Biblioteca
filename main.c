#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "livro.h"
#include "lista.h"

int main() {
    No* biblioteca = criar_lista();
    Pilha historico;
    inicializarPilha(&historico);   
    int opcao;

    do {
        printf("\n===== SISTEMA BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Buscar livro\n");
        printf("3 - Remover livro\n");
        printf("4 - Exibir biblioteca\n");
        printf("5 - Emprestar livro\n");
        printf("6 - Devolver livro\n");
        printf("7 - Mostrar historico\n");
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
                push(&historico, "Livro cadastrado");

                break;
            }

            case 2: {

                int id;

                printf("Digite o ID do livro: ");
                scanf("%d", &id);

                struct Livro *livro = buscar_livro(biblioteca, id);

                if (livro != NULL)
                {
                    exibir_livro(*livro);
                }
                else
                {
                    printf("Livro nao encontrado!\n");
                }

                break;
            }

            case 3: {

                int id;

                printf("Digite o ID do livro: ");
                scanf("%d", &id);

                if (remover_livro(&biblioteca, id))
                {
                    printf("Livro removido com sucesso!\n");
                    push(&historico, "Livro removido");
                }
                else
                {
                    printf("Livro nao encontrado!\n");
                }

                break;
            }

            case 4: {

                printf("\n===== LIVROS CADASTRADOS =====\n");
                exibir_biblioteca(biblioteca);

                break;
            }

            case 5: {

                int id;

                printf("Digite o ID do livro: ");
                scanf("%d", &id);

                if (emprestar_livro(biblioteca, id))
                {
                    printf("Emprestimo realizado!\n");
                    push(&historico, "Emprestimo realizado");
                }
                else
                {
                    printf("Nao foi possivel realizar o emprestimo.\n");
                }

                break;
            }

            case 6: {

                int id;

                printf("Digite o ID do livro: ");
                scanf("%d", &id);

                if (devolver_livro(biblioteca, id))
                {
                    printf("Devolucao realizada!\n");
                    push(&historico, "Devolucao realizada");
                }
                else
                {
                    printf("Livro nao encontrado!\n");
                }

                break;
            }

            case 7: {

                mostrarHistorico(&historico);

                break;
            }

            case 0: {

                printf("\nEncerrando sistema...\n");

                liberar_lista(biblioteca);
                liberarPilha(&historico);

                break;
            }

            default:
                printf("\nOpcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
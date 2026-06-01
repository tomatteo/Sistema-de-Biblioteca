#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "lista.h"
#include "pilha.h" // Inclui o módulo da pilha do João

int main() {
    No* biblioteca = criar_lista();
    
    // Inicializa a estrutura da pilha do João
    Pilha historico;
    inicializarPilha(&historico);
    
    int opcao;
    int idDigitado;    // Variável para ler os IDs nas buscas/remoções
    char msg[250];     // Buffer para formatar as mensagens do histórico

    do {
        printf("\n===== SISTEMA BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Exibir biblioteca\n");
        printf("3 - Buscar livro por ID\n");
        printf("4 - Remover livro\n");
        printf("5 - Pegar livro emprestado (-1)\n");
        printf("6 - Devolver livro (+1)\n");
        printf("7 - Ver historico de operacoes (Pilha)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1: {
                struct Livro novoLivro;
                novoLivro = criar_livro();
                inserir_livro(&biblioteca, novoLivro);
                snprintf(msg, sizeof(msg), "Cadastro: Livro '%s' (ID: %d) adicionado.", novoLivro.titulo, novoLivro.id);
                push(&historico, msg);
                
                printf("\nLivro cadastrado com sucesso!\n");
                break;
            }

            case 2: {
                printf("\n===== LIVROS CADASTRADOS =====\n");
                exibir_biblioteca(biblioteca);
                break;
            }

            case 3: {
                printf("\nDigite o ID do livro que deseja buscar: ");
                scanf("%d", &idDigitado);
                
                struct Livro* encontrado = buscar_livro(biblioteca, idDigitado);
                if (encontrado != NULL) {
                    exibir_livro(*encontrado);
                } else {
                    printf("\nLivro com ID %d nao encontrado.\n", idDigitado);
                }
                break;
            }

            case 4: {
                printf("\nDigite o ID do livro que deseja remover: ");
                scanf("%d", &idDigitado);
                struct Livro* l_rem = buscar_livro(biblioteca, idDigitado);
                if (l_rem != NULL) {
                    snprintf(msg, sizeof(msg), "Remocao: Livro '%s' (ID: %d) removido do sistema.", l_rem->titulo, idDigitado);
                    
                    remover_livro(&biblioteca, idDigitado);
                    push(&historico, msg);
                    printf("\nLivro removido com sucesso!\n");
                } else {
                    printf("\nLivro com ID %d nao encontrado para remocao.\n", idDigitado);
                }
                break;
            }

            case 5: {
                printf("\nDigite o ID do livro para emprestimo: ");
                scanf("%d", &idDigitado);
                
                struct Livro* l_emp = buscar_livro(biblioteca, idDigitado);
                if (l_emp != NULL) {
                    if (emprestar_livro(biblioteca, idDigitado)) {
                        snprintf(msg, sizeof(msg), "Emprestimo: Uma unidade de '%s' (ID: %d) retirada.", l_emp->titulo, idDigitado);
                        push(&historico, msg);
                        printf("\nEmprestimo registrado com sucesso!\n");
                    }
                } else {
                    printf("\nLivro com ID %d nao encontrado.\n", idDigitado);
                }
                break;
            }

            case 6: {
                printf("\nDigite o ID do livro para devolucao: ");
                scanf("%d", &idDigitado);
                
                struct Livro* l_dev = buscar_livro(biblioteca, idDigitado);
                if (l_dev != NULL) {
                    devolver_livro(biblioteca, idDigitado);
                    
                    snprintf(msg, sizeof(msg), "Devolucao: Uma unidade de '%s' (ID: %d) devolvida.", l_dev->titulo, idDigitado);
                    push(&historico, msg);
                    printf("\nDevolucao registrada com sucesso!\n");
                } else {
                    printf("\nLivro com ID %d nao pertence a este catálogo.\n", idDigitado);
                }
                break;
            }

            case 7: {
                mostrarHistorico(&historico);
                break;
            }

            case 0: {
                printf("\nEncerrando sistema e limpando memoria...\n");
                break;
            }
            
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(opcao != 0);

    liberarPilha(&historico);
    while (biblioteca != NULL) {
        remover_livro(&biblioteca, biblioteca->livro.id);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "livro.h"
#include "lista.h"   


#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define CYAN    "\x1b[36m"
#define BOLD    "\x1b[1m"


void aguardar_usuario() {
    printf("\nPressione " BOLD "ENTER" RESET " para continuar...");
    getchar();
}

int main() {
    // inicializa a biblioteca e o histórico
    No* biblioteca = criar_lista();

    Pilha historico;
    inicializarPilha(&historico);   
    
    int opcao;

    //loop do menu
    do {
        system("clear");
        
        printf(BLUE "==================================================\n" RESET);
        printf(BOLD CYAN "            SISTEMA DE BIBLIOTECA                 \n" RESET);
        printf(BLUE "==================================================\n" RESET);
        printf(BOLD " [1]" RESET " Cadastrar Novo Livro\n");
        printf(BOLD " [2]" RESET " Buscar Livro por ID\n");
        printf(BOLD " [3]" RESET " Remover Livro do Catálogo\n");
        printf(BOLD " [4]" RESET " Exibir Catálogo de Livros\n");
        printf(BOLD " [5]" RESET " Emprestar Livro\n");
        printf(BOLD " [6]" RESET " Devolver Livro\n");
        printf(BOLD " [7]" RESET " Visualizar Histórico de Operações\n");
        printf(YELLOW BOLD " [0]" RESET YELLOW " Sair do Sistema\n" RESET);
        printf(BLUE "--------------------------------------------------\n" RESET);
        printf("Escolha uma opção: ");
        
        // evita q o usuario digite algo q n é do menu
        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
            getchar();
        } else {
            getchar();
        }

        //menu
        switch(opcao) {
            
            // cadastrar livro
            case 1: {
                system("clear");
                printf(BOLD CYAN ">>> CADASTRAR LIVRO <<<\n\n" RESET);
                
                struct Livro novoLivro = criar_livro(); //preenche a struct do livro
                
                inserir_livro(&biblioteca, novoLivro);
                
                printf(GREEN BOLD "\n[SUCESSO] Livro cadastrado com sucesso!\n" RESET);
                
                // adiciona a acao no historico
                push(&historico, "Livro cadastrado");
                
                aguardar_usuario();
                break;
            }

            case 2: {
                system("clear");
                printf(BOLD CYAN ">>> BUSCAR LIVRO <<<\n\n" RESET);
                int id;
                printf("Digite o ID do livro: ");
                scanf("%d", &id);
                getchar();

                struct Livro *livro = buscar_livro(biblioteca, id);
                printf("\n");
                
                // se o livro exite exibe detalhes
                if (livro != NULL) {
                    exibir_livro(*livro);
                } else {
                    printf(RED BOLD "[ERRO] Livro não encontrado!\n" RESET);
                }
                aguardar_usuario();
                break;
            }

            // remove o livro do catalogo pelo id
            case 3: {
                system("clear");
                printf(BOLD CYAN ">>> REMOVER LIVRO <<<\n\n" RESET);
                int id;
                printf("Digite o ID do livro para remoção: ");
                scanf("%d", &id);
                getchar();

                // ajusta ponteiro da lista para remover quem tiver o id digitado
                if (remover_livro(&biblioteca, id)) {
                    printf(GREEN BOLD "\n[SUCESSO] Livro removido com sucesso!\n" RESET);
                    // empilha a ação na estrutura do histórico
                    push(&historico, "Livro removido");
                } else {
                    printf(RED BOLD "\n[ERRO] Livro não encontrado!\n" RESET);
                }
                aguardar_usuario();
                break;
            }

            // exibir o catalogo
            case 4: {
                system("clear");
                // percorre a lista de livros e exibe o id e quantidade
                exibir_biblioteca(biblioteca);
                aguardar_usuario();
                break;
            }

            // empresta o livro
            case 5: {
                system("clear");
                printf(BOLD CYAN ">>> EMPRESTAR LIVRO <<<\n\n" RESET);
                int id;
                printf("Digite o ID do livro: ");
                scanf("%d", &id);
                getchar();

                // localiza o livro eno estoque e decrementa a quantidade se disponivel
                if (emprestar_livro(biblioteca, id)) {
                    printf(GREEN BOLD "\n[SUCESSO] Empréstimo realizado com sucesso!\n" RESET);
                    push(&historico, "Empréstimo realizado");
                } else {
                    printf(RED BOLD "\n[ERRO] Não foi possível realizar o empréstimo.\n" RESET);
                }
                aguardar_usuario();
                break;
            }

            // devolver o livro
            case 6: {
                system("clear");
                printf(BOLD CYAN ">>> DEVOLVER LIVRO <<<\n\n" RESET);
                int id;
                printf("Digite o ID do livro: ");
                scanf("%d", &id); //busca pelo id
                getchar();

                //localiza o livro pra devolver
                if (devolver_livro(biblioteca, id)) {
                    printf(GREEN BOLD "\n[SUCESSO] Devolução realizada com sucesso!\n" RESET);
                    push(&historico, "Devolução realizada");
                } else { 
                    printf(RED BOLD "\n[ERRO] Livro não encontrado no catálogo!\n" RESET);
                }
                aguardar_usuario();
                break;
            }

            // vizualizar o historico de opecoes
            case 7: {
                system("clear");
                mostrarHistorico(&historico);
                aguardar_usuario();
                break;
            }

            // sair do sistema
            case 0: {
                system("clear");
                printf(YELLOW BOLD "\nEncerrando sistema.\n" RESET);
                
                // pevitar memory leaks (vazamento de memoria)
                liberar_lista(biblioteca);
                liberarPilha(&historico);
                break;
            }
            default:
                printf(RED BOLD "\n[AVISO] Opção inválida! Tente novamente.\n" RESET);
                aguardar_usuario();
        }
    } while(opcao != 0);

    return 0;
}
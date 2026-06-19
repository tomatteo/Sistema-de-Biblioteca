#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Cria uma lista vazia
No* criar_lista() {
    return NULL; // O topo aponta para NULL, indicando que não há elementos
}

// Insere um novo livro no início da lista
void inserir_livro(No** topo, struct Livro novo_livro) {

    // Aloca memória dinamicamente para um novo nó
    No* novo_no = (No*)malloc(sizeof(No));

    // Verifica se a alocação foi bem-sucedida
    if (novo_no == NULL)
        return;

    // Copia os dados do livro para o novo nó
    novo_no->livro = novo_livro;

    // O novo nó aponta para o antigo primeiro elemento
    novo_no->proximo = *topo;

    // Atualiza o topo da lista para o novo nó
    *topo = novo_no;
}

// Exibe todos os livros cadastrados na biblioteca
void exibir_biblioteca(No* topo) {

    // Cria um ponteiro para percorrer a lista
    No* atual = topo;

    // Verifica se a lista está vazia
    if (atual == NULL) {
        printf("Biblioteca vazia!\n");
        return;
    }

    // Percorre todos os nós da lista
    while (atual != NULL) {

        // Exibe informações básicas do livro
        printf("ID: %d | Titulo: %s\n",
               atual->livro.id,
               atual->livro.titulo);

        // Avança para o próximo nó
        atual = atual->proximo;
    }
}

// Busca um livro pelo ID
struct Livro* buscar_livro(No* topo, int id) {

    // Cria um ponteiro para percorrer a lista
    No* atual = topo;

    // Percorre todos os nós
    while (atual != NULL) {

        // Verifica se o ID informado corresponde ao livro atual
        if (atual->livro.id == id) {

            // Retorna o endereço do livro encontrado
            return &(atual->livro);
        }

        atual = atual->proximo;
    }

    // Retorna NULL caso o livro não seja encontrado
    return NULL;
}

// Remove um livro da lista utilizando o ID
int remover_livro(No** topo, int id) {

    // Ponteiro para o nó atual
    No* atual = *topo;

    // Ponteiro para guardar o nó anterior
    No* anterior = NULL;

    // Procura o livro desejado
    while (atual != NULL && atual->livro.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Livro não encontrado
    if (atual == NULL)
        return 0;

    // Caso o livro esteja no início da lista
    if (anterior == NULL) {

        // O topo passa a apontar para o próximo nó
        *topo = atual->proximo;

    } else {

        // O nó anterior passa a apontar para o próximo do atual
        // "pulando" o nó removido
        anterior->proximo = atual->proximo;
    }

    // Libera a memória ocupada pelo nó removido
    free(atual);

    return 1; // Remoção realizada com sucesso
}

// Realiza o empréstimo de um livro
int emprestar_livro(No* topo, int id) {

    No* atual = topo;

    // Procura o livro pelo ID
    while (atual != NULL) {

        if (atual->livro.id == id) {

            // Verifica se há exemplares disponíveis
            if (atual->livro.quantidade > 0) {

                // Reduz uma unidade do estoque
                atual->livro.quantidade--;

                return 1; // Empréstimo realizado

            } else {

                // Não há livros disponíveis
                printf("Desculpe, o livro '%s' esta esgotado no momento\n",
                       atual->livro.titulo);

                return 0;
            }
        }

        atual = atual->proximo;
    }

    // Livro não encontrado
    return 0;
}

// Registra a devolução de um livro
int devolver_livro(No* topo, int id) {

    No* atual = topo;

    // Procura o livro pelo ID
    while (atual != NULL) {

        if (atual->livro.id == id) {

            // Incrementa a quantidade disponível
            atual->livro.quantidade++;

            return 1; // Devolução realizada
        }

        atual = atual->proximo;
    }

    // Livro não encontrado
    return 0;
}

// Libera toda a memória utilizada pela lista
void liberar_lista(No* topo) {

    No* temp;

    // Percorre todos os nós
    while (topo != NULL) {

        // Guarda o nó atual
        temp = topo;

        // Avança para o próximo nó
        topo = topo->proximo;

        // Libera a memória do nó anterior
        free(temp);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_lista() {
    return NULL;
}

void inserir_livro(No** topo, struct Livro novo_livro) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) return;

    novo_no->livro = novo_livro;
    novo_no->proximo = *topo;
    *topo = novo_no;
}

void exibir_biblioteca(No* topo) {
    No* atual = topo; 
    
    printf("===== LIVROS CADASTRADOS =====\n");
    if (atual == NULL) {
        printf("Biblioteca vazia!\n");
        printf("==============================\n");
        return;
    }

    while (atual != NULL) {
        printf("ID: %d | Titulo: %s (Estoque: %d)\n", atual->livro.id, atual->livro.titulo, atual->livro.quantidade);
        atual = atual->proximo;
    }
    printf("==============================\n");
}

struct Livro* buscar_livro(No* topo, int id) {
    No* current = topo;
    while (current != NULL) {
        if (current->livro.id == id) {
            return &(current->livro);
        }
        current = current->proximo;
    }
    return NULL;
}

int remover_livro(No** topo, int id) {
    No* atual = *topo;
    No* anterior = NULL;

    while (atual != NULL && atual->livro.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return 0;

    if (anterior == NULL) {
        *topo = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}

int emprestar_livro(No* topo, int id) {
    No* atual = topo;
    while (atual != NULL) {
        if (atual->livro.id == id) {
            if (atual->livro.quantidade > 0) {
                atual->livro.quantidade--;
                return 1;
            } else {
                printf("Desculpe, o livro '%s' esta esgotado no momento.\n", atual->livro.titulo);
                return 0;
            }
        }
        atual = atual->proximo;
    }
    return 0;
}

int devolver_livro(No* topo, int id) {
    No* atual = topo;
    while (atual != NULL) {
        if (atual->livro.id == id) {
            atual->livro.quantidade++;
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void liberar_lista(No* topo) {
    No* temp;
    while (topo != NULL) {
        temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}
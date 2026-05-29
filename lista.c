#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_lista() {
    return NULL; // lista comeca vazia
}

void inserir_livro(No** topo, struct Livro novo_livro) {
    No* novo_no = (No*)malloc(sizeof(No)); // aloca memoria pro no
    if (novo_no == NULL) return;

    novo_no->livro = novo_livro; // poem o livro no no
    novo_no->proximo = *topo;    // aponta pro antigo primeiro
    *topo = novo_no;             // o novo no vira o primeiro da lista
}

void exibir_biblioteca(No* topo) {
    No* atual = topo; // comeca do inicio
    
    if (atual == NULL) {
        printf("Biblioteca vazia!\n");
        return;
    }

    while (atual != NULL) {
        printf("ID: %d | Titulo: %s\n", atual->livro.id, atual->livro.titulo);
        atual = atual->proximo; // anda pro proximo no
    }
}

struct Livro* buscar_livro(No* topo, int id) {
    No* atual = topo;

    while (atual != NULL) {
        if (atual->livro.id == id) {
            return &(atual->livro); // Retorna o endereco do livro encontrado
        }
        atual = atual->proximo;
    }
    return NULL; // se nao encontrar, retorna vazio
}

// Remove um livro pelo ID
int remover_livro(No** topo, int id) {
    No* atual = *topo;
    No* anterior = NULL;

    // procura o livro guardando o no anterior
    while (atual != NULL && atual->livro.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return 0; // livro nao encontrado

    
    if (anterior == NULL) {
        *topo = atual->proximo;
    } else { // Se estiver no meio ou fim
        anterior->proximo = atual->proximo;
    }

    free(atual); // libera a memoria do no deletado
    return 1;
}
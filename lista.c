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
#ifndef LISTA_H
#define LISTA_H

#include "livro.h"

// No da lista encadeada
typedef struct No {
    struct Livro livro;
    struct No* proximo; // aponta para o proximo livro
} No;

// funcoes da lista
No* criar_lista();
void inserir_livro(No** topo, struct Livro novo_livro);
void exibir_biblioteca(No* topo);

#endif
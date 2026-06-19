#ifndef LISTA_H
#define LISTA_H

#include "livro.h"

// Estrutura que representa cada nó da lista encadeada
typedef struct No {
    // Dados do livro armazenado
    struct Livro livro;
    // Ponteiro para o próximo nó
    struct No* proximo;
} No;

No* criar_lista(); //Vazia
void inserir_livro(No** topo, struct Livro novo_livro); //No inicio da lista
void exibir_biblioteca(No* topo);
struct Livro* buscar_livro(No* topo, int id); //Busca pelo Id
int remover_livro(No** topo, int id); // Remove pelo Id
int emprestar_livro(No* topo, int id); // Empresta pelo Id
int devolver_livro(No* topo, int id); // Devolve pelo Id
void liberar_lista(No* topo); // Libera todas as memorias da lista

#endif
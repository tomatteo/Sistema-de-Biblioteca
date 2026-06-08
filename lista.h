#ifndef LISTA_H
#define LISTA_H

#include "livro.h"

typedef struct No {
    struct Livro livro;
    struct No* proximo; 
} No;

No* criar_lista();

void inserir_livro(No** topo, struct Livro novo_livro);
void exibir_biblioteca(No* topo);
struct Livro* buscar_livro(No* topo, int id);       
int remover_livro(No** topo, int id);
int emprestar_livro(No* topo, int id);
int devolver_livro(No* topo, int id);         
void liberar_lista(No* topo);     

#endif
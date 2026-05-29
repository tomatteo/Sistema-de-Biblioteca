#ifndef PILHA_H
#define PILHA_H

typedef struct Operacao {
    char descricao[200];
    struct Operacao *prox;
} Operacao;

typedef struct {
    Operacao *topo;
} Pilha;

// Inicializar pilha
void inicializarPilha(Pilha *p);

// Inserir operação
void push(Pilha *p, char descricao[]);

// Remover operação
void pop(Pilha *p);

// Mostrar histórico
void mostrarHistorico(Pilha *p);

// Liberar memória
void liberarPilha(Pilha *p);

#endif
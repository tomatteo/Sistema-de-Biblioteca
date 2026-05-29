#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

void push(Pilha *p, char descricao[]) {
    Operacao *novo = (Operacao*) malloc(sizeof(Operacao));
    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        return;
    }

    strcpy(novo->descricao, descricao);
    novo->prox = p->topo;
    p->topo = novo;
}

void pop(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    Operacao *temp = p->topo;
    p->topo = temp->prox;
    free(temp);
}

void mostrarHistorico(Pilha *p) {
    if (p->topo == NULL) {
        printf("Nenhuma operacao registrada.\n");
        return;
    }

    Operacao *aux = p->topo;
    printf("\n=== HISTORICO ===\n");
    while (aux != NULL) {
        printf("%s\n", aux->descricao);
        aux = aux->prox;
    }
}

void liberarPilha(Pilha *p) {
    Operacao *aux;
    while (p->topo != NULL) {
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }
}
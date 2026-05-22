#include <stdio.h>
#include <string.h>
#include "livro.h"

struct Livro criar_livro() {
    struct Livro l;

    printf("Digite o ID: ");
    scanf("%d", &l.id);
    getchar(); 

    printf("Digite o titulo: ");
    fgets(l.titulo, 50, stdin);
    l.titulo[strcspn(l.titulo, "\n")] = '\0'; 

    printf("Digite o autor: ");
    fgets(l.autor, 50, stdin);
    l.autor[strcspn(l.autor, "\n")] = '\0'; 

    printf("Digite o ano: ");
    scanf("%d", &l.ano_publicacao);

    printf("Digite a quantidade: ");
    scanf("%d", &l.quantidade);

    return l;
}

void exibir_livro(struct Livro l) {
    printf("--- Detalhes do Livro ---\n");
    printf("ID: %d\n", l.id);
    printf("Titulo: %s\n", l.titulo);
    printf("Autor: %s\n", l.autor);
    printf("Ano: %d\n", l.ano_publicacao);
    printf("Quantidade em estoque: %d\n", l.quantidade);
}
#ifndef LIVRO_H
#define LIVRO_H

struct Livro {
    int id;               
    char titulo[50];
    char autor[50];
    int ano_publicacao;
    int quantidade;
    int qtd_maxima; 
};

struct Livro criar_livro();
void exibir_livro(struct Livro l);

#endif
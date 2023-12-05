#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct no {
    int dado;
    struct No* proximo;
} no;
typedef struct no No;

struct listaLigadaEstatica {
    No elementos[100];
    int tamanho;
};
typedef struct listaLigadaEstatica ListaLigadaEstatica;

void percorrerConstruirL1(ListaLigadaEstatica* L, ListaLigadaEstatica* L1);
void percorrerConstruirL2(ListaLigadaEstatica* L, ListaLigadaEstatica* L2);
void liberarLista(ListaLigadaEstatica* lista);

#endif // LISTAALUNOS_INCLUDED

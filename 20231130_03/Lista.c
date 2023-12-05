#include <stdio.h>
#include <stdlib.h>

#include <Lista.h>

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

void percorrerConstruirL1(ListaLigadaEstatica* L, ListaLigadaEstatica* L1) {
    L1->tamanho = L->tamanho;

    for (int i = 1; i < L->tamanho; i++) {
        L1->elementos[i - 1] = L->elementos[i];
    }

    L1->elementos[L1->tamanho - 1] = L->elementos[0];
}

void percorrerConstruirL2(ListaLigadaEstatica* L, ListaLigadaEstatica* L2) {
    L2->tamanho = L->tamanho;

    for (int i = L->tamanho - 1, j = 0; i >= 0; i--, j++) {
        L2->elementos[j] = L->elementos[i];
    }
}

void liberarLista(ListaLigadaEstatica* lista) {
    free(lista);
}

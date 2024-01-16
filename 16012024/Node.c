
// tabela_hash.c

#include <stdio.h>
#include <stdlib.h>

#include "Node.h"

int funcaoHash(int chave, int tamanho) {
    return (2 * chave + 5) % tamanho;
}

void inicializarTabela(struct TabelaHash* tabela, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabela->tabela[i] = NULL;
    }
}

void inserirNaTabela(struct TabelaHash* tabela, int chave, int tamanho) {
    int indice = funcaoHash(chave, tamanho);
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->chave = chave;
    novoNo->proximo = NULL;

    if (tabela->tabela[indice] == NULL) {
        tabela->tabela[indice] = novoNo;
    } else {
        novoNo->proximo = tabela->tabela[indice];
        tabela->tabela[indice] = novoNo;
    }
}

void imprimirTabela(struct TabelaHash* tabela, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Posição %d: ", i);
        struct Node* atual = tabela->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->chave);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

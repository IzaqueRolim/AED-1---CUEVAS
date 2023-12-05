#include <stdio.h>
#include <stdlib.h>
#include <Lista.h>

int main() {

    ListaLigadaEstatica *L = (ListaLigadaEstatica*)malloc(sizeof(ListaLigadaEstatica));
    L->tamanho = 5;
    for (int i = 0; i < L->tamanho; i++) {
        L->elementos[i].dado = i + 1;
        L->elementos[i].proximo = NULL;
    }

    ListaLigadaEstatica *L1 = (ListaLigadaEstatica*)malloc(sizeof(ListaLigadaEstatica));
    ListaLigadaEstatica *L2 = (ListaLigadaEstatica*)malloc(sizeof(ListaLigadaEstatica));

    percorrerConstruirL1(L, L1);
    percorrerConstruirL2(L, L2);

    printf("A)L1: ");
    for (int i = 0; i < L1->tamanho; i++) {
        printf("%d ", L1->elementos[i].dado);
    }
    printf("\nB)L1: ");
    for (int i = 0; i < L2->tamanho; i++) {
        printf("%d ", L2->elementos[i].dado);
    }

    free(L);
    free(L1);
    free(L2);

    return 0;
}

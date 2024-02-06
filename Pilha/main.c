#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro {
    int codigo;
    char chapa[10];
    char *modelo;
} CARRO;

typedef struct elemento {
    CARRO carro;
    struct elemento *proximoCarro;
} ELEMENTO;

typedef struct pilha {
    ELEMENTO *topo;
} PILHA;

PILHA *push(PILHA *pilha, CARRO novoCarro) {
    ELEMENTO *novoElemento = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    if (novoElemento == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    novoElemento->carro = novoCarro;
    novoElemento->proximoCarro = pilha->topo;
    pilha->topo = novoElemento;

    return pilha;
}

CARRO pop(PILHA *pilha) {
    if (pilha->topo == NULL) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    ELEMENTO *elementoRemovido = pilha->topo;
    CARRO carroRemovido = elementoRemovido->carro;

    pilha->topo = pilha->topo->proximoCarro;
    free(elementoRemovido);

    return carroRemovido;
}

int main() {
    PILHA *pilha;
    CARRO carro;

    printf("Digite o codigo do carro:");
    scanf("%d",&carro.codigo);
    printf("Digite a chapa do carro:");
   // fgets(carro.chapa);
     scanf("%s",&carro.chapa);

    fget
    printf("Digite o modelo do carro:");
    fgetc(carro.modelo);
}

#include <stdio.h>
#include <stdlib.h>

#include <Lista.h>

typedef struct lista Lista;

Lista *CriaLista(int tamanho){
    Lista *retorno = malloc(sizeof(Lista));
    int* elementos = malloc(tamanho * sizeof(int));

    retorno->elementos = elementos;
    retorno->tamanho = tamanho;
    return retorno;
}

void PreencherValoresDaListaAutomaticamente(Lista *lista){
    for(int i = 1;i<lista->tamanho;i++){
        lista->elementos[i] = i;
    }
}


void PreencherValoresDaLista(Lista *lista){
    if(lista == NULL){
        return;
    }

    printf("Por Favor preencha a lista\n");
    for(int i = 0;i<lista->tamanho;i++){
        printf("   Elemento %d da lista: ",i);
        int elemento;
        scanf("%d",&elemento);
        lista->elementos[i] = elemento;
    }
}

void buscaBinariaRecursiva(Lista *lista, int numeroProcurado,int inicio, int fim) {
    if (inicio > fim) {
        printf("Numero nao encontrado");
        return;
    }

    int meio = (inicio + fim) / 2;

    if (lista->elementos[meio] == numeroProcurado) {
        printf("Numero %d encontrado na posicao %d",numeroProcurado,meio);
    } else if (lista->elementos[meio] < numeroProcurado) {
        buscaBinariaRecursiva(lista, numeroProcurado, meio + 1, fim);
    } else {
        buscaBinariaRecursiva(lista, numeroProcurado, inicio, meio - 1);
    }
}
void exibirListaDeFormaRecursiva(Lista *lista, int indice) {
    if (indice == lista->tamanho) {
        return;
    }
    printf("Elemento: %d: %d\n", indice, lista->elementos[indice]);
    exibirListaDeFormaRecursiva(lista, indice + 1);
}


int somaElementosRecursivo(Lista *lista, int tamanho, int indice) {
    if (indice == tamanho - 1) {
        return lista->elementos[indice];
    } else {
        return lista->elementos[indice] + somaElementosRecursivo(lista, tamanho, indice + 1);
    }
}

int produtoDosElementosRecursivo(Lista *lista, int tamanho, int indice) {
    if (indice == tamanho - 1) {
        return lista->elementos[indice];
    } else {
        return lista->elementos[indice] * produtoDosElementosRecursivo(lista, tamanho, indice + 1);
    }
}

int retornarMenorNumeroRecursivo(Lista *lista, int indice) {
    if (lista == NULL || indice >= lista->tamanho) {
        return -1;
    }

    int menorRestante = retornarMenorNumeroRecursivo(lista, indice + 1);

    if (menorRestante == -1 || lista->elementos[indice] < menorRestante) {
        return lista->elementos[indice];
    } else {
        return menorRestante;
    }
}

int retornarMaiorNumeroRecursivo(Lista *lista, int indice) {
    if (lista == NULL || indice >= lista->tamanho) {
        return -1;
    }

    int maiorRestante = retornarMaiorNumeroRecursivo(lista, indice + 1);

    if (maiorRestante == -1 || lista->elementos[indice] > maiorRestante) {
        return lista->elementos[indice];
    } else {
        return maiorRestante;
    }
}

void DestruirLista(Lista* lista){
    free(lista->elementos);
    free(lista);
}

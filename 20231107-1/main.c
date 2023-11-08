#include <stdio.h>
#include <stdlib.h>

struct lista{
  int* elementos;
  int tamanho;
};

typedef struct lista Lista;

Lista *CriaLista(int tamanho){
    Lista *retorno = malloc(sizeof(Lista));
    int* elementos = malloc(tamanho * sizeof(int));

    retorno->elementos = elementos;
    retorno->tamanho = tamanho;
    return retorno;
}

void PreencherValoresDaListaAutomaticamente(Lista *lista){
    for(int i = i;i<lista->tamanho;i++){
        lista->elementos[i] = i*2+1;
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

void ExibirLista(Lista *lista){
    if(lista == NULL){
        return;
    }
    printf("INICIO DA EXIBICAO DOS ELEMENTOS\n\n");
    for(int i = 0; i< lista->tamanho;i++){
        printf("Elemento %d da Lista: %d\n",i, lista->elementos[i]);
    }
    printf("\nFIM DA EXIBICAO DOS ELEMENTOS\n\n");
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
        printf("Elemento: %d\n", lista->elementos[indice]);
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



void DestruirLista(Lista* lista){
    free(lista->elementos);
    free(lista);
}


int main() {
    Lista* lista = CriaLista(10);
    PreencherValoresDaListaAutomaticamente(lista);
    exibirListaDeFormaRecursiva(lista,0);
    buscaBinariaRecursiva(lista,16,0,lista->tamanho-1);

    printf("\nSoma de todos os elementos de forma RECURSIVA: %d\n",somaElementosRecursivo(lista,lista->tamanho,0));
    printf("Produto de todos os elementos de forma RECURSIVA: %d\n",produtoDosElementosRecursivo(lista,lista->tamanho,0));

    DestruirLista(lista);

    return 0;
}

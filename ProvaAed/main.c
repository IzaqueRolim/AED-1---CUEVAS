#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct listaSequencial {
    int array[MAX_SIZE];
    int size;
};

typedef struct listaSequencial ListaSequencial;

// Função para inicializar a lista sequencial
ListaSequencial *initializeList() {
    ListaSequencial *retorno = malloc(sizeof(ListaSequencial));

    retorno->size = 0;
    return retorno;
}

// Função para inserir um elemento no final da lista sequencial
void insertElement(ListaSequencial *list, int element) {
    if (list->size < MAX_SIZE) {
        list->array[list->size] = element;
        list->size++;
        printf("Elemento %d inserido com sucesso.\n", element);
    } else {
        printf("Erro: Lista cheia. Elemento %d não inserido.\n", element);
    }
}

// Função para imprimir os elementos da lista sequencial
void printList(ListaSequencial *list) {
    printf("Lista sequencial: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

int tamanho_lista(ListaSequencial *list)
{
    if(list->size == NULL){
        return -1
    }
    return list->size;
}
void liberarList(ListaSequencial *list) {
    free(list);
}


int main() {
    // Criando e inicializando a lista sequencial
    ListaSequencial *lista = initializeList();

    // Inserindo elementos na lista sequencial
    insertElement(lista, 10);
    insertElement(lista, 20);
    insertElement(lista, 30);

    int numero = 1;

    while (numero != 0) {
        printf("Digite um numero para inserir na lista (Digite 0 para sair): ");
        scanf("%d", &numero);
        insertElement(lista, numero);
        printList(lista);
    }

    liberarList(lista);

    return 0;
}

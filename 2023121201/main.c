#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct aluno {
    int matricula;
    char nome[50];
    int idade;
    struct aluno* proximo;
};

typedef struct aluno Aluno;

struct listaAlunos {
    struct Aluno* cabeca;
    int tamanho;
};

typedef struct listaAlunos ListaAlunos;

void inicializarLista(ListaAlunos* lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

void reiniciarLista(ListaAlunos* lista) {
    Aluno* atual = lista->cabeca;
    while (atual != NULL) {
        Aluno* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->cabeca = NULL;
}

int contarElementos(ListaAlunos* lista) {
    int contador = 0;
    Aluno* atual = lista->cabeca;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

bool listaCheia(ListaAlunos* lista) {
    return lista->tamanho<10;
}

bool listaVazia(ListaAlunos* lista) {
    return lista->cabeca == NULL;
}

void exibirLista(ListaAlunos* lista) {
    Aluno* atual = lista->cabeca;
    printf("Lista de Alunos:\n");
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Idade: %d\n", atual->matricula, atual->nome, atual->idade);
        atual = atual->proximo;
    }
    printf("Tamanho da lista %d\n\n",lista->tamanho);
}

void inserirElementoOrdenado(ListaAlunos* lista, int matricula, const char* nome, int idade) {
    Aluno* novoAluno = ( Aluno*)malloc(sizeof(Aluno));
    if (novoAluno == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return;
    }
    if(lista->tamanho>=10){
        printf("Tamanho maximo da lista atingido\n");
        return;
    }

    novoAluno->matricula = matricula;
    snprintf(novoAluno->nome, sizeof(novoAluno->nome), "%s", nome);
    novoAluno->idade = idade;
    novoAluno->proximo = NULL;

    Aluno* anterior = NULL;
    Aluno* atual = lista->cabeca;
    lista->tamanho++;

    while (atual != NULL && atual->matricula < matricula) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        novoAluno->proximo = lista->cabeca;
        lista->cabeca = novoAluno;
    } else {

        anterior->proximo = novoAluno;
        novoAluno->proximo = atual;
    }
}


void excluirElemento(ListaAlunos* lista, int matricula) {
     Aluno* anterior = NULL;
     Aluno* atual = lista->cabeca;


    while (atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->proximo;
    }


    if (atual != NULL) {
        if (anterior == NULL) {

            lista->cabeca = atual->proximo;
        } else {

            anterior->proximo = atual->proximo;
        }
        free(atual);
        lista->tamanho--;
    }
}


int main() {
    ListaAlunos *lista;
    inicializarLista(lista);

    printf("A lista esta vazia?%s\n",listaVazia(lista)?"sim":"nao");
    inserirElementoOrdenado(lista, 102, "Izaque", 21);
    inserirElementoOrdenado(lista, 105, "Cuevas", 16);
    inserirElementoOrdenado(lista, 101, "Angelo", 51);
    inserirElementoOrdenado(lista, 103, "Alexandre", 21);
    inserirElementoOrdenado(lista, 104, "Maxwell", 11);
    inserirElementoOrdenado(lista, 106, "Jucimar", 41);
    inserirElementoOrdenado(lista, 107, "Flavia", 52);
    inserirElementoOrdenado(lista, 108, "Adailton", 23);
    inserirElementoOrdenado(lista, 109, "Roberto", 26);
    printf("A lista esta vazia?%s\n\n",listaVazia(lista)?"sim":"nao");

    exibirLista(lista);
    inserirElementoOrdenado(lista, 110, "Roberto 2", 27);
    inserirElementoOrdenado(lista, 111, "Izaque 2", 21);
    excluirElemento(lista, 105);
    exibirLista(lista);
    reiniciarLista(lista);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ListaAlunos.h>

typedef struct aluno Aluno;
typedef struct listaAlunos ListaAlunos;

void inicializarLista(ListaAlunos *lista) {
    lista->quantidade = 0;
}

void liberarLista(ListaAlunos *lista) {
    lista->quantidade = 0;
    free(lista);
}

int quantidadeElementos(ListaAlunos *lista) {
    return lista->quantidade;
}

int listaCheia(ListaAlunos *lista) {
    return lista->quantidade == 100;
}

int listaVazia(ListaAlunos *lista) {
    return lista->quantidade == 0;
}

void exibirLista(ListaAlunos *lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        printf("Matricula: %d, Nome: %s, Idade: %d\n", lista->alunos[i].matricula, lista->alunos[i].nome, lista->alunos[i].idade);
    }
}

void inserirElementoOrdenado(ListaAlunos *lista, Aluno aluno) {
    if (listaCheia(lista)) {
        printf("Erro: Lista cheia.\n");
        return;
    }

    int posicao = 0;

    while (posicao < lista->quantidade && lista->alunos[posicao].matricula < aluno.matricula) {
        posicao++;
    }

    for (int i = lista->quantidade; i > posicao; i--) {
        lista->alunos[i] = lista->alunos[i - 1];
    }

    lista->alunos[posicao] = aluno;
    lista->quantidade++;
}

void excluirElemento(ListaAlunos *lista, int matricula) {
    int posicao = 0;

    while (posicao < lista->quantidade && lista->alunos[posicao].matricula != matricula) {
        posicao++;
    }

    if (posicao == lista->quantidade) {
        printf("Erro: Elemento não encontrado.\n");
        return;
    }

    for (int i = posicao; i < lista->quantidade - 1; i++) {
        lista->alunos[i] = lista->alunos[i + 1];
    }

    lista->quantidade--;
}

void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula) {
    int posicao = 0;

    while (posicao < lista->quantidade && lista->alunos[posicao].matricula != matriculaAntiga) {
        posicao++;
    }

    if (posicao == lista->quantidade) {
        printf("Erro: Elemento não encontrado.\n");
        return;
    }

    lista->alunos[posicao].matricula = novaMatricula;
}

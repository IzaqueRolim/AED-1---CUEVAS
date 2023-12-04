#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ListaAlunos.h>


int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    Aluno aluno1 = {101, "Joao", 20};
    Aluno aluno2 = {102, "Maria", 22};
    Aluno aluno3 = {103, "Pedro", 21};

    inserirElementoOrdenado(&lista, aluno2);
    inserirElementoOrdenado(&lista, aluno1);
    inserirElementoOrdenado(&lista, aluno3);

    printf("Quantidade de elementos: %d\n", quantidadeElementos(&lista));
    printf("Lista cheia: %s\n", listaCheia(&lista) ? "Sim" : "N�o");
    printf("Lista vazia: %s\n", listaVazia(&lista) ? "Sim" : "N�o");

    printf("Elementos da lista:\n");
    exibirLista(&lista);

    excluirElemento(&lista, 102);

    printf("Elementos da lista ap�s excluir:\n");
    exibirLista(&lista);

    alterarMatricula(&lista, 101, 201);

    printf("Elementos da lista ap�s alterar matr�cula:\n");
    exibirLista(&lista);

    liberarLista(&lista);

    return 0;
}

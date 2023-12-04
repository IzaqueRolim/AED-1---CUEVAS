#include <stdio.h>
#include <stdlib.h>
#include <ListaAlunos.h>

int main() {
    ListaAlunos *lista;
    inicializarLista(lista);

    inserirElemento(lista, 102);
    inserirElemento(lista, 105);
    inserirElemento(lista, 101);
    inserirElemento(lista, 103);

    exibirLista(lista);
    printf("Quantidade de elementos na lista: %d\n", quantidadeElementos(lista));
    printf("Lista %s\n", listaCheia(lista) ? "cheia" : "n�o cheia");
    printf("Lista %s\n", listaVazia(lista) ? "vazia" : "n�o vazia");

    excluirElemento(lista, 105);
    exibirLista(lista);

    alterarMatricula(lista, 101, 110);
    exibirLista(lista);

    liberarLista(lista);

    return 0;
}

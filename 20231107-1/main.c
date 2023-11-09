#include <stdio.h>
#include <stdlib.h>

#include <Lista.h>

int main() {
    Lista *lista = CriaLista(10);
    PreencherValoresDaListaAutomaticamente(lista);
    exibirListaDeFormaRecursiva(lista,0);
    buscaBinariaRecursiva(lista,3,0,lista->tamanho-1);

    printf("\nSoma de todos os elementos de forma RECURSIVA: %d\n",somaElementosRecursivo(lista,lista->tamanho,0));
    printf("Produto de todos os elementos de forma RECURSIVA: %d\n",produtoDosElementosRecursivo(lista,lista->tamanho,0));
    printf("Maior numero = %d\n",retornarMaiorNumeroRecursivo(lista,0));
    printf("Menor numero = %d\n",retornarMenorNumeroRecursivo(lista,0));

    DestruirLista(lista);

    return 0;
}

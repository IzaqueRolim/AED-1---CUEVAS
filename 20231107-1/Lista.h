#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


struct lista{
  int* elementos;
  int tamanho;
};

typedef struct lista Lista;

Lista *CriaLista(int tamanho);
void PreencherValoresDaListaAutomaticamente(Lista *lista);
void PreencherValoresDaLista(Lista *lista);
void buscaBinariaRecursiva(Lista *lista, int numeroProcurado,int inicio, int fim);
void exibirListaDeFormaRecursiva(Lista *lista, int indice);
int somaElementosRecursivo(Lista *lista, int tamanho, int indice);
int produtoDosElementosRecursivo(Lista *lista, int tamanho, int indice);
int retornarMenorNumeroRecursivo(Lista *lista, int indice);
int retornarMaiorNumeroRecursivo(Lista *lista, int indice);
void DestruirLista(Lista* lista);

#endif // LISTA_H_INCLUDED

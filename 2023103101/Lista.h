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
void ExibirLista(Lista *lista);
void InserirElementoNaLista(Lista* lista, int elemento);
void BuscarElementoNaListaDeFormaSequencial(Lista *lista, int numeroProcurado);
void BuscarElementosDeFormaBinaria(Lista *lista,int numeroProcurado);
void BuscarOMenorElemento(Lista *lista);
void SomarTodosOsElementos(Lista *lista);
void ProdutoDeTodosOsElementos(Lista *lista);
void DestruirLista(Lista* lista);


#endif // LISTA_H_INCLUDED

#ifndef LISTAALUNOS_H_INCLUDED
#define LISTAALUNOS_H_INCLUDED

struct listaAlunos {
    int elementos[MAX_ALUNOS];
    int quantidade;
};

typedef struct listaAlunos ListaAlunos;

void inicializarLista(ListaAlunos *lista);

void liberarLista(ListaAlunos *lista);

int quantidadeElementos(ListaAlunos *lista);

int listaCheia(ListaAlunos *lista);

int listaVazia(ListaAlunos *lista);

void exibirLista(ListaAlunos *lista);

void inserirElemento(ListaAlunos *lista, int matricula);

void excluirElemento(ListaAlunos *lista, int matricula) ;

void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula);


#endif // LISTAALUNOS_H_INCLUDED

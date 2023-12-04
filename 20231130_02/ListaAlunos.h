#ifndef LISTAALUNOS_H_INCLUDED
#define LISTAALUNOS_H_INCLUDED

struct aluno {
    int matricula;
    char nome[50];
    int idade;
};
typedef struct aluno Aluno;

struct listaAlunos {
    Aluno alunos[100];
    int quantidade;
};
typedef struct listaAlunos ListaAlunos;

void inicializarLista(ListaAlunos *lista);
void liberarLista(ListaAlunos *lista);
int quantidadeElementos(ListaAlunos *lista);
int listaCheia(ListaAlunos *lista);
int listaVazia(ListaAlunos *lista);
void exibirLista(ListaAlunos *lista;
void inserirElementoOrdenado(ListaAlunos *lista, Aluno aluno);
void excluirElemento(ListaAlunos *lista, int matricula);
void alterarMatricula(ListaAlunos *lista, int matriculaAntiga, int novaMatricula);


#endif // LISTAALUNOS_INCLUDED

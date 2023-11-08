#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char nome[50];
    int codigo;
    int idade;
    float coeficiente;
};
typedef struct aluno Aluno;

struct turma{
    Aluno* listaAlunos;
    int quantidadeAlunos;
};
typedef struct turma Turma;

Turma* criarTurma(int quantidadeAlunos) {
    Turma* turma = (Turma*)malloc(sizeof(Turma));
    turma->listaAlunos = (Aluno*)malloc(quantidadeAlunos * sizeof(Aluno));
    turma->quantidadeAlunos = 0;
    return turma;
}


void inserirAluno(Turma* turma, Aluno aluno) {
    if (turma->quantidadeAlunos < sizeof(turma->listaAlunos)) {
        turma->listaAlunos[turma->quantidadeAlunos] = aluno;
        turma->quantidadeAlunos++;
    }
}


void liberarTurma(Turma* turma) {
    free(turma->listaAlunos);
    free(turma);
}

void buscarAlunoPorCodigo(Turma* turma, int codigo) {
    for (int i = 0; i < turma->quantidadeAlunos; i++) {
        if (turma->listaAlunos[i].codigo == codigo) {
            printf("Aluno encontrado:\n");
            printf("Codigo: %d\n", turma->listaAlunos[i].codigo);
            printf("Nome: %s\n", turma->listaAlunos[i].nome);
            printf("Idade: %d\n", turma->listaAlunos[i].idade);
            printf("Coeficiente: %.2f\n", turma->listaAlunos[i].coeficiente);
            return;
        }
    }
    printf("Aluno com codigo %d nao encontrado na turma.\n", codigo);
}


void imprimirCodigoNomeAlunos(Turma* turma) {
    printf("Codigo e Nome dos Alunos na Turma:\n");
    for (int i = 0; i < turma->quantidadeAlunos; i++) {
        printf("Codigo: %d, Nome: %s\n", turma->listaAlunos[i].codigo, turma->listaAlunos[i].nome);
    }
}

int main() {
    Turma* minhaTurma = criarTurma(10);

    Aluno aluno1 = {1, "Joao", 20, 8.5};
    Aluno aluno2 = {2, "Maria", 22, 7.8};
    Aluno aluno3 = {3, "Pedro", 21, 9.2};

    inserirAluno(minhaTurma, aluno1);
    inserirAluno(minhaTurma, aluno2);
    inserirAluno(minhaTurma, aluno3);

    printf("Operacoes na Turma:\n");
    buscarAlunoPorCodigo(minhaTurma, 2);
    imprimirCodigoNomeAlunos(minhaTurma);

    liberarTurma(minhaTurma);

    return 0;
}

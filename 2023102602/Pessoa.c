#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
    char nome[51]; 
    Data DataNascimento;
    char cpf[12]; 
};
typedef struct pessoa Pessoa;

void RelacionarPessoaData(Pessoa *pessoa, Data *DataNascimento) {
    if (pessoa == NULL || DataNascimento == NULL) {
        return; 
    }
    pessoa->DataNascimento = *DataNascimento; 
}

Pessoa *CriaPessoa(char nome[51], char cpf[12]) {
    Pessoa *out = malloc(sizeof(Pessoa));
    strcpy(out->nome, nome);
    strcpy(out->cpf, cpf);
    return out;
}

int AtribuirPessoa(Pessoa *pessoa, char nome[51], char cpf[12]) {
    if (pessoa == NULL) {
        return 0;
    }
    strcpy(pessoa->nome, nome);
    strcpy(pessoa->cpf, cpf);
    return 1;
}

void LerPessoa(Pessoa *pessoa) {
    if (pessoa == NULL) {
        return; 
    }
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de Nascimento: %s/%s/%s\n", pessoa->DataNascimento.dia, pessoa->DataNascimento.mes, pessoa->DataNascimento.ano);
    printf("CPF: %s\n", pessoa->cpf);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include<Pessoa.h>

struct pessoa{
    char nome[50];
    char dataNascimento[8];
    char cpf[11];
};

typedef struct pessoa Pessoa;

Pessoa *CriaPessoa(char nome[50], char dataNascimento[8], char cpf[11]){
    Pessoa *out = malloc(sizeof(Pessoa));
    strcpy(out->nome,nome);
    strcpy(out -> dataNascimento,dataNascimento);
    strcpy(out -> cpf,cpf);
    return out;
}

int AtribuirPessoa(Pessoa *pessoa, char nome[50], char dataNascimento[8],char cpf[11]){
    if(pessoa == NULL){
        return 0;
    }
    strcpy(pessoa-> nome,nome);
    strcpy(pessoa->dataNascimento,dataNascimento);
    strcpy(pessoa->cpf,cpf);
    return 1;
}
int LerPessoa(Pessoa *pessoa){
    if(pessoa == NULL){
        return 0;
    }
    
    printf("%s\n",pessoa->nome);
    printf("%s\n",pessoa->dataNascimento);
    printf("%s\n",pessoa->cpf);
    return 1;
}
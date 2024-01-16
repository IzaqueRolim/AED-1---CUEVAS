#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANHO 100

typedef struct {
    char dados[MAX_TAMANHO];
    int topo;
} Pilha;

typedef struct {
    Pilha expressao;
    int tamanho;
} Expressoes;

Expressoes* criarExpressao(char *expressao) {
    Expressoes *novaExpressao = (Expressoes *)malloc(sizeof(Expressoes));
    inicializarPilha(&(novaExpressao->expressao));
    novaExpressao->tamanho = 0;

    for (int i = 0; i < strlen(expressao); i++) {
        empilhar(&(novaExpressao->expressao), expressao[i]);
    }

    return novaExpressao;
}

void apagarExpressao(Expressoes *expressoes) {
    free(expressoes);
}

void imprimirExpressao(Expressoes *expressoes) {
    for(int j=0;j<expressoes->tamanho;j++){
        printf("Expressao na notacao tradicional: ");
        for (int i = 0; i <= expressoes->expressao.topo; i++) {
            printf("%c ", expressoes->expressao.dados[i]);
        }
        printf("\n");
    }
}

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

void empilhar(Pilha *pilha, char elemento) {
    pilha->dados[++pilha->topo] = elemento;
}

char desempilhar(Pilha *pilha) {
    return pilha->dados[pilha->topo--];
}

int isOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int prioridade(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    Pilha operadores;
    inicializarPilha(&operadores);

    int tamanho = strlen(infix);
    int j = 0;

    // Itera sobre a expressão infix da esquerda para a direita
    for (int i = 0; i < tamanho; i++) {
        char atual = infix[i];

        if (atual == ' ') {
            // Ignora espaços em branco
            continue;
        } else if (isOperador(atual)) {
            // Manipula operadores
            while (operadores.topo != -1 && prioridade(operadores.dados[operadores.topo]) >= prioridade(atual)) {
                postfix[j++] = desempilhar(&operadores);
                postfix[j++] = ' ';
            }
            empilhar(&operadores, atual);
        } else if (atual == '(') {
            // Empilha '('
            empilhar(&operadores, atual);
        } else if (atual == ')') {
            // Desempilha operadores até encontrar '('
            while (operadores.topo != -1 && operadores.dados[operadores.topo] != '(') {
                postfix[j++] = desempilhar(&operadores);
                postfix[j++] = ' '; // Adiciona espaço entre os operadores no resultado posfixo
            }
            desempilhar(&operadores); // Desempilha o '('
        } else {
            // Operandos são diretamente adicionados ao resultado
            postfix[j++] = atual;
            if (i + 1 < tamanho && !isOperador(infix[i + 1])) {
                // Se o próximo caractere também for um operando, adiciona espaço
                postfix[j++] = ' ';
            }
        }
    }

    // Desempilha operadores restantes
    while (operadores.topo != -1) {
        postfix[j++] = desempilhar(&operadores);
        postfix[j++] = ' '; // Adiciona espaço entre os operadores no resultado posfixo
    }


    postfix[j] = '\0';
}

int avaliarExpressao(char *expressaoPosfixa) {
    Pilha operandos;
    inicializarPilha(&operandos);
    int tamanho = strlen(expressaoPosfixa);

    for (int i = 0; i < tamanho; i++) {
        char atual = expressaoPosfixa[i];

        if (atual == ' ') {
            continue;
        } else if (isdigit(atual)) {
            empilhar(&operandos, atual - '0'); // Converte o caractere para o valor numérico correspondente e empilha
        } else if (isOperador(atual)) {
            int op2 = desempilhar(&operandos);
            int op1 = desempilhar(&operandos);

            switch (atual) {
                case '+':
                    empilhar(&operandos, op1 + op2);
                    break;
                case '-':
                    empilhar(&operandos, op1 - op2);
                    break;
                case '*':
                    empilhar(&operandos, op1 * op2);
                    break;
                case '/':
                    empilhar(&operandos, op1 / op2);
                    break;
            }
        }
    }
    return desempilhar(&operandos);
}


int main() {

        char expressaoInfixa[MAX_TAMANHO];
        char expressaoPosfixa[MAX_TAMANHO];

        printf("\nDigite uma expressao aritmetica na notacao tradicional (infixa): ");
        fgets(expressaoInfixa, MAX_TAMANHO, stdin);
        expressaoInfixa[strcspn(expressaoInfixa, "\n")] = '\0';

        Expressoes *expressoes = criarExpressao(expressaoInfixa);

        imprimirExpressao(expressoes);

        infixToPostfix(expressaoInfixa, expressaoPosfixa);

        printf("Expressao na notacao posfixa: %s\n", expressaoPosfixa);
        int resultado = avaliarExpressao(expressaoPosfixa);
        printf("Resultado da expressao: %d\n", resultado);

        apagarExpressao(expressoes);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct complexo {
    double real;
    double imaginario;
};

typedef struct complexo Complexo;

Complexo* criarComplexo(double real, double imaginario) {
    Complexo* numComplexo = (Complexo*)malloc(sizeof(Complexo));
    if (numComplexo == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    numComplexo->real = real;
    numComplexo->imaginario = imaginario;
    return numComplexo;
}

void destruirComplexo(Complexo* numComplexo) {
    free(numComplexo);
}

Complexo* somarComplexos(Complexo* num1, Complexo* num2) {
    double realSoma = num1->real + num2->real;
    double imaginarioSoma = num1->imaginario + num2->imaginario;
    return criarComplexo(realSoma, imaginarioSoma);
}

Complexo* subtrairComplexos(Complexo* num1, Complexo* num2) {
    double realSubtracao = num1->real - num2->real;
    double imaginarioSubtracao = num1->imaginario - num2->imaginario;
    return criarComplexo(realSubtracao, imaginarioSubtracao);
}

Complexo* multiplicarComplexos(Complexo* num1, Complexo* num2) {
    double realMultiplicacao = (num1->real * num2->real) - (num1->imaginario * num2->imaginario);
    double imaginarioMultiplicacao = (num1->real * num2->imaginario) + (num1->imaginario * num2->real);
    return criarComplexo(realMultiplicacao, imaginarioMultiplicacao);
}


Complexo* dividirComplexos(Complexo* num1, Complexo* num2) {
    double divisor = (num2->real * num2->real) + (num2->imaginario * num2->imaginario);
    double realDivisao = ((num1->real * num2->real) + (num1->imaginario * num2->imaginario)) / divisor;
    double imaginarioDivisao = ((num1->imaginario * num2->real) - (num1->real * num2->imaginario)) / divisor;
    return criarComplexo(realDivisao, imaginarioDivisao);
}

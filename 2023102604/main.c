#include <stdio.h>
#include <stdlib.h>
#include <Complexo.h>

int main() {
    Complexo* numero1 = criarComplexo(3.0, 4.0);
    Complexo* numero2 = criarComplexo(1.0, 2.0);

    Complexo* soma = somarComplexos(numero1, numero2);
    Complexo* subtracao = subtrairComplexos(numero1, numero2);
    Complexo* multiplicacao = multiplicarComplexos(numero1, numero2);
    Complexo* divisao = dividirComplexos(numero1, numero2);

    printf("Soma: %.2f + %.2fi\n", soma->real, soma->imaginario);
    printf("Subtração: %.2f + %.2fi\n", subtracao->real, subtracao->imaginario);
    printf("Multiplicação: %.2f + %.2fi\n", multiplicacao->real, multiplicacao->imaginario);
    printf("Divisão: %.2f + %.2fi\n", divisao->real, divisao->imaginario);

    destruirComplexo(numero1);
    destruirComplexo(numero2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}

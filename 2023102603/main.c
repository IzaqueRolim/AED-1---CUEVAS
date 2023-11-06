#include <stdio.h>

#include <Cubo.h>


int main() {
    Cubo cubo;
    double ladoCubo = 5.0;

    inicializarCubo(&cubo, ladoCubo);

    printf("O lado do cubo é: %.2f\n", obterLado(cubo));
    printf("A área do cubo é: %.2f\n", calcularArea(cubo));
    printf("O volume do cubo é: %.2f\n", calcularVolume(cubo));

    return 0;
}

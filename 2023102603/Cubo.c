#include <stdio.h>

typedef struct {
    double lado;
} Cubo;

void inicializarCubo(Cubo *cubo, double lado) {
    cubo->lado = lado;
}

double obterLado(Cubo *cubo) {
    return cubo->lado;
}


double calcularArea(Cubo *cubo) {
    return 6.0 * (cubo->lado * cubo->lado);
}

double calcularVolume(Cubo *cubo) {
    return cubo->lado * cubo->lado * cubo->lado;
}
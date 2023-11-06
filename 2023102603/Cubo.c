#include <stdio.h>

typedef struct {
    double lado;
} Cubo;

// Função para inicializar o cubo
void inicializarCubo(Cubo *cubo, double lado) {
    cubo->lado = lado;
}

// Função para obter o tamanho de cada lado
double obterLado(Cubo cubo) {
    return cubo.lado;
}

// Função para calcular a área do cubo
double calcularArea(Cubo cubo) {
    return 6.0 * (cubo.lado * cubo.lado);
}

// Função para calcular o volume do cubo
double calcularVolume(Cubo cubo) {
    return cubo.lado * cubo.lado * cubo.lado;
}
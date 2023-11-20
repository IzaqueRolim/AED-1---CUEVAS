#include <stdio.h>
#include <stdlib.h>

#include <Vetor.h>


int main() {
  
    Vetor *vetor1;
    Vetor *vetor2;
    Vetor *resultado_soma;
    
    vetor1 = CriaVetor(1.0, 2.0, 3.0);
    vetor2 = CriaVetor(4.0, 5.0, 6.0);
    resultado_soma = CriaVetor(0,0,0);

   
    soma(vetor1, vetor2, resultado_soma);

    
    printf("Soma: (%.2f, %.2f, %.2f)\n", resultado_soma->x, resultado_soma->y, resultado_soma->z);

    // Chamando a função produto_escalar e exibindo o resultado
    printf("Produto Escalar: %.2f\n", produto_escalar(vetor1, vetor2));

    return 0;
}

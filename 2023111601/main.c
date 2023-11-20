#include <stdio.h>


int k_esimo_digito(int n, int k) {
    
    if (n < 10 || k == 1) {
        return n % 10;
    }

   
    return k_esimo_digito(n / 10, k - 1);
}

int main() {
    
    int numero,posicao;
    
    printf("Digite o numero para buscar o digito:");
    scanf("%d",&numero);
    printf("Digite a posição para buscar:");
    scanf("%d",&posicao);
    
    
    int resultado = k_esimo_digito(numero, posicao);
    printf("O %d-ésimo dígito de %d é %d\n", posicao, numero, resultado);

    return 0;
}

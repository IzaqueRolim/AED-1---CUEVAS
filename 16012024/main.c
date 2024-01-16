#include <stdio.h>
#include <stdlib.h>

#include <Node.h>

int main()
{
    struct TabelaHash tabela;
    inicializarTabela(&tabela);

    int chaves[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < numChaves; i++) {
        inserirNaTabela(&tabela, chaves[i]);
    }

    imprimirTabela(&tabela);

    return 0;
}

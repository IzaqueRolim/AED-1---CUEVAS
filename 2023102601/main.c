
#include <stdio.h>

#include <Pessoa.h>

int main()
{
    Pessoa *pessoa;
    pessoa = CriaPessoa("Izaque","02/10/2005","00000000000");

    LerPessoa(pessoa);
    DestruirPessoa(pessoa);

    return 0;
}

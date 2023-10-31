
#include <stdio.h>
#include <Pessoa.h>
#include <Data.h>

int main()
{
    Pessoa *pessoa;
    Data *data;

    pessoa = CriaPessoa("Izaque", "06166800000");
    data = CriaData("02", "10", "2003");

    RelacionarPessoaData(pessoa, data);

    LerPessoa(pessoa);

    return 0;
}

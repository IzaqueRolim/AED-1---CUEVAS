/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <Pessoa.h>

int main()
{
    Pessoa *pessoa;
    pessoa = CriaPessoa("Izaque","02/10/2005","00000000000");
    
    LerPessoa(pessoa);
    printf("Hello World");

    return 0;
}

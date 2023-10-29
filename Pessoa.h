typedef struct pessoa Pessoa;

Pessoa *CriaPessoa(char nome[50], char dataNascimento[8], char cpf[11]);
int AtribuirPessoa(Pessoa *pessoa, char nome[50], char dataNascimento[8],char cpf[11]);
int LerPessoa(Pessoa *pessoa);


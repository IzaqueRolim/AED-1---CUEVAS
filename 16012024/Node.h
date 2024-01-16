#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
struct Node {
    int chave;
    struct Node* proximo;
};

struct TabelaHash {
    struct Node* tabela[M];
};

int funcaoHash(int chave, int tamanho);
void inicializarTabela(struct TabelaHash* tabela, int tamanho);
void inserirNaTabela(struct TabelaHash* tabela, int chave, int tamanho);
void imprimirTabela(struct TabelaHash* tabela, int tamanho);

#endif // NODE_H_INCLUDED

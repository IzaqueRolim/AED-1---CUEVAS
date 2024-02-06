#include <stdio.h>
#include "tree.h"

int main() {
    struct Node* root = NULL;
    int keys[] = {24, 10, 32, 5, 12, 29, 35};
    int i, n = sizeof(keys) / sizeof(keys[0]);

    for (i = 0; i < n; i++)
        root = insert(root, keys[i]);

    printf("Árvore em ordem: ");
    inorder(root);
    printf("\n");

    printf("Número de elementos na árvore: %d\n", countNodes(root));

    int searchKey = 12;
    struct Node* result = search(root, searchKey);
    if (result != NULL)
        printf("Elemento %d encontrado na árvore.\n", searchKey);
    else
        printf("Elemento %d não encontrado na árvore.\n", searchKey);

    freeTree(root);

    return 0;
}

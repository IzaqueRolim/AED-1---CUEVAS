#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int item);
struct Node* insert(struct Node* node, int key);
void inorder(struct Node* root);
int countNodes(struct Node* root);
struct Node* search(struct Node* root, int key);
void freeTree(struct Node* root);

#endif // TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Parcours en profondeur prefixé (pre-ordre)
void prefixe(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    prefixe(root->left);
    prefixe(root->right);
}

// Parcours en profondeur infixé (in-ordre)
void infixe(struct Node* root) {
    if (root == NULL)
        return;

    infixe(root->left);
    printf("%d ", root->data);
    infixe(root->right);
}

// Parcours en profondeur postfixe (post-ordre)
void postfixe(struct Node* root) {
    if (root == NULL)
        return;

    postfixe(root->left);
    postfixe(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* arbreBinaireDeRecherche = NULL;

    // Inserting nodes into the tree
    arbreBinaireDeRecherche = insertNode(arbreBinaireDeRecherche, 4);
    insertNode(arbreBinaireDeRecherche, 2);
    insertNode(arbreBinaireDeRecherche, 5);
    insertNode(arbreBinaireDeRecherche, 1);
    insertNode(arbreBinaireDeRecherche, 3);


    // Pre-order traversal
    printf("parcours prefix: ");
    prefixe(arbreBinaireDeRecherche);
    printf("\nparcours infix: ");
    infixe(arbreBinaireDeRecherche);
    printf("\nparcours postfix: ");
    postfixe(arbreBinaireDeRecherche);

    return 0;
}

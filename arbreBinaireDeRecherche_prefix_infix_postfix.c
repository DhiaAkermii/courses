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

struct Node* Supprimer(struct Node* arbre, int valeur) {
  if (arbre == NULL) {
    return NULL;
  }

  if (valeur < arbre->data) {
    arbre->left = Supprimer(arbre->left, valeur);
  } else if (valeur > arbre->data) {
    arbre->right = Supprimer(arbre->right, valeur);
  } else {
    // Le noeud à supprimer est la racine
    if (arbre->left == NULL) {
      return arbre->right;
    } else if (arbre->right == NULL) {
      return arbre->left;
    } else {
      // Trouver le minimum dans le sous arbre de son fils à droite
      struct Node* minimum = arbre->right;
      while (minimum->left != NULL) {
        minimum = minimum->left;
      }

      // Remplacer la valeur de la racine par la valeur du minimum
      arbre->data = minimum->data;

      // Supprimer le minimum de l'arbre
      arbre->right = Supprimer(arbre->right, minimum->data);
    }
  }
  return arbre;
}


int rechercher(struct Node* arbre, int valeur) {
  if (arbre == NULL) {
    return 0;
  }

  if (valeur == arbre->data) {
    return 1;
  } else if (valeur < arbre->data) {
    return rechercher(arbre->left, valeur);
  } else {
    return rechercher(arbre->right, valeur);
  }
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

// Find the node with the minimum value
struct Node* findMinimum(struct Node* root) {
    if (root == NULL) {
        return NULL;  // Empty tree
    }

    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


// Find the node with the maximum value
struct Node* findMaximum(struct Node* root) {
    if (root == NULL) {
        return NULL;  // Empty tree
    }

    while (root->right != NULL) {
        root = root->right;
    }
    return root;
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


    // est ce que le nombre 4 existe dans l'arbre ou non
    if(rechercher(arbreBinaireDeRecherche,4)){
      printf("\n4 existe dans l'arbre");
    }else{
      printf("\n4 n'existe pas dans l'arbre");
    }

    // est ce que le nombre 5 existe dans l'arbre ou non
    if(rechercher(arbreBinaireDeRecherche,5)){
      printf("\n5 existe dans l'arbre");
    }else{
      printf("\n5 n'existe pas dans l'arbre");
    }

    // est ce que le nombre 6 existe dans l'arbre ou non
    if(rechercher(arbreBinaireDeRecherche,7)){
      printf("\n7 existe dans l'arbre");
    }else{
      printf("\n7 n'existe pas dans l'arbre");
    }

    Supprimer(arbreBinaireDeRecherche,5);


     // est ce que le nombre 5 existe dans l'arbre ou non
    if(rechercher(arbreBinaireDeRecherche,5)){
      printf("\n5 existe dans l'arbre");
    }else{
      printf("\n5 n'existe pas dans l'arbre");
    }



    struct Node *minNode = findMinimum(arbreBinaireDeRecherche);
    struct Node *maxNode = findMaximum(arbreBinaireDeRecherche);

    if (minNode != NULL) {
        printf("`\nLe minimum dans cet arbre binaire de recherche est = : %d", minNode->data);
    } else {
        printf("The BST is empty.\n");
    }

    if (maxNode != NULL) {
        printf("\nLe maximum dans cet arbre binaire de recherche est = : %d\n", maxNode->data);
    } else {
        printf("The BST is empty.\n");
    }

    return 0;
}
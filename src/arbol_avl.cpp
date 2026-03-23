// An AVL tree defined as a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees for any node cannot be more than one.
// Balance Factor = left subtree height - right subtree height
// For a Balanced Tree(for every node): -1 ≤ Balance Factor ≤ 1
// Source: https://www.geeksforgeeks.org/dsa/introduction-to-avl-tree/ 
// Source: (implementación a C++) https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/
#include "arbol_avl.hpp"

#include <iostream>
#include <algorithm>

using namespace std;

nodoAVL* createAVLNode(int data){
    nodoAVL* node = new nodoAVL; 
    node->data = data;
    node->left = nullptr; 
    node->right = nullptr;
    node->height = 1;
    return node; 
}

int height(nodoAVL* node){
    return node ? node->height : 0; 
}

// Balance Factor: (height of left subtree - height of right subtree) is -1, 0, or 1.
int balanceFactor(nodoAVL* node){
    return node ? height(node->left) - height(node->right) : 0;
}

//Rotaciones: 
nodoAVL* rightRotate(nodoAVL* y){
    nodoAVL* x = y->left;
    nodoAVL* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
nodoAVL* leftRotate(nodoAVL* x){
    nodoAVL* y = x->right;
    nodoAVL* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
// Inserción
nodoAVL* insert(nodoAVL* node, int key){
    if (!node) return createAVLNode(key);

    if (key < node->data) // la clave es menor, insertamos a la izquierda
        node->left = insert(node->left, key); 
    else if (key > node->data) // la clave es mayor, insertamos a la derecha
        node->right = insert(node->right, key);
    else
        return node; // claves iguales no permitidas

    //Se actualiza la altura actual
    node->height = 1 + max(height(node->left), height(node->right));

    //Se calcula el factor de balance para ver si se desbalanceó.
    int balance = balanceFactor(node);


    // Revisamos los 4 casos de desbalance y aplicamos rotaciones según corresponda
    // LL
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
//Búsqueda
int searchAVL(nodoAVL* node, int key, int counter){
    if (!node) return -1;
    if (node->data == key) return counter;

    if (key < node->data)
        return searchAVL(node->left, key, counter);
    else
        return searchAVL(node->right, key, counter);
}
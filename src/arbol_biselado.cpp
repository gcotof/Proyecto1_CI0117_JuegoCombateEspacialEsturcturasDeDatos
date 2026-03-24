#include "arbol_biselado.hpp"

// Crear nodo
nodeSplay* crearNodo(int data) {
    nodeSplay* n = new nodeSplay();
    n->data = data;
    n->left = n->right = nullptr;
    return n;
}

// Rotaciones
nodeSplay* rotarIzquierda(nodeSplay* x) {
    if (!x || !x->right) return x;

    nodeSplay* temp = x->right;
    x->right = temp->left;
    temp->left = x;

    return temp;
}

nodeSplay* rotarDerecha(nodeSplay* y) {
    if (!y || !y->left) return y;

    nodeSplay* temp = y->left;
    y->left = temp->right;
    temp->right = y;

    return temp;
}

// Splay 
nodeSplay* biselar(nodeSplay* root, int key) {
    if (!root || root->data == key)
        return root;

    if (key < root->data) {
        if (!root->left) return root;

        if (key < root->left->data) {
            root->left->left = biselar(root->left->left, key);
            root = rotarDerecha(root);
        }
        else if (key > root->left->data) {
            root->left->right = biselar(root->left->right, key);
            if (root->left->right)
                root->left = rotarIzquierda(root->left);
        }

        return (root->left == nullptr) ? root : rotarDerecha(root);
    }
    else {
        if (!root->right) return root;

        if (key > root->right->data) {
            root->right->right = biselar(root->right->right, key);
            root = rotarIzquierda(root);
        }
        else if (key < root->right->data) {
            root->right->left = biselar(root->right->left, key);
            if (root->right->left)
                root->right = rotarDerecha(root->right);
        }

        return (root->right == nullptr) ? root : rotarIzquierda(root);
    }
}

// SEARCH (IMPORTANTE, CON EL COUNTER)
int searchSplay(nodeSplay*& root, int key) {
    int counter = 0;
    nodeSplay* current = root;

    while (current) {
        counter++; // “¿está aquí?”

        if (current->data == key) {
            root = biselar(root, key); // reestructura después
            return counter;
        }

        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    // No encontrado → igual haces splay del último acceso
    root = biselar(root, key);

    return counter;
}

// Insertar
nodeSplay* insert(nodeSplay* root, int key) {
    if (!root) return crearNodo(key);

    root = biselar(root, key);

    if (root->data == key)
        return root;

    nodeSplay* n = crearNodo(key);

    if (key < root->data) {
        n->right = root;
        n->left = root->left;
        root->left = nullptr;
    } else {
        n->left = root;
        n->right = root->right;
        root->right = nullptr;
    }

    return n;
}

// Eliminar
nodeSplay* eliminar(nodeSplay* root, int key) {
    if (!root) return nullptr;

    root = biselar(root, key);

    if (root->data != key)
        return root;

    nodeSplay* temp;

    if (!root->left) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = biselar(root->left, key);
        root->right = temp->right;
    }

    delete temp;
    return root;
}
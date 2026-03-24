#include <iostream>
using namespace std;

struct nodeSplay {
    int data;
    nodeSplay* left;
    nodeSplay* right;
};

// Crear nodo
nodeSplay* crearNodo(int data);

// Rotaciones
nodeSplay* rotarIzquierda(nodeSplay* x);
nodeSplay* rotarDerecha(nodeSplay* y);

// Splay
nodeSplay* biselar(nodeSplay* root, int key);

// Operaciones principales
int searchSplay(nodeSplay*& root, int key);
nodeSplay* insert(nodeSplay* root, int key);
nodeSplay* eliminar(nodeSplay* root, int key);

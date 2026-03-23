
#include <iostream>

using namespace std; 

struct nodoAVL {
    int data; 
    nodoAVL* left; 
    nodoAVL* right; 
    int height;
};

nodoAVL* createAVLNode(int data);
int height(nodoAVL* node);
int balanceFactor(nodoAVL* node);

//Rotaciones: 
nodoAVL* rightRotate(nodoAVL* y);
nodoAVL* leftRotate(nodoAVL* x);
// Inserción
nodoAVL* insert(nodoAVL* node, int key);
//Búsqueda
int searchAVL(nodoAVL* node, int key, int counter);

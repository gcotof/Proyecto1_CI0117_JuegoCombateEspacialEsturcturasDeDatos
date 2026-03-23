#ifndef ARBOL_BINARIO_HPP
#define ARBOL_BINARIO_HPP



//Estructura de nodo de un árbol binario. (Tiene cada nodo tiene una 'hoja' derecha e izquierda.)
struct Node {
    int data; 
    Node* left; //Se usan punteros porque si no, el compilador no sabr´ʼa cuanto espacio reservar. (Cada node contiene otros notes que contienen más nodes y así infinitamente.)
    Node* right; 
};

Node* createNode(int data);
Node* insertNode(Node* root, int data);


int searchBT(Node* root, int key, int counter);



#endif
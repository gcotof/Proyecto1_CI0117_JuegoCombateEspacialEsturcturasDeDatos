// A Binary Tree Data Structure is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child.
// Source: https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/

#include <iostream>
#include "arbol_binario.hpp"
using namespace std; 


// Función para crear un nuevo nodo. 
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data; 
    newNode->left = newNode->right = nullptr;
    return newNode; 
}

//Función para insertar un nodo en el árbol binario.
Node* insertNode(Node* root, int data){
    if (root == nullptr){
        return createNode(data); //Si el árbol está vacío, retornar nuevo nodo.
    }

    if (data < root->data){
        root->left = insertNode(root->left, data);
    }else if (data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root; 
}


//IMPORTANTE: FUNCIÓN DE BÚSQUEDA. 
//En vez de retornar un nodo. Debemos retornar un int con la cantidad de 'pasos' que tomamos.
int searchBT(Node* root, int key, int counter){
    // Base Cases: root is null or key is present at root
    if (root == nullptr) {
        return -1;
    }

    if (root->data == key){
        return counter; //Se encontró. Devolvemos la cantidad de pasos. 
    }

    if (root->data < key){
        return searchBT(root->right, key, counter + 1);
    }

    return searchBT(root->left, key, counter + 1);
}
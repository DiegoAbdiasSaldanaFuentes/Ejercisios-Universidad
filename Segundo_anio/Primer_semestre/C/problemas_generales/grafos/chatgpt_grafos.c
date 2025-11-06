/*HECHO POR CHATGPT*/


#include <stdio.h>
#include <stdlib.h>

// Estructura para un nodo de la lista
struct Nodo {
    int destino;
    struct Nodo* siguiente;
};

// Estructura para la lista de adyacencia
struct ListaAdyacencia {
    struct Nodo* cabeza;
};

// Estructura del grafo
struct Grafo {
    int numVertices;
    struct ListaAdyacencia* array;
};

// Función para crear un nodo
struct Nodo* crearNodo(int destino) {
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevoNodo->destino = destino;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Crear grafo con V vértices
struct Grafo* crearGrafo(int V) {
    struct Grafo* grafo = (struct Grafo*) malloc(sizeof(struct Grafo));
    grafo->numVertices = V;
    grafo->array = (struct ListaAdyacencia*) malloc(V * sizeof(struct ListaAdyacencia));
    for (int i = 0; i < V; i++)
        grafo->array[i].cabeza = NULL;
    return grafo;
}

// Añadir arista no dirigida
void agregarArista(struct Grafo* grafo, int origen, int destino) {
    // origen -> destino
    struct Nodo* nuevoNodo = crearNodo(destino);
    nuevoNodo->siguiente = grafo->array[origen].cabeza;
    grafo->array[origen].cabeza = nuevoNodo;

    // destino -> origen (por ser no dirigido)
    nuevoNodo = crearNodo(origen);
    nuevoNodo->siguiente = grafo->array[destino].cabeza;
    grafo->array[destino].cabeza = nuevoNodo;
}

// Imprimir
void imprimirGrafo(struct Grafo* grafo) {
    for (int v = 0; v < grafo->numVertices; v++) {
        struct Nodo* temp = grafo->array[v].cabeza;
        printf("Lista de adyacencia del vertice %d:\n", v);
        while (temp) {
            printf(" -> %d", temp->destino);
            temp = temp->siguiente;
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    struct Grafo* grafo = crearGrafo(V);
    agregarArista(grafo, 0, 1);
    agregarArista(grafo, 0, 4);
    agregarArista(grafo, 1, 2);
    agregarArista(grafo, 1, 3);
    agregarArista(grafo, 1, 4);
    agregarArista(grafo, 2, 3);
    agregarArista(grafo, 3, 4);

    imprimirGrafo(grafo);

    return 0;
}

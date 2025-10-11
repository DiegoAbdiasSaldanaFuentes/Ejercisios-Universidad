#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matriz;

// Inicializa la matriz de adyacencia de tamaño n x n
void crearMatriz(int n) {
    for (int i = 0; i < n; i++) {
        vector<int> row(n, 0);  // cada fila con n ceros
        matriz.push_back(row);
    }
}

// Agrega una conexión no dirigida entre dos nodos
void anadirConexion(int a, int b) {
    matriz[a][b] = 1;
    matriz[b][a] = 1;
}

int main() {
    int n; // cantidad de nodos
    cout << "Cantidad de nodos: ";
    cin >> n;

    crearMatriz(n);

    int q; // cantidad de aristas
    cout << "Cantidad de conexiones: ";
    cin >> q;

    cout << "Ingrese las conexiones (a b):" << endl;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        anadirConexion(a, b);
    }

    // Mostrar matriz resultante
    cout << "Matriz de adyacencia:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

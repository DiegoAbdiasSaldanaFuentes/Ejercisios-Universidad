#include <iostream>
#include <vector>
using namespace std;

int n; // número de ciudades
vector<vector<int>> dist; // matriz de distancias
int mejorDistancia = 999999; // valor grande al inicio

// Función recursiva para explorar rutas
void tsp(int ciudadActual, vector<bool> visitado, int visitadas, int distanciaActual) {
    // Caso base: si ya visitamos todas las ciudades
    if (visitadas == n) {
        // Volvemos al inicio (ciudad 0)
        distanciaActual += dist[ciudadActual][0];
        if (distanciaActual < mejorDistancia)
            mejorDistancia = distanciaActual;
        return;
    }

    // Explorar cada ciudad no visitada
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            visitado[i] = true;
            tsp(i, visitado, visitadas + 1, distanciaActual + dist[ciudadActual][i]);
            visitado[i] = false; // volver al estado anterior
        }
    }
}

int main() {
    // Definir la matriz de distancias
    dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    n = dist.size();
    vector<bool> visitado(n, false);
    visitado[0] = true; // empezamos en la ciudad 0

    tsp(0, visitado, 1, 0); // ciudad 0, 1 visitada, distancia 0

    cout << "Distancia mínima: " << mejorDistancia << endl;
    return 0;
}

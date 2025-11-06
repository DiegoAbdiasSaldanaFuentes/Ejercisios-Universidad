#include <iostream>
using namespace std;

int main() {
    double a, b, c;

    // Pedir los coeficientes
    cout << "Ingresa el coeficiente a: ";
    cin >> a;
    cout << "Ingresa el coeficiente b: ";
    cin >> b;
    cout << "Ingresa el coeficiente c: ";
    cin >> c;

    // Calcular el discriminante
    double D = b*b - 4*a*c;

    // Evaluar el discriminante
    if (D > 0) {
        cout << "La ecuacion tiene dos soluciones reales:" << endl;
        cout << "x1 = (-" << b << " + sqrt(" << D << ")) / " << 2*a << endl;
        cout << "x2 = (-" << b << " - sqrt(" << D << ")) / " << 2*a << endl;
    } else if (D == 0) {
        double x = -b / (2*a);
        cout << "La ecuacion tiene una solucion real: x = " << x << endl;
    } else {
        cout << "La ecuacion tiene soluciones complejas:" << endl;
        cout << "x1 = (-" << b << " + i*sqrt(" << -D << ")) / " << 2*a << endl;
        cout << "x2 = (-" << b << " - i*sqrt(" << -D << ")) / " << 2*a << endl;
    }

    return 0;
}

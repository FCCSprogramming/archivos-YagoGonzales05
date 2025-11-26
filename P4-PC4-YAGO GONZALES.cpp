#include <iostream>
using namespace std;

int main() {

    int g1, g2;
    cout << "Ingrese el grado del primer polinomio: ";
    cin >> g1;
    cout << "Ingrese el grado del segundo polinomio: ";
    cin >> g2;

    float *P = new float[g1 + 1];
    float *Q = new float[g2 + 1];
    float *R = new float[g1 + g2 + 1];

    for (int i = 0; i <= g1 + g2; i++) {
        R[i] = 0;
    }

    cout << "Coeficientes del primer polinomio:\n";
    for (int i = 0; i <= g1; i++) {
        cout << "Coeficiente de x^" << i << ": ";
        cin >> P[i];
    }

    cout << "Coeficientes del segundo polinomio:\n";
    for (int i = 0; i <= g2; i++) {
        cout << "Coeficiente de x^" << i << ": ";
        cin >> Q[i];
    }

    cout<<endl;
    cout << "PRIMER POLINOMIO: ";
    for (int i = g1; i >= 0; i--) {
        if (P[i] != 0) {
            if (i != g1 && P[i] > 0) cout << " + ";
            cout << P[i];
            if (i > 0) cout << "x^" << i;
        }
    }
    cout << endl;


    cout << "SEGUNDO POLINOMIO: ";
    for (int i = g2; i >= 0; i--) {
        if (Q[i] != 0) {
            if (i != g2 && Q[i] > 0) cout << " + ";
            cout << Q[i];
            if (i > 0) cout << "x^" << i;
        }
    }
    cout << endl;


    for (int i = 0; i <= g1; i++) {
        for (int j = 0; j <= g2; j++) {
            R[i + j] += P[i] * Q[j];
        }
    }

    cout<<endl;
    cout << "POLINOMIO RESULTANTE: ";
    for (int i = g1 + g2; i >= 0; i--) {
        if (R[i] != 0) {
            if (i != g1 + g2 && R[i] > 0) cout << " + ";
            cout << R[i];
            if (i > 0) cout << "x^" << i;
        }
    }
    cout << endl;

    delete[] P;
    delete[] Q;
    delete[] R;

    return 0;
}

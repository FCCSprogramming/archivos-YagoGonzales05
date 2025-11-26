#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

double areaTriangulo(double x1, double y1,
                     double x2, double y2,
                     double x3, double y3) {
    double A = x1 * (y3 - y2)
             + x2 * (y1 - y3)
             + x3 * (y2 - y1);

    return fabs(A) / 2.0;
}

int main() {

    ifstream in("laguna.txt");
    if (!in) {
        cout << "Error al abrir laguna.txt" << endl;
        return 1;
    }

    int nt, nv;
    in >> nt;
    in >> nv;

    vector<double> x(nv+1), y(nv+1);


    for (int i = 1; i <= nv; i++) {
        in >> x[i] >> y[i];
    }

    double areaTotal = 0.0;


    for (int i = 0; i < nt; i++) {
        int a, b, c;
        in >> a >> b >> c;

        areaTotal += areaTriangulo(
            x[a], y[a],
            x[b], y[b],
            x[c], y[c]
        );
    }

    in.close();


    ofstream out("area.txt");
    if (!out) {
        cout << "Error al crear area.txt" << endl;
        return 1;
    }

    out << areaTotal << endl;
    out.close();

    return 0;
}


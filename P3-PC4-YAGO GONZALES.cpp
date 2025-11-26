#include <iostream>
#include <fstream>
using namespace std;

void escribirFibonacciBinario() {
    ofstream archivo("fibonacci.bin", ios::binary);

    if (!archivo) {
        cout << "Error al crear el archivo." << endl;
        return;
    }

    long long fib[20];


    fib[0] = 0;
    fib[1] = 1;


    for (int i = 2; i < 20; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }


    archivo.write(reinterpret_cast<char*>(fib), sizeof(fib));

    archivo.close();
}

void leerFibonacciBinario() {
    ifstream archivo("fibonacci.bin", ios::binary);

    if (!archivo) {
        cout << "Error al leer el archivo." << endl;
        return;
    }

    long long fib[20];

    archivo.read(reinterpret_cast<char*>(fib), sizeof(fib));

    archivo.close();


    for (int i = 0; i < 20; i++) {
        cout << fib[i] << endl;
    }
}

int main() {
    escribirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}


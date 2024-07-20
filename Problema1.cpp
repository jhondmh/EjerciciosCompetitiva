// Escriba una funcion que tome un arreglo de enteros y un numero "k",
// y determine si esxisten los numeros en el arreglo cuya suma sea igual a k

#include <iostream>
#include <cstdlib>
using namespace std;

bool tiene_suma_k(int arr[], int tamaño, int k) {
    for (int i = 0; i < tamaño; ++i) {
        for (int j = i + 1; j < tamaño; ++j) {
            if (arr[i] + arr[j] == k) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {10, 15, 3, 7};
    int k = 17;
    int tamaño = sizeof(arr) / sizeof(arr[0]);

    if (tiene_suma_k(arr, tamaño, k)) {
        cout << "Existen dos numeros en el arreglo cuya suma es " << k << endl;
    } else {
        cout << "No existen dos numeros en el arreglo cuya suma sea " << k << endl;
    }

    system("pause");

    return 0;
}

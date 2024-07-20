// Dado un arreglo de enteros hallar el producto máximo
// de 3 numero diferentes

#include <cstdlib>
#include <iostream>


using namespace std;

int producto_maximo_de_tres(int arr[], int tamaño) {
    if (tamaño < 3) {
        throw invalid_argument(
            "El arreglo debe tener al menos tres elementos.");
    }

    // Inicializamos los tres números más grandes y los dos números más pequeños
    int max1 = -1000000000, max2 = -1000000000, max3 = -1000000000;
    int min1 = 1000000000, min2 = 1000000000;

    for (int i = 0; i < tamaño; ++i) {
        int num = arr[i];
        // Actualizamos los tres números más grandes
        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }

        // Actualizamos los dos números más pequeños
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    // Calculamos el producto de los tres números más grandes y el producto de los
    // dos números más pequeños y el número más grande
    int product1 = max1 * max2 * max3;
    int product2 = min1 * min2 * max1;

    // Devolver el máximo de los dos productos
    return (product1 > product2) ? product1 : product2;
}

int main() {
    int arr[] = {1, 10, -5, 1, -100};
    int tamaño = sizeof(arr) / sizeof(arr[0]);

    try {
        int max_producto = producto_maximo_de_tres(arr, tamaño);
        cout << "El producto maximo de tres numeros diferentes es: "
             << max_producto << endl;
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    cout << "\n";
    system("pause");

    return 0;
}

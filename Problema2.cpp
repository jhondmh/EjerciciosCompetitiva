// Dado una matriz cuadrada de nxn, escribe una funcion que rote
// la matriz 90 grados en sentido horario y devuelve la matriz

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Función para transponer la matriz
void transponer(vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matriz[i][j], matriz[j][i]);
        }
    }
}

// Función para invertir cada fila de la matriz
void invertir_filas(vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(matriz[i][j], matriz[i][n - 1 - j]);
        }
    }
}

// Función para rotar la matriz 90 grados en sentido horario
vector<vector<int>> rotar_matriz(vector<vector<int>>& matriz) {
    transponer(matriz);
    invertir_filas(matriz);
    return matriz;
}

// Función para imprimir la matriz
void imprimir_matriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matriz = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriz original:" << endl;
    imprimir_matriz(matriz);

    vector<vector<int>> matriz_rotada = rotar_matriz(matriz);

    cout << "\nMatriz rotada 90 grados en sentido horario:" << endl;
    imprimir_matriz(matriz_rotada);

    cout << "\n";

    system ("pause");

    return 0;
}

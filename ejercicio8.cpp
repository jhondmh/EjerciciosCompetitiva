// PROBLEMA DE LA MOCHILA

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Función para encontrar el valor máximo que se puede llevar en la mochila
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Crear una tabla para almacenar los resultados de los subproblemas
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Llenar la tabla dp de manera ascendente
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // Base case: no items or weight capacity is zero
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    // Capacidades de peso y valores de los objetos
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50; // Capacidad de la mochila
    int n = val.size();

    // Llamar a la función de la mochila y mostrar el resultado
    cout << "El valor máximo que se puede llevar en la mochila es " << knapsack(W, wt, val, n) << endl;

    system("pause");
    return 0;
}

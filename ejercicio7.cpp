// ORDENACIÓN TOPOLÓGICA

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <cstdlib>

void ordenacion_topologica(int V, std::vector<std::list<int>>& adj) {
    std::vector<int> grado_entrada(V, 0);

    // Calcular el grado de entrada de cada nodo
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            grado_entrada[v]++;
        }
    }

    // Encontrar todos los nodos sin aristas entrantes
    std::queue<int> cola;
    for (int i = 0; i < V; i++) {
        if (grado_entrada[i] == 0) {
            cola.push(i);
        }
    }

    std::vector<int> orden_topologico;
    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        orden_topologico.push_back(u);

        // Reducir el grado de entrada de los nodos vecinos
        for (int v : adj[u]) {
            grado_entrada[v]--;
            if (grado_entrada[v] == 0) {
                cola.push(v);
            }
        }
    }

    // Verificar si se procesaron todos los nodos
    if (orden_topologico.size() == V) {
        std::cout << "Orden topologico: ";
        for (int i : orden_topologico) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "No es posible ordenar las tareas debido a un ciclo.\n";
    }
}

int main() {
    int V = 5; // Número de nodos (tareas)
    std::vector<std::list<int>> adj(V);

    // Añadir aristas al grafo (dependencias entre tareas)
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[3].push_back(1);
    adj[3].push_back(4);

    // Resolver usando el algoritmo de Khan
    ordenacion_topologica(V, adj);

    system("pause");

    return 0;
}

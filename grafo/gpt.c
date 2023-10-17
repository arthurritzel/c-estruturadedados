#include <stdio.h>
#include <limits.h>

#define V 7  // Número de vértices (cidades)

// Função para encontrar o vértice com a distância mínima não incluído no conjunto SPT (Shortest Path Tree)
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Função para imprimir o caminho mais curto a partir do array de predecessores
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf(" -> %c", 'A' + j);
}

// Função para imprimir as distâncias e caminhos mais curtos
void printSolution(int dist[], int parent[]) {
    printf("Cidade\tDistância\tCaminho\n");
    for (int i = 0; i < V; i++) {
        printf("%c\t%d km\tA", 'A' + i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

// Função que implementa o algoritmo de Dijkstra
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Vetor de distâncias mínimas
    int sptSet[V];    // Conjunto de vértices já processados
    int parent[V];    // Array para armazenar o caminho mínimo

    // Inicialize todas as distâncias como infinito e sptSet como falso
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // A distância do vértice de origem para ele mesmo é sempre 0
    dist[src] = 0;
    parent[src] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        
        // Atualize as distâncias dos vértices adjacentes
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Imprimir o resultado
    printSolution(dist, parent);
}

int main() {
    int graph[V][V] = {
        {0, 10, 30, 0, 0, 0, 0},
        {10, 0, 15, 70, 0, 0, 0},
        {30, 15, 0, 0, 40, 0, 0},
        {0, 70, 0, 0, 60, 45, 0},
        {0, 0, 40, 60, 0, 15, 70},
        {0, 0, 0, 45, 15, 0, 15},
        {0, 0, 0, 0, 70, 15, 0}
    };
    
    printf("Caminho mais curto entre A e G:\n");
    dijkstra(graph, 0);  // Começando de A (índice 0)

    return 0;
}
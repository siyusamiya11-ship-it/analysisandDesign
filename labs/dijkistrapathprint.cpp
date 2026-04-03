#include <iostream>
#include <climits>
using namespace std;

#define V 5  


int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, index;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}


void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}


void printSolution(int dist[], int parent[]) {
    cout << "Vertex\tDistance\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}


void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Distance array
    bool visited[V]; // Visited set
    int parent[V];   // To store path

    
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;
    parent[src] = -1;

 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, parent);
}


int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0); // Source vertex = 0

    return 0;
}
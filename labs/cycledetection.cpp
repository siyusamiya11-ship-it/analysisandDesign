#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

bool hasCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<int> adj[5];

    // Example graph
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(1); // creates cycle
    adj[1].push_back(3);

    if (hasCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

const int N = 4;

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

bool visited[N];
int minCost = INT_MAX;

// TSP function
void tsp(int currCity, int count, int cost) {

    // If all cities visited, return to start
    if (count == N && graph[currCity][0] > 0) {
        minCost = min(minCost, cost + graph[currCity][0]);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[currCity][i] > 0) {

            visited[i] = true;

            tsp(i, count + 1, cost + graph[currCity][i]);

            // Backtracking
            visited[i] = false;
        }
    }
}

int main() {

    // Initialize visited array
    for (int i = 0; i < N; i++)
        visited[i] = false;

    // Start from city 0
    visited[0] = true;

    tsp(0, 1, 0);

    cout << "Minimum Cost = " << minCost << endl;

    return 0;
}

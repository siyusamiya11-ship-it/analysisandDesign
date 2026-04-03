#include <iostream>
#include <algorithm>
using namespace std;

#define V 4   
#define E 5   


struct Edge {
    int src, dest, weight;
};


struct Subset {
    int parent;
    int rank;
};


int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}


bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}


void kruskalMST(Edge edges[]) {
    sort(edges, edges + E, compare);

    Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    Edge result[V]; 
    int e = 0; 
    int i = 0; 

    while (e < V - 1 && i < E) {
        Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

       
        if (x != y) {
            result[e++] = next;
            Union(subsets, x, y);
        }
    }

 
    cout << "Edge \tWeight\n";
    for (i = 0; i < e; i++) {
        cout << result[i].src << " - "
             << result[i].dest << "\t"
             << result[i].weight << endl;
    }
}


int main() {
    Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges);

    return 0;
}
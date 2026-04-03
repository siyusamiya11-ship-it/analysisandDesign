#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

void ShortestPaths(int v, int cost[MAX][MAX], int dist[], int n)
{
    bool S[MAX];  

  
    for(int i = 1; i <= n; i++)
    {
        S[i] = false;
        dist[i] = cost[v][i];
    }

    S[v] = true;
    dist[v] = 0;


    for(int num = 2; num <= n-1; num++)
    {
        int u = -1;
        int min = INF;


        for(int i = 1; i <= n; i++)
        {
            if(!S[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        S[u] = true;

        
        for(int w = 1; w <= n; w++)
        {
            if(!S[w] && cost[u][w] != INF)
            {
                if(dist[w] > dist[u] + cost[u][w])
                {
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }
    }
}

int main()
{
    int n, v;
    int cost[MAX][MAX], dist[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;   
        }
    }

    cout << "Enter source vertex: ";
    cin >> v;

    ShortestPaths(v, cost, dist, n);

    cout << "\nShortest distances from vertex " << v << ":\n";
    for(int i = 1; i <= n; i++)
    {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    return 0;
}
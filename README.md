Searching Algorithms
1. Linear Search
Theory:
Checks each element one by one until the target is found.
Time Complexity:
Best: O(1)
Average: O(n)
Worst: O(n)
INPUT
```cpp
 #include <iostream>
#include <cstdlib>      
#include <ctime>        
#include <chrono>       

using namespace std;
using namespace chrono;


int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;   
    }
    return -1;  
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

   
    srand(time(0));


    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;  
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    auto start = high_resolution_clock::now();

    int result = linearSearch(arr, n, key);

    auto stop = high_resolution_clock::now();


    auto duration = duration_cast<nanoseconds>(stop - start);

    if(result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
```
OUTPUT:
```cpp
Enter number of elements: 6
Enter sorted elements:
10 20 30 40 50 70
Enter element to search: 70
Element found at index 5
```
2. Binary Search
Theory:
Divides the sorted array into halves and searches efficiently.
Time Complexity:
Best: O(1)
Average: O(log n)
Worst: O(log n)
INPUT:
```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;         

        else if (arr[mid] < key)
            low = mid + 1;       

        else
            high = mid - 1;     
    }

    return -1;  
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
```
OUTPUT:
```
Enter number of elements: 5
Enter sorted elements:
10 20 30 40 50
Enter element to search: 30
Element found at index 2
```
Sorting Algorithms
3. Bubble Sort
Theory:
Repeatedly swaps adjacent elements if they are in wrong order.
Time Complexity:
Best: O(n)
Worst: O(n²)
INPUT:
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;


void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
          
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    int n;
    cout << "Enter array size: ";
    cin >> n;

    int* arr = new int[n];

    srand(time(0));

  
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    cout << "Random numbers generated.\n";

    auto start = high_resolution_clock::now();

    bubbleSort(arr, n);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Time taken for Bubble Sort: "
         << duration.count() << " milliseconds" << endl;

    delete[] arr;

    return 0;
	}
```
OUTPUT
```cpp
Enter number of elements: 5
Enter elements:
5 2 4 1 3
Sorted array:
1 2 3 4 5
```
4. Selection Sort
Theory:
Finds the minimum element and places it at correct position.
Time Complexity:
Best/Worst: O(n²)
INPUT:
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

  
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

  
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }


    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```
OUTPUT:
```cpp
Enter number of elements: 5
Enter elements:
64 25 12 22 11

Sorted array:
11 12 22 25 64
```
5. Insertion Sort
Theory:
Builds sorted array one element at a time.
Time Complexity:
Best: O(n)
Worst: O(n²)
INPUT:
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

  
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

      
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

  
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```
OUTPUT:
```cpp
Enter number of elements: 5
Enter elements:
5 2 4 6 1

Sorted array:
1 2 4 5 6
```
6. Merge Sort
Merge Sort
Theory:
Divides array into halves and merges sorted parts.
Time Complexity:
Best/Worst: O(n log n)
INPUT:
```cpp
#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }


    for (int i = left, t = 0; i <= right; i++, t++) {
        arr[i] = temp[t];
    }
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);      // Left half
        mergeSort(arr, mid + 1, right); // Right half
        merge(arr, left, mid, right);   // Merge
    }
}


int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```
OUTPUT:
```cpp
Enter number of elements: 5
Enter elements:
5 2 4 6 1

Sorted array:
1 2 4 5 6
```
7. Quick Sort
Theory:
Uses divide-and-conquer with pivot element.
Time Complexity:
Best: O(n log n)
Average: O(n log n)
Worst: O(n²)
INPUT:
```cpp
#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];   
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  
    }


    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

  
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by Quick Sort: "
         << duration.count() << " nanoseconds" << endl;

    return 0;
}
```
OUTPUT:
```cpp
Enter number of elements: 5
Enter elements:
5 2 9 1 6

Sorted array:
1 2 5 6 9
```
Graph Algorithm
8. Adjacency Matrix
Theory:
Graph represented using a 2D matrix.
Time Complexity:
Space: O(V²)
INPUT:
```cpp
//adjancency matrix to calculate 
#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter number of modes: ";
cin>>n;
int adj[n][n];
cout<<"enter adjacency matrix:\n";
for(int i=0;i<n;i++){
    for(int j=0; j<n; j++){
    cin>>adj[i][j];
}
}
cout<<"number of modes="<<n<<endl;
return 0;
}
```
OUTPUT:
```cpp
Enter number of vertices: 3
Enter adjacency matrix:
0 1 1
1 0 0
1 0 0

Adjacency Matrix:
0 1 1
1 0 0
1 0 0
```
9. Dijkstra’s Algorithm
Theory:
Finds shortest path from source to all vertices.
Time Complexity:
O(V²) (basic)
O(E log V) (with priority queue)
INPUT:
```cpp
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
```
OUTPUT:
```cpp
Enter number of vertices: 5

Enter adjacency matrix:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0

Enter source vertex: 0
```
10. Prim’s Algorithm
Theory:
Finds Minimum Spanning Tree using greedy approach.
Time Complexity:
O(V²) or O(E log V)
INPUT:
```cpp
#include <iostream>
#include <climits>
using namespace std;

#define V 5   

int findMin(int key[], bool mstSet[]) {
    int min = INT_MAX, index;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}


void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}


void primMST(int graph[V][V]) {
    int parent[V];   
    int key[V];      
    bool mstSet[V]; 


    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;     
    parent[0] = -1; 

    // Build MST
    for (int count = 0; count < V - 1; count++) {
        int u = findMin(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}


int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
```
OUTPUT:
Edge    Weight
0 - 1    2
1 - 2    3
1 - 4    5
0 - 3    6
```
11. Cycle Detection
Theory:
Checks if a graph contains a cycle.
Time Complexity:
O(V + E)
INPUT:
```cpp
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
```cpp
OUTPUT:
Enter number of vertices: 4
Enter number of edges: 4
Enter edges:
0 1
1 2
2 3
3 1

Graph contains cycle
```
12. Multistage Graph
Theory:
Used in shortest path problems with stages.
Time Complexity:
O(V + E)
INPUT:
```cpp
#include <iostream>
#include <climits>
using namespace std;

#define N 8   

int main() {

    int graph[N][N] = {
        {0, 1, 2, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 11, 0, 0},
        {0, 0, 0, 0, 9, 5, 16, 0},
        {0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 18},
        {0, 0, 0, 0, 0, 0, 0, 13},
        {0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int cost[N], path[N];


    cost[N - 1] = 0;

  
    for (int i = N - 2; i >= 0; i--) {
        cost[i] = INT_MAX;

        for (int j = i + 1; j < N; j++) {
            if (graph[i][j] != 0) {
                if (graph[i][j] + cost[j] < cost[i]) {
                    cost[i] = graph[i][j] + cost[j];
                    path[i] = j;
                }
            }
        }
    }

   
    cout << "Minimum cost: " << cost[0] << endl;

  
    cout << "Path: 0 ";
    int i = 0;
    while (i != N - 1) {
        i = path[i];
        cout << "-> " << i;
    }

    return 0;
}
```
OUTPUT:
```cpp
Minimum cost = 9
Shortest path:
0 → 3 → 6 → 7
```
Optimization Problems
13. Knapsack
Theory:
Maximize profit under weight constraint.
Time Complexity:
O(nW)
INPUT:
```cpp
#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[100][100];

 
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n = 3;
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;

    cout << "Maximum value = " << knapsack(W, wt, val, n);

    return 0;
}
```
OUTPUT:
```cpp
Enter number of items: 4

Enter weights:
2 3 4 5

Enter profits:
3 4 5 6

Enter capacity of knapsack: 5
```
14. Activity Selection
Theory:
Select maximum non-overlapping activities.
Time Complexity:
O(n log n)
INPUT:
```cpp
#include <iostream>
#include <algorithm>
using namespace std;


struct Activity {
    int start, finish;
};


bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity arr[], int n) {
   
    sort(arr, arr + n, compare);

    cout << "Selected activities:\n";

    // First activity always selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";

    // Select remaining activities
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")\n";
            i = j;
        }
    }
}

int main() {
    Activity arr[] = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    activitySelection(arr, n);

    return 0;
}
```
OUTPUT:
```cpp
Selected activities are:
(1, 3)
(3, 5)
(5, 7)
(8, 9)

Maximum number of activities = 4
```
15. Travelling Salesperson (TSP)
Theory:
Find shortest route visiting all cities.
Time Complexity:
O(n!)
INPUT:
```cpp
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


void tsp(int currCity, int count, int cost) {


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

    for (int i = 0; i < N; i++)
        visited[i] = false;

    visited[0] = true;

    tsp(0, 1, 0);

    cout << "Minimum Cost = " << minCost << endl;

    return 0;
}
```
OUTPUT:
```cpp
Enter number of cities: 4

Cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
```
Recursion & Divide-Conquer
16. Permutations
Theory:
Generates all possible arrangements.
Time Complexity:
O(n!)
INPUT:
```cpp
#include <iostream>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << endl;
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);      
        permute(str, l + 1, r);   
        swap(str[l], str[i]);      
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    permute(str, 0, str.length() - 1);
    return 0;
}
```
OUTPUT:
```cpp
Enter string: ABC
ABC
ACB
BAC
BCA
CAB
CBA
```
17. Tower of Hanoi
Theory:
Move disks using recursion.
Time Complexity:
O(2ⁿ)
INPUT:
```cpp
//TOWER OF HANOI USING RECURSION
#include<iostream>
using namespace std;
void towerOfhanoi(int n,char F,char T, char U){
    if(n==1){
    cout<<"move disc 1 : "<< F<<" to "<< T<<endl;
return;
}
    towerOfhanoi(n-1,F,T,U);
    cout<<"move disc :"<<F<<" to "<<U<<endl;
    towerOfhanoi(n-1,F,T,U);


}
int main(){
    int n;
    cout<<"enter number of disc";
    cin>>n;
    towerOfhanoi(n,'F','T','U');
    return 0;

}
```
OUTPUT:
```cpp
Enter number of disks: 3
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
18. Matrix Chain Multiplication
Theory:
Find optimal multiplication order.
Time Complexity:
O(n³)
INPUT:
```cpp
#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int p[], int n) {
    int m[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter dimensions array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int result = matrixChainMultiplication(p, n + 1);

    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}
```
OUTPUT:
```cpp
Enter number of matrices: 4

Enter dimensions array:
10 20 30 40 30
```
19. Strassen Algorithm
Theory:
Fast matrix multiplication.
Time Complexity:
O(n^2.81)
INPUT:
```cpp
#include <iostream>
using namespace std;

void add(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2];
    int M5[2][2], M6[2][2], M7[2][2];
    int AResult[2][2], BResult[2][2];

 
    add(A, A, AResult);
    add(B, B, BResult);
    M1[0][0] = AResult[0][0] * BResult[0][0];


    M2[0][0] = (A[1][0] + A[1][1]) * B[0][0];

    M3[0][0] = A[0][0] * (B[0][1] - B[1][1]);


    M4[0][0] = A[1][1] * (B[1][0] - B[0][0]);


    M5[0][0] = (A[0][0] + A[0][1]) * B[1][1];

   
    M6[0][0] = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);


    M7[0][0] = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

  
    C[0][0] = M1[0][0] + M4[0][0] - M5[0][0] + M7[0][0];
    C[0][1] = M3[0][0] + M5[0][0];
    C[1][0] = M2[0][0] + M4[0][0];
    C[1][1] = M1[0][0] - M2[0][0] + M3[0][0] + M6[0][0];
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    strassen(A, B, C);

    cout << "Result matrix:\n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
```
OUTPUT
```cpp
C[0][0] = 65 + 8 - 24 - 30 = 19
C[0][1] = -2 + 24          = 22
C[1][0] = 35 + 8           = 43
C[1][1] = 65 - 35 - 2 + 22 = 50
Resultant matrix:
19 22
43 50
```
Mathematical Algorithms
20. Power (xⁿ)
Theory:
Computes exponent using recursion.
Time Complexity:
O(log n)
INPUT:
```cpp
#include <iostream>
using namespace std;

long long power(int x, int n) {
    long long result = 1;

    if(n < 0) {
        cout << "Negative powers not supported for integers.";
        return -1;
    }

    while(n > 0) {
        if(n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }

    return result;
}

int main() {
    int x, n;

    cout << "Enter base (X): ";
    cin >> x;

    cout << "Enter power (n): ";
    cin >> n;

    long long result = power(x, n);

    if(result != -1) {
        cout << "Result (X^n) = " << result << endl;
    }

    return 0;
}
```
OUTPUT"
```cpp
Enter value of x: 2
Enter value of n: 5
Result = 32
21. Horner’s Method
Theory:
Efficient polynomial evaluation.
Time Complexity:
O(n)
INPUT:
```cpp
#include <iostream>
using namespace std;


int horner(int coeff[], int n, int x)
{
    if (n == 0)
        return coeff[0];

    return horner(coeff, n - 1, x) * x + coeff[n];
}

int main()
{
    int n, x;

    cout << "Enter degree of polynomial: ";
    cin >> n;

    int coeff[n + 1];

    cout << "Enter coefficients (from constant to highest degree):\n";
    for (int i = 0; i <= n; i++)
        cin >> coeff[i];

    cout << "Enter value of x: ";
    cin >> x;

    int result = horner(coeff, n, x);

    cout << "Polynomial value is: " << result << endl;

    return 0;
}
```
OUTPUT:
```cpp
Enter degree of polynomial: 3

Enter coefficients:
2  -6  2  -1

Enter value of x: 3
```
22. Max & Min
Theory:
Find largest and smallest elements.
Time Complexity:
O(n)
INPUT:
```cpp
#include <iostream>
using namespace std;

struct Pair {
    int min;
    int max;
};

Pair findMinMax(int arr[], int low, int high) {
    Pair result, left, right;
    int mid;

    
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

   
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    
    mid = (low + high) / 2;

    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

 
    result.min = (left.min < right.min) ? left.min : right.min;

    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Pair ans = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << ans.min << endl;
    cout << "Maximum element: " << ans.max << endl;

    return 0;
}
```
OUTPUT:
```cpp
Enter number of elements: 5
Enter elements:
3 7 2 9 5
Maximum element = 9
Minimum element = 2
```
23. Kth Smallest
Theory:
Find kth smallest element (Quickselect).
Time Complexity:
Average: O(n)
INPUT:
```cpp
#include <iostream>
using namespace std;


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];   
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}


int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k)
            return arr[pi];
        else if (pi > k)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1;  
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];   

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cout << "Enter k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid value of k";
        return 0;
    }

    int result = quickSelect(arr, 0, n - 1, k - 1);

    cout << "Kth smallest element is: " << result;

    return 0;
}
```
OUTPUT
```CPP
Enter number of elements: 6
Enter elements:
7 10 4 3 20 15
Enter value of k: 3
Kth smallest element = 7
```
24.Duplicate Number
Theory:
Find repeating element in array.
Time Complexity:
O(n)
INPUT:
```cpp
#include <iostream>
using namespace std;

void findDuplicate(int arr[], int n, int i, int j)
{

    if (i >= n - 1)
        return;

 
    if (j >= n)
    {
        findDuplicate(arr, n, i + 1, i + 2);
        return;
    }

    if (arr[i] == arr[j])
    {
        cout << "Duplicate element: " << arr[i] << endl;
        return;   
    }

  
    findDuplicate(arr, n, i, j + 1);
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    findDuplicate(arr, n, 0, 1);

    return 0;
}
```
OUTPUT
```cpp
Enter number of elements: 6
Enter elements:
1 3 4 2 2 5
Duplicate element = 2
```
25. Consecutive Numbers
Theory:
Checks sequence continuity.
Time Complexity:
O(n)
INPUT:
```cpp
#include <iostream>
using namespace std;

int xorRange(int n) {
    if (n == 0)
        return 0;
    return n ^ xorRange(n - 1);
}

int xorArray(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] ^ xorArray(arr, n - 1);
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[n - 1];
    cout << "Enter " << n - 1 << " numbers:\n";

    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];

    int result = xorRange(n) ^ xorArray(arr, n - 1);

    cout << "Missing number is: " << result;
    return 0;
}
26. Velocity
Theory:
Speed calculation (distance/time).
Time Complexity:
O(1)
INPUT:
#include <iostream>
using namespace std;


int velocity(int u, int a, int t)
{

    if (t == 0)
        return u;

  
    return velocity(u, a, t - 1) + a;
}

int main()
{
    int u, a, t;

    cout << "Enter initial velocity: ";
    cin >> u;

    cout << "Enter acceleration: ";
    cin >> a;

    cout << "Enter time: ";
    cin >> t;

    cout << "Final velocity is: " << velocity(u, a, t);

    return 0;
}
```
OUTPUT:
```CPP
Enter number of elements: 5
Enter elements:
3 4 5 6 7
Array contains consecutive numbers
```
27. Truth Table
Theory:
Evaluates logical expressions.
Time Complexity:
O(2ⁿ)
INPUT:
```cpp
#include <iostream>
using namespace std;

int main() {
    int A, B;

    cout << "A B | AND OR XOR NOT(A) NOT(B)\n";
    cout << "--------------------------------\n";

    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            cout << A << " " << B << " | "
                 << (A && B) << "   "
                 << (A || B) << "   "
                 << (A ^ B) << "    "
                 << (!A) << "      "
                 << (!B) << endl;
        }
    }

    return 0;
}
```
OUTPUT
```cpp
A B | AND OR XOR NOTA NOTB
--------------------------
0 0 |  0   0   0    1     1
0 1 |  0   1   1    1     0
1 0 |  0   1   1    0     1
1 1 |  1   1   0    0     0
```
28.N QUEEN's
INPUT:
```cpp
 #include <iostream>
using namespace std;

int board[20][20];
int n;

bool isSafe(int row, int col) {
    // Check left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve(int col) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solve(col + 1))
                return true;

            board[i][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (solve(0)) {
        cout << "Solution exists:\n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}
```
OUTPUT:
```cpp
Enter number of queens: 4
Solution exists:

0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
29. SUBSET SUM
INPUT:
```cpp
#include <iostream>
using namespace std;

int arr[20], x[20], n, sum;

void subset(int s, int k, int r) {
    x[k] = 1;

    if (s + arr[k] == sum) {
        cout << "\nSubset: ";
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1)
                cout << arr[i] << " ";
        }
    }
    else if (s + arr[k] + arr[k + 1] <= sum) {
        subset(s + arr[k], k + 1, r - arr[k]);
    }

    if ((s + r - arr[k] >= sum) && (s + arr[k + 1] <= sum)) {
        x[k] = 0;
        subset(s, k + 1, r - arr[k]);
    }
}

int main() {
    int total = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    cout << "Enter sum: ";
    cin >> sum;

    subset(0, 0, total);

    return 0;
}
```
OUTPUT:
```cpp
Enter number of elements: 4
Enter elements:
1 2 3 4
Enter sum: 5
Subset: 1 4
Subset: 2 3
```
30. CHROMATIC NUMBER
INPUT:
```cpp
#include <iostream>
using namespace std;

int graph[20][20], color[20];
int n;

bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

void graphColoring() {
    for (int i = 0; i < n; i++)
        color[i] = 0;

    color[0] = 1; // first color

    for (int v = 1; v < n; v++) {
        for (int c = 1; c <= n; c++) {
            if (isSafe(v, c)) {
                color[v] = c;
                break;
            }
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    graphColoring();

    cout << "\nVertex Coloring:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " -> Color " << color[i] << endl;
    }

    int chromaticNumber = 0;
    for (int i = 0; i < n; i++)
        chromaticNumber = max(chromaticNumber, color[i]);

    cout << "\nChromatic Number = " << chromaticNumber << endl;

    return 0;
}
```
OUTPUT:
```CPP
Enter number of vertices: 4

Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Vertex Coloring:
Vertex 0 -> Color 1
Vertex 1 -> Color 2
Vertex 2 -> Color 3
Vertex 3 -> Color 2

Chromatic Number = 3
```
30.Hamiltonian Graph
INPUT:
```cpp
#include <iostream>
using namespace std;

int graph[20][20], path[20];
int n;

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianUtil(int pos) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(pos + 1))
                return true;

            path[pos] = -1;
        }
    }
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamiltonianUtil(1)) {
        cout << "\nHamiltonian Cycle exists:\n";
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << path[0] << endl;
    } else {
        cout << "\nNo Hamiltonian Cycle exists";
    }

    return 0;
}
```
OUTPUT:
```cpp
Enter number of vertices: 5

Enter adjacency matrix:
0 1 1 1 0
1 0 1 0 1
1 1 0 1 0
1 0 1 0 1
0 1 0 1 0
Hamiltonian Cycle exists:
0 1 2 3 4 0
```
31. merge graph

```python
import matplotlib.pyplot as plt

steps = []

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        merge_sort(left)
        merge_sort(right)

        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

        steps.append(arr.copy())


def plot_steps(steps):
    passes = list(range(len(steps)))

    for i in range(len(steps[0])):
        plt.plot(passes, [step[i] for step in steps], marker='o')

    plt.xlabel("Steps (Merges)")
    plt.ylabel("Element Values")
    plt.title("Merge Sort Visualization")
    plt.grid()
plt.savefig("merge_sort_graph.png", dpi=300)
    plt.show()


arr = [5, 2, 9, 1, 6]
steps.append(arr.copy())

merge_sort(arr)
plot_steps(steps)
```
OUTPUT:
```cpp
The following graph shows the working of Merge Sort:

![Merge Sort Graph](merge_sort_graph.png)
```
32. Graph selection
INPUT:
```python
import matplotlib.pyplot as plt

def selection_sort_graph(arr):
    n = len(arr)
    steps = []
    passes = []

    # Store initial state
    steps.append(arr.copy())
    passes.append(0)

    # Selection sort
    for i in range(n):
        min_idx = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j

        # Swap
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

        # Store step after each pass
        steps.append(arr.copy())
        passes.append(i + 1)

    # Plot graph
    for i in range(len(arr)):
        plt.plot(passes, [step[i] for step in steps], marker='o')

    plt.xlabel("Pass Number")
    plt.ylabel("Element Value")
    plt.title("Selection Sort Visualization")
    plt.grid()
 plt.savefig("selection_sort_graph.png")
    plt.show() 

# Example
arr = [64, 25, 12, 22, 11]
selection_sort_graph(arr)
```
OUTPUT:
```python
##  Selection Sort Graph

![Selection Sort](selection_sort_graph.png)
```
33.Linear graph
INPUT:
```python
import matplotlib.pyplot as plt

def linear_search_graph(arr, target):
    steps = []
    indices = []

    for i in range(len(arr)):
        steps.append(i + 1)     # Step number
        indices.append(i)       # Index being checked

        if arr[i] == target:
            print(f"Element found at index {i}")
            break

    # Plot graph
    plt.plot(steps, indices, marker='o')
    plt.xlabel("Steps")
    plt.ylabel("Index Checked")
    plt.title("Linear Search Visualization")
    plt.grid()
  plt.savefig("linear_search_graph.png")
    plt.show()
```
OUTPUT:
```python
##  Linear Search Graph

![Linear Search](linear_search_graph.png)
```
34. Bubble graph
INPUT:
```python
import matplotlib.pyplot as plt

def bubble_sort_graph(arr):
    n = len(arr)
    passes = []
    values = []

    # Store initial state
    passes.append(0)
    values.append(arr.copy())

    # Bubble sort
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

        # Store array after each pass
        passes.append(i + 1)
        values.append(arr.copy())

    # Plot graph
    for i in range(len(values[0])):
        plt.plot(passes, [v[i] for v in values], marker='o')

    plt.xlabel("Pass Number")
    plt.ylabel("Element Value")
    plt.title("Bubble Sort Visualization")
    plt.grid()
   plt.savefig("bubble_sort_graph.png")
    plt.show()


# Example
arr = [5, 2, 4, 3, 1]
bubble_sort_graph(arr)
```
OUTPUT:
```python
##  Bubble Sort Graph

![Bubble Sort](bubble_sort_graph.png)
35. Graph binary
INPUT:
```python
import matplotlib.pyplot as plt

def binary_search_graph(arr, target):
    low = 0
    high = len(arr) - 1

    steps = []
    mids = []

    step = 1

    while low <= high:
        mid = (low + high) // 2

        steps.append(step)
        mids.append(mid)

        if arr[mid] == target:
            print(f"Element found at index {mid}")
            break
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

        step += 1

    # Plot graph
    plt.plot(steps, mids, marker='o')
    plt.xlabel("Steps")
    plt.ylabel("Mid Index")
    plt.title("Binary Search Process Visualization")
    plt.grid()
 plt.savefig("binary_search_graph.png")
    plt.show()


# Example
arr = [2, 3, 4, 5, 6, 7, 8]
target = 5

binary_search_graph(arr, target)
```
OUTPUT:
```python
## Binary Search Graph

![Binary Search](binary_search_graph.png)
```



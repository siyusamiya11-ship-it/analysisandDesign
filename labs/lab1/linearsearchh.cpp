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
    cout << "Enter array size: ";
    cin >> n;

    int* arr = new int[n];

    
    srand(time(0));

    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;   
    }

    cout << "Random numbers generated successfully.\n";

    int key = -1;  

    auto start = high_resolution_clock::now();

    linearSearch(arr, n, key);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    delete[] arr;

    return 0;
}

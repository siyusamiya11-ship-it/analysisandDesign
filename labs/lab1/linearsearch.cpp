#include <iostream>
#include <cstdlib>      // for rand()
#include <ctime>        // for time()
#include <chrono>       // for time measurement

using namespace std;
using namespace chrono;

// Linear Search Function
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;   // return index if found
    }
    return -1;  // not found
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    // Seed random number generator
    srand(time(0));

    // Generate random numbers
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;  // numbers between 0–9999
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    // Start time
    auto start = high_resolution_clock::now();

    int result = linearSearch(arr, n, key);

    // End time
    auto stop = high_resolution_clock::now();

    // Calculate duration in nanoseconds
    auto duration = duration_cast<nanoseconds>(stop - start);

    if(result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
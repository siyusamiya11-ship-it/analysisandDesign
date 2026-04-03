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

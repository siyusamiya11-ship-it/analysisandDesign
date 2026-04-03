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
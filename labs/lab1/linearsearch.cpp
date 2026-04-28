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

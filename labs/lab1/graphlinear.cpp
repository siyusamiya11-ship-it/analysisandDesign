#include <iostream>
using namespace std;

// Linear Search function
int linearSearch(int arr[], int n, int key) {
    int comparisons = 0;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            break;
        }
    }
    return comparisons;
}

int main() {
    int n;
    cout << "Enter max size: ";
    cin >> n;

    cout << "\nSize\tComparisons\n";

    for (int size = 1; size <= n; size++) {
        int arr[1000];  // fixed size (safe for beginners)

        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        int key = size; // worst case
        int comparisons = linearSearch(arr, size, key);

        cout << size << "\t" << comparisons << endl;
    }

    return 0;
}
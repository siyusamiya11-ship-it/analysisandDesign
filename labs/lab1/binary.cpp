#include <iostream>
using namespace std;

int searchTwoThird(int arr[], int low, int high, int key) {

    while (low <= high) {

        // Divide array into n/3 and 2n/3
        int mid = low + (high - low) / 3;

        if (arr[mid] == key)
            return mid;

        // If key is smaller → search first n/3 part
        if (key < arr[mid]) {
            high = mid - 1;
        }
        // Else search remaining 2n/3 part
        else {
            low = mid + 1;
        }
    }

    return -1;  // Not found
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = searchTwoThird(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
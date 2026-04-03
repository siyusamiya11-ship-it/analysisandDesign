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
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
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
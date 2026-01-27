#include <iostream>
using namespace std;


int horner(int coeff[], int n, int x)
{
    if (n == 0)
        return coeff[0];

    return horner(coeff, n - 1, x) * x + coeff[n];
}

int main()
{
    int n, x;

    cout << "Enter degree of polynomial: ";
    cin >> n;

    int coeff[n + 1];

    cout << "Enter coefficients (from constant to highest degree):\n";
    for (int i = 0; i <= n; i++)
        cin >> coeff[i];

    cout << "Enter value of x: ";
    cin >> x;

    int result = horner(coeff, n, x);

    cout << "Polynomial value is: " << result << endl;

    return 0;
}
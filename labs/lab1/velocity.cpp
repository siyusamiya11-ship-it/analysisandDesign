#include <iostream>
using namespace std;


int velocity(int u, int a, int t)
{

    if (t == 0)
        return u;

    // Recursive case
    return velocity(u, a, t - 1) + a;
}

int main()
{
    int u, a, t;

    cout << "Enter initial velocity: ";
    cin >> u;

    cout << "Enter acceleration: ";
    cin >> a;

    cout << "Enter time: ";
    cin >> t;

    cout << "Final velocity is: " << velocity(u, a, t);

    return 0;
}

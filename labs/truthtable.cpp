#include <iostream>
using namespace std;

int main() {
    int A, B;

    cout << "A B | AND OR XOR NOT(A) NOT(B)\n";
    cout << "--------------------------------\n";

    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            cout << A << " " << B << " | "
                 << (A && B) << "   "
                 << (A || B) << "   "
                 << (A ^ B) << "    "
                 << (!A) << "      "
                 << (!B) << endl;
        }
    }

    return 0;
}
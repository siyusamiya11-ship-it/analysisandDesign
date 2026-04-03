#include <iostream>
using namespace std;

void add(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2];
    int M5[2][2], M6[2][2], M7[2][2];
    int AResult[2][2], BResult[2][2];

 
    add(A, A, AResult);
    add(B, B, BResult);
    M1[0][0] = AResult[0][0] * BResult[0][0];


    M2[0][0] = (A[1][0] + A[1][1]) * B[0][0];

    M3[0][0] = A[0][0] * (B[0][1] - B[1][1]);


    M4[0][0] = A[1][1] * (B[1][0] - B[0][0]);


    M5[0][0] = (A[0][0] + A[0][1]) * B[1][1];

   
    M6[0][0] = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);


    M7[0][0] = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

  
    C[0][0] = M1[0][0] + M4[0][0] - M5[0][0] + M7[0][0];
    C[0][1] = M3[0][0] + M5[0][0];
    C[1][0] = M2[0][0] + M4[0][0];
    C[1][1] = M1[0][0] - M2[0][0] + M3[0][0] + M6[0][0];
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    strassen(A, B, C);

    cout << "Result matrix:\n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

void transpose(int A[][3], int B[][3]) {
    int rows = A[0][0], cols = A[0][1], terms = A[0][2];
    B[0][0] = cols;
    B[0][1] = rows;
    B[0][2] = terms;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= terms; j++) {
            if (A[j][1] == i) {
                B[k][0] = A[j][1];
                B[k][1] = A[j][0];
                B[k][2] = A[j][2];
                k++;
            }
        }
    }
}

void print(int A[][3]) {
    for (int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}

int main() {
    int A[6][3] = { {4, 4, 5}, {0, 0, 10}, {0, 3, 12}, {1, 1, 8}, {2, 2, 15}, {3, 0, 5} };
    int B[6][3];

    cout << "Original Matrix (Triplet):\n";
    print(A);

    transpose(A, B);

    cout << "\nTranspose Matrix (Triplet):\n";
    print(B);

    return 0;
}

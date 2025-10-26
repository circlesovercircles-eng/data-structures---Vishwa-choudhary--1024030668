#include <iostream>
using namespace std;

void add(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible!\n";
        return;
    }

    int i=1, j=1, k=1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
            C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0]==A[i][0] && B[j][1]<A[i][1])) {
            C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++;
        }
        else { 
            int sum = A[i][2]+B[j][2];
            if (sum != 0) {
                C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=sum; k++;
            }
            i++; j++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++;
    }

    C[0][2]=k-1;
}

void print(int A[][3]) {
    for (int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}

int main() {
    int A[5][3] = { {3,3,4}, {0,0,3}, {0,2,5}, {1,1,7}, {2,2,9} };
    int B[4][3] = { {3,3,3}, {0,0,2}, {1,2,6}, {2,2,10} };
    int C[10][3];

    cout << "Matrix A:\n"; print(A);
    cout << "\nMatrix B:\n"; print(B);

    add(A,B,C);

    cout << "\nResult of Addition:\n"; print(C);

    return 0;
}

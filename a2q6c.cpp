#include <iostream>
using namespace std;

void transpose(int A[][3], int B[][3]) {
    int rows = A[0][0], cols = A[0][1], terms = A[0][2];
    B[0][0] = cols; B[0][1] = rows; B[0][2] = terms;
    int k=1;
    for (int i=0;i<cols;i++) {
        for (int j=1;j<=terms;j++) {
            if (A[j][1]==i) {
                B[k][0]=A[j][1]; B[k][1]=A[j][0]; B[k][2]=A[j][2];
                k++;
            }
        }
    }
}

void multiply(int A[][3], int B[][3], int C[][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible!\n"; return;
    }

    int m=A[0][0], n=A[0][1], p=B[0][1];
    int BT[20][3]; transpose(B, BT);

    int k=1;
    for (int i=0;i<m;i++) {
        for (int j=0;j<p;j++) {
            int sum=0;
            for (int a=1;a<=A[0][2];a++) {
                if (A[a][0]==i) {
                    for (int b=1;b<=BT[0][2];b++) {
                        if (BT[b][0]==j && BT[b][1]==A[a][1]) {
                            sum += A[a][2]*BT[b][2];
                        }
                    }
                }
            }
            if (sum!=0) {
                C[k][0]=i; C[k][1]=j; C[k][2]=sum; k++;
            }
        }
    }
    C[0][0]=m; C[0][1]=p; C[0][2]=k-1;
}

void print(int A[][3]) {
    for (int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}

int main() {
    int A[5][3] = { {2,3,4}, {0,0,1}, {0,2,2}, {1,1,3}, {1,2,4} };
    int B[4][3] = { {3,2,3}, {0,0,5}, {1,1,6}, {2,0,7} };
    int C[10][3];

    cout << "Matrix A:\n"; print(A);
    cout << "\nMatrix B:\n"; print(B);

    multiply(A,B,C);

    cout << "\nResult of Multiplication:\n"; print(C);

    return 0;
}

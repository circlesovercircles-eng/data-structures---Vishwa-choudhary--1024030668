#include <iostream>
using namespace std;

class UpperTriangular {
    int *arr, n;
public:
    UpperTriangular(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for (int i=0;i<n*(n+1)/2;i++) arr[i]=0;
    }
    void set(int i, int j, int x) {
        if (i<=j) arr[(i-1)*n - (i-1)*(i-2)/2 + (j-i)] = x;
    }
    int get(int i, int j) {
        if (i<=j) return arr[(i-1)*n - (i-1)*(i-2)/2 + (j-i)];
        return 0;
    }
    void display() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UpperTriangular u(4);
    u.set(1,1,1); u.set(1,2,2); u.set(1,3,3); u.set(1,4,4);
    u.set(2,2,5); u.set(2,3,6); u.set(2,4,7);
    u.set(3,3,8); u.set(3,4,9);
    u.set(4,4,10);
    u.display();
    return 0;
}

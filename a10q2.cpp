#include <iostream>
#include <unordered_set>
using namespace std;

void findCommon(int A[], int n1, int B[], int n2) {
    unordered_set<int> setA(A, A + n1);
    cout << "Common elements: ";
    
    for (int i = 0; i < n2; i++) {
        if (setA.count(B[i])) {
            cout << B[i] << " ";
            setA.erase(B[i]); // Avoid duplicates
        }
    }
    cout << endl;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    
    cout << "A = [1, 2, 3, 4]\nB = [3, 4, 5, 6]" << endl;
    findCommon(A, 4, B, 4);
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinctCount = 0;

    // Check each element if it appeared before
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        // Compare with all previous elements
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct) {
            distinctCount++;
        }
    }

    cout << "Total number of distinct elements: " << distinctCount << endl;

    return 0;
}

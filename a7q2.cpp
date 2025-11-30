#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int min_idx = left, max_idx = left;
        
        // Single pass to find both min and max
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[min_idx]) {
                min_idx = i;
            }
            if (arr[i] > arr[max_idx]) {
                max_idx = i;
            }
        }
        
        // Place minimum at left end
        swap(arr[left], arr[min_idx]);
        
        // If max was at left position, update max_idx after swap
        if (min_idx == left) {
            max_idx = left;
            for (int i = left + 1; i <= right; i++) {
                if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
        }
        
        // Place maximum at right end
        swap(arr[right], arr[max_idx]);
        
        left++;
        right--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    improvedSelectionSort(arr, n);
    
    cout << "Improved Selection Sort: ";
    printArray(arr, n);
    
    return 0;
}

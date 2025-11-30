#include <iostream>
using namespace std;

// a. Selection Sort - O(n²)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

// b. Insertion Sort - O(n²) worst, O(n) best
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// c. Bubble Sort - O(n²)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// Merge function for merge sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

// d. Merge Sort - O(n log n)
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// e. Quick Sort - O(n log n) average
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    // Test each algorithm on separate copies
    int test1[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(test1, n);
    cout << "\nSelection Sort: "; printArray(test1, n);
    
    int test2[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(test2, n);
    cout << "Insertion Sort: "; printArray(test2, n);
    
    int test3[] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(test3, n);
    cout << "Bubble Sort: "; printArray(test3, n);
    
    int test4[] = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(test4, 0, n-1);
    cout << "Merge Sort: "; printArray(test4, n);
    
    int test5[] = {64, 34, 25, 12, 22, 11, 90};
    quickSort(test5, 0, n-1);
    cout << "Quick Sort: "; printArray(test5, n);
    
    return 0;
}

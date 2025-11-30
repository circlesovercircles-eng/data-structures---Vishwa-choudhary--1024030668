#include <iostream>
#include <unordered_map>
using namespace std;

int firstNonRepeating(int arr[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == 1) return arr[i];
    }
    return -1;
}

int main() {
    int nums[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(nums)/sizeof(nums[0]);
    
    cout << "Input: [4, 5, 1, 2, 0, 4]" << endl;
    int result = firstNonRepeating(nums, n);
    cout << "Output: " << result << endl;
    return 0;
}

#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(int arr[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.count(arr[i])) return true;
        seen.insert(arr[i]);
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums)/sizeof(nums[0]);
    
    cout << "Input: [1, 2, 3, 1]" << endl;
    cout << "Output: " << (containsDuplicate(nums, n) ? "true" : "false") << endl;
    return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

void countFrequency(int arr[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    cout << "Frequency:\n";
    for (auto& p : freq) {
        cout << "• " << p.first << " → " << p.second << " times" << endl;
    }
}

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = sizeof(nums)/sizeof(nums[0]);
    
    cout << "Input: [2, 3, 2, 4, 3, 2]" << endl;
    countFrequency(nums, n);
    return 0;
}

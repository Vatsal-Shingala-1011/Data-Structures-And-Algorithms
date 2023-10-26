#include <iostream>

using namespace std; 

// Function to find the smallest missing positive integer in an array
int firstMissingPositive(int nums[], int n) {
    // Rearrange elements to their correct positions
    for (int i = 0; i < n; ++i) {
        while (1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Find the first index where nums[i] != i + 1
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1; // Smallest missing positive integer
        }
    }

    return n + 1;// If all positive integers are present, return n + 1
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int nums[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = firstMissingPositive(nums, n);
    cout << "Smallest missing positive integer: " << result << endl;

    return 0;
}

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/
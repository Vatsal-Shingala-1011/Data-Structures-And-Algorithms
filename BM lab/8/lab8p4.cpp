#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySum(const vector<int>& nums) {
    int maxSoFar = 0, maxEndingHere = 0;

    for (int num : nums) {
        maxEndingHere = maxEndingHere + num;
        if (maxEndingHere < 0) maxEndingHere = 0;//if negative then start with zero
        if (maxSoFar < maxEndingHere) maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}

int main() {
    int n;
    cout << "Enter the number of elements ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = maxSubArraySum(nums);
    cout << "The maximum subarray sum is " << result << endl;

    return 0;
}
/*
Time & Space Complexity: O(n)
*/
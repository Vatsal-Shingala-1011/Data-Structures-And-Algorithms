#include <iostream>
using namespace std;

class Solution {
public:
  int** subsets(int* nums, int n) {
    int** subsets = new int*[1 << n];
    for (int i = 0; i < (1 << n); i++) {
      subsets[i] = new int[n];
      int subset_size = 0;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          subsets[i][subset_size++] = nums[j];
        }
      }
      subsets[i][subset_size] = -1;
    }
    return subsets;
  }
};

int main() {
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  int* nums = new int[n];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution s;
  int** subsets = s.subsets(nums, n);

  for (int i = 0; i < (1 << n); i++) {
    int* subset = subsets[i];
    while (*subset != -1) {
      cout << *subset++ << ' ';
    }
    cout << endl;
  }

  delete[] subsets;
  delete[] nums;

  return 0;
}

/*
Time complexity:
subsets(): O(2^n), where n is the size of the input array.

Space complexity:
subsets(): O(n*2^n) + O(n), where the first term is the space required to store the recursive stack and the second term is the space required to store the array of subsets.

*/
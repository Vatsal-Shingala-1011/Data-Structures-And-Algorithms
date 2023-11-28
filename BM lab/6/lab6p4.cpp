#include <iostream>
using namespace std;

bool isPalindrome(string s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

void backtrack(string** partitions, string& s, int idx, string* curr) {
  if (idx == s.size()) {
    for (int i = 0; i < s.size(); i++) {
      cout << curr[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = idx; i < s.size(); i++) {
    if (isPalindrome(s.substr(idx, i - idx + 1))) {
      curr[idx] = s.substr(idx, i - idx + 1);
      backtrack(partitions, s, i + 1, curr);
      curr[idx] = "";
    }
  }
}

string** partition(string s) {
  int n = s.size();
  string** partitions = new string*[n];

  string* curr = new string[n];
  for (int i = 0; i < n; i++) {
    curr[i] = "";
  }

  backtrack(partitions, s, 0, curr);

  delete[] curr;
  return partitions;
}

int main() {
  string s;
  cout << "Enter a string: ";
  cin >> s;

  string** partitions = partition(s);
  delete[] partitions;
  return 0;
}
/*
Time complexity:
isPalindrome(): O(n) where n is the length of the string s.
backtrack(): O(2^n)
partition(): O(2^n)

Space complexity:
isPalindrome(): O(1)
backtrack(): O(n)
partition(): O(n)
*/

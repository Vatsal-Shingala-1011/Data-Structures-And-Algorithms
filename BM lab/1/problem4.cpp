#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int store[n]; // Store the next greater elements
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if(!s.empty()){
        while (arr[s.top()] < arr[i]) {
            store[s.top()] = arr[i];
            s.pop();
            if(s.empty())
            break; 
        }
        }
        s.push(i);
    }

    // Elements in the stack at this point have no greater element to their right.
    while (!s.empty()) {
        store[s.top()] = -1; // Set them to -1.
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << store[i] << " ";
    }

    return 0;
}

/*
Time Complexity O(n) :
all three loop runs ones 

2) Space Complexity O(n)
all three array has space n

*/
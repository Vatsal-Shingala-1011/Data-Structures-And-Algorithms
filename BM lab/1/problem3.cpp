#include <iostream>
#include <stack>
using namespace std;

bool check(string str) {
    stack<char> s;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (s.empty()) {
                return false; // closing bracket but there is no open bracket exist.
            }
            char top = s.top();
            s.pop();
            if ((str[i] == ')' && top != '(') || (str[i] == ']' && top != '[') || (str[i] == '}' && top != '{')) {
                return false; // brackets 
            }
        }
        else {
            return false;
        }
    }

    return s.empty(); // If brackets are balanced.
}

int main() {
    string s;
    cin >> s;
    if (check(s)) {
        cout << "string: " << s <<" is beautiful" << endl;
    } else {
        cout << "string: " << s <<" is not beautiful" << endl;
    }
    return 0;
}

/*
Time complextity = O(len of str)
push & pop, isempty :O(1) time complexity
loop is runing n time so overall time complexity is O(n)

Space Complexity = O(n) n = length of string

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<char> s;
    string str;
    cin >> str;
    int len = str.size();
    if (len == 0) {
        cout << "string is empty" << endl;
        return 0;
    }

    s.push(str[0]);
    char ch = str[0];
    for (int i = 1; i < len; i++) {
        if (!s.empty() && str[i] == s.top()) {
            ch = str[i];
            s.pop();
        } else if (str[i] != ch) {
            s.push(str[i]);
            ch = '1'; // put ch=1
        }
    }
    string ans = "";//empty string
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end()); //reverse the string
    if(ans.empty()){
        cout<<"string is empty "<<endl;
    }
    else{
        cout<<ans <<endl;
    }
    return 0;
}

/*
Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <iostream>
#include <queue>
using namespace std;

class stack_using_queues {

private:
    queue<int> q1; 
    queue<int> q2; 
public:
    
    void push(int val) {// Push val in stack
        while (!q1.empty()) {// shifting all eles q1 to q2
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);//pushing val

        while (!q2.empty()) { //moving back
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() { //pop the element
        if (empty()) {
            cout << "Empty stack" << endl;
            return -1; 
        }
        int top = q1.front();
        q1.pop();
        return top;
    }
    bool empty() {
        return q1.empty();
    }
};

int main() {
    stack_using_queues s;
    s.push(3);
    s.push(9);
    s.push(1);
    cout << s.pop() << endl; // return 1
    cout << s.pop() << endl; //return 9

    s.push(7);
    cout << s.pop() << endl; //  return 7
    cout << s.pop() << endl; // return 3
    cout << s.pop() << endl; 
    return 0;
}

/*

push
Time Complexity: O(N)
Space Complexity: O(1)

pop:
Time Complexity: O(1)
Space Complexity: O(1)

empty:
Time Complexity: O(1)
Space Complexity: O(1)

*/
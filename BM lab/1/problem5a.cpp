#include <iostream>
#include <stack>

using namespace std;

class queue_using_stacks {
private:
    stack<int> s1; //use for push
    stack<int> s2;  //use for front

public:
    void push(int ele) { //pushing ele in queue
        s1.push(ele);
    }
    int front(){ // front an ele from the queue
        if (s2.empty()) {
            // in case of empty stack2 , move elements from stack1 to stack2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            // in case both stacks are empty, the queue is empty
            cout << "Empty queue" << endl;
            return -1; 
        }

        int front = s2.top();
        s2.pop();
        return front;
    }
};

int main() {
    queue_using_stacks q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl; // return 1
    cout << q.front() << endl; // return 2

    q.push(4);
    cout << q.front() << endl; // return 3
    cout << q.front() << endl; // return 4

    cout << q.front() << endl; 

    return 0;
}

/*

for push operation
Time Complexity: O(1)
Space Complexity: O(1)

for front 
Time Complexity: O(N)
Space Complexity: O(N)

*/

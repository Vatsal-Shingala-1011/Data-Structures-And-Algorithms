#include <iostream>
using namespace std;

class Stack {
    public:
        int size;
        int *arr;
        int top;
        
    Stack(int size) {
        top = -1;
        arr = new int[size];
        this->size = size;
    }

    void push(int val) {//push value into stack
        if (size - top > 1) {
            arr[++top] = val;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    int top_element() {//give top element from stack
        if (top >= 0 && top < size) return arr[top];
        else if (top < 0) {
            cout << "Stack Underflow, Return -1" << endl;
            return -1;
        } else {
            cout << "Stack overflow, Return INT_MAX" << endl;
            return INT_MAX;
        }
    }

    int peek() { //give top element from stack
        if (top >= 0 && top < size) {
            return arr[top];
        } else if (top < 0) {
            cout << "Stack Underflow,Return -1" << endl;
            return -1;
        } else {
            cout << "Stack overflow, Return INT_MAX" << endl;
            return INT_MAX;
        }
    }

    void pop() { //remove top elemet from stack
        if (top >= 0) top--;
        else {
            cout << "Stack Underflow" << endl;
        }
    }

    int stack_size() {//return size of stack
        if (top >= 0 && top < size) {
            return top + 1;
        } else if (top >= size) {
            cout << "stack is full" << endl;
            return size;
        } else {
            return 0;
        }
    }

    bool isEmpty() { //return -1 if stack is empty
        return top == -1;
    }
    
};

int main() {
    Stack st(9);  //initialize stack of size 9
    st.push(7);
    st.push(3);
    st.push(9);

    cout << "top Element : " << st.top_element() << endl;
    cout << "Peek Element : " << st.peek() << endl;
    if (st.isEmpty()) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Stack not Empty" << endl;
    }

    st.pop();
    cout << "top Element element : " << st.top_element() << endl;
    cout << "stack size : " << st.stack_size() << endl;
    return 0;
}

/* 
Time and space complexity 

stack 
time complexity O(1)
space complexity O(size) 

-> top() ,push() ,peek() ,isEmty() , pop() , size() : time complexity O(1) ,space complexity O(1) 

*/


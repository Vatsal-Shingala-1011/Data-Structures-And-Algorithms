#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public:
    int first = 0;
    int rear = 0;
    int size = 0;
    int *arr;
    Queue(int val){
        arr = new int(val+1);
        size = val+1;
    }
    void push(int val){
        if((rear+1)%size!=first){
            arr[rear] = val;
            rear = (rear+1)%size;
        }
        else{
            cout<<"queue overflow" <<endl;
        }
        return;
    }
    int front(){
        if(first!= rear){
            return arr[first];
        }
        cout<<"queue if empty"<<endl;
        return -1;
    }
    void emplace(int val){
        if((rear+1)%size!=first){
            arr[rear] = val;
            rear = (rear+1)%size;
        }
        else{
            cout<<"queue overflow"<<endl;
        }
        return;
    }
    bool isEmpty()
    {
        if(first == rear){
            return true;
        }
        return false;
    }
    void pop(){
        if(first!=rear){
            first++;
        }
    }
    int Size(){
        return abs(rear-first);
    }
};

int main() {
    Queue q(100);
    

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "front element of queue: " << q.front() << endl; //pop 1
    cout << "size of queue: " << q.Size() << endl;   //size 3

    q.pop();
    cout << "front after pop: " << q.front() << endl; // Front after pop: 2

    q.emplace(4);
    cout << "Size after emplace: " << q.Size() << endl; // Size after emplace: 3

    while (!q.isEmpty()) {
        q.pop();
    }
    cout << "queue empty or not : " << q.isEmpty() << endl; // empty return 1 

    return 0;
}

/*

Queue:
Time Complexity: O(1)
Space Complexity: O(N)

push,front,emplace,isempty,pop,size:
Time Complexity: O(1)
Space Complexity: O(1)

*/
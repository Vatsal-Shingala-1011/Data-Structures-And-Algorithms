#include <iostream>
using namespace std;
#include<queue>


int main()  //100% done
{
    //max heap
    priority_queue<int> pq;  
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<< pq.top();
    pq.pop();
    cout<< pq.top();

    //minheap
    priority_queue<int,vector<int>,greater<int>> minheap;

    return 0;
}

// What does it mean when a cout is ambiguous?
// Ambiguity means there are multiple references to the same keyword: either two libraries have been included that have a cout fuction, or sometimes something gets messy in temporary compiled files. If you think your includes are okay, then cleaning your project or restarting might help.
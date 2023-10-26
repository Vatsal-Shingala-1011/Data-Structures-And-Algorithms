#include <iostream>
using namespace std;

class Heap {
private:
    int* heap; 
    int capacity; // capacity of heap
    int size; ///denote size of heap
    bool isMaxHeap;//heap is maxheap or minheap

public:
    Heap(int capacity, bool isMaxHeap = true) { //by default maxheap
        this->capacity = capacity;
        this->isMaxHeap = isMaxHeap;
        heap = new int[capacity];
        size = 0;
    }

    ~Heap() {
        delete[] heap;
    }


   // Function to heapify the array
    void heapify(int idx) {
        int left = 2 * idx + 1;//left index
        int right = 2 * idx + 2;//right index 
        int largest = idx;
        if (isMaxHeap) { //if maxheap
            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;
        } else { //if minheap then
            if (left < size && heap[left] < heap[largest])
                largest = left;
            if (right < size && heap[right] < heap[largest])
                largest = right;
        }
        if (largest != idx) {
            swap(heap[idx], heap[largest]);
            heapify(largest);
        }
    }

    // Function to insert a value into the heap
    void insert(int value) {
        if (size == capacity) {//when size is full
            cout << "Heap is full." << endl;
            return;
        }
        int idx = size;
        heap[idx] = value; //insert at last and then we move it to its correct posstion
        size++;
        int parent;
        if (isMaxHeap) {//if heap is maxheap
            while (idx > 0) {
                parent = (idx - 1) / 2;
                if (heap[idx] > heap[parent]) {
                    swap(heap[idx], heap[parent]);
                    idx = parent;
                } else {
                    break;
                }
            }
        } else { //if heap is minheap
            while (idx > 0) {
                parent = (idx - 1) / 2;
                if (heap[idx] < heap[parent]) {
                    swap(heap[idx], heap[parent]);
                    idx = parent;
                } else {
                    break;
                }
            }
        }
    }

    // Function to delete the root element
    void deleteRoot() { 
        if (size == 0) {//if heap is empty 
            cout << "Heap is empty." << endl;
            return;
        }
        size--;
        heap[0] = heap[size]; //move last element to root  then 
        heapify(0);//move that last element to root possition to its correct possition
    }

    // Function to get the maximum or minimum element
    int getTop() {
        if (size == 0) { //if heap is empty no top element
            cout << "Heap is empty." << endl;
            return -1;
        }
        return heap[0]; //return top element
    }

    int getHeapElement(int index) {
        if (index >= 0 && index < size) {
            return heap[index];
        }
        return -1; // Invalid index
    }

    int getHeapSize() {
        return size;
    }
};


int main() {
    int capacity;
    cout << "Enter the capacity of the heap: ";
    cin >> capacity;

    int choice;
    bool isMaxHeap = true; // Default to a max heap

    cout << "Choose the type of heap (1 for Max Heap, 2 for Min Heap): ";
    cin >> choice;

    if (choice == 2) {
        isMaxHeap = false;
    }

    Heap minHeap(capacity, false);//making min and max heap
    Heap maxHeap(capacity, true);

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    // Insert the first `k` elements into both the min and max heaps.    
    for(int i=0;i<k;i++){
        minHeap.insert(arr[i]);
        maxHeap.insert(arr[i]);
    }

    for(int i=k;i<n;i++)
        {
            // If the current element is greater than the smallest element in the min heap,
            // remove the smallest element and insert the current element.
            if(arr[i]>minHeap.getTop()){
            minHeap.deleteRoot();
            minHeap.insert(arr[i]);
            }
            // If the current element is smaller than the largest element in the max heap,
            // remove the largest element and insert the current element.
            if(arr[i]<maxHeap.getTop()){
            maxHeap.deleteRoot();
            maxHeap.insert(arr[i]);
            }
        }

    if (k > 0 && k <= n) {//if k is out of range
        int kthSmallest = maxHeap.getTop();// kth smallest element
        int kthLargest =minHeap.getTop();//k th largest elelmt
        cout << "Kth Smallest: " << kthSmallest << endl;
        cout << "Kth Largest: " << kthLargest << endl;
    } else {
        cout << "Invalid value of k." << endl;
    }

    return 0;
}


/*

heapify():
Time Complexity: O(log n)
Space Complexity: O(1)

insert():
Time Complexity: O(log n)
Space Complexity: O(1)

deleteRoot():
Time Complexity: O(log n)
Space Complexity: O(1)

getTop():
Time Complexity: O(1)
Space Complexity: O(1)

getHeapSize():
Time Complexity: O(1)
Space Complexity: O(1)

getHeapElement(int index):
Time Complexity: O(1)
Space Complexity: O(1)

findKthSmallest:
Time Complexity: O(n * log k)
Space Complexity: O(k) //to store k elemnt in heap

findKthLargest:
Time Complexity: O(n * log k)
Space Complexity: O(k) //store k element in heap

*/
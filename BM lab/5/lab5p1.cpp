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

    Heap heap(capacity, isMaxHeap);

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Get Max_element / Min_element" << endl;
        cout << "3. Delete root" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                break;

            case 2:
                if (isMaxHeap) {
                    cout << "Max Element: " << heap.getHeapElement(0) << endl;
                } else {
                    cout << "Min Element: " << heap.getHeapElement(0) << endl;
                }
                break;

            case 3:
                heap.deleteRoot();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Current Heap:";
        int size = heap.getHeapSize();
        for (int i = 0; i < size; i++) {
            cout << " " << heap.getHeapElement(i);
        }
        cout << endl;
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


*/
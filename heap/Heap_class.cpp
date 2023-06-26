#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;  //starting from 1 index
        size = 0;
    }
    void insert(int val)
    {
        int index = size;
        arr[index] = val;
        size++;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
                ;
            }
        }
    }

    // root node always
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "empty heap";
            return;
        }
        arr[1] = arr[size];
        size--;
        // take root node to correct position
        int i = 1;
        while (i < size)
        {
            int l = i * 2;
            int r = l + 1;
            if (l < size && arr[i] < arr[l])
            {
                swap(arr[i], arr[l]);
                i = l;
            }
            else if (r < size && arr[i] < arr[r])
            {
                swap(arr[i], arr[r]);
                i = r;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// heapify convert that index to all part below it into heap
void heapify(int arr[], int n, int i) //max heapify
{                            //index which we want to shift to it's correct position
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && arr[largest < arr[left]])
    {
        largest = left;
    }
    if (right < n && arr[largest < arr[right]])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}



void heapsort(int arr[], int n)
{   //build max heap
    for(int i=n/2;i>=1;i--) 
    {
        heapify(arr,n,i);
    }
    //remove top element every time and put it at last index of currunt heap
    // int size=n;
    for(int i=n;i>=1;i--)
    {   swap(arr[1],arr[i]);
        heapify(arr,n,1);
    }
}

int main()  //100% done
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    // h.print();
    // h.deleteRoot();
    // h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    heapsort(arr,n);
    cout << "printing array ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
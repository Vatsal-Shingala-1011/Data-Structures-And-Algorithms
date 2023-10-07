#include <iostream>
using namespace std;


void bubble(int *a, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int a[8],int n){
    for (int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void selection_sort(int a[8], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = a[i];
        int j = i + 1;
        int index = i;
        while (j < n)
        {
            if (a[j] <= min)
            {
                min = a[j];
                index = j;
            }
            j++;
        }
        swap(a[index], a[i]);
    }
}


//Merge sort

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1; // size of the left subarray
    int n2 = right - middle;    // size of the right subarray

    int L[n1], R[n2]; // temporary arrays for the two subarrays

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[middle + 1 + i];
    }

    // Merge the two subarrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// function to perform merge sort on arr[]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2; // Calculate middle index

        // Recursively sort the left and right subarrays
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted subarrays
        merge(arr, left, middle, right);
    }
}


// Quick sort
int partition_index(int a[], int low, int high) {
    int pivot = a[low]; // Choose the first element as the pivot
    int i = low + 1;
    int j = high;
    while (true) {
        // Move the 'i' pointer to the right until we find an element greater than the pivot
        while (i <= j && a[i] <= pivot) {
            i++;
        }
        // Move the 'j' pointer to the left until we find an element less than or equal to the pivot
        while (a[j] > pivot) {
            j--;
        }
        if (i < j) {
            // Swap a[i] and a[j] if 'i' is less than 'j'
            swap(a[i], a[j]);
        } else {
            // Break the loop when 'i' is greater than or equal to 'j'
            break;
        }
    }
    // Swap the pivot element with a[j] to place the pivot in its correct position
    swap(a[low], a[j]);

    return j; // Return the index of the pivot element
}

// Function to perform Quick Sort
void quick_sort(int a[], int low, int high) {
    if (low < high) {
        // Find the partition index (pivot)
        int index = partition_index(a, low, high);
        //sort the elements before and after the pivot
        quick_sort(a, low, index - 1);  // Sort elements before the pivot
        quick_sort(a, index + 1, high); // Sort elements after the pivot
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int choice;
    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubble(a, n);
            break;
        case 2:
            insertion_sort(a, n);
            break;
        case 3:
            selection_sort(a, n);
            break;
        case 4:
            mergeSort(a, 0, n - 1);
            break;
        case 5:
            quick_sort(a, 0, n - 1);
            break;
        default:
            cout << "Invalid choice" << endl;
            return 1;
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}

/*

bubble sort = Time Complexity: O(n^2)
             Space Complexity: O(1) 

Insertion Sort = Time Complexity: O(n^2)
             Space Complexity: O(1) 

Selection Sort = Time Complexity: O(n^2)
            Space Complexity: O(1) 

merge Sort = Time Complexity: O(n log n)
             Space Complexity: O(n) 

quick Sort = Time Complexity: O(n^2)
             Space Complexity: O(n) 


*/
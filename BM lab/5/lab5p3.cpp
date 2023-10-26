#include <iostream>
using namespace std; 

struct node {
    int data;
    struct node* next;// Point to next node pointer
    struct node* prev;// Point to prev node pointer
};

// Function to get the length of the linked list
int get_length(node* head) {
    int length = 0;
    node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void add_at_end(node* &head, int val) { //add element val at end of linked list
    node* new_node = new node;
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// struct to represent a linked list
struct LinkedList {
    node* head;
    node* tail;
};

void mergeKSortedArrays(LinkedList* arrays, int k) {
    // Create an array to store the current position in each linked list
    int* indices = new int[k];
    for (int i = 0; i < k; i++) {
        indices[i] = 0;
    }

    node* result_head = NULL;

    while (true) {
        int smallest = INT_MAX;
        int smallest_idx = -1;
        bool all_empty = true;

        // Find the smallest element across all linked lists
        for (int i = 0; i < k; i++) {
            if (arrays[i].head != NULL) {
                all_empty = false;
                if (arrays[i].head->data < smallest) {
                    smallest = arrays[i].head->data;
                    smallest_idx = i;
                }
            }
        }

        // If all lists are empty, break out of the loop
        if (all_empty) {
            break;
        }
        // Add the smallest element to the merged list
        add_at_end(result_head, smallest);
        // Move to the next element in the linked list
        arrays[smallest_idx].head = arrays[smallest_idx].head->next;
    }

    // Output the merged linked list
    cout << "Merged Linked List: ";
    node* temp = result_head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int k;
    cout <<"Enter the value of k: ";
    cin >> k;

    LinkedList* arrays = new LinkedList[k];

    for (int i = 0; i < k; i++) {
        arrays[i].head = NULL;
        arrays[i].tail = NULL;
    }

    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter the number of elements for linked list " << i+1<< ": ";
        cin >> n;

        cout << "Enter " << n<< " elements for linked list " <<i+1<<": ";
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            add_at_end(arrays[i].head, val);
        }
    }

    mergeKSortedArrays(arrays, k);

    return 0;
}

/*
N=total number of element across all liked list
get_length():
Time Complexity: O(N)
Space Complexity: O(1)

add_at_end():
Time Complexity: O(N)
Space Complexity: O(1)

mergeKSortedArrays() :
Time Complexity: O(N * k),k is the number of linked lists 
Space Complexity: O(N)
*/

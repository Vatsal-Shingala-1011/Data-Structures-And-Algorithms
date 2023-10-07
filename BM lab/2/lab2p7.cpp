#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;
};

// Function to insert a new node at the end of the linked list
void add_to_list(Node* &head, int data) {   
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to swap the data of two nodes
void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// // Function to perform bubble sort on the linked list
// void bubbleSort(Node* head) {
//     if (head == NULL || head->next == NULL) return; //if List is empty
//     bool swapped;
//     Node* current;
//     Node* lastSorted = NULL;

//     do {
//         swapped = false;
//         current = head;

//         while (current->next != lastSorted) {
//             if (current->data > current->next->data) {
//                 swapData(current, current->next);
//                 swapped = true;
//             }
//             current = current->next;
//         }
//         lastSorted = current;
//     } while (swapped);
// }

Node* midNode(Node* root) { //find mid node in liked list
    Node* slow = root; //move one step at each time
    Node* fast = root->next; //move two step at each time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    Node* ans = new Node;
    Node* temp = ans;  // pointer to the current node in the merged list
    while (left != NULL && right != NULL) {// merge the two sorted lists while maintaining the sorted order
        if (left->data < right->data) {
            temp->next = left;
            left = left->next;
        }
        else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    while (left != NULL) {// Handle any remaining elements in the left and right lists
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }
    while (right != NULL) {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }
    return ans->next; // Return the merged sorted list
}

Node* merge_sort(Node* head) { // Function to perform merge sort on a linked list
    if (head == NULL || head->next == NULL) return head; //If the list is empty
    Node* mid = midNode(head);//Find the middle node of the list

    // Split the list into two halves
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL; // Disconnect the two halves

    // Recursively sort and merge the two halves
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);// Merge the sorted halves and return the result

}

 
// Function to remove duplicate elements from the sorted linked list
void removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) return; // List is empty 

    Node* current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

//Traversing a linked list
void display(struct Node* head) {
    struct Node* temp  = head ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice;
    
    do {
        int data;
        cout << "Enter an integer: ";
        cin >> data;
        add_to_list(head, data);

        cout << "Do you want to enter another integer? (1 for yes, 0 for no): ";
        cin >> choice;
    } while (choice == 1);

    cout <<endl;
    cout << "Original linked list: ";
    display(head);

    merge_sort(head);
    removeDuplicates(head);
    cout <<endl;
    cout << "Linked list after sorting and removing duplicates: "<<endl;;
    display(head);

    return 0;
}


/*  n=length of linked list


add_to_list :time complexity = O(n)
                space complexity =O(1)  

swapData      :time complexity = O(1)
                space complexity = O(1)

midNode  :time complexity = O(n)
                space complexity = O(1)

merge  = Time Complexity: O(n)
             Space Complexity: O(1) 

merge Sort = Time Complexity: O(n log n)
             Space Complexity: O(log n) 

removeDuplicates :time complexity = O(n)
                   space complexity = O(!)     

display  : time complexity = O(n)
                space complexity = O(1)  

*/
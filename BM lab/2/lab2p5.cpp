#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

// reverse a doubly linked list
void reverse_doubly_linked_list(struct node*& head) {
    struct node* current = head;
    struct node* temp = NULL;
    
    while (current != NULL) { // swap the next and prev pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;
    }
    
    // Update the head pointer to the new head
    if (temp != NULL) {
        head = temp->prev;
    }
}

// Function to display a doubly linked list from head
void display_from_head(struct node* head) {
    struct node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void add_to_list(struct node* & head, char val) { //add node at last index
    struct node* new_node = new struct node;
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

int main() {
    struct node* head = NULL;
    int choice;

    int t;
    cout<<"Enter total element integers in doubly linked list: ";
    cin>>t;
    while(t--){
        int data;
        cout << "Enter your data : ";
        cin >> data;
        add_to_list(head, data);
    }
    cout<<endl;
    cout << "given Linked list: ";
    display_from_head(head);

    reverse_doubly_linked_list(head);

    cout<<endl;
    cout << "Reversed Linked list: ";
    display_from_head(head);
    cout<<endl;


    return 0;
}

/*  n=length of linked list

reverse_doubly_linked_list  :   time complexity = O(n)
                space complexity = 1

display_from_head:time complexity = O(n)
                space complexity = 1       

add_to_list: time complexity = O(n)
                space complexity = 1


*/
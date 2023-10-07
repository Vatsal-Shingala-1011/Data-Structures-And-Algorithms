#include<iostream>
using namespace std;

struct node
{
    char data;          // Character value for node 
    struct node* next; // Point to next node pointer
    struct node* prev; // Point to prev node pointer
};

// Function to get the length of the linked list
int get_length(struct node* head) {
    int length = 0;
    struct node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Get a pointer to the tail (last node) of the linked list
struct node* Tail(struct node*& head){ 
    struct node* temp = head;
    if(temp==NULL) return NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}

bool isPalindrome(struct node* head) {
    int length = get_length(head);
    
    if (length <= 1) return true; // A list with 0 or 1 elements is always palindrome
    
    struct node* front = head;
    struct node* back = Tail(head);
    
    for (int i = 0; i < length / 2; i++) {
        if (front->data != back->data) {
            return false; // If the values at corresponding positions don't match, it's not a palindrome
        }
        front = front->next;
        back = back->prev;
    }
    
    return true;
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

void add_values_from_user(struct node* & head) {
    char choice;
    do {
        char val;
        cout << "Enter a character: ";
        cin >> val;
        
        add_to_list(head, val);

        cout << "Do you want to enter another character? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

// Traversing a linked list from head to tail
void display_from_head(struct node* head) {
    struct node* temp  = head ;
    while(temp != NULL) {  
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

// Traversing a linked list from tail to head
void display_from_tail(struct node* tail) {
    struct node* temp  = tail ;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> prev;
    }
    cout << endl;
}

int main()
{
   struct node* head = NULL;

    // take characters from the user
    add_values_from_user(head);
    cout << endl;

    display_from_head(head);//print the given input 

    if (isPalindrome(head)) {//check input is Palindrome or not
        cout << "True." << endl;
    } else {
        cout << "False" << endl;
    }
    cout << endl;

    return 0;
}

/*  n=length of linked list

get_length  :   time complexity = O(n)
                space complexity = 1

Tail        :   time complexity = O(n)
                space complexity = 1

isPalindrome:   time complexity = O(n)
                space complexity = 1

add_to_list:   time complexity = O(n)
                space complexity = 1

add_values_from_user:time complexity = O(n)
                space complexity = 1

display_from_head:time complexity = O(n)
                space complexity = 1       

display_from_tail: time complexity = O(n)
                space complexity = 1

*/
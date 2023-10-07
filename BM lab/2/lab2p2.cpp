#include<iostream>
using namespace std;

struct node
{
    int data;          //value for node 
    struct node* next; //point to next node pointer
    struct node* prev; //point to prev node pointer
};

int get_length(struct node* head) { //give length of liked list
    int length = 0;
    struct node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void add_at_index(struct node* & head, int index, int val) {// add element at given index
    struct node* x = new struct node;
    x->data = val;
    x->next = NULL;
    x->prev = NULL;

    if (index == 0) {
        x->next = head;
        x->prev = NULL; // set the previous pointer of the new node to NULL
        if (head != NULL) {
            head->prev = x; // Update the previous pointer of the current head
        }
        head = x; // Update the head pointer in the calling function
        return;
    }
    
    if (index < 0 || index > get_length(head)) { // Check if index is out of bounds
        cout << "Index is out of bounds. Not possible to add at that index." << endl;
        delete x; // Free the allocated memory
        return;
    }

    struct node* prev = head;
    while (index > 1 && prev != NULL) {
        prev = prev->next;
        index--;
    }

    if (prev == NULL) {
        // Index is out of bounds
        delete x; // Free the allocated memory
        return;
    }

    x->next = prev->next;
    x->prev = prev;
    if (prev->next != NULL) {
        prev->next->prev = x; // Update the previous pointer of the node after 'prev'
    }
    prev->next = x;
}


//traversing a linked list
void display_from_head(struct node* head) {
    struct node* temp  = head ;

    while(temp != NULL) {  //traverse linkes list till end
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}
void display_from_tail(struct node* tail) {
    struct node* temp  = tail ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> prev;
    }
    cout << endl;
}

void deletion(struct node*& head,int index){//delete element at given index
    if(head==NULL) return; // Check if the list is empty
    if(index==0) { // Check if we need to delete the first node (index 0)
        head=head->next; // Update the head to the next node
        head->prev=NULL; // Update the previous pointer of the new head to NULL
        return;
    }
    struct node* temp=head;
    while(--index){// Traverse the list to find the node at the specified index
        // cout<<index<<endl;
        temp=temp->next;
        if(temp==NULL){ //if index is greater than length of list 
            cout<<"index is greater than total length of list"<<endl;
            return;
        }
    }
    if(temp->next==NULL){ // Check if the next node exists (not the last node)
        cout<<"index is greater than total length of list"<<endl;
        return;
    }
    cout<<"temp data "<<temp->data<<endl;

    // Update the next pointer of the current node to skip the node to be deleted
    temp->next=temp->next->next;

    // Update the previous pointer of the new next node, if it exists
    if(temp->next!=NULL){
        temp->next->prev=temp;
    }
}

void search(struct node*& head,int val){ // Search for a specific element 'val' in the linked list
    struct node* temp = head;
    int index=0;
    while(1){
        if(temp==NULL){
            cout<<"element is not found"<<endl;
            return;
        }
        if(temp->data==val){
            cout<<"element " <<val<< " is found at index "<<index<<endl;
            return;
        }
        temp=temp->next;
        index++;
    }
}

// Get a pointer to the head of the linked list
struct node* Head(struct node*& head){ 
    return head;
}

// Get a pointer to the tail (last node) of the linked list
struct node* Tail(struct node*& head){ 
    struct node* temp = head;
    if(temp==NULL){
        return NULL;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}


int main() {
    struct node* head = NULL;
    int choice = 0;
    cout << "Enter the choice" << endl;
    cout << "1). Insert" << endl;
    cout << "2). Delete" << endl;
    cout << "3). Search" << endl;
    cout << "4). Display from head" << endl;
    cout << "5). Display from tail" << endl; 
    cout<<">=6). Exit"<<endl;

    cout<< endl;

    int value, index;

    while (choice < 6) { 
        cout << "Enter the choice" << endl;
        cin >> choice;
        cout<< endl;
        switch (choice) {
            case 1:
                cout << "Insertion" << endl;
                cout << "Enter value and index" << endl;
                cin >> value >> index;
                add_at_index(head, index, value);
                break;
            case 2:
                cout << "Deletion" << endl;
                cout << "Enter index" << endl;
                cin >> index;
                deletion(head, index);
                break;
            case 3:
                cout << "Search" << endl;
                cout << "Enter value" << endl;
                cin >> value;
                search(head, value);
                break;
            case 4:
                cout << "Display from head" << endl;
                display_from_head(head);
                break;
            case 5:
                cout << "Display from tail" << endl;
                struct node* tail = Tail(head);
                display_from_tail(tail);
                break;
        }
    }

    return 0;
}



/*  n=length of linked list

get_length  :   time complexity = O(n)
                space complexity = 1

add_at_index: time complexity = O(n)
                space complexity = 1

deletion: time complexity = O(n)
                space complexity = 1

search: time complexity = O(n)
                space complexity = 1

head : time complexity = O(1)
                space complexity = 1

Tail        :   time complexity = O(n)
                space complexity = 1

display_from_head:time complexity = O(n)
                space complexity = 1       

display_from_tail: time complexity = O(n)
                space complexity = 1   

*/
#include<iostream>
using namespace std;

struct node
{
    int data;          //value for node 
    struct node* next; //point to next node pointer
};

int get_length(struct node* head) {  //give length of liked list
    int length = 0;
    struct node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void add_at_index(struct node* & head, int index, int val) { // add element at given index
    struct node* x = new struct node;
    x->data = val;
    x->next = NULL;

    if (index == 0) {
        x->next = head;
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
    prev->next = x;
}

//Traversing a linked list
void display(struct node* head) {
    struct node* temp  = head ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

void deletion(struct node*& head,int index){ //delete element at given index
    if(head==NULL) return;  // Check if the list is empty
    if(index==0) {  // Check if we need to delete the first node (index 0)
        head=head->next;  // Update the head to the next node
        return;
    }
    struct node* temp=head;

    while(--index){// Traverse the list to find the node just before the one to be deleted
        temp=temp->next;
        if(temp->next==NULL){ //if index is greater than length of list 
            cout<<"index is greater than total length of list can not delete the elemet at index"<<endl;
            return;
        }
    }
    temp->next=temp->next->next; // Update the next pointer of the current node to skip the node to be deleted
}

void search(struct node*& head,int val){ //search for val
    struct node* temp = head;
    int index=0,cnt=0; //cnt=at howmany index val is found
    while(1){
        if(temp==NULL){
            if(cnt==0){
            cout<<"element is not found"<<endl;
            }
            return;
        }
        if(temp->data==val){
            cnt++;
            cout<<"element " <<val<< " is found at index "<<index<<endl;
        }
        temp=temp->next;
        index++;
    }
}

// Get a pointer to the head of the linked list
struct node* Head(struct node*& head){
    return head;
}

int main()
{
    struct node* head=NULL;
    int choice=0;
    cout<<"Enter the choice"<<endl;
    cout<<"1). insert"<<endl;
    cout<<"2). delete"<<endl;
    cout<<"3). search"<<endl;
    cout<<"4). display"<<endl;
    cout<<">=5). Exit"<<endl;

    int value,index;

    while(choice<5){

        cout<<"Enter the choice"<<endl;
        cin>>choice;
        cout<<endl;
        
        switch(choice){
            case 1:
                cout<<"insertion "<<endl;
                cout<<"Enter value and index"<<endl;
                cin>>value>>index;
                add_at_index(head,index,value);
                cout<<endl;
                break;
            case 2:
                cout<<"deletion "<<endl;
                cout<<"Enter index"<<endl;
                cin>>index;
                deletion(head,index);
                break;
            case 3:
                cout<<"search "<<endl;
                cout<<"Enter value"<<endl;
                cin>>value;
                search(head,value);
                cout<<endl;
                break;
            case 4:
                cout<<"display "<<endl;
                display(head);
                cout<<endl;
                break;
            default:
                cout<<"Invalid choice.  Exit..." <<endl<<endl;
        }

    }

    // // add_at_index(head,0,3); //insert element at 0th index
    // // add_at_index(head,0,9); //insert element at 0th index
    // // add_at_index(head,0,8); //insert element at 0th index
    // // add_at_index(head,0,7); //insert element at 0th index
    // // add_at_index(head,0,9); //insert element at 0th index

    // display(head);//print all element in list

    // // add_at_index(head,1,1000); //insert at 5th index
    // // display(head);


    // // add_at_index(head,4,99);
    // // display(head);

    // deletion(head,5);
    // display(head);

    // // search(head,9); //seaech element 9 in list
    return 0;
}


/*  n=length of linked list

get_length  :   time complexity = O(n)
                space complexity = 1

add_at_index: time complexity = O(n)
                space complexity = 1

display     :time complexity = O(n)
                space complexity = 1       

deletion: time complexity = O(n)
                space complexity = 1

search: time complexity = O(n)
                space complexity = 1

head : time complexity = O(1)
                space complexity = 1
   

*/
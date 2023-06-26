#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
// Node* reverse(Node* head){  //self iterative
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     Node* prev=NULL;
//     Node* curr=head;
//     Node* forward=curr->next;
//     while(curr->next!=NULL ){
//         curr->next=prev;
//         prev=curr;
//         curr=forward;
//         forward=curr->next;
//     }
//     curr->next=prev;
//     head=curr;
//     return head;
// }

// Node* reverse(Node* head){  //self recursive 1 //done
//     if(head==NULL || head->next==NULL){
//         return head; 
//     }
//     Node* rev=reverse(head->next);
//     head->next->next=head;
//     head->next=NULL;

//     return rev;
// }

void reverse(Node*& head,Node* prev, Node*curr){  //self recursive 2 //done
    if(curr==NULL){
        head=prev;
        return;
    }
    Node* forward=curr->next;
    reverse(head,curr,forward);
    curr->next=prev;
}

int main() 
{
    // created a new node
    Node* head = new Node(0);
    Node* tail=head;
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    // print(head);
    
    // Node* rev=reverse(head); ////self iterative & rec1
    // print(rev);              ////self iterative & rec1

    Node* prev=NULL;            ////self iterative 2
    Node* curr=head;            ////self iterative 2
    reverse(head,prev,curr);    ////self iterative 2
    print(head);                ////self iterative 2

    return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void add_to_list(Node* &head, int data) { //insert at last index
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

void find_first_mid_last_element(Node* head) { //print first, mid and last elements of linked list
    if (head == NULL) { //empty list
        cout << "The linked list is empty." << endl;
        cout<<-1<<endl;
        return ;
    }
    cout<<head->data<<" ";//print first element

    if(head->next==NULL) return; //if there is only one element in liked list

    Node* slow = head; //move one node at each step
    Node* fast = head; //move two node at each step

    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data<<" "; //print mid element

    while(slow->next!=NULL){ //to reach at last element onf linked list
        slow = slow->next;
    }
    cout<<slow->data; //print last element

    return ;
}

void display(Node* head) { //print all element in liked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice;

    int t;
    cout<<"give total number of integers you want to give: ";
    cin>>t;
    while(t--){
        int data;
        cout << "Enter your data : ";
        cin >> data;
        add_to_list(head, data);
    }
    
    cout << "Linked list: ";
    display(head);

    find_first_mid_last_element(head);

    return 0;
}

/*  n=length of linked list


add_to_list :time complexity = O(n)
                space complexity = 1       

find_first_mid_last_element :time complexity = O(n)
                   space complexity = 1       

display  : time complexity = O(n)
                space complexity = 1   

*/
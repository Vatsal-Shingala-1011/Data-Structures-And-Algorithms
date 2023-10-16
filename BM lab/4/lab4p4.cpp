#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = new struct node; // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void inOrder(struct node* root) { //inorder traversal
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Function to insert a binary tree based on user input
struct node* insertUserInput() {
    int data;
    cout << "Enter node data (-1 for NULL): ";
    cin >> data;

    if (data == -1) return NULL; // Return NULL to indicate no child
    struct node* root = createNode(data);
    
    cout << "Enter left child of " << data << ":" << endl;
    root->left = insertUserInput();
    
    cout << "Enter right child of " << data << ":" << endl;
    root->right = insertUserInput();

    return root;
}

// Function to swap the left and right subtrees of a given node
void swapSubtrees(struct node* root, int n) {
    if (root == NULL){
        cout<<"value not found "<<endl;
        return; //If the tree is empty
    }
    if (root->data == n) {
        // Swap the left and right subtrees for the current node
        struct node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    } else {
        // Recursively search for the target node in the left and right subtrees
        swapSubtrees(root->left, n);
        swapSubtrees(root->right, n);
    }
}


int main(){

    struct node *p = NULL;
    p=insertUserInput();
    inOrder(p);
    cout<<endl;
    int n;
    cout<<"Enter the value(data) of nodes "<<endl;
    cin>>n;
    swapSubtrees(p,n);
    cout<<"After swapping inorder of tree is "<<endl;
    inOrder(p);
    cout<<endl;
    return 0;
}


/* n is number of node
createNode: Time - O(1), Space - O(1)
inorder: Time - O(n), Space - O(h) (where h is the height of the tree)
insertUserInput: Time - O(n), Space - O(n)
swapSubtrees: Time - O(n), Space - O(Height of tree) 
*/
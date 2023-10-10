#include<iostream>
#define MIN -2147483648
#define MAX -2147483648
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

bool isBST(node* root,int min,int max){
    if(root==NULL)  return true; //if root is NULL return true
    if(root->data>=min && root->data<=max){ //if root is in give range
        bool left=isBST(root->left,min,root->data);//min is=min but max range is change to data of that root
        bool right=isBST(root->right,root->data,max);//max value same but min value change to data value
        return (left && right); //if left and right sub tree both are BST then only tree is BST
    }
    return false; //root is not in given range
}

int main(){

    struct node *p = NULL;

    p=insertUserInput();
    inOrder(p);
    cout<<endl;

    bool BST = isBST(p,MIN,MAX); //function for check BST or not
    if(BST)cout<<"tree is BST "<<endl;
    else{
        cout<<"tree is not BST "<<endl;
    }
    return 0;
}


/* n is number of node
createNode: Time - O(1), Space - O(1)
inorder: Time - O(n), Space - O(h) (where h is the height of the tree)
insertUserInput: Time - O(n), Space - O(n)
isBST: Time - O(n), Space - O(n)
*/
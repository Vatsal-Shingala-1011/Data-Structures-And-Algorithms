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

//Lowest Common Ancestor is nearest common parents of give two node
//so thw LCA is a node which is first common ancestor of given node
struct node* lca(struct node* root,int  p,int q) {
    // If the current node is NULL or is one of the target nodes p or q, return the current node as the LCA
    if(root == NULL || root->data == p || root->data == q) return root;
        
    // Recursively search for the LCA in the left and right subtrees
    struct node *leftAns = lca(root->left, p, q);
    struct node *rightAns = lca(root->right, p, q);

    //if leftAns and rightAns both are not NULL, it means p and q are found in both subtrees, so the current root is the LCA.
    if(leftAns != NULL && rightAns != NULL) return root;
    else if(leftAns != NULL && rightAns == NULL) return leftAns;// If leftAns and rightAns both are not NULL, it means p and q are found in both subtrees, so the current root is the LCA.
    return rightAns; //else return rightAns
}

int main(){

    struct node *p = NULL;
    p=insertUserInput();
    inOrder(p);
    cout<<endl;
    struct node* x;
    int a,b;
    cout<<"Enter the value of nodes  "<<endl;
    cin>>a>>b;
    x=lca(p,a,b);
    cout<<"Lowest Common Ancestor is  "<<x->data<<endl;

    return 0;
}


/* n is number of node
createNode: Time - O(1), Space - O(1)
inorder: Time - O(n), Space - O(h) (where h is the height of the tree)
insertUserInput: Time - O(n), Space - O(n)
TopVIew: Time - O(n), Space - O(n)
*/
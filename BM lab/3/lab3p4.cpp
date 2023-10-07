
#include<iostream>
#include<vector>
#include<queue>
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

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

struct node* lca(struct node* root, struct node* p, struct node* q) {
    // If the current node is NULL or is one of the target nodes 'p' or 'q', return the current node as the LCA
    if(root == NULL || root == p || root == q) return root;
        
    // Recursively search for the LCA in the left and right subtrees
    struct node *leftAns = lca(root->left, p, q);
    struct node *rightAns = lca(root->right, p, q);

    //if leftAns and rightAns both are not NULL, it means p and q are found in both subtrees, so the current root is the LCA.
    if(leftAns != NULL && rightAns != NULL) return root;
    else if(leftAns != NULL && rightAns == NULL) return leftAns;// If leftAns and rightAns both are not NULL, it means p and q are found in both subtrees, so the current root is the LCA.
    return rightAns; //else return rightAns
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


int main(){
     
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(7);
    struct node *p6 = createNode(9);

    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \ / \
    //  1  4 7  9

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;


    struct node* x=lca(p,p3,p2);
    cout<<x->data;
    // inOrder(p);
    return 0;
}

/*
createNode: Time - O(1), Space - O(1)
inOrder: Time - O(n), Space - O(h) (where h is the height of the tree)
lca: Time - O(n), Space - O(h) (where h is the height of the tree)
insertUserInput: Time - O(n), Space - O(n)
*/
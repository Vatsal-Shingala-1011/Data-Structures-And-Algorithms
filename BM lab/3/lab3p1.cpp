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

int height(struct node* root){ //Function for find height of tree
    if(root==NULL) return 0; 
    return 1+max(height(root->left),height(root->right));
}

int diameterOfBinaryTree(struct node* root) {//Function for find diameter of tree
    if(root==NULL) return 0;
    int a=diameterOfBinaryTree(root->left); //find left diameter
    int b=diameterOfBinaryTree(root->right); //find right diameter
    int c=height(root->left)+height(root->right); //find height form node
    return max(a,max(b,c)); //return maximum of a,b and c
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

int main(){

    struct node *p = NULL;

    p=insertUserInput();
    inOrder(p);
    cout<<endl;

    int choice;
    bool flag=false;
    while (true) {
        cout << "\nEnter yout choice"<<endl;
        cout << "1. Find the diameter of the binary tree" <<endl;
        cout << "2. Find the height of the binary tree"<< endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Diameter of the binary tree: "<<diameterOfBinaryTree(p) << endl;
                break;
            case 2:
                cout << "Height of the binary tree: " <<height(p) << endl;
                break;
            case 3:
                flag=true;
                break; // Exit the program
            default:
                cout << "Invalid choice please enter 1, 2, or 3." << endl;
        }
        if(flag) break;
    }
    return 0;
}

    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

/*

createNode: Time - O(1), Space - O(1)
height: Time - O(n), Space - O(h) (where h is the height of the tree)
diameterOfBinaryTree: Time - O(n), Space - O(h)
inOrder: Time - O(n), Space - O(h)
insertUserInput: Time - O(n), Space - O(n)

*/
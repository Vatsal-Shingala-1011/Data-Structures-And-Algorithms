#include <iostream>
#include <vector>
#include <unordered_map>
#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* n = new struct node; // Allocating memory in the heap
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

void preOrder(struct node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int findindex(vector<int>& inorder, int val, int n) { // funciton for find index of that value
    for (int i = 0; i < n; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1;
}

struct node* solve(vector<int>& preorder, vector<int>& inorder, int& index, int inorderstart, int inorderend, int n, unordered_map<int, int>& map) {
    if (index >= n || inorderstart > inorderend) {
        return NULL;
    }
    // Make a node
    int ele = preorder[index];
    struct node* root = createNode(ele);

    int indexininorder = findindex(inorder, ele, n); // Find the index of current element
    index++;
    // Recursive call
    root->left = solve(preorder, inorder, index, inorderstart, indexininorder - 1, n, map);
    root->right = solve(preorder, inorder, index, indexininorder + 1, inorderend, n, map);
    return root;
}

// Function to construct a binary tree from given preorder and inorder traversals
struct node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int m = inorder.size();
    int n = preorder.size();
    int PreOrderIndex = 0;
    unordered_map<int, int> map; // Define the map
    struct node* ans = solve(preorder, inorder, PreOrderIndex, 0, n - 1, n, map);
    return ans;
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


int main() {

    struct node *p = NULL;

    p=insertUserInput();
    inOrder(p);
    cout<<endl;

    int choice;
    while (true) {
        cout << "\nSelect an operation:" << endl;
        cout << "1. Inorder Traversal" << endl;
        cout << "2. Preorder Traversal" << endl;
        cout << "3. Postorder Traversal" << endl;
        cout << "4. Construct a binary tree from Inorder and Preorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        bool flag=false;
        switch (choice) {
            case 1:
                cout << "\nInorder Traversal: \n";
                inOrder(p);
                cout << endl;
                break;
            case 2:
                cout << "\nPreorder Traversal: \n";
                preOrder(p);
                cout << endl;
                break;
            case 3:
                cout << "\nPostorder Traversal: \n";
                postOrder(p);
                cout << endl;
                break;
            case 4: {
                cout << "\nEnter total number of element : ";
                int n;
                cin>>n;
                vector<int> inorder(n);
                vector<int> preorder(n);

                cout << "\nEnter Inorder traversal values:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> inorder[i];
                }
                cout << "\nEnter Preorder traversal values:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> preorder[i];
                }

                p = buildTree(preorder, inorder);
                cout << "\nBinary Tree constructed with node p \n" << endl;
                break;
            }
            case 5:
                flag=true; // Exit the program
            default:
                cout << "\nInvalid choice\n" << endl;
        }
        if(flag)break;
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
inOrder, preOrder, postOrder: Time - O(n), Space - O(h) (where h is the height of the tree)
findindex: Time - O(n), Space - O(1)
solve: Time - O(n), Space - O(h)
buildTree: Time - O(n^2) , Space - O(n)
insertUserInput: Time - O(n), Space - O(n)


*/
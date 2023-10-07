#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void insertion(struct node * root,int key) //insertion always occurs at last node
{
    static struct node * prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(root->data == key){
            printf("can't insert");
            return;
        }
        if(root->data>key) root=root->left;
        else {
            root=root->right;
        }
    }

    struct node* n=createNode(key);

    if(key>prev->data) prev->right=n;
    else{                                   //needed
        prev->left=n;
    }          
}

void kth_smallest_node(struct  node* root,int& k){
    if(root!=NULL){
        kth_smallest_node(root->left,k);
        k=k-1;
        if(k==0){
            cout<<"kth smallest node value is: "<<root->data<<endl;
        }
        kth_smallest_node(root->right,k);
    }
}

void kth_largenst_node(struct  node* root,int &k){
    if(root!=NULL){
        kth_largenst_node(root->right,k);
        k=k-1;
        if(k==0){
            cout<<"kth largest node value is: "<<root->data<<endl;
        }
        kth_largenst_node(root->left,k);
    }
}

// Function to check if a value exists in the BST
bool search(struct node* root, int value) {
    if (root == NULL)return false;
    
    if (root->data == value) return true;
    else if (root->data > value) return search(root->left, value);
    else
        return search(root->right, value);
}

struct node* lowestCommonAncestor(struct node* root, int p, int q) {
    if(search(root,p)==false || search(root,q)==false ){
        cout<<"value is not in tree  "<<endl;
        return NULL;
    }
    while (root != NULL) {
        if (root->data > p && root->data > q)
            root = root->left;
        else if (root->data < p && root->data < q)
            root = root->right;
        else
            return root; // This is the LCA
    }

    return NULL; // LCA not found
}

// Function to insert a value into the binary tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, return a new node as the root
        return createNode(data);
    } else {
        // Otherwise, recur down the tree
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

struct node *inorderpredecessor(struct node *root)
{
    if (root->left == NULL) return NULL;
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *inordersuccessor(struct node *root)
{
    if (root->right == NULL) return NULL;
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *deletion(struct node *root, int value)
{
    struct node *ipre;
    struct node *isuc;
    
    if (root == NULL) return NULL; //if null return null

    if (root->left == NULL && root->right == NULL){
        if(root->data==value){
            free(root);
            return NULL;
        }
        else{
            printf("value is not found in tree ");
            return root;
        }
        return NULL;
    }

    // searching for the node to be deleted
    if (value < root->data) root->left = deletion(root->left, value);
    else if (value > root->data)
    {
        root->right = deletion(root->right, value);
    }
    else   // deletion strategy when the node is found
    {
        ipre = inorderpredecessor(root); // problem is if left of root is null
        if (ipre==NULL)
        {
            isuc=inordersuccessor(root);
            root->data = isuc->data;
            root->right = deletion(root->right, isuc->data);
        }
        else
        {
            root->data = ipre->data;
            root->left = deletion(root->left, ipre->data);
        }
    }
    return root;
}

int main() {
    struct node *p = NULL;

    char choice;
    while (true) {
        cout << "\nEnter your choice:" << endl;
        cout << "a) Insert a node" << endl;
        cout << "b) Kth smallest node" << endl;
        cout << "c) Kth largest node" << endl;
        cout << "d) Lowest common ancestor" << endl;
        cout << "e) Delete a node" << endl;
        cout << "f) Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                int data;
                cout << "Enter the value to insert: ";
                cin >> data;
                p = insert(p, data);
                cout << "Value " << data << " inserted." << endl << "Inorder is: ";
                inOrder(p);
                cout << endl;
                break;
            }
            case 'b': {
                int k;
                cout << "Enter the value of k: ";
                cin >> k;
                kth_smallest_node(p, k);
                break;
            }
            case 'c': {
                int k;
                cout << "Enter the value of k: ";
                cin >> k;
                kth_largenst_node(p, k);
                break;
            }
            case 'd': {
                int pp, qq;
                cout << "Enter the values of p and q: ";
                cin >> pp >> qq;
                struct node *lcaNode = lowestCommonAncestor(p, pp, qq);
                if (lcaNode != NULL) {
                    cout << "Lowest common ancestor: " << lcaNode->data << endl;
                }
                break;
            }
            case 'e': {
                int data;
                cout << "Enter the value to delete: ";
                cin >> data;
                deletion(p,data);
                cout << "Value " << data << " deleted." << endl << "Inorder is: ";
                inOrder(p);
                cout << endl;
                break;
            }
            case 'f':
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

/*
createNode: Time - O(1), Space - O(1)
inOrder: Time - O(n), Space - O(h) (where h is the height of the tree)
insertion: Time - O(h), Space - O(1)
kth_smallest_node: Time - O(n), Space - O(h)
kth_largest_node: Time - O(n), Space - O(h)
search: Time - O(h), Space - O(h)
lowestCommonAncestor: Time - O(h), Space - O(h)
insert: Time - O(h), Space - O(h)
inorderpredecessor: Time - O(h), Space - O(1)
inordersuccessor: Time - O(h), Space - O(1)
deletion: Time - O(h), Space - O(h)
*/
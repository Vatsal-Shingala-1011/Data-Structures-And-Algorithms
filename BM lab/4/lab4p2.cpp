#include<iostream>
using namespace std;
#define MIN -2147483648
#define MAX -2147483648

template <typename T>
class Queue {
public:
    int first = 0;
    int rear = 0;
    int size = 0;
    T* arr;

    Queue(int val) {
        arr = new T[val + 1];
        size = val + 1;
    }

    void push(const T& val) {
        if ((rear + 1) % size != first) {
            arr[rear] = val;
            rear = (rear + 1) % size;
        } else {
            std::cout << "Queue overflow" << std::endl;
        }
        return;
    }

    T front() {
        if (first != rear) {
            return arr[first];
        }
        std::cout << "Queue is empty" << std::endl;
        return T();
    }

    void emplace(const T& val) {
        if ((rear + 1) % size != first) {
            arr[rear] = val;
            rear = (rear + 1) % size;
        } else {
            std::cout << "Queue overflow" << std::endl;
        }
        return;
    }

    bool isEmpty() {
        return first == rear;
    }

    void pop() {
        if (first != rear) {
            first = (first + 1) % size;
        }
    }

    int Size() {
        return (rear - first + size) % size;
    }
};

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

int countNodes(node* root) { // Function for cnt total nodes in tree
    if (root == NULL) return 0;

    // Recursively count nodes in the left and right subtrees
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return leftCount + rightCount + 1;
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

void topView(node* root) {
    if (root == NULL) return;  // If the tree is empty, return

    Queue<pair<node*, int>> q(1000); // Create a queue for level order traversal
    q.push({root, 0});  // Initialize the queue with the root and horizontal distance 0

    int MAX_HD = countNodes(root); // maximum horizontal distance
    int MIN_HD = -countNodes(root);; // minimum horizontal distance

    int* topNodes= new int[MAX_HD - MIN_HD + 1]; // Initialize an array for the top nodes

    for(int i=0;i<MAX_HD - MIN_HD + 1;i++){
        topNodes[i]=MIN;
    }
    while (!q.isEmpty()) {
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second; // Current horizontal distance

        if (topNodes[hd - MIN_HD] == MIN) {
            // If this horizontal distance is not set, it means this is the top node for that distance
            topNodes[hd - MIN_HD] = frontnode->data;
        }

        if (frontnode->left != NULL) q.push({frontnode->left, hd - 1});//add left node to queue
        if (frontnode->right != NULL) q.push({frontnode->right, hd + 1});//add right node to queue
    }

    // printing the top nodes in order of their horizontal distance
    for (int i = 0; i < MAX_HD - MIN_HD + 1; i++) {
        if (topNodes[i] != MIN) {
            cout << topNodes[i] << " ";
        }
    }
}

int main(){
    struct node *p = NULL;
    p=insertUserInput();
    inOrder(p);
    cout<<endl;
    cout<<"Top view of Tree is: ";
    topView(p);
    return 0;
}


/* n is number of node
createNode: Time - O(1), Space - O(1)
inorder: Time - O(n), Space - O(h) (where h is the height of the tree)
insertUserInput: Time - O(n), Space - O(n)
topView: Time - O(n), Space - O(n)
*/
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

void Depth_first_search(struct node* root) { //inorder traversal
    if (root != NULL) {
        Depth_first_search(root->left);
        cout << root->data << " ";
        Depth_first_search(root->right);
    }
}
void levelOrder(struct node* root) {//Level Order Traversal of a binary tree
    if(root==NULL) return ;// If the tree is empty, return
    queue<struct node*> q;
    q.push(root);
    while(!q.empty()){// Continue until the queue is empty
        int n=q.size();
        while(n--){// Process nodes at the current level
            struct node* front=q.front();
            cout<<q.front()->data<<" ";
            q.pop();
            // Enqueue the left and right child of the front node if they exist
            if(front->left!=NULL)q.push(front->left);
            if(front->right!=NULL)q.push(front->right);
        }
    }
    return ;
}

void zigzagLevelOrder(struct node* root) {
    vector<vector<int> > ans;
    if(root==NULL){return ;}
    queue<struct node*> q; // queue contains poiner 
    bool lefttoright=true; //direction is left to right at starting
    q.push(root);
        
    while(!q.empty()){ // Continue while the queue is not empty
        int n=q.size();
        vector<int> level_ans(n);

        //for every level
        for(int i=0;i<n;i++)
        {
            struct node* front=q.front();
            q.pop();
            int index=lefttoright?i:n-i-1;
            level_ans[index]=front->data;
            // Enqueue the left and right children of the front node if they exist
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
        //direction change
        lefttoright=!lefttoright; //change direction
        ans.push_back(level_ans);
    }
    for(auto i : ans){ //print zigzag levelorder 
        for (auto j : i){
        cout<<j<<" ";
        }
    }
return ;
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
    struct node* p = NULL;

    p = insertUserInput();
    cout << endl;

    char choice;
    bool flag = false;
    while (true) {
        cout << "\nEnter your choice" << endl;
        cout << "a) Depth First Search (Inorder Traversal)" << endl;
        cout << "b) Level Order Traversal" << endl;
        cout << "c) Zigzag Traversal" << endl;
        cout << "d) Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Depth First Search (Inorder Traversal): ";
                Depth_first_search(p);
                cout << endl;
                break;
            case 'b':
                cout << "Level Order Traversal: ";
                levelOrder(p);
                cout << endl;
                break;
            case 'c':
                cout << "Zigzag Traversal: " << endl;
                zigzagLevelOrder(p);
                cout << endl;
                break;
            case 'd':
                flag = true;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        if (flag) break;
    }

    return 0;
}

/*
createNode: Time - O(1), Space - O(1)
Depth_first_search: Time - O(n), Space - O(h) (where h is the height of the tree)
levelOrder: Time - O(n), Space - O(w) (where w is the maximum width of the tree)
zigzagLevelOrder: Time - O(n), Space - O(w)
insertUserInput: Time - O(n), Space - O(n)
*/
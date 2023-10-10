#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(node *root) //using level order traversal
{
    if(root ==NULL) return;
    map<int,int> topnode;
    //  hd, val       //hd=horizontal distance
    queue<pair<node*,int>> q;
    //                hd
    q.push({root,0});
    while(!q.empty()){ 
        auto temp=q.front();
        //pair<node*,int>=q.front();
        q.pop();
        node* frontnode=temp.first;
        int hd=temp.second;
        if(topnode.find(hd)==topnode.end()){ //if key hd is not found
            topnode[hd]=frontnode->data; //store in topnode map
        }
        if(frontnode->left!=NULL)
        {
            q.push({frontnode->left,hd-1});
    //OR // q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontnode->right!=NULL) q.push({frontnode->right,hd+1});
    }

    for(auto i:topnode){ //<int,int> i is corresponding values of key, its give increasing order horizontal level 
        cout<<i.second<<" ";
    }
    cout<<endl;
}

int main(){

    struct node *p = NULL;
    p=insertUserInput();
    inOrder(p);
    cout<<endl;
    topView(p);
    return 0;
}


/* n is number of node
createNode: Time - O(1), Space - O(1)
inorder: Time - O(n), Space - O(h) (where h is the height of the tree)
insertUserInput: Time - O(n), Space - O(n)
TopVIew: Time - O(n), Space - O(n)
*/
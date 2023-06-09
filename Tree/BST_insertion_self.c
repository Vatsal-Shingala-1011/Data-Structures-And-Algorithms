#include<stdio.h>        //self
#include<malloc.h>

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

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
//////is it work? check
// struct Node *insert(struct Node* node, int key){
//     if (node == NULL)
//         return  createNode(key);
 
//     if (key < node->key)
//         node->left  = insert(node->left, key);
//     else if (key > node->key)
//         node->right = insert(node->right, key);

//         ........some code......
// }


void insertion(struct node * root,int key)   //recursion
{
    struct node* prev=root;
    if(root->data==key)
    {
        printf("can't be added");
    }
    else if(root->data>key)
    {
        root=root->left;
        if(root==NULL)
        {
        struct node* n = createNode(key);
        prev->left=n;
        return;
        }
        insertion(root,key);
    }
    else if(root->data<key)
    {
        root=root->right;
        if(root==NULL)
        {
        struct node* n = createNode(key);
        prev->right=n;
        return;
        }
        insertion(root,key);

    }
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(66);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p); 
    // printf("\n");
    // inOrder(p);
    // printf("\n");
    // printf("%d", isBST(p)); 
    // insertion(p,40);
    // insertion(p,88);
    insertion(p,34);
    insertion(p,2);
    insertion(p,37);
    insertion(p,34);
    insertion(p,343);
    insertion(p,314);



    inOrder(p);
    return 0;
}

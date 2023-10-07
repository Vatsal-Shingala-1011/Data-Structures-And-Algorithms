#include<stdio.h>        //self
#include<malloc.h>
#include <vector>

// #include<bits/stdc++.h>

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

int findindex(vector<int> &inorder,int val,int n){
    for(int i=0;i<n;i++)
    {
        if(inorder[i]==val)
        {
            return i;
        }
    }
    return -1;
}

struct node* solve(vector<int>& preorder, vector<int>& inorder,int& index,int inorderstart,int inorderend,int n,unordered_map<int,int>& map){
    if(index>=n || inorderstart>inorderend){
        return NULL;
    }
    //make a node
    int ele=preorder[index];
    struct node* root=new struct node(ele);

    int indexininorder=findindex(inorder,ele,n);
    index++;
    //recursive call
    root->left=solve(preorder,inorder,index,inorderstart,indexininorder-1,n,map);
    root->right=solve(preorder,inorder,index,indexininorder+1,inorderend,n,map);
    return root;
}

struct node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int m=inorder.size();
    int n=preorder.size();
    int PreOrderIndex=0;
    struct node* ans=solve(preorder,inorder,PreOrderIndex,0,n-1,n,map);
    return ans;
}

int main(){
    vector<int> pre(8);
    vector<int> ino(8);

    int n=8;
    for(int i=0;i<n;i++){
        cin>>ino[i];
    }
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    struct node *p = buildTree(pre,ino);
    inOrder(p);
    
    return 0;
}

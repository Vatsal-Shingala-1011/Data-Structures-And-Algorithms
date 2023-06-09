#include <stdio.h> // error
#include <stdlib.h>
#include <malloc.h>


struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node* create(int data) //function
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

int search(int inorder[],int start,int end,int curr)
{
    for(int i =start;i<end;i++)
    {
        if(inorder[i]==curr)
        {return i;}
    }
    return -1;
}

struct node * buildtree(int preorder[], int inorder[],int start,int end)
{
    if(start>end){
        return NULL;
    }
    static int idx=0;
    int curr= preorder[idx];
    idx++;
    struct node* new=create(curr);
    if(start==end)
    {
        return new;
    }

    int pos=search(inorder,start,end,curr);
    new->left=buildtree(preorder,inorder,start,pos-1);
    new->right=buildtree(preorder,inorder,pos+1,end);
    return new; 

}
void inorderprint(struct node* root) {
    inorderprint(root->left);
    printf("%d ",root->data);
    inorderprint(root->left);

}

int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    struct node* root=buildtree(preorder,inorder,0,4);
    inorderprint(root);

    return 0;
}
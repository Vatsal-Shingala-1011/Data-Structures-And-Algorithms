#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
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
        if(root->data == key)
        {
            printf("can't insert");
            return;
        }
        if(root->data>key)
        {
            root=root->left;
        }
        else 
        {
            root=root->right;
        }
    }
    struct node* n=createNode(key);
    if(key>prev->data)                      //needed
    {
        prev->right=n;
    }
    else                                    //needed
    {
        prev->left=n;
    }           //no return because argument struct node * root is duplicate  //++ //root is duplicte varialble which contain address of struct node type variable 
}


struct node *inorderpredecessor(struct node *root)
{
    if (root->left == NULL)
    {
        return NULL;
    }
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *inordersuccessor(struct node *root)
{
    if (root->right == NULL)
    {
        return NULL;
    }
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
// /////////what is error here?
// void deletion(struct node *root, int key)
// {
//     struct node *ipre=NULL;
//     if (root == NULL)
//     {
//         return;
//     }
//     while (root != NULL && root->data != key)
//     {
//         if (root->data > key)
//         {
//             deletion(root->left, key);
//         }
//         else if (root->data < key)
//         {
//             deletion(root->right, key);
//         }
//     }
//     if (root->data == key)
//     {
//         if (root->left == NULL && root->right == NULL)
//         {
//             free(root);
//             return;
//         }
//         else
//         {
//             ipre = inorderpredecessor(root);
//             root->data = ipre->data;
//             free(ipre);
//             return;
//         }
//     }
// }


struct node *deletion(struct node *root, int value) //correct code , self , not in cwd
{
    struct node *ipre;
    struct node *isuc;
    
    if (root == NULL)
    {
        return NULL;
    }
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
    if (value < root->data)
    {
        root->left = deletion(root->left, value);
    }
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

int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
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

    inOrder(p);
    // printf("\n");
    // postOrder(p);
    // printf("\n");
    // inOrder(p);
    printf("\n");
    // printf("%d", isBST(p));
    insertion(p, 8);
    insertion(p, 40);
    insertion(p, 88);
    insertion(p, 34);
    inOrder(p);
    printf("\n");
    deletion(p, 41230);
    inOrder(p);

    // printf("%d", p->right->right->data);
    return 0;
}

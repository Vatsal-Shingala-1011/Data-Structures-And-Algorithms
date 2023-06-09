#include <stdio.h> //self
#include <stdlib.h>

struct Node
{
    int key;
    int c; // black 0 , red 1
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};


struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->c = 0;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

struct Node *root = NULL;
struct Node *newnode = NULL;

struct Node *insert(struct Node *node, int key)
{

    if (node == NULL)
    {
        newnode = createNode(key);
        return createNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
        node->left->parent = node; // set parent of every node
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
        node->right->parent = node; // set parent of every node
    }
    return node;
}

void *red_black_insertion(struct Node *node)
{
    struct Node *grandparent;
    while (newnode != root && newnode->c==1 && newnode->parent->c == 1)   //new node globle variable
    {
        grandparent = newnode->parent->parent;

        if (newnode->parent == grandparent->left)   /////case 1
        {
            struct Node *uncle = grandparent->right;

            if (uncle == NULL || uncle->c == 0) // uncle is black or null
            {
                if (newnode = newnode->parent->left) // rr rotation
                {
                    grandparent->c = 1;
                    newnode->parent->c = 0;
                    rightRotate(grandparent);
                    // rr rotation 2
                    // recolor
                }
                if (newnode = newnode->parent->right) // lr rotation
                {
                    newnode->c = 0;
                    grandparent->c = 1;
                    leftRotate(newnode->parent);
                    rightRotate(grandparent);
                    // lr rotation 2
                    // recolor
                }
            }
            else // uncle red
            {
                newnode->parent->c = 0;
                uncle->c = 0;
                if (grandparent == root)
                {
                    grandparent->c = 0;
                    break;
                }
                else
                {
                    grandparent->c = 1;
                    red_black_insertion(grandparent);
                }
            }
        }


        if (newnode->parent == grandparent->right)     ///case 2
        {
            struct Node *uncle = grandparent->left;

            if (uncle == NULL || uncle->c == 0) // uncle is black or null
            {
                if (newnode = newnode->parent->left) // rl rotation
                {
                    grandparent->c = 1;
                    newnode->c = 0;
                    rightRotate(newnode->parent);
                    leftRotate(grandparent);
                }
                if (newnode = newnode->parent->right) // ll rotation
                {
                    newnode->parent->c = 0;
                    grandparent->c = 1;
                    leftRotate(newnode->parent);
                    rightRotate(grandparent);
                }
            }
            else // uncle red
            {
                newnode->parent->c = 0;
                uncle->c = 0;
                if (grandparent == root)
                {
                    grandparent->c = 0;
                    break;
                }
                else
                {
                    grandparent->c = 1;
                    red_black_insertion(grandparent);
                }
            }
        }


    }
}
void preOrder(struct Node* root){
    if(root!=NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct  Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
int main()
{

    root = insert(root, 447);
    red_black_insertion(root);

    root = insert(root, 16);
    red_black_insertion(root);

    red_black_insertion(root);
    root = insert(root, 53);

    red_black_insertion(root);
    root = insert(root, 45);

    red_black_insertion(root);
    root = insert(root, 3);
    red_black_insertion(root);

    root = insert(root, 02);
    red_black_insertion(root);

    root = insert(root, 0);
    red_black_insertion(root);

    // preOrder(root);
    inOrder(root);
    return 0;
}

#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int key;
    Color c; // black 0, red 1
    Node *left;
    Node *right;
    Node *parent;
};

void preOrder(Node* root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->key << " ";
        inOrder(root->right);
    }
}

Node* createNode(int key) {
    Node *node = new Node;
    node->key = key;
    node->c = BLACK;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    return node;
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

Node* root = nullptr;
Node* newnode = nullptr;

Node* insert(Node *node, int key) { //normal insertion
    if (node == nullptr) {
        newnode = createNode(key);
        return newnode;
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
        node->left->parent = node; // set parent of every node
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
        node->right->parent = node; // set parent of every node
    }
    return node;
}

void red_black_insertion(Node *node) {
    Node *grandparent;
    //if newnode == root do nothing
    while (newnode != root && newnode->c == RED && newnode->parent->c == RED) {
        grandparent = newnode->parent->parent;

        if (newnode->parent == grandparent->left) { // case 1 left side
            Node *uncle = grandparent->right;

            if (uncle == nullptr || uncle->c == BLACK) { // uncle is black or null
                if (newnode == newnode->parent->right) { // rr rotation
                    grandparent->c = RED;
                    newnode->parent->c = BLACK;
                    leftRotate(newnode->parent);
                    rightRotate(grandparent);
                    // rightRotate(grandparent);
                }
                if (newnode == newnode->parent->left) { // lr rotation
                    newnode->c = BLACK;
                    grandparent->c = RED;
                    // leftRotate(newnode->parent);
                    // rightRotate(grandparent);
                    rightRotate(grandparent);
                }
            }
            else { // uncle red
                newnode->parent->c = BLACK;
                uncle->c = BLACK;
                if (grandparent == root) {
                    grandparent->c = BLACK;
                }
                else {
                    grandparent->c = RED;
                    red_black_insertion(grandparent);
                }
            }
        }

        if (newnode->parent == grandparent->right) { // case 2 right side
            Node *uncle = grandparent->left;

            if (uncle == nullptr || uncle->c == BLACK) { // uncle is black or null
                if (newnode == newnode->parent->left) { // rl rotation
                    grandparent->c = RED;
                    newnode->c = BLACK;
                    rightRotate(newnode->parent);
                    leftRotate(grandparent);
                }
                if (newnode == newnode->parent->right) { // ll rotation
                    newnode->parent->c = BLACK;
                    grandparent->c = RED;
                    leftRotate(newnode->parent);//corection
                    rightRotate(grandparent);
                }
            }
            else { // uncle red
                newnode->parent->c = BLACK;
                uncle->c = BLACK;
                if (grandparent == root) {
                    grandparent->c = BLACK;
                    break;
                }
                else {
                    grandparent->c = RED;
                    red_black_insertion(grandparent);
                }
            }
        }
    }
}

int main() {
    root = insert(root, 447); // insertion function with assigned parents
    red_black_insertion(root);

    root = insert(root, 16);
    red_black_insertion(root);

    root = insert(root, 53);
    red_black_insertion(root);

    root = insert(root, 45);
    red_black_insertion(root);

    root = insert(root, 3);
    red_black_insertion(root);

    root = insert(root, 2);
    red_black_insertion(root);

    root = insert(root, 0);
    red_black_insertion(root);

    // preOrder(root);
    inOrder(root);

    return 0;
}
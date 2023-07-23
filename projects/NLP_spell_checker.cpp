#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    string word;
    Color color;
    Node* parent;
    Node* left;
    Node* right;
};

typedef Node* NodePtr;

class SpellChecker {
private:
    NodePtr root;
    NodePtr TNULL; //NULL poiter

    NodePtr createNode(const string& word) { // create new node
        NodePtr node = new Node;
        node->word = word;
        node->color = RED; //bydefault red colour
        node->left = TNULL;
        node->right = TNULL;
        return node;
    }

    void initializeNULLNode(NodePtr node, NodePtr parent) { //initialize NULL Node with Black color and empty word
        node->word = "";
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = BLACK;
    }

    void leftRotate(NodePtr x) {   //left rotete from x
        NodePtr y = x->right;     
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(NodePtr y) { //right rotate from y
        NodePtr x = y->left;
        y->left = x->right;
        if (x->right != TNULL) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nullptr) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }

    void make_RedBlackTree_insert(NodePtr k) {// function for make red black tree proparties
        NodePtr uncle;
        while (k->parent != nullptr && k->parent->color == RED) {//this loop run till k is not root node or two adjecent node are Red
            NodePtr grandparent=k->parent->parent;

            if (k->parent == grandparent->right) {
                uncle = grandparent->left; // k->parent's sibling
                if (uncle->color == RED) {//if uncle color is red then tree is balance no need of rotation
                    uncle->color = BLACK;
                    k->parent->color = BLACK;
                    grandparent->color = RED;
                    k = grandparent;
                }else {//uncle->color == Black
                    if (k == k->parent->left) {//correct done
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    grandparent->color = RED;
                    leftRotate(grandparent);
                }
            } else {
                uncle = grandparent->right; // uncle
                if (uncle->color == RED) {
                    uncle->color = BLACK;
                    k->parent->color = BLACK;
                    grandparent->color = RED;
                    k = grandparent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    grandparent->color = RED;
                    rightRotate(grandparent);
                }
            }
            if (k == root) break;
        }
        root->color = BLACK;
    }

    void insert(NodePtr node, const string& word) { //insert contact at correct possition and satisfy red black tree proparties
        NodePtr prev = nullptr;
        while (node != TNULL) {
            prev = node;
            if (word < node->word) {
                node = node->left;
            } else if (word > node->word) {
                node = node->right;
            } else {
                //if word is already exist then return
                return;
            }
        }
        NodePtr newNode = createNode(word);
        newNode->parent = prev;
        if (prev == nullptr) {
            root = newNode;
        } else if (word < prev->word) {
            prev->left = newNode;
        } else {
            prev->right = newNode;
        }
        make_RedBlackTree_insert(newNode);
    }

    NodePtr findNode(const string& word, NodePtr node) {
        if (node == TNULL || node->word==word) {
            return node;
        }
        if (word < node->word) {
            return findNode(word, node->left);
        }
        return findNode(word, node->right);
    }

        NodePtr findMinNode(NodePtr node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    void make_RedBlackTree_Remove(NodePtr x) { // make tree redblacktree after removing contact
        NodePtr s;
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->left->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }
    
    void rbTransplant(NodePtr u, NodePtr v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void remove(string& word) {
        NodePtr z = findNode(word, root);
        if (z == TNULL) {
            cout << "Spell not found in the dictionary." << endl;
            return;
        }
        NodePtr x, y;
        Color originalColor = z->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        } else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        } else {
            y = findMinNode(z->right);
            originalColor = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (originalColor == BLACK) {
            make_RedBlackTree_Remove(x);
        }
        cout<<endl<<"Spell removed successfully."<<endl;
    }

    void inorderTraversal(NodePtr node) {
        if (node != TNULL) {
            inorderTraversal(node->left);
            cout<<node->word<<", ";
            inorderTraversal(node->right);
        }
    }

public:
    SpellChecker() { //default constructor 
        TNULL = new Node;
        TNULL->color = BLACK;
        TNULL->left = NULL;
        TNULL->right = NULL;
        root = TNULL;
    }

    void insert(const string& word) { //inserting word
        insert(root, word);
        cout<<endl<<"Spell added successfully."<<endl;
    }

    // void search(const string& word) { //searching word
    //     NodePtr node = findNode(word, root);
    //     if (node == TNULL) {
    //         cout<<endl<<"word "<<word<<" is not correct. possible spelling may be :"<< endl;
    //     } else {
    //         cout<<endl<<"Word is spelled correctly."<<endl;
    //         //write code for suggetion
    //         // Implement suggestions logic here based on the dictionary
    //     }
    // }
    void search(const string& word) {
        NodePtr node = findNode(word, root);
        if (node == TNULL) {
            cout << "word " << word << " is not correct. Possible spellings may be:" << endl;

            // Call machine learning model to get suggested corrections
            vector<string> suggestedCorrections = getMachineLearningSuggestion(word);

            // Display suggested corrections to the user
            for (const string& suggestion : suggestedCorrections) {
                cout << suggestion << endl;
            }
        } else {
            cout << "Word is spelled correctly." << endl;
        }
    }

    void dispdisplayAllDictionary() {  //printing all word
        inorderTraversal(root);
    }

    void removeWord(string& word) { //removing word
        remove(word);
    }

    NodePtr getRoot() {
        return this->root;
    }

};

int main() {
    SpellChecker spellChecker;
    int choice;
    string word;
    do {
        cout << "\n************** Spell Checker **************" << endl;
        cout << "1. Insert Spell" << endl;
        cout << "2. Check valid Spell or not" << endl;
        cout << "3. Remove Contact" << endl;
        cout << "4. Display Dictionary" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;
        switch (choice) {
            case 1:
                cout<<"Enter word: ";
                cin.ignore();
                getline(cin, word);
                spellChecker.insert(word);
                break;
            case 2:
                cout<<endl<<"Enter word: ";
                cin.ignore();
                getline(cin, word);
                spellChecker.search(word);
                break;
            case 3:
                cout<<endl<<"Enter word: ";
                cin.ignore();
                getline(cin, word);
                spellChecker.removeWord(word);
                break;
            case 4:
                cout<<"********** All Words in the dictionary **********"<<endl;
                cout<<"[ ";
                spellChecker.dispdisplayAllDictionary();
                cout<<"]"<<endl;
                break;
            case 5:
                cout<<"Exiting Spell Checker System. Goodbye!"<<endl<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while (choice != 5);

    return 0;
}

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

    void search(const string& word) { //searching word
        NodePtr node = findNode(word, root);
        if (node != TNULL) {
            cout<<endl<<"Word is spelled correctly."<<endl;    
        } else {
            cout<<endl<<"word "<<word<<" is not correct. possible spelling may be :"<< endl;
            //write code for suggetion
            // Implement suggestions logic here based on the dictionary
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



//NLTK library not NLP (Using Levenshtein Distance(Edit Distance))
// import numpy as np
// import nltk
// from nltk.corpus import words

// class Color:
//     RED = 0
//     BLACK = 1

// class Node:
//     def __init__(self, word):
//         self.word = word
//         self.color = Color.RED  # by default, the color is red
//         self.parent = None
//         self.left = None
//         self.right = None

// class SpellChecker:
//     def __init__(self):
//         self.root = None
//         self.TNULL = Node("")  # NULL pointer
//         self.TNULL.color = Color.BLACK
//         self.TNULL.left = None
//         self.TNULL.right = None
//         self.root = self.TNULL

//     def create_node(self, word):
//         node = Node(word)
//         node.left = self.TNULL
//         node.right = self.TNULL
//         return node

//     def left_rotate(self, x):
//         y = x.right
//         x.right = y.left
//         if y.left != self.TNULL:
//             y.left.parent = x
//         y.parent = x.parent
//         if x.parent is None:
//             self.root = y
//         elif x == x.parent.left:
//             x.parent.left = y
//         else:
//             x.parent.right = y
//         y.left = x
//         x.parent = y

//     def right_rotate(self, y):
//         x = y.left
//         y.left = x.right
//         if x.right != self.TNULL:
//             x.right.parent = y
//         x.parent = y.parent
//         if y.parent is None:
//             self.root = x
//         elif y == y.parent.left:
//             y.parent.left = x
//         else:
//             y.parent.right = x
//         x.right = y
//         y.parent = x

//     def make_red_black_tree_insert(self, k): #function for make red black tree proparties
//         while k.parent is not None and k.parent.color == Color.RED:
//             grandparent = k.parent.parent
//             if k.parent == grandparent.right: #k->parent's sibling
//                 uncle = grandparent.left   #if uncle color is red then tree is balance no need of rotation
//                 if uncle.color == Color.RED:
//                     uncle.color = Color.BLACK
//                     k.parent.color = Color.BLACK
//                     grandparent.color = Color.RED
//                     k = grandparent
//                 else:  #uncle->color == Black
//                     if k == k.parent.left:
//                         k = k.parent
//                         self.right_rotate(k)
//                     k.parent.color = Color.BLACK
//                     grandparent.color = Color.RED
//                     self.left_rotate(grandparent)
//             else:
//                 uncle = grandparent.right
//                 if uncle.color == Color.RED:
//                     uncle.color = Color.BLACK
//                     k.parent.color = Color.BLACK
//                     grandparent.color = Color.RED
//                     k = grandparent
//                 else:
//                     if k == k.parent.right:
//                         k = k.parent
//                         self.left_rotate(k)
//                     k.parent.color = Color.BLACK
//                     grandparent.color = Color.RED
//                     self.right_rotate(grandparent)
//             if k == self.root:
//                 break
//         self.root.color = Color.BLACK

//     def insert(self, word): #insert contact at correct possition and satisfy red black tree proparties
//         prev = None
//         node = self.root
//         while node != self.TNULL:
//             prev = node
//             if word < node.word:
//                 node = node.left
//             elif word > node.word:
//                 node = node.right
//             else:
//                 # If the word is already in the dictionary, return
//                 return
//         new_node = self.create_node(word)
//         new_node.parent = prev
//         if prev is None:
//             self.root = new_node
//         elif word < prev.word:
//             prev.left = new_node
//         else:
//             prev.right = new_node
//         self.make_red_black_tree_insert(new_node)

//     def find_node(self, word, node):
//         if node == self.TNULL or node.word == word:
//             return node
//         if word < node.word:
//             return self.find_node(word, node.left)
//         return self.find_node(word, node.right)

//     def find_min_node(self, node):
//         while node.left != self.TNULL:
//             node = node.left
//         return node

//     def make_red_black_tree_remove(self, x): #make tree redblacktree after removing contact
//         while x != self.root and x.color == Color.BLACK:
//             if x == x.parent.left:
//                 s = x.parent.right
//                 if s.color == Color.RED:
//                     s.color = Color.BLACK
//                     x.parent.color = Color.RED
//                     self.left_rotate(x.parent)
//                     s = x.parent.right

//                 if s.left.color == Color.BLACK and s.right.color == Color.BLACK:
//                     s.color = Color.RED
//                     x = x.parent
//                 else:
//                     if s.right.color == Color.BLACK:
//                         s.left.color = Color.BLACK
//                         s.color = Color.RED
//                         self.right_rotate(s)
//                         s = x.parent.right

//                     s.color = x.parent.color
//                     x.parent.color = Color.BLACK
//                     s.right.color = Color.BLACK
//                     self.left_rotate(x.parent)
//                     x = self.root
//             else:
//                 s = x.parent.left
//                 if s.color == Color.RED:
//                     s.color = Color.BLACK
//                     x.parent.color = Color.RED
//                     self.right_rotate(x.parent)
//                     s = x.parent.left

//                 if s.right.color == Color.BLACK and s.left.color == Color.BLACK:
//                     s.color = Color.RED
//                     x = x.parent
//                 else:
//                     if s.left.color == Color.BLACK:
//                         s.right.color = Color.BLACK
//                         s.color = Color.RED
//                         self.left_rotate(s)
//                         s = x.parent.left

//                     s.color = x.parent.color
//                     x.parent.color = Color.BLACK
//                     s.left.color = Color.BLACK
//                     self.right_rotate(x.parent)
//                     x = self.root

//         x.color = Color.BLACK

//     def rb_transplant(self, u, v):
//         if u.parent is None:
//             self.root = v
//         elif u == u.parent.left:
//             u.parent.left = v
//         else:
//             u.parent.right = v
//         v.parent = u.parent

//     def remove_word(self, word):
//         z = self.find_node(word, self.root)
//         if z == self.TNULL:
//             print("Spell not found in the dictionary.",end="")
//             return
//         x = None
//         y = z
//         original_color = y.color
//         if z.left == self.TNULL:
//             x = z.right
//             self.rb_transplant(z, z.right)
//         elif z.right == self.TNULL:
//             x = z.left
//             self.rb_transplant(z, z.left)
//         else:
//             y = self.find_min_node(z.right)
//             original_color = y.color
//             x = y.right
//             if y.parent == z:
//                 x.parent = y
//             else:
//                 self.rb_transplant(y, y.right)
//                 y.right = z.right
//                 y.right.parent = y
//             self.rb_transplant(z, y)
//             y.left = z.left
//             y.left.parent = y
//             y.color = z.color
//         del z
//         if original_color == Color.BLACK:
//             self.make_red_black_tree_remove(x)
//         print("Spell removed successfully.")

//     def inorder_traversal(self, node):
//         if node != self.TNULL:
//             self.inorder_traversal(node.left)
//             print(node.word + ", ", end="")
//             self.inorder_traversal(node.right)
       
//     def levenshtein_distance(self,s1, s2):
//         m, n = len(s1), len(s2)
//         dp = np.zeros((m + 1, n + 1), dtype=int)
//         for i in range(m + 1):
//             dp[i][0] = i
//         for j in range(n + 1):
//             dp[0][j] = j
//         for i in range(1, m + 1):
//             for j in range(1, n + 1):
//                 cost = 0 if s1[i - 1] == s2[j - 1] else 1
//                 dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost)
//         return dp[m][n]
    
//     # Function to find suggestions for a given word
//     def get_suggestions(self,word, dictionary, max_distance=1):
//         suggestions = []
//         suggestions2 = []
//         for dict_word in dictionary:
//             distance = self.levenshtein_distance(word, dict_word)
//             if distance <= max_distance:
//                 suggestions.append(dict_word)
//             if distance<=max_distance+1:
//                 suggestions2.append(dict_word)
//         if suggestions==[]:
//             return suggestions2
//         return suggestions
    
//     def search(self,word):
//         node=self.find_node(word,self.root) #return none if not found
//         if node is not self.TNULL:
//             print(" word is spelled correctly",end="")
//         else:
//             print("word \"",word,"\" is not correct. possible spelling may be : ",end="")
//             suggestions = self.get_suggestions(word, dictionary,1)
//             if suggestions: #suggestions is not empty
//                 print(", ".join(suggestions))
//             else: #could not find any word similar to given word
//                 print("could not find any word similar to \"", word,"\"",end="")  
//             return 
    
// if __name__ == "__main__":
// #     dictionary = ["apple", "banana", "orange", "pear", "peach", "grape", "watermelon"]
//     dictionary = words.words()
//     S = SpellChecker()
//     for word in dictionary:
//         S.insert(word)

//     choice = None
//     while choice != "5":
//         print("\n************** Spell Checker **************")
//         print("1. Insert Spell")
//         print("2. Check valid Spell or not")
//         print("3. Remove Contact")
//         print("4. Display Dictionary")
//         print("5. Exit")
//         choice = input("Enter your choice: ")
//         if choice == "1":
//             word = input("Enter word: ")
//             S.insert(word)#insert in Tree
//             dictionary.append(word)
//         elif choice == "2":
//             word = input("Enter word: ")
//             node = S.search(word)
//         elif choice == "3":
//             word = input("Enter word: ")
//             S.remove_word(word)
//         elif choice == "4":
//             print("********** All Words in the dictionary **********")
//             S.inorder_traversal(S.root)
//         elif choice == "5":
//             print("Exiting Spell Checker System. Goodbye!\n")
//         else:
//             print("Invalid choice. Please try again.")